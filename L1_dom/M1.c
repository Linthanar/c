#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*pobieram biblioteki*/
/*uzywam zmiennych w języku angielskim, poniewaz wtedy kod wygląda mądrzej:)*/

int main(){
    srand(time(NULL));         /*funkcja ktora sprawia że wynik (rand) nie jest stały -> zależy od czasu */
    int volume,max = 500;   
                                 
    volume = rand() % max+1;   /*losuję dużą liczbę -> i biorę resztę z dzielania(modulo) przez małą liczbę  -> aby uzyskać wartość z przedziału 0-coś */
    printf("wskazanie na zbiorniku: %d dm3\n",volume);
    printf("______________________________\n");

    if(volume < 50){
        printf("ALARM: za mało wody!\n");
    }
    else{
        printf("wszystkie parametry w normie\n");
    }

    return 0;
}