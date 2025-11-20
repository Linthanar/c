#include <stdio.h>


int main(){                  /* kopiowanie pliku na standardowe wyjscie */
    FILE *plik;
    void kopiuj(FILE *, FILE *);
    if ((plik=fopen("tekst.txt", "r")) == NULL){
      printf("kopiuj: nie moge otworzyc kubusia");
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


