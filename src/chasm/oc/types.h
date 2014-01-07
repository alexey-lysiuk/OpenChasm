
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

#ifndef OPENCHASM_OC_TYPES_H_INCLUDED
#define OPENCHASM_OC_TYPES_H_INCLUDED

namespace OC
{

typedef float       Float;
typedef double      Double;
typedef long double LongDouble;

typedef std::string  String;
typedef std::wstring WideString;

typedef std::streambuf    StreamBuffer;
typedef std::stringbuf    StringBuffer;
typedef std::stringstream StringStream;

typedef boost::filesystem::path Path;

typedef boost::format Format;


// ===========================================================================


template <typename T>
class Singleton : boost::noncopyable
{
public:
    static void initialize()
    {
        SDL_assert(NULL == s_instance);
        s_instance = new T;
    }

    static void shutdown()
    {
        delete s_instance;
        s_instance = NULL;
    }

    static T& instance()
    {
        SDL_assert(NULL != s_instance);
        return *s_instance;
    }

protected:
    Singleton()
    {
    }

private:
    static T* s_instance;
};


template <typename T>
T* Singleton<T>::s_instance = NULL;


// ===========================================================================


#ifdef _MSC_VER

template <typename T>
inline T Exponent(const T& significand, const int exponent)
{
    return ldexp(significand, exponent);
}

#else // !_MSC_VER

template <typename T>
inline T Exponent(const T& significand, const int exponent);

template <>
inline Float Exponent(const Float& significand, const int exponent)
{
    return ldexpf(significand, exponent);
}

template <>
inline Double Exponent(const Double& significand, const int exponent)
{
    return ldexp(significand, exponent);
}

template <>
inline LongDouble Exponent(const LongDouble& significand, const int exponent)
{
    return ldexpl(significand, exponent);
}

#endif // _MSC_VER


// Conversion is based on DTOTP6.C and DTOTP6.H from SNIPPETS
// http://www.brokersys.com/snippets/
// https://raw.github.com/vonj/snippets/master/dtotp6.c
// https://raw.github.com/vonj/snippets/master/dtotp6.h

class Real
{
public:
    Real()
    {
        SDL_zero(m_data);
    }

    Real(const Uint8 b0, const Uint8 b1, const Uint8 b2, 
        const Uint8 b3, const Uint8 b4, const Uint8 b5)
    {
        m_data.bytes[0] = b0;
        m_data.bytes[1] = b1;
        m_data.bytes[2] = b2;
        m_data.bytes[3] = b3;
        m_data.bytes[4] = b4;
        m_data.bytes[5] = b5;
    }

    Real(const Uint16 s0, const Uint16 s1, const Uint16 s2)
    {
        // TODO: swap from native to little endian
        m_data.shorts[0] = s0;
        m_data.shorts[1] = s1;
        m_data.shorts[2] = s2;
    }

    template <typename FloatType>
    FloatType convert() const
    {
        if (0 == m_data.split.be)
        {
            return FloatType(0);
        }

        const FloatType mantissa = ((128 + m_data.split.v3) * FloatType(65536) + m_data.split.v2)
            * FloatType(65536) + m_data.split.v1;
        const FloatType exponent = Exponent(m_data.split.s ? FloatType(-1) : FloatType(1), m_data.split.be - (129 + 39));

        return mantissa * exponent;
    }

    operator Float() const
    {
        return convert<Float>();
    }

    operator Double() const
    {
        return convert<Double>();
    }

    operator LongDouble() const
    {
        return convert<LongDouble>();
    }

private:
    union Helper
    {
#pragma pack(push, 1)
        struct Split
        {
            Uint8  be;     /* biased exponent */
            Uint16 v1;     /* lower 16 bits of mantissa */
            Uint16 v2;     /* next  16 bits of mantissa */
            Uint16 v3:7;   /* upper  7 bits of mantissa */
            Uint16 s :1;   /* sign bit */
        } split;
#pragma pack(pop)
        Uint8   bytes[6];
        Uint16 shorts[3];
    };

    Helper m_data;
};

} // namespace OC

#endif // OPENCHASM_OC_TYPES_H_INCLUDED
