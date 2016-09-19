#include "StdTextStream.h"

namespace Assimp {

StdTextStream::StdTextStream( const std::string &filename )
: IOStream()
, m_theFile( filename )
, m_filesize( 0 ) {
    m_theFile.seekg( 0, m_theFile.end );
    m_filesize = m_theFile.tellg();
    m_theFile.seekg( 0, m_theFile.beg );
}

StdTextStream::~StdTextStream() {
    if ( m_theFile.is_open() ) {
        m_theFile.close();
    }
}

size_t StdTextStream::Read( void *buffer, size_t size, size_t count ) {
    if ( !m_theFile.is_open() ) { 
        return 0; 
    }
    
    m_theFile.read( (char*) buffer, count );
    if ( !m_theFile ) {
        return 0;
    }
    
    return count;
}

bool StdTextStream::ReadNextLine( std::string &line ) {
    if ( !m_theFile.is_open() ) {
        line = "";
        return false;
    }

    std::getline( m_theFile, line );
    
    return !m_theFile.eof();
}

size_t StdTextStream::Write( const void* pvBuffer, size_t size, size_t count ) {
    // not supported

    return 0;
}

aiReturn StdTextStream::Seek( size_t pOffset, aiOrigin pOrigin ) {
    if ( !m_theFile.is_open() ) {
        return aiReturn_FAILURE;
    }

    m_theFile.seekg( pOffset, m_theFile.beg );
    
    return aiReturn_SUCCESS;
}

size_t StdTextStream::Tell() const {
    // not supported
    //size_t pos( m_theFile.tellg() );
    return 0;
}

size_t StdTextStream::FileSize() const {
    return m_filesize;
}

void StdTextStream::Flush() {
    // not supported
}

} // Namespace Assimp
