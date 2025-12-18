#include <stdio.h>

int main() {
    int parametr,i;

    for(i = 1;;i++) {
        printf("\n Podaj %d. parametr: ", i);
        scanf("%d", &parametr);

        if (parametr == 99) {
            break;
        }

        if (parametr >= -5 && parametr <= 5) {
            printf(" Aktualna wartosc parametru: %d", parametr);
        } else {
            printf(" Bledna wartosc parametru!");
        }
    }

    return 0;
}