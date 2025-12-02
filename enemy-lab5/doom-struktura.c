#include <stdio.h>
#include <stdlib.h>
/*Przygotuj strukturę, która opisuje planszę i zawierać będzie:

dynamiczną tablicę znaków (wskaźnik)
szerokość
wysokość
znak pusty (znak, który w tablicy będzie oznaczał puste pole)
znak niepusty (znak, który w tablicy będzie oznaczał niepuste pole)

np. poniższa tablica ma 4 puste znaki (zdefiniowane jako 'o') i 2 niepuste znaki zdefiniowane jako 'X'. Jej wysokość to 2, a szerokość to 3.

		o  o X
		o X  o
*/


typedef struct {

    int sze;
    int wys;
    char pusty;
    char niepusty;
    char **tablica;
} plansza;
void alokacja(plansza *obiekt){
obiekt->tablica = (char **)calloc(obiekt->wys,sizeof(char *));
for(int i = 0; i < obiekt->wys; i++){
    obiekt->tablica[i]= (char *)calloc(obiekt->sze,sizeof(char[3]));
}
}
void fill(plansza *obiekt, char z, int w, int k){

    if(w>=0 && k>=0){
    obiekt->tablica[w][k] = z;
    } 
}
void fill_all(plansza *obiekt, char z){
    
    for(int w = 0; w < obiekt->wys ;w++){
        for(int k = 0; k < obiekt->sze; k++){
            obiekt->tablica[w][k] = z;
        }
    } 
}

int main(){
plansza obiekt;

obiekt.sze = 3;
obiekt.wys = 2;
obiekt.pusty = 'O';
obiekt.niepusty = 'X';

alokacja(&obiekt);
fill_all(&obiekt,'O');
fill(&obiekt,'X',1,1);
fill(&obiekt,'X',0,2);


for(int x = 0; x<obiekt.wys;x++){
    for(int y = 0; y<obiekt.sze;y++){
    printf("%c ",obiekt.tablica[x][y]);
    }
    printf("\n");
}
free(obiekt.tablica);
return 0;
}




/*gorbowiec*/

// printf("%p",obiekt.tablica);   
// printf("\n%d",obiekt.sze);
// printf("\n%d",obiekt.wys);
// printf("\n%c",obiekt.pusty);
// printf("\n%c",obiekt.niepusty);

//obiekt.tablica = (char *)malloc(obiekt.wys*obiekt.sze*sizeof(char));

//void rezerwacja(plansza *plan){
// obiekt->tablica = malloc(obiekt->wys*obiekt->sze*sizeof(char));
// char (*tablica)[obiekt->wym->wys];         
//     tablica=(char(*)[obiekt->wys]) obiekt->tablica;


// void wypełnij(plansza *obiekt, char element, int wiersz, int kolumna){
//     //if(wiersz >= 0 && kolumna >= 0){
//         obiekt->tablica[wiersz][kolumna] = obiekt->niepusty;
//     //} 
//     // else  { 
//     //     for(int x = 0; x<obiekt->wys;x++){
//     //         for(int y = 0; y<obiekt->sze;y++){
//     //             obiekt->tablica[x][y] = element;
//     //         }
//     //     }  
//     // }
// }