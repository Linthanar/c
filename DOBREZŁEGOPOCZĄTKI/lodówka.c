#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_BAZA 3

/*PRE: na wejściu przyjmuje ścierzkę do pliku*/
void print_f_path(char path[]){
    char ascii;                                 /*miejsce do zapisu znaku z pliku*/
    FILE *plik = fopen(path,"r");               /*otwarcie pliku o podanej ścierzce*/
    while(fscanf(plik,"%c",&ascii) != EOF){     /*wypisanie znakow*/
        printf("%c",ascii);
    }
    fclose(plik);
}
/*POST: wypisuje zawartość pliku*/

/*tworzenie ścierzki*/
/*PRE: na wejściu przyjmuje nazwę folderu %s i numer od 1 do 999*/
char *path_finder(char path[], char folder[], int p){
    int  inumer[4];
    char numer[4] = "";
    /*separacja liczby na elemanty tablicy[3] przykład: 12 -> {0,1,2}*/
    inumer[0] = (p/100);
    inumer[1] = (p/10 ) - ((p/100)*10);
    inumer[2] = (p/1  ) - ((p/100)*100) - ((p/10)*10);
    /*zamiana (tablicy) {0,1,2} na (string) 012 */
    sprintf(numer,"%d%d%d",inumer[0],inumer[1],inumer[2]);
    sprintf(path,"%s/%3s.txt",folder,numer);
    return path;
}
/*POST: zwraca nazwę ścierzki w formacie "[folder]/[xxx].txt" np. quiz/001.txt */

int main(){
    char path[] = "baza/001.txt";             /*ścierzka do wybranego pliku*/
    char folder[] = "baza"; 
    
    path_finder(path,folder,2);
    /*print_f_path(path);*/   /*wypisuje zawartość pliku z podanej ścierzki*/
    printf("\n");
    print_line_path(path,3);
/*
     Proste menu:
        1 - Pozycja pierwsza
        2 - Pozycja druga
        3 - Pozycja trzecia
        4 - Zakończ działanie*/
/*
    int menu = 0;
    while(menu!=4){
        printf("Proste menu:\n1 - Pozycja pierwsza\n2 - Pozycja druga\n3 - Pozycja trzecia\n4 - Zakończ działanie\n");
        scanf("%1d",&menu);
        switch( menu ){
            case 1:
                printf("twoj wybor: %1d\n",menu);
                break;
            case 2:
                printf("twoj wybor: %1d\n",menu);
                break;
            case 3:
                printf("twoj wybor: %1d\n",menu);
                break;
            case 4:
                printf("twoj wybor: %1d\n",menu);
                break;
            default:
                printf("\n the end of time \n");
                menu = 4;
                break;
            } 
    }
*/

return 0;
}

    


/*segmentation fault*/

/*PRE: na wejściu przyjmuje ścierzkę do pliku oraz numer lini do wypisania,*/
/*numeracja lini zaczyna się od zera*/
// void print_line_path(char path[], int line){
//     char ascii;                              /*miejsce do zapisu str z pliku*/
//     FILE *plik = fopen(path,"r");               /*otwarcie pliku o podanej ścierzce*/
//     while((ascii = fgetc(plik)) != EOF){        /*wypisanie znakow*/
//             printf("%1d",line);
//             if(ascii == '\n')line--;
//             if(line == 0){printf("%c",ascii);}    /*wypisuje do gdy linia jest odpowiednia*/ 
//     }
    
//     fclose(plik);
// }
/*POST: wypisuje zawartość wypranej lini z pliku*/