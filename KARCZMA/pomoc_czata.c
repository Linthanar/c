#include <stdio.h>
#include <stdlib.h>
#define WIERSZ 2
#define KOLUMNA 3

int main(void){

    int **tablica_2d;
    tablica_2d = (int **)malloc(sizeof(int *) * WIERSZ);
    for(int j = 0; j < WIERSZ; j++){
        tablica_2d[j] = (int *)malloc(sizeof(int) * KOLUMNA);
    }

    tablica_2d[1][1] = 2;
    printf("%d",tablica_2d[1][1]);
    
    for (int j = 0; j < WIERSZ; j++) {
        free(tablica_2d[j]);
    }
    free(tablica_2d);
    return 0;
}