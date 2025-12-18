#include <stdio.h>

/* Program szuka przecięć zera w sekwencji 99 pomiarów.

******************************
*  Autor: Michał Zawada         
*  Data utworzenia: 10.11.2023
*  Wersja: 2
******************************

Dane wejśćiowe:
    Plik z danymi w formacie: 99 pomiarów ww.ww odzielonych znakiem nowej lini
   
Dane wyjśćiowe:
    Informacja o błędnym pulsie, gdy nie mieści się w granicach ustalonych w stałych symbolicznych


Modyfikacje Programu:
    1. Zmieniono stałe symbloiczne na czas testów 10.11.2023
    2. Poprawiono strukturę graficzną 17.11.2023

*/

#define WARTOSC_POMIARU_MIN -10 
#define WARTOSC_POMIARU_MAX 10
#define CZESTOTLIWOSC_MIN 8 
#define CZESTOTLIWOSC_MAX 14 
#define WARNUEK_KONCA_CZYTANIA_DANYCH 99
#define ILOSC_DANYCH_W_SEKWENCJI 20

int zakoncz_dzialanie_progrmu = 0; //zmienna sterująca

/*
    Funkcja zwraca ilość przecięć zera odnalezionych w sekwencji danych
        Odczytuje wartość ze standardowego wejścia(pliku wysłanego strummieniem) stdin
    PRE 
        Plik z obrobionymi danymi o pomiarach

    POST
        Nadpisuje zmienną globalną zakoncz_dzialanie_programu  

*/
int szukaj_przeciec_zera()
{
    int obecny_znak, poprzedni_znak=2, zmian_znaku=0;
    float pomiar;

    for(int i=0; i<ILOSC_DANYCH_W_SEKWENCJI; i++){

        scanf("%f", &pomiar);
        if(pomiar!=WARNUEK_KONCA_CZYTANIA_DANYCH){
            if((pomiar > WARTOSC_POMIARU_MAX ) || (pomiar < WARTOSC_POMIARU_MIN))
                continue;  /*jesli wynik nie miesci się w podanym zakresie, odrzuc pomiar 
                            jako bledny i przejdz do kolejnego*/
            else{
                if (pomiar == 0.00) 
                    obecny_znak = 0;
                else if (pomiar>0)
                    obecny_znak = 1;
                else if (pomiar < 0 )
                    obecny_znak = -1;
            }
            if(((poprzedni_znak==1) && (obecny_znak ==-1)) || (((poprzedni_znak==-1) && (obecny_znak==1)))){
                zmian_znaku ++;
                poprzedni_znak = obecny_znak;
            }
            if((obecny_znak!=poprzedni_znak) && (obecny_znak!=0)){
                poprzedni_znak = obecny_znak;
            }
        }
        else{
           zakoncz_dzialanie_progrmu = 1; 
        }
    }

    return zmian_znaku;
}

/*
    Informuje użytkownika o rezultacie poszukiwania przecięć zera
    Wyświetla stosowny komunikat
*/

void ocen_wynik_ekg(unsigned int przeciec_zera){
    if((przeciec_zera < CZESTOTLIWOSC_MIN) || (przeciec_zera > CZESTOTLIWOSC_MAX))
       // printf("Uwaga niewlasciwy puls wynoszacy: %d.\n", przeciec_zera);
       printf("Uwaga niewlasciwy puls!\n");
    else{
       printf("Puls wynosi: %d, a przeciec zera: %d. \n",przeciec_zera*6, przeciec_zera);    
    }
}

int main()
{
    int wynik_pomiaru=0;

    while(zakoncz_dzialanie_progrmu!=1)
    {
        wynik_pomiaru = szukaj_przeciec_zera();
        char c=getchar(); // usun znak przerwy miedzy sekwencjami
        if(zakoncz_dzialanie_progrmu!=1)
            ocen_wynik_ekg(wynik_pomiaru);
        else
            {
                printf("Wykryto sygnal konca pomiarow. Wynik w tej sekwencji nie jest prawdziwy!");
                printf("\n");
            }
        
    }
    return 0;
}