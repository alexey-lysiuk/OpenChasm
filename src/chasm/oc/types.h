
/*
 **---------------------------------------------------------------------------
 ** OpenChasm - Free software reconstruction of Chasm: The Rift game
 ** Copyright (C) 2013 Alexey Lysiuk
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

#ifndef OPENCHASM_OC_TYPES_H_INCLUDED
#define OPENCHASM_OC_TYPES_H_INCLUDED

namespace OC
{

// TODO: 48-bit Pascal Real type
typedef double Real;

typedef std::string  String;
typedef std::wstring WideString;


// TODO: template alias from C++11, in Visual Studio starting from 2013 :(
template <typename T, typename Alloc = std::allocator<T> >
class Array : public std::vector<T, Alloc>
{
private:
    typedef std::vector<T, Alloc> Base;

public:
    explicit Array(const allocator_type& alloc = allocator_type())
    : Base(alloc)
    {
    }

    explicit Array(const size_type count, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
    : Base(count, value, alloc)
    {
    }

    template <class InputIterator>
    Array(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
    : Base(first, last, alloc)
    {
    }

    Array(const Array& other)
    : Base(other)
    {
    }

    inline Array& operator=(const Array& other)
    {
        Base::operator=(other);
        return *this;
    }
};

typedef Array<String>     StringArray;
typedef Array<WideString> WideStringArray;


typedef boost::filesystem::path Path;

typedef boost::format Format;

} // namespace OC

#endif // OPENCHASM_OC_TYPES_H_INCLUDED
