#include <stdio.h>
#include <math.h>

int main(){
int tab[5];
int i = 0;
    while(i<5)
    {
        /* code */
        tab[i]= 7 + i*2 - pow(i,2);
        printf("element[%d] = %d\n",i,tab[i]);
        i++;
    }


int *wint;              // wskaźnik int
int zpint;                 //zmienna pomocnicza
int j = 0;
wint = &(tab[0]);

    while(j<5){
        if(zpint < *(wint)){
            zpint = *(wint);
        }
        wint++;
        j++;
    }
    printf("MAX: %d\n",zpint);
    return 0;
}