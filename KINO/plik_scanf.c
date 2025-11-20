#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 10
#define SZACH "Hikaru"


int *add(int tab_wynik[],int wynik){
    int i=0;
    while(i<SIZE){
        if(tab_wynik[i]==0){
            tab_wynik[i] = wynik;
            break;
        }
        i++;
    }
    return tab_wynik;
}
void write(int tab_napisz[SIZE]){
    int i;
    for(i=0;i<SIZE;i++){
        printf("%d:",tab_napisz[i]);
    }
}


int main(){
    bool war = true;
    char zaw_1[64], zaw_2[64];
    int wyn_1, wyn_2;
    int tab_turniej[SIZE];
    int i;
    int *t;

    for(i=0;i<SIZE;i++){
        tab_turniej[i]=0;}
    write(tab_turniej);


    while(war){
        printf("\n wpierdol \n");

    scanf("%63s %d%*c%d %63s",zaw_1,&wyn_1,&wyn_2,zaw_2);

    if(strcmp(SZACH,zaw_1)==0){
        printf("\n%d - wynik1\n", wyn_1);
        add(tab_turniej,wyn_1);
    }
    else if(strcmp(SZACH,zaw_2)==0){
        printf("\n%d - wynik2\n", wyn_2);
        add(tab_turniej,wyn_2);
    }
     
    //printf("%s %c:%c %s\n",zaw_1,wyn_1,wyn_2,zaw_2);
    if(strcmp(zaw_1,zaw_2)==0){
        break;}
    }   

    // t = add(tab_turniej,3);
    // printf("\n%d\n",*t);
    // write(t);
    printf("\n");
    write(tab_turniej);

    return 0;
}





 // FILE *plik;
    // char str[100];
    // if((plik = fopen("przedmioty.txt", "r"))==NULL){
    //     printf("it's your fault\n"); return 1;
    // }
    // else{
    // printf("%p\n",(void *)plik);

    // fscanf(plik,"%[^0]",str);
    // printf("%s",str);
    // }