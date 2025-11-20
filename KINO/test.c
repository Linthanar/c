#include <stdio.h>
#include <string.h>

#define SIZE 10

int main(){

int tab[10];

int k;
for(k=0;k<SIZE;k++){
    tab[k]=0;}

int i = 0;
while(i<10){
    printf("%d\n",tab[i]);
    i++;
}


//______porownanie strringow______
// char a[] = "kot"; char b[] = "kot";

// if(strcmp(a,b) == 0){
//     printf("kot\n");}
// else{
//     printf("płot\n");}

//______działa_________
// int a=0; scanf("%d",&a);

//_____segmentation fault_____________
//int *x; x=1; printf("%d",*x);  //wypisze zawsze warto ́s ́c 1?

//_______pętla przerwana gdy (;0;)____    
// int i; for (i=5;;i--){
//     printf("%d\n",i);}

//_______wskaźniki przypisywanie_______
// int x=1; int *y=&x;
// printf("%d\n",*y);
// printf("%d\n",y);
// printf("%d\n",&x);

//_______tablica out of range__________
// int tab[20];
// tab[20]=5;

//____cannot print int as float_________
// int a = 7;
// printf("%f", a);
return 0;
}