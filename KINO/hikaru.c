#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 2                          /*modyfikacja ilości rund*/
#define SZACH "Firouzja2003"            /*modyfikacja nazwy gracza*/

char *add(char tab_wynik[],char wynik);
void write(char tab_napisz[SIZE]);
char *set_tab(char tab_set[SIZE]);

int main(){
    char zaw_1[64], zaw_2[64];
    char wyn_1, wyn_2;
    char tab_turniej[SIZE];

    set_tab(tab_turniej);

    while(1){

    scanf("%63s %c%*c%c %63s",zaw_1,&wyn_1,&wyn_2,zaw_2);

    if(strcmp(SZACH,zaw_1)==0){
        add(tab_turniej,wyn_1);
        printf("grają białe\n");
    }
    else if(strcmp(SZACH,zaw_2)==0){
        add(tab_turniej,wyn_2);
        printf("grają czarne\n");
    }

    if(strcmp(zaw_1,zaw_2)==0){
        break;}
    }   

    printf("tabela wynikow: ");
    write(tab_turniej);
    return 0;
}

char *add(char tab_wynik[],char wynik){
    int i=0;
    while(i<SIZE){
        if(tab_wynik[i]=='9'){
            tab_wynik[i] = wynik;
            break;
        }
        i++;
    }
    return tab_wynik;
}
void write(char tab_napisz[SIZE]){
    int i;
    for(i=0;i<SIZE;i++){
        printf("[%c],",tab_napisz[i]);
    }
}

char *set_tab(char tab_set[SIZE]){
    int i;
    for(i=0;i<SIZE;i++){
        tab_set[i]='9';
    }
    return tab_set;
    }








