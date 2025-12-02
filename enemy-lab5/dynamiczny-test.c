#include <stdio.h>
#include <stdlib.h>



int main(){
int w_x = 5; 
int w_y = 3;
int (*tablica)[w_x];

tablica = (int (*)[w_x])calloc(w_x,w_y*sizeof(int));


for(int x = 0; x<w_x;x++){
    for(int y = 0; y<w_y;y++){
        tablica[x][y]=x+10*y;
    }
}

for(int x = 0; x<w_x;x++){
    for(int y = 0; y<w_y;y++){
    printf("%d ",tablica[x][y]);
    }
    printf("\n");
}
free(tablica);
    return 0;
}