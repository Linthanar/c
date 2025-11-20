#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int re;
  int im;
} zespolona;

zespolona dodaj(zespolona *x, zespolona *y)
  {
    (*x).re += (*y).re;
    (*x).im += (*y).im;
    /*co jest tym samym co:
    x->re += y->re;
    x->im += y->im;*/
    return *x;
  }



int main(){
zespolona zm0;
zespolona zm1 = {
    .re = 2,
    .im = 3
};
zespolona zm2 = {
    .re = 1,
    .im = -1
};
zm0 = dodaj(&zm1,&zm2);
printf("\n %d, %di",zm0.re,zm0.im);





return 0;
}