#include <stdio.h>


int main() {
    float dochod, podatek;  // Deklaracje zmiennych
    float prog_podatkowy = 120000.0;
    float stawka_progu1 = 0.12;  // 12% dla dochodów do 120 000 zł
    float stawka_progu2 = 0.32;  // 32% dla dochodów powyżej 120 000 zł


    printf("Proszę podać dochód roczny: ");
    scanf("%f", &dochod);


    if (dochod <= prog_podatkowy) {
        podatek = dochod * stawka_progu1;
    } else {
        podatek = (prog_podatkowy * stawka_progu1) 
+ ((dochod - prog_podatkowy) * stawka_progu2);
    }


    printf("Należny podatek: %.2f zł\n", podatek);


    return 0;
}
