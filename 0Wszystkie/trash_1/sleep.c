#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

#define SEK 1000000

int main( int argc, char ** argv )
{

        const unsigned long long nano = 1000000000;
        unsigned long long t1, t2;

        struct timespec tm;
        int i;

        for(i=0;i<10;i++)
        {

                clock_gettime( CLOCK_REALTIME, &tm );
                t1 = tm.tv_nsec + tm.tv_sec * nano;

                usleep( SEK );
                system("clear");
                clock_gettime( CLOCK_REALTIME, &tm );
                t2 = tm.tv_nsec + tm.tv_sec * nano;

                printf( "delay: %llu\n", ( t2 - t1 ) / 1000 );
        }

        return 0;

}