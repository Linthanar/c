#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    
    char baza[6] = "baza/"; 
    char numer[4] = "";
    char empty[4] = "";
    int  size;
    char txt[5] = ".txt";
    numer[0] = 0 + '0';
    numer[1] = 0 + '0';
    numer[2] = 1 + '0';
    int p[4] = {0,0,1};
    // sscanf(liczba,"%3s",numer);
    printf("%s\n",numer);
    strcpy(numer,empty);

    size = sprintf(numer,"%d%d%d",p[0],p[1],p[2]);
    printf("%s-%d\n",numer,size);
   
return 0;
}