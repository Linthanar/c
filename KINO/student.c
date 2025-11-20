#include <stdio.h>

#define NSTUDENTOW 10      /* calkowita liczba studentow */
  int main() {
     int Grupa[NSTUDENTOW];
     int stud, min, max, srednia, suma;
  /************************************************************/
    suma = 0;
    min = 10;
    max = 0;
    for (stud = 0; stud < NSTUDENTOW; stud++)
    {
      printf("Prosze podac zaliczenie dla studenta %d\n",stud);
      scanf("%d",&(Grupa[stud]));  /* mozna to zrobic ladniej */
      suma += Grupa[stud];
      if (Grupa[stud] > max) max = Grupa[stud];
      if (Grupa[stud] < min) min = Grupa[stud];
    }
    srednia = suma / NSTUDENTOW;
    return 0;
}