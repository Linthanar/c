#include <stdio.h>
#include <stdlib.h>

/*PRE: na wejście Program przyjmuje plik obrazu, używa struktury aby operować plikiem obrazu. 
--> czytać fscanf i zapisywać w tablicy dwu wymiarowej o predefiniowanej wielkości.
--> struktura jest zapisywana dynamicznie. 
--> komentarz: aby odwoływać się do struktury, dynamicznej potrzeba specjalnego sposobu odwoałania, nie do, końca wiem why*/

/*POST: na wyjściu Program zapisuje obraz w tablicy, wypisuje obraz. 
--> komentarz: mogłby też zapisywać go do pliku*/
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

/*definicja struktury*/
typedef struct {
    /*string charakteryzujące rodzaj obrazu np. P1*/
    char typ_obrazu[3];
    /*wymiary obrazu x,y */
    int wym_x, wym_y;
    /*tablica do ktorej zostanie zapisany obraz*/
    int piksele[1000][1000];
} t_obraz;

/*głowna funkcja programu*/
/*Przepisuje plik wejściowy FILE *plik_we do struktury t_obraz *obraz */
void czytaj(FILE *plik_we, t_obraz *obraz) {
    /*...*/
    /*zdaje się mi że, 
    dereferencja (-> / *) dobraz->typ_obrazu, czyli siengnięcie do (zmienej/wartości) w strukturze );*/
    /*i zapisujemy z pliku.*/
    fscanf(plik_we,"%s", &(obraz->typ_obrazu)[0]); 
    fscanf(plik_we,"%d", &(obraz->wym_x)); 
    fscanf(plik_we,"%d", &(obraz->wym_y));


    /*zapis z pliku pojedynczych liczb do tablicy pikseli.*/
    for(int i = 0; i < obraz->wym_x; i++){
      for(int j = 0; j < obraz->wym_y; j++){
        /*warto zastanowić się dlaczego jest potrzebny znak referencjii? */
        fscanf(plik_we, "%1d", &(obraz->piksele)[i][j]);
        }
    }
}
    

int main(int arg_num , char *arg_tab[] ){

    /*otwarcie pliku read, i zapisanie w plik1*/
    FILE *plik1 = fopen(arg_tab[1], "r");
    /*deklaracja zmiennej (wskaźnikowej) typu struktura t_obraz*/
    /*komentarz: ważne jest to że *obraz1 jest wskażnikiem/tablicą co sprawia że można dynamicznie zapisać jego miejsce w pamięci*/
    t_obraz *obrazek1;
    /*lokowanie pamięci typu (t_obraz *) wielkości typu t_obraz*/              
    obrazek1 = (t_obraz *) malloc(sizeof(t_obraz));
    /*PRE: plik -> FILE i obraz -> struct*/
    czytaj(plik1, obrazek1);
    /*POST: treść FILE zapisana do struct obraz*/


    /*wyjście na terminal zmiennych struktury t_obraz*/
    /*komentarz: z powodu dynamicznej deklaracji potrzebne jest specjalne wywołanie*/
    printf("%s wymiar x: %d y: %d\n",(char *)obrazek1->typ_obrazu,(int)obrazek1->wym_x, (int)obrazek1->wym_y);
    
    /*wypisanie tablicy pikseli*/
    for(int y = 0 ; y < obrazek1->wym_y ; y++ ){
        for(int x = 0 ; x < obrazek1->wym_x ; x++ ){
            printf("%d",(int)obrazek1->piksele[y][x]);
        }
        printf("\n");
    }

    /*zamykanie pliku i zwalnia nie pamięci */
    fclose(plik1);
    free(obrazek1);

return 0;
}