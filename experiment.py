#!/usr/bin/env python3

import os
import time
import statistics

N = 100

def main():
    M1 = []
    M2 = []
    timeouts1 = 0;
    timeouts2 = 0;
    for i in range( N ):
        os.system( "rm -f ./crash*" )
        start = time.time()
        rv = os.system( "timeout 240s ../Build/math-1" )
        end = time.time()
        M1.append( end - start )
        exit_code = rv / 256
        if exit_code == 124:
            timeouts1 += 1

        os.system( "rm -f ./crash*" )
        start = time.time()
        rv = os.system( "timeout 240s ../Build/math-2" )
        end = time.time()
        M2.append( end - start )
        exit_code = rv / 256
        if exit_code == 124:
            timeouts1 += 1

    print( M1 )
    print( statistics.median( M1 ) )
    print( statistics.mean( M1 ) )
    print( statistics.pstdev( M1 ) )
    print( timeouts1 )
    print( M2 )
    print( statistics.median( M2 ) )
    print( statistics.mean( M2 ) )
    print( statistics.pstdev( M2 ) )
    print( timeouts2 )

main()


