#include <stdio.h>
#include <stdlib.h>



int main(int arg_num , const char *arg_tab[] ){

int tab[15][15];
char znak;
FILE *plik = fopen(arg_tab[1],"r");
if (plik == NULL) { return 1; }

for(int i = 0; i < 15; i++){
    for(int j = 0; j < 15; j++){
        fscanf(plik,"%1d",&tab[i][j]);
        printf("%1d",tab[i][j]);
    }
    printf("\n");
}

fclose(plik);
return 0;
}