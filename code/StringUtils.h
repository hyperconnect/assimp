/*
Open Asset Import Library (assimp)
----------------------------------------------------------------------

Copyright (c) 2006-2016, assimp team
All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the
following conditions are met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the
following disclaimer in the documentation and/or other
materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
contributors may be used to endorse or promote products
derived from this software without specific prior
written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------
*/
#ifndef INCLUDED_AI_STRINGUTILS_H
#define INCLUDED_AI_STRINGUTILS_H

#include <cstdlib>
#include <sstream>
#include <stdarg.h>

///	@fn		ai_snprintf
///	@brief	The portable version of the function snprintf ( C99 standard ), which works on visual studio compilers 2013 and earlier.
///	@param	outBuf		The buffer to write in
///	@param	size		The buffer size
///	@param	format		The format string
///	@param	ap			The additional arguments.
///	@return	The number of written characters if the buffer size was big enough. If an encoding error occurs, a negative number is returned.
#if defined(_MSC_VER) && _MSC_VER < 1900

	inline int c99_ai_vsnprintf(char *outBuf, size_t size, const char *format, va_list ap) {
		int count(-1);
		if (0 != size) {
			count = _vsnprintf_s(outBuf, size, _TRUNCATE, format, ap);
		}
		if (count == -1) {
			count = _vscprintf(format, ap);
		}

		return count;
	}

	inline int ai_snprintf(char *outBuf, size_t size, const char *format, ...) {
		int count;
		va_list ap;

		va_start(ap, format);
		count = c99_ai_vsnprintf(outBuf, size, format, ap);
		va_end(ap);

		return count;
	}

#else
#   define ai_snprintf snprintf
#endif

template <typename T>
inline
std::string to_string( T value ) {
    std::ostringstream os;
    os << value;
    return os.str();
}

inline
float ai_strtof( const char *begin, const char *end ) {
    if ( nullptr == begin ) {
        return 0.0f;
    }
    float val( 0.0f );
    if ( nullptr == end ) {
        val = static_cast< float >( ::atof( begin ) );
    } else {
        std::string::size_type len( end - begin );
        std::string token( begin, len );
        val = static_cast< float >( ::atof( token.c_str() ) );
    }

    return val;
}

#endif // INCLUDED_AI_STRINGUTILS_H

