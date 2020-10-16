// Top Matter

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>

int LLVMFuzzerTestOneInput( const uint8_t *data, size_t size )
{
    if( size != 24 )
        return 0;
    uint64_t n1 = ( (uint64_t*)data )[ 0 ];
    uint64_t n2 = ( (uint64_t*)data )[ 1 ];
    uint64_t n3 = ( (uint64_t*)data )[ 2 ];
    if( n1 > 100000000 && n2 > 100000000 )
    {
        uint64_t n4 = n1 * n2;
        if( n4 > n1 )
        {
            if( n4 == n3 )
            {
                printf( "%"PRIu64" %"PRIu64" %"PRIu64"\n", n1, n2, n2 );
                assert( 0 );
            }
        }
    }
    return 0;
}
