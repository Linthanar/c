#include <stdio.h>
#include <stdlib.h>

/*PRE: Program wymaga pliku przy wywołaniu ./a.out <plik> oraz ilości wierszy  #define ILOSC_WIERSZY */
/*  Przykładowy format pliku*/
/*  . 6 7 . . 1 1 4 . .
    . . . * . . . 1 . .
    . . 3 5 . . 6 3 3 .
    . . . . . . # $ . .
    6 1 7 * . . . . . .
    . . . . . + . 5 8 .
    . . 5 9 2 . . . . .
    . . . . . . 7 5 5 .
    . . . $ . * . . . .
*/
/*POST: Program zapisuje ciągi cyfr do tabilcy[] podając wspłżędną(0,1) pierwszego wyrazu. 
z formatu . 6 7 . . 1 1 4 . .  do [ 0, 1, 6, 7, \n, 0, 5, 1, 1, 4, \n]*/
/*gdzie 0 -> kolumna i 1 -> wiersz dla [0,1,-> 6,7]*/




#define ILOSC_WIERSZY 9
/*PRE: char tab[][256] oraz ILOSC_WIERSZY <ilość wierszy>, każdy wiersz musi kończyć się symbolem '\n'*/
void read_char_tab_two(char tab[][256]);
/*POST: wypisuje z tablicy 2-wymiarowej wartości linia po lini */

/*PRE: char tab[256], wiersz musi kończyć się symbolem '\0'*/
void read_char_tab_one(char tab[256]);
/*POST: wypisuje tablicę danych wyjściowych [ 0, 1, 6, 7, \n, 0, 5, 1, 1, 4, \n] */

/*PRE: char tab[256], wiersz musi kończyć się symbolem '\0'*/ 
void read_complex_tab_one(char tab[256]);
/*POST: wypisuje tablicę danych wyjściowych w graficzniej formie*/

/*PRE: wywołanie funkcji main -> ./a.out <plik> lub ./nazwa <plik>*/
int main(int argc, char *argv[]) {

    /*gdy nie zostaną podane dwie tablice 1[./a.out] 2[plik] to zwroć błąd do stderr i zakończ "return 1;"*/
    if (argc != 2) {
        fprintf(stderr, "Użycie: %s <nazwa_pliku>\n", argv[0]);
        return 1;} 

    /*otworz plik z tablicy 2[plik] -> jeśli tablica pusta to zakończ "return 1"*/    
    FILE *plik = fopen(argv[1], "r");
    if (plik == NULL) { return 1; }

    /*zmienna w ozancza numer wiersza, zmianna k numer kolumny
    przyczy aby wypisać wiersz trzeba wypisywać numery z kolumn*/
    int w = 0, k = 0;
    char tab[256][256];
    /*pobieraj z pliku po pojedynczym znaku do tablicy do zakończenia pliku "EOF"*/
    while(fscanf(plik,"%c",&tab[w][k]) == 1){
        /*gdy w wierszu jest spacja ' ' to nadpisz ją kolejnym znakiem*/
        if(tab[w][k]==' '){
           k--; 
        }
        /*gdy koniec lini to zmień wiersz na następny*/
        if(tab[w][k]=='\n'){
            k = 0; w++;
        /*jeśli nie to zmień komorkę na następną*/
        } else {
            k++;
        }
    }
    read_char_tab_two(tab);


    /*TUTAj ważna część kodu*/
    /*tablica z wartościami w formacie, zmienna pozycji elementu, wiadomość zakończenia ciągu cyfr*/
    char tab_danych[256];
    int z = 0;
    int message = 1;

    /*pętla czyta podaną ilość wierszy ILOSC_WIERSZY, wiersz zakończony '\n'*/
    w = 0, k = 0;
    for(w=0;w < ILOSC_WIERSZY; w++){
        for(k = 0;tab[w][k]!='\n';k++){

    
            /*zapis [z] elementu gdy następujące po sobie elementy [z] i [z+1] są z przedziału liczb '1' -- '9'*/
            if(('1'<=tab[w][k] && tab[w][k] <='9')  && ('1'<=tab[w][k+1] && tab[w][k+1]<='9')){
                    /*jeśli początek nowego ciągu to zapisz wspłżędne pierwszego elementu*/
                    if(message == 1){ tab_danych[z]= w +'0'; z++; tab_danych[z]= k +'0'; z++; message = 0;}
                /*zapisz element [z] i przesuń się w tablicy*/
                tab_danych[z]= tab[w][k];
                z++;
            }

            /*gdy [z] jest ostatnim elementem ciągu to zapisz i zakończ*/
            else if(('1'<=tab[w][k-1] && tab[w][k-1] <='9')  && ('1'<=tab[w][k] && tab[w][k-1] <='9') && !('1'<=tab[w][k+1] && tab[w][k+1] <='9') && (k-1)>=0){        
                /*zapisz element [z] i przesuń się w tablicy*/
                tab_danych[z]= tab[w][k];
                z++;
                /*zakończ ciąg, przesuń się w tablicy, wyślij wiadomość końca ciągu*/
                tab_danych[z]= '\n';
                z++;
                message = 1;
            }
        }
    } 
  


    
    /*zakończ tablicę danych wartością '\0' aby odczytać treść*/
    tab_danych[z]='\0';
    read_complex_tab_one(tab_danych);

    /*zamknij plik*/
    fclose(plik);
    return 0;
}













void read_char_tab_two(char tab[][256]){
    int w = 0;
    int k = 0;
    for(w=0;w < ILOSC_WIERSZY; w++){
        k = 0;
        while(tab[w][k]!='\n'){
            printf("%c",tab[w][k]);
            k++;
        }
        printf("\n");  
    }
}

void read_char_tab_one(char tab[256]){
    int x = 0;
    while(!(tab[x] =='\0')){
        printf("%c",tab[x]);
        x++;
    }  
}



void read_complex_tab_one(char tab[256]){
    int x = 0;
    /*wypisuj dopuki nie osiągniesz znaku końca '\0' null*/
    while(!(tab[x] =='\0')){
        /*na początku wypisz dwa znaki ktore odpowiadają za wspołżędna*/
        printf("poziomo (%c,%c) ",tab[x],tab[x+1]);
        x ++;x++;
        /*potem wypisz ciąg znakow do znalezienia znaku nowej lini*/
        while((tab[x] != '\n')){
            printf("%c",tab[x]);
            x++;
        }
    /*na końcu zrob nową linię i przesuń się na nowe miejsce*/
    printf("\n");  
    x++;
    }
}