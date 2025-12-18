/*Zadanie 2: Funkcja scanf
Proszę przygotować program, który wczytuje w pętli linie
z pliku w poniższym formacie, aż do napotkania wartości (0,0) koniec - 0.0 

(3,4) taboret - 13.5
(5,6) walizka - 15.75
(7, 11) portfel - 12.55 
Użyj funkcji scanf.
Program wypisze dane z pliku linia po linii  w wybranym formacie na ekran np. 
{ pozycja (3,4), przedmiot: taboret, cena 13.5 }
Plik z danymi wejściowymi można przekazać do programu poprzez przekierowanie pliku czyli
./a.out < dane.txt
Załóż, że plik jest poprawnie sformatowany*/


#include <stdio.h>


int main(){                  /* kopiowanie pliku na standardowe wyjscie */
    FILE *plik;
    void kopiuj(FILE *, FILE *);
    
    if ((plik=fopen("przedmioty.txt", "r")) == NULL){
      printf("kopiuj: nie moge otworzyc pliku");
      return 1;
    } else {
      kopiuj(plik,stdout);
      fclose(plik);
}
return 0; }

void kopiuj(FILE *wej, FILE *wyj){
int znak;
   
while ((znak = getc(wej)) != EOF)
      putc(znak, wyj);
}