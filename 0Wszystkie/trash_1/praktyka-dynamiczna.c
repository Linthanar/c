#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
int w_x = 5; 
int w_y = 3;
void *coś;
char **tablica;
char **ktoś;


tablica = (char **)calloc(w_x,sizeof(char *));
for(int i = 0; i < w_x; i++){
    tablica[i]= (char *)calloc(w_y,sizeof(char[3]));
}
coś = tablica;

for(int x = 0; x<w_x;x++){
    for(int y = 0; y<w_y;y++){
        tablica[x][y]=((x*y)+'0');
    }
}

for(int x = 0; x<w_x;x++){
    for(int y = 0; y<w_y;y++){
    printf("%c ",tablica[x][y]);
    }
    printf("\n");
}
printf("\n%p\n%p",tablica,coś);
free(tablica);
    return 0;
}
