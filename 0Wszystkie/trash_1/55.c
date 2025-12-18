#include <stdio.h>
#include <stdlib.h>

int main(int l_arg, char *t_wej[]){

    if(l_arg != 2){
        fprintf(stderr,"__warning__ wymagany format --> %s <plik>", t_wej[0]);
        return 1;
    }


char tbl[3][3] ={{'1','2','3'},{'4','5','6'},{'7','8','9'},};

FILE *plik = fopen(t_wej[1],"r");
if (plik == NULL) { return 1; }

tbl[0][0] = fgetc(plik);
tbl[0][1] = fgetc(plik);

int i;
for(i=0;i<3;i++){
    printf("%c",tbl[0][i]);
}


    return 0;
}