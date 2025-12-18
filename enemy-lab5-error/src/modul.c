#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include "modul.h"


int alokacja(plansza *obiekt){
    /*assert(obiekt->wys>0 && obiekt->sze>0);*/

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
    /*asercja sprawdza czy tablica ma dostateczne wymiary*/
    assert(obiekt->wys>w && obiekt->sze>k);
    obiekt->tablica[w][k] = z;
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