#include <stdio.h>
#include <stdlib.h>
/*PRE: Program zapiszewartości w dynamicznej tablicy 2D*/
/*POST: Program wyświetli zawartość tablicy przez osobną fynkcję*/

/*Zdefiniuję na swoj użytek wielkości ktorych użuję do zdefiniowania wielkości tablic*/

/*ilość wierszy*/
#define WIERSZ 3
/*ilość kolumn*/
#define KOLUMNA 3

int main(void){
    /*jak widać deklarujętablice*/
    /*tworzę miejsce dla tablicy 2D jako ilość(n) 1D tablic*/
    /*ważna uwaga! (int **)malloc to specyfikacja miejsca w pamięci dla 2D*/
    int **tablica_2d = (int **)malloc(sizeof(int *) * WIERSZ);;
    /*dla każdego miejsca na 1D tablicę tworzę rozmiar (dynamicznie)*/
    for(int j = 0; j < WIERSZ; j++){
        /*ważna uwaga! (int **)malloc to specyfikacja miejsca w pamięci dla 2D*/
        tablica_2d[j] = (int *)malloc(sizeof(int) * KOLUMNA);
    }
     for(int i = 0; i < WIERSZ; i++){
      for(int j = 0; j < KOLUMNA; j++){
        tablica_2d[i][j] = 10*(WIERSZ-i)+(KOLUMNA -j);}
     }



    /*testy*/
   
    printf("\n1.0 pointer: %p to array of pointers",&tablica_2d);
    printf("\n1.1 pointer: %p to array of pointers",&tablica_2d[0]);
    printf("\n2.0 pointer: %p to array of pointers",tablica_2d);
    printf("\n2.1 pointer: %p to array[0] of ints",tablica_2d[0]);/*adress*/
    /* dereferenced value (of pointer is equal, to (adress) of first pointer of array of pointers.*/
    printf("\n3.0 value  : %p of array of pointers",*tablica_2d);
    /* value (of pointer is equal, to (4 bytes) of first element of array of ints )*/
    printf("\n3.1 value  : %d of array[0] of ints",*(tablica_2d[0]));
    printf("\n4.0 value  : %d of array[0] of ints",**tablica_2d);

    printf("\n\n");

    printf("\n1.0 adress : %p to array[0] of ints",tablica_2d[0]);
    printf("\n1.1 adress : %p to array[0] of ints",*&*(tablica_2d));
    printf("\n1.2 adress : %p to array[0] of ints",*&(tablica_2d[0]));
    printf("\n1.3 adress : %p to array[0] of ints",&(tablica_2d[0][0]));


    
    

    printf("\n\n");

    printf("\n3.  value  : %p of array[-3] of ints",&(tablica_2d[0][-3]));
    printf("\n3.  value  : %p of array[-2] of ints",&(tablica_2d[0][-2]));
    printf("\n3.  value  : %p of array[-1] of ints",&(tablica_2d[0][-1]));
    printf("\n3.  value  : %p of array[ 0] of ints",&(tablica_2d[0][0]));
    printf("\n3.  value  : %p of array[ 1] of ints",&(tablica_2d[0][1]));
    printf("\n3.  value  : %p of array[ 2] of ints",&(tablica_2d[0][2]));
    printf("\n3.  value  : %p of array[ 3] of ints",&(tablica_2d[0][3]));
    
    

    printf("\n\n");
    printf("\n3.  value  : %x of array[-3] of ints",(tablica_2d[0][-8]));
    printf("\n3.  value  : %x of array[-3] of ints",(tablica_2d[0][-7]));
    printf("\n3.  value  : %x of array[-3] of ints",(tablica_2d[0][-6]));
    printf("\n3.  value  : %x of array[-3] of ints",(tablica_2d[0][-5]));
    printf("\n3.  value  : %x of array[-3] of ints",(tablica_2d[0][-4]));
    printf("\n3.  value  : %x of array[-3] of ints",(tablica_2d[0][-3]));
    printf("\n3.  value  : %x of array[-2] of ints",(tablica_2d[0][-2]));
    printf("\n3.  value  : %x of array[-1] of ints",(tablica_2d[0][-1]));
    printf("\n3.  value  : %p of array[ 0] of ints",&(tablica_2d[0][0]));












    /*zwalnianie miejsca w tablicy od tyłu*/
    for (int j = 0; j < WIERSZ; j++) {
        free(tablica_2d[j]);
    }
    free(tablica_2d);
    
    return 0;
}