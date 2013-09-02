
# ---------------------------------------------------------------------------
#  OpenChasm - Free software reconstruction of Chasm: The Rift game
#  Copyright (C) 2013 Alexey Lysiuk
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

from idaapi import *


def make_struc(name):
	return get_struc(add_struc(BADADDR, name))

def make_struc_member(struc, name, offset, type, size, element_size, flags):
	if not struc:
		return

	flags  |= FF_DATA
	typeid  = -1
	comment = type

 	if -1 != element_size:
		comment += '[' + str(size / element_size) + ']'

	if isASCII(flags):
		typeid   = ASCSTR_PASCAL
		comment += ' // Pascal string'
	elif isStruct(flags):
		typeid  = get_struc_id(type)
		comment = 'struct ' + comment

	Eval('AddStrucMember(%d, "%s", %d, %d, %d, %d);' % (struc.id, name, offset, flags, typeid, size))

	set_member_cmt(get_member(struc, offset), comment, 0)

def make_ea(segment, offset):
	return getnseg(segment - 1).startEA + offset

def make_func(segment, offset, name, type):
	ea = make_ea(segment, offset)
	old_name = get_name(BADADDR, ea)
	if None == old_name or '@' != old_name[0]:
		set_name(ea, name, SN_CHECK)
	if create_insn(ea):
		autoWait()
	if add_func(ea, BADADDR):
		autoWait()
	func = get_func(ea)
	cmt = get_func_cmt(func, 1)
	if None == cmt or 0 == len(cmt):
		cmt = type
	else:
		cmt += '\\n' + type
	set_func_cmt(func, cmt, 1)
	return func

def make_data(segment, offset, name, type, size):
	ea = make_ea(segment, offset)
	set_name(ea, name, SN_CHECK)
	set_cmt(ea, type, 1)
	do_unknown_range(ea, size, DOUNK_SIMPLE)
	if 1 == size:
		doByte(ea, 1)
	elif 2 == size:
		doWord(ea, 2)
	elif 4 == size:
		doDwrd(ea, 4)
	else:
		do_data_ex(ea, FF_BYTE, size, BADADDR)

def make_import(imported_name, name, type):
	ea = get_name_ea(BADADDR, imported_name)
	set_name(ea, name, SN_CHECK)
	set_cmt(ea, type, 1)

def make_local(func, offset, name, type):
	offset += func.frsize
	frame = get_frame(func)
	set_member_name(frame, offset, name)
	member = None
	try:
		member = get_member(frame, offset)
	except OverflowError:
		pass
	if member:
		set_member_cmt(member, type, 1)

def make_src_file(segment, start_offset, end_offset, filename):
	start_addr = make_ea(segment, start_offset)
	end_addr = make_ea(segment, end_offset)
	add_sourcefile(start_addr, end_addr, filename)

def make_src_line(segment, offset, line):
	set_source_linnum(make_ea(segment, offset), line)


get_inf_structure().s_cmtflg = SW_RPTCMT | SW_ALLCMT | SW_LINNUM

# Program entry function has BP-based frame
func = get_func(get_name_ea(BADADDR, 'PROGRAM'))
func.flags &= ~FUNC_NORET
func.flags |= FUNC_FRAME
reanalyze_function(func)

