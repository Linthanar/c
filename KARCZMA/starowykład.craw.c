#include <stdio.h>
#include <stdlib.h>
/*PRE: na wejście Program przyjmuje plik obrazu, urzywa struktury aby operować plikiem obrazu 
--> czytać fscanf i zapisywać w tablicy dwu wymiarowej o predefiniowanej wielkości.
--> struktura jest zapisywana dynamicznie */
/*format obrazu:
P1
15 15
011000010000110
100000111000001
000001111100000
000011111110000
000111111111000
001111101111100
011111000111110
111110000011111
011111000111110
001111101111100
000111111111000
000011111110000
000001111100000
100000111000001
011000010000110*/

typedef struct {
    int wym_x, wym_y;
    char typ_obrazu[3];
    int piksele[16][16];
} t_obraz;
void czytaj(FILE *plik_we, t_obraz *obraz) {
    /*...*/
    fscanf(plik_we,"%s", obraz->typ_obrazu); 
    fscanf(plik_we,"%d", &(obraz->wym_x)); 
    fscanf(plik_we,"%d", &(obraz->wym_y));
    for(int i = 0; i < obraz->wym_x; i++){
      for(int j = 0; j < obraz->wym_y; j++){
        fscanf(plik_we, "%1d", &(obraz->piksele[i][j]));
        }
    }
}
    

int main(int arg_num , char *arg_tab[] ){

    FILE *plik1 = fopen(arg_tab[1], "r");
        /* i gdzies w jakies funkcji */
    t_obraz *obrazek1;               /* albo dynamicznie */
    obrazek1 = (t_obraz *) malloc(sizeof(t_obraz));
    czytaj(plik1, obrazek1);

    t_obraz zmienna;
    zmienna = *obrazek1;


    // printf("%s wymiar x: %d y: %d\n",zmienna.typ_obrazu,zmienna.wym_x, zmienna.wym_y);
    // printf("%s wymiar x: %d y: %d\n",obrazek1[0].typ_obrazu,obrazek1[0].wym_x, obrazek1[0].wym_y);
    printf("%s wymiar x: %d y: %d\n",(char *)obrazek1->typ_obrazu,(int)obrazek1->wym_x, (int)obrazek1->wym_y);
    for(int y=0;y<15;y++){
        for(int x=0;x<15;x++){
            //printf("%d",zmienna.piksele[y][x]);
            printf("%d",(int)obrazek1->piksele[y][x]);
            //printf("%d",obrazek1[0].piksele[y][x]);
        }
        printf("\n");
    }
    fclose(plik1);
    free(obrazek1);

return 0;
}