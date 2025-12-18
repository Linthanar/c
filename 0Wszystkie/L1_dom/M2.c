#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*pobieram biblioteki*/

int main(){
    srand(time(NULL));                 /*funkcja ktora sprawia że wynik (rand) nie jest stały -> zależy od czasu */
    int passengers, capsules, i = 0;
    passengers = rand() % 101;         /*losuję dużą liczbę -> i biorę resztę z dzielania(modulo) przez małą liczbę  -> aby uzyskać wartość z przedziału 0-coś */
    capsules = rand() % 41;
 
    printf("\npassengers: %d\ncapsules: %d\n ",passengers,capsules); /*liczba pasarzerów i kapsuł*/

    while (capsules>0 && passengers>passengers % 4){    /*pętla wysyła pasarzerów kapsułami dopuki nie zostanie 1,2 lub 3 ludzi, lub Kot*/
        i += 1;                                     
        capsules -= 1;  
        passengers -= 4;
        printf("kapsuła: %d ____ wystrzelona\n ",i);   
    }
    if(capsules >= 1){            /*warunek sprawdza który pasarzer jest na pokładzie ostatniej kapsuły*/
        i += 1;
        if(passengers == 0){
            printf("ostatni pasarzer Kot na pokładzie!!! kapsuły %dL\n", i);
        }    
        else{    
            printf("ostatni %d pasarzer na pokładzie!!! kapsuły %dL\n", (passengers % 4), i);
        }

    }
    else if(passengers == 0){     /*warunki sprawdzją który pasarzer się nie uratował*/
        printf("módlcie się za Kota który został sam samotny...\n");
    }
    else{
        printf("módlcie się za %d tych którzy dla was zostali...\n",passengers);
    }
    
    return 0;
}


