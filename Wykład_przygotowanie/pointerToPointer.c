#include <stdio.h>

#define ROZMIAR 5

void przykład2(){
int liczby[ROZMIAR]={ 3, 8, 10,  3, 9};
int *wsk1, *wsk2;
wsk1=liczby;
wsk2=&liczby[3];
/*określ wartość każdego z poniższych wyrażeń:*/
/*a)*/ printf("%u\n",liczby+2==&liczby[2]);
/*b)*/ printf("%u\n",*(liczby+2)==liczby[2]);
/*c)*/ printf("%u\n",*(liczby+1));
/*d)*/ printf("%u\n",*liczby+2);
/*e)*/ printf("%p\n",liczby);
/*f)*/ printf("%u\n",*wsk1);
/*g)*/ printf("%d,%p\n",*wsk1++,wsk1);wsk1--;
/*h)*/ printf("%d,%p\n",*++wsk1,wsk1);wsk1--;
/*i)*/ printf("%u\n",(*wsk2)++);
/*j)*/ printf("%u\n",wsk1+4==&liczby[4]);
/*k)*/ printf("%u\n",wsk2-2!=&liczby[1]);
/*l)*/ printf("%u\n",*--wsk2);
/*m)*/ printf("%ld\n",wsk2-wsk1);
/*n)*/ printf("%u\n",wsk2==wsk1);
/*o)*/ printf("%u\n",*wsk2==*wsk1);
}
void ćwiczenie1(){
int i=7; 
int *p=&i;
int *t[10];
int **q1;
//q1=&i;    //warnin: incompatible pointer types assigning to 'int **' from 'int *'
//q1=&(&i); //error: cannot take the address of an rvalu\ne of type 'int *'
//q1=p;     //warning: incompatible pointer types assigning to 'int **' from 'int *';
q1=&p;
printf("%p\n",&p);
//q1=*t[5]; //warning: incompatible integer to pointer conversion assigning to 'int **' from 'int' [-Wint-conversion]
q1=&t[5];
printf("%p\n",&t[5]); 
//q1=&t;    //warning: incompatible pointer types assigning to 'int **' from 'int *(*)[10]'
q1=t;
printf("%p\n",t); 

printf("\n%p\n",t[1]); 
q1++;printf("%p\n",*q1); 
}

int main(){
przykład2();
return 0;
}