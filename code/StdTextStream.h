/*
---------------------------------------------------------------------------
Open Asset Import Library (assimp)
---------------------------------------------------------------------------

Copyright (c) 2006-2016, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the following
conditions are met:

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
---------------------------------------------------------------------------
*/
/** @file StdTextStream.h
*  @brief File I/O wrappers for C++ string streams for text-base formats.
*/

#ifndef AI_STDTEXTSTREAM_H_INC
#define AI_STDTEXTSTREAM_H_INC

#include <assimp/IOStream.hpp>
#include <assimp/types.h>

#include <iostream>
#include <fstream>
#include <string>

#ifndef __cplusplus
#   error This header requires C++ to be used. aiFileIO.h is the \
    corresponding C interface.
#endif

namespace Assimp {

class StdTextStream : public IOStream {
public:
    StdTextStream( const std::string &filename );
    virtual ~StdTextStream();
    virtual size_t Read( void *buffer, size_t size, size_t count );
    virtual bool ReadNextLine( std::string &line );
    virtual size_t Write( const void* pvBuffer, size_t size, size_t count );
    virtual aiReturn Seek( size_t pOffset, aiOrigin pOrigin );
    virtual size_t Tell() const;
    virtual size_t FileSize() const;
    virtual void Flush();

private:
    std::ifstream m_theFile;
    size_t m_filesize;
}; //! class StdTextStream

} // Namespace Assimp

#endif // AI_STDTEXTSTREAM_H_INC
