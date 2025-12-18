#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include "module.h"

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
typedef struct {
    int sze;            
    int wys;
    char pusty;
    char niepusty;
    char **tablica;
} plansza;


/*PRE: przyjmuje strukturę plansza*/
int alokacja(plansza *obiekt);
/*POST: alokuje miejsce na tablicę "planszę" zgodnie z parametrami sze i wys*/
/*PRE: z - znak jaki zostanie zapisany, w -  w ktrym wierszu, k - w ktorej kolumnie*/
int fill(plansza *obiekt, char z, int w, int k);
/*POST: wypełnia komorkę w tablicy znakiem*/
/*PRE: przyjmuje strukturę plansza i znak*/
int fill_all(plansza *obiekt, char z);
/*POST: zapisuje całą tablicę tym znakiem*/
/*PRE: */
int show(plansza *obiekt);
/*POST pokazuje zawartość tablicy*/

int main(int argc, char *argv[]){
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
                fprintf(stderr," ");
                exit(EXIT_FAILURE);
        }
    }

/***********************************************************************/


alokacja(&obiekt);
fill_all(&obiekt,obiekt.pusty);
fill(&obiekt,obiekt.niepusty,1,1);
fill(&obiekt,obiekt.niepusty,0,2);
show(&obiekt);

free(obiekt.tablica);
return 0;
}


int alokacja(plansza *obiekt){
    /*pamięć alokowana do typu wskaźnik na wskaźnik char ->(char **)
    ilość elementw rowna ilości wierszy każdy element to wskaźnik na char */
obiekt->tablica = (char **)calloc(obiekt->wys,sizeof(char *));
    /*tyle razy ile wskaźnikow na char alokowanie szerokość razy znakow char.*/
for(int i = 0; i < obiekt->wys; i++){
    obiekt->tablica[i]= (char *)calloc(obiekt->sze,sizeof(char));
}
return 0;
}
int fill(plansza *obiekt, char z, int w, int k){
    if(w>=0 && k>=0){
    obiekt->tablica[w][k] = z;
    } 
    return 0;
}
int fill_all(plansza *obiekt, char z){
    /*pętla przechodzi przez tablicę dwuwymiarową*/
    for(int w = 0; w < obiekt->wys ;w++){
        for(int k = 0; k < obiekt->sze; k++){
            obiekt->tablica[w][k] = z;
        }
    } 
    return 0;
}
int show(plansza *obiekt){
    /*pętla przechodzi przez tablicę dwuwymiarową*/
for(int x = 0; x<obiekt->wys;x++){
    for(int y = 0; y<obiekt->sze;y++){
    /*elementy są oddzielane spacją*/
        printf("%c ",obiekt->tablica[x][y]);
    }
        printf("\n");
}
return 0;
}