#include <stdio.h>
#include <math.h>


int main() {
    float brutto, netto, pensja;  // Deklaracje zmiennych
    float prog_podatkowy = 40000;
    float stawka_progu1 = 0.12;  // 12% dla dochodów do 120 000 zł
    float stawka_progu2 = 0.32;  // 32% dla dochodów powyżej 120 000 zł


    printf("Proszę podać dochód roczny brutto: ");
    scanf("%f", &brutto);


    if (brutto <= prog_podatkowy) {
        netto = brutto / (1+ stawka_progu1);
    } else {
        netto = (prog_podatkowy / (1+ stawka_progu1)) 
+ ((brutto - prog_podatkowy) / (1+ stawka_progu2));
    }
    pensja = round(netto/12);

    printf("kwota netto: %.2f zł\n", netto);
    printf("średnia miesięczna pensja: %.2f zł\n", pensja);


    return 0;
}


// 1.Proszę przeanalizować i przetestować program. Co dokładnie oblicza program?
// 2.Proszę uzupełnić program tak, by wypisywał ile podatnik zarobił netto (czyli po odliczeniu od dochodu należnego podatku).
// 3.Proszę uzupełnić program, by uwzględnić kwotę wolną od podatku wynoszącą 40 000 zł. Proszę przetestować program  dla różnych zestawów danych. 
// 4.Proszę wpisać średnią miesięczną pensję pracownika. Proszę wykorzystać funkcję round z biblioteki math.h do zaokrąglenia wyniku. (Proszę też dodać flagę -lm do kompilacji)
// Co się stanie gdy użytkownik wpisze kwotę dochodu poniżej zera? Co powinno się stać? Proszę zaprogramować wybrane przez siebie rozwiązanie.
// Proszę zmienić wyjście programu w sposób następujący:
// dla danych poprawnych
// Wpisz: 50000
// Podatek: 1200.00
// Netto: 48800.00
// AVG: 4067
// dla danych niepoprawnych
// Wpisz: -95
// ERR
// dla zera
// Wpisz: 0
// Podatek: 0.00
// Netto: 0.00
// AVG: 0
// Proszę zastanowić się jak przetestować powyższy program. Jakie przypadki należy koniecznie sprawdzić?
