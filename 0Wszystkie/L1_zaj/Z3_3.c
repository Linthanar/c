#include <stdio.h>


int main() {
    int a, b;
    printf("Podaj liczbe a: ");
    scanf("%d", &a);
     printf("Podaj liczbe b: ");
    scanf("%d", &b);


    if (a > 0){
        if (b > 0){
            printf("a i b są większe niż 0\n");}
        }
        
    else{
        printf("a nie jest większe niż 0\n");
        }
        
    return 0;
}
