#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_char_tab_one(char tab[256]);

int main(int argc, char *argv[]) {
    /*gdy nie zostaną podane dwie tablice 1[./a.out] 2[plik] to zwroć błąd do stderr i zakończ "return 1;"*/
    if (argc != 2) {
        fprintf(stderr, "Użycie: %s <nazwa_pliku>\n", argv[0]);
        return 1;} 
    /*otworz plik z tablicy 2[plik] -> jeśli tablica pusta to zakończ "return 1"*/    
    FILE *plik = fopen(argv[1], "r");
    if (plik == NULL) { return 1; }


// const char *c = "[2,7,11,15]";
// long int l_num;
// l_num = atol(c);
// printf("%ld",l_num);

char c_tab[256];
int x = 0, i = 0;
while(fscanf(plik,"%c",&c_tab[x])==1){
    if(c_tab[x] == '\n'){
        /*zrob nic*/
    }
    else if(!(('0'<= c_tab[x]) && (c_tab[x] <= '9'))){
        c_tab[x] = ' ';
    }
    x++;
}

c_tab[x] = '\0';
read_char_tab_one(&c_tab[0]);

return 0;
}


void read_char_tab_one(char tab[256]){
    int x = 0;
    while(!(tab[x] =='\0')){
        printf("%c",tab[x]);
        x++;
    }  
}