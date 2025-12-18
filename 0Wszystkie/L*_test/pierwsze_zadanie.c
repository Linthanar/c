#include <stdio.h>
#include <stdlib.h>

void wypelnij(int tab[][10], int wymiar_x, int wymiar_y){

    for(int i = 0; i < wymiar_x; i++){
        for(int j = 0; j < wymiar_y; j++){
            tab[i][j] = i*j;
        }
    }
}

void wypisz(int tab[][10], int wymiar_x, int wymiar_y){
    for(int i = 0; i < wymiar_x; i++){
        for(int j = 0; j < wymiar_y; j++){
            printf("%3d ",tab[i][j]);
        }
        printf("\n");
    }
}
void zmien_znaki(int tab[][10], int wymiar_x, int wymiar_y){
    for(int i = 0; i < wymiar_x; i++){
        for(int j = 0; j < wymiar_y; j++){
            tab[i][j] = -tab[i][j];
        }
    }
}


int main(){

    int tablica[10][10];

       wypelnij(tablica,3,7);
       printf("Zawartość oryginalna:\n");
       wypisz(tablica,3,7);
       zmien_znaki(tablica,3,7);
       printf("Zawartość po zmianie znaków:\n");
       wypisz(tablica,3,7);
       return 0;
}