#include <stdio.h>



int scanf_int(int liczba){
    //int liczba;
    printf("Podaj liczbe calkowita: ");
    scanf("%d", &liczba);
    printf("liczba: %d\n", liczba);
    return liczba;
}
void scanf_void_int(){
    int a,b,c;
    printf("Podaj 3 liczby calkowite: ");
    scanf("%d %d %d", &a,&b,&c);
    printf("liczby: %d %d %d\n", a,b,c);

    
}
int scanf_int_double(int liczba_1, int liczba_2){
    //int liczba;
    printf("Podaj dwie liczby calkowite liczba\" \"liczba: ");
    scanf("%d %d", &liczba_1, &liczba_2);
    printf("liczba\" \"liczba: %d %d\n", liczba_1,liczba_2);
    return liczba_1 + liczba_2;
}
void scanf_char(){
    char znak;
    printf("znak: ");
    scanf("%c",&znak);
    printf("znak: %c\n",znak);
}
void scanf_spacje(){
    char napis[100];
    scanf("%[^\n]", napis); //Wczytuje aż do napotkania znaku nowej linii
    //Nie kończy wczytywania na spacji
    printf("\nNapis: [%s]\n", napis);
}
void scanf_tekst(){
    char napis[100];
    printf("napisz tekst: ");
    scanf("%s", napis); 
    printf("\nNapis: [%s]\n", napis);
}
void scanf_kropek(){
    char napis[100];
    printf("Wpisz napis ze spacjami: ");
    scanf("%[^:^:]", napis); //Wczytuje aż do napotkania :: //Nie kończy wczytywania na spacji
    printf("Napis: [%s]\n", napis);
}
void scanf_ok(){
//char napis[100];
char buf[10];
    int a, b, pos;
    sscanf(buf, "%d %n", &a, &pos);  
    sscanf(buf+pos, "%d", &b);  //Wymaga ręcznego przesunięcia wskaźnika
    printf("a=%d, b=%d", a, b);  
}

int main() {
    //scanf_tekst();
    //scanf_void_int();
    //scanf_spacje();
    scanf_kropek();
    //scanf_ok();
    //int a, b, odpowiedz;
    //odpowiedz = scanf_int(a) + scanf_int(b);
    //odpowiedz = scanf_int_double(a,b);
    //printf("odpowiedz: %d",odpowiedz);
    //scanf_char();
    //scanf_spacje();
    
    return 0;
}
