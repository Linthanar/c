#include <stdio.h>
#include <stdlib.h>

 void czytaj_tab_dwu_wym(int *tablica[256], int wym_x, int wym_y);

 int main() {
   int wym_x, wym_y;            /* wymiary tablicy */
   wym_x = 5; wym_y = 7;        /* symulujemy pobranie wymiarow */
       /* definiujemy zmienna wskaznikowa odpowiedniej postaci */
    int (*tablica)[wym_x];
       /* i powolujemy nasza tablice do zycia */
    tablica = (int(*)[wym_x]) malloc(wym_x*wym_y*sizeof(int));
      /* teraz mozemy robic z nia co chcemy :) */
    for(int i = 0; i < wym_y; i++)
      for(int j = 0; j < wym_x; j++)
        tablica[i][j] = 10*i+j;

 czytaj_tab_dwu_wym(*tablica, wym_x, wym_y);
return 0; }

void czytaj_tab_dwu_wym(int *tablica[256], int wym_x, int wym_y){
    
    for(int i = 0; i < wym_y; i++){
        for(int j = 0; j < wym_x; j++){
            printf("miejsce [%d,%d] wartość (%d)",i,j,tablica[i][j]);
        }
    }
}

