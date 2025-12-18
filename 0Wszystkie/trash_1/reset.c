#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TIME 10000 /* value of 1e6 to change from ms to s*/

int main(){
    printf("ohh");
    int t = TIME;
        while(1){
        usleep(1*t);  
        system("clear");
        usleep(1*t);    
        printf("ohh");
        usleep(1*t);
        }
    return 0;
}