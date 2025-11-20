#include <stdio.h>
/*[john_doe@diablo:~]$ ./a.out
     Proste menu:
        1 - Pozycja pierwsza
        2 - Pozycja druga
        3 - Pozycja trzecia
        4 - Zakończ działanie*/
int main(){

    int menu = 0;

    while(menu!=4){
        printf("Proste menu:\n1 - Pozycja pierwsza\n2 - Pozycja druga\n3 - Pozycja trzecia\n4 - Zakończ działanie\n");
        scanf("%1d",&menu);
        switch( menu ){
            case 1:
                printf("twoj wybor: %1d\n",menu);
                break;
            case 2:
                printf("twoj wybor: %1d\n",menu);
                break;
            case 3:
                printf("twoj wybor: %1d\n",menu);
                break;
            case 4:
                printf("twoj wybor: %1d\n",menu);
                break;
            default:
                printf("\n the end of time \n");
                menu = 4;
                break;
            } 
    }

    return 0;
}