#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // dla usleep()

void pasek_postepu(int dlugosc, int opoznienie) {
    int i = 0;
    while (i <= dlugosc) {
        usleep(opoznienie);
        system("reset");  // czyści ekran
        
        
        printf("[");
        // drukuj wypełnione znaki
        for (int j = 0; j < i; j++)
            printf("+");
        // drukuj puste miejsca
        for (int j = i; j < dlugosc; j++)
            printf("-");
        printf("]\n");
        usleep(opoznienie);
        printf("\nciemno wszędzie");
          // czekaj (mikrosekundy)
        i++;
    }
}

int main() {
    int dlugosc = 10;        // długość paska
    int opoznienie = 500000; // 150 000 mikrosekund = 0.15 sekundy
    
    pasek_postepu(dlugosc, opoznienie);
    
    printf("\nZakończono!\n");
    return 0;
}