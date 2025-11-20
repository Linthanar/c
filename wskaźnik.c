// #include <stdio.h>

// int main(void)
// {
//   unsigned char tab[10] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109 };
//   unsigned short *ptr = (unsigned short*)&tab[2];
//   unsigned i;
//   *ptr = 0xffff;
//   for (i = 0; i < 10; ++i) {
//     printf("%d\n", tab[i]);
//     tab[i] = tab[i] - 100;
//   }
//   printf("poza tablica: %d\n", tab[10]);
//   tab[10] = -1;
//   return 0;
// }




#include <stdio.h>
int main (void)
{
  int liczba = 80;
  int *wskaznik = &liczba;
  printf("Wartosc zmiennej: %d; jej adres: %p.\n", liczba, (void*)&liczba);
  printf("Adres zapisany we wskazniku: %p, wskazywana wartosc: %d.\n",
         wskaznik, *wskaznik);
  *wskaznik = 42;
  printf("Wartosc zmiennej: %d, wartosc wskazywana przez wskaznik: %d\n",
         liczba, *wskaznik);
//   liczba = 0x42;
//   printf("Wartosc zmiennej: %d, wartosc wskazywana przez wskaznik: %p\n",
//          liczba, *wskaznik);
return 0; }