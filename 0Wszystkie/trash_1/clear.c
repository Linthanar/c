#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(){
    int i;
    for(i=0;i < 3;i++){
        
        if(1==1){printf("hello");}
        usleep( 1000000 );
        system("clear");
    }

    return 0;
}



/*void clearScreen();*/

/*void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}*/