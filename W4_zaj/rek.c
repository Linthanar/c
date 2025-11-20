#include <stdio.h>

int silnia(int n);

int main(){
    int a = 6;
    printf("%d",silnia(a));
    return 0;
}
int silnia(int n)
 /* Funkcja wylicza rekurencyjnie */
 /* wartosc silni.                */
 /* UWAGA: dla n <= 0 zwraca 1    */
 {
   if (n <= 1)
     return 1;
else
return n * silnia(n-1);
}
