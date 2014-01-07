#!/usr/bin/env python

# ---------------------------------------------------------------------------
#  OpenChasm - Free software reconstruction of Chasm: The Rift game
#  Copyright (C) 2013, 2014 Alexey Lysiuk
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <http://www.gnu.org/licenses/>.
# ---------------------------------------------------------------------------

import sys, os, re

def writeheader(file):
	file.write("""
/*
**---------------------------------------------------------------------------
** OpenChasm - Free software reconstruction of Chasm: The Rift game
** Copyright (C) 2013, 2014 Alexey Lysiuk
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
**---------------------------------------------------------------------------
*/

#include "%s"

""" % file.name.replace('.cpp', '.h').replace('\\', '/'))

def finish(file):
	if file:
		file.write('')
		file.close()


if len(sys.argv) < 2:
	print('Usage: asmsplit.py asm-file')
	sys.exit()

infile = open(sys.argv[1])

currentfilename = ''
outfile = None

processedfiles = []

for line in infile:
	if re.match('cseg09\s+ends', line):
		# have no interest in cseg10 (Pascal library functions)
		# and following data segments
		break
	elif re.match('cseg\d{2}\s+ends', line):
		currentfilename = ''

		finish(outfile)
		outfile = None
	elif line.startswith('; #line	"'):
		filename = line.split('"')[1]

		if filename.endswith('TPSTRING.PAS'):
			continue

		if currentfilename != filename:
			currentfilename = filename

			filename = filename.lower().replace('.pas', '.cpp')
			pathparts = filename.split('\\')

			if len(pathparts) > 1:
				filename = pathparts.pop()
				path = os.sep.join(pathparts)
				filename = path + os.sep + filename

				try:
					os.makedirs(path)
				except OSError:
					pass

			finish(outfile)

			mode = 'w'

			if filename in processedfiles:
				mode = 'a'
			else:
				processedfiles.append(filename)

			outfile = open(filename, mode)

			print('Writing ' + filename + '...')
			writeheader(outfile)

	if outfile:
		outfile.write('//@ ' + line.rstrip('\r\n') + '\n');

finish(outfile)

infile.close()
