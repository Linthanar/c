#include <stdio.h>

int PROG_TEMP = 20;

int main(){
    int t;
    printf(" Podaj temperature we Wroclawiu:");
    scanf("%d", &t);
    if(t<PROG_TEMP){
        printf(" Nie jest zbyt cieplo!");
    }
    else{
        printf(" Jest bardzo ladna pogoda!");
    }
    return 0;
}
















/*
Pobieranie z klawiatury wartości aktualnej temperatury i wyświetlanie pozytywnego bądź negatywnego komunikatu w zależności od przekroczenia ustalonego progu, zadanego w stałej symbolicznej (instrukcja if, stała symboliczna).
# prog = 20
[john_doe@diablo:~]$ ./a.out 
Podaj temperature we Wroclawiu:  15
Nie jest zbyt cieplo! 

[john_doe@diablo:~]$ ./a.out 
Podaj temperature we Wroclawiu:  27
Jest bardzo ladna pogoda!
*/