// Top Matter

#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>

int eqBitByBit( uint64_t, uint64_t );

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
            if( eqBitByBit( n4, n3 ) )
            {
                printf( "%"PRIu64" %"PRIu64" %"PRIu64"\n", n1, n2, n2 );
                assert( 0 );
            }
        }
    }
    return 0;
}

int eqBitByBit( uint64_t a, uint64_t b )
{
    uint64_t mask = 1;

#define CHECK_01                           \
    if( ( a & mask ) != ( b & mask ) )     \
        return 0;                          \
    mask = mask << 1;
#define CHECK_02 CHECK_01 CHECK_01
#define CHECK_04 CHECK_02 CHECK_02
#define CHECK_08 CHECK_04 CHECK_04
#define CHECK_16 CHECK_08 CHECK_08
#define CHECK_32 CHECK_16 CHECK_16
#define CHECK_64 CHECK_32 CHECK_32

    CHECK_64;
    return 1;
}
