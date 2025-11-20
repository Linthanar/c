 #include <stdio.h>
 
 int main(void)
 {
   int i = 0;
   for (; i<100; ++i)
   {
     /* Nie jest to pierwsza liczba w wierszu */
     if (i % 10)
     {
     putchar(' ');
     }
     printf("%2d", i);
     /* Jest to ostatnia liczba w wierszu */
     if ((i % 10)==9)
     {
       putchar('\n');
     }
}
return 0; }