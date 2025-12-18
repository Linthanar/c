#include <stdio.h>

void napisz(int x, int y,int *ip,int i){
printf("%d\n",x);
printf("%d\n",y);
printf("%d\n",ip);
i++;
printf("_______%d________\n",i);
}


int main(){

int x = 1, y = 2, i = 0;
int *ip;  napisz(x,y,ip,i);i++;  /* 1. ip jest wskaznikiem do obiektow typu int */
ip=&x;  napisz(x,y,ip,i);i++;    /* 2. teraz ip wskazuje na x */
y=*ip;  napisz(x,y,ip,i);i++;    /* 3. y ma teraz wartosc 1 */
*ip=0;  napisz(x,y,ip,i);i++;    /* 4. x ma teraz wartosc 0 */
ip=&y;  napisz(x,y,ip,i);i++;    /* 5. teraz ip wskazuje na y */
*ip=0;  napisz(x,y,ip,i);        /* 6. y ma teraz wartosc 0 */


return 0;
}
