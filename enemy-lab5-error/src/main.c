#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

#include <assert.h>
#include <errno.h> 

#include "modul.h"
int errno;

/*PRE: do poprawnego działania programu, potrzebne jest przekazanie 
argumentow przy wywołaniu w postaci -> a.out -n -p -s -w 
gdzie wartości są przekazywane do zmiennych struktury:

char niepusty := n      
char pusty    := p
int szerokość := s
int wysokość. := w
*/

/*POST: program dynamicznie alokuje tablicę o parametrach przekazanych do programu
i pozwala na jej wypełnianie znakami (pustymi i niepustymi) */

/*struktura planszy*/


int main(int argc, char *argv[]){

if(argc != 9){
    /*<symbol> -> 1 znak, <symbol_pusty> -> 1 znak, <szerokość> i <wysokość> to int */
    fprintf(stderr,"\n\033[31m error argc:\033[0m poprawne wywołanie->\033[32m ./a.make -n <symbol> -p <symbol_pusty> -s <szerokość> -w <wysokość>\033[0m, %s\n",strerror(errno));
    fprintf(stderr,"\n\033[36m ./a.make -n X -p o -s 2 -w 2\033[0m\n");
    /*exit można sprawdzić wpisując w terminal->  echo $?    */
    exit(0);
}

plansza obiekt; /*tworzenie obiektu*/



/***********************************************************************/
/*PRE: to jest fragment kodu odpowiadający za pobranie argumentow 
przy wywołaniu programu*/
int opt; /* zmienna przyjmuje kolejne wartośći argumentu przy wywołaniu np.
dla a.out -n -p -s -w najpierw n potem p itd */

    /* dopuki getopt nie zakończy sprawdzania to będzie pobierał artgumenty
    gdzie (:) po każdej opcji oznacza że wymaga ona argumentu
    argumenty są zapisywanie w postaci (char *) */
    while ((opt = getopt(argc, argv, "n:p:s:w:")) != -1) {

        switch (opt) {
            case 'n':
                obiekt.niepusty = optarg[0];
                break;
            case 'p':
                obiekt.pusty = optarg[0];
                break;
            case 's':
                obiekt.sze = atoi(optarg);
                break;
            case 'w':
                obiekt.wys = atoi(optarg);
                break;
            default:
                /**/
                fprintf(stderr,"\n\033[31m error getopt:\033[0m poprawne argumenty->\033[32m ./a.make -n <> -p <> -s <> -w <>\033[0m, %s\n",strerror(errno));
                fprintf(stderr,"\n\033[36m ./a.make -n X -p o -s 2 -w 2\033[0m\n");
                exit(EXIT_FAILURE);
        }
    }

/***********************************************************************/

alokacja(&obiekt);
fill_all(&obiekt,obiekt.pusty);
fill(&obiekt,obiekt.niepusty,0,0);
show(&obiekt);


for(int i = 0; i < obiekt.wys; i++)
    free(obiekt.tablica[i]);
free(obiekt.tablica);
return 0;
}
