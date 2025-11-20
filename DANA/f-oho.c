#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){  
    /*gdy nie zostaną podane dwie tablice 1[./a.out] 2[plik] to zwroć błąd do stderr i zakończ "return 1;"*/
    if (argc != 2) {
        fprintf(stderr, "Użycie: %s <nazwa_pliku>\n", argv[0]);
        return 1;} 
    /*otworz plik z tablicy 2[plik] -> jeśli tablica pusta to zakończ "return 1"*/    
    FILE *plik_t = fopen(argv[1], "r");
    if (plik_t == NULL) { return 1; }


    int case_tab[256];
    char check_char;
    int k;
    for(k=0;k<15;k++){
        fscanf(plik_t,"%c",&check_char);
        printf("%c",check_char);
        if((check_char != '[')||(check_char != ']')||(check_char != '\n')){
            fscanf(plik_t,"%2d",&case_tab[k]);
            printf("%d",case_tab[k]);
        }
        //printf("\n k: %d",k);
    }
    return 0;
}




    // //char case_tab[256];
    // // int case_tab[256];
    // // char 
    // //case_tab[1] = 0;
    // //case_tab[2] = 0;
    // int n = 0;

    // while(fscanf(plik_t,"%*c%4d",&case_tab[n]) == 1){
   
    //     printf("%d\n",case_tab[n]);
 
    //     n ++;
    // }
    // printf("\n%d",n);
    // fscanf(plik_t,"%d",&case_tab[n]);
    // printf("\n%d",&case_tab[n]);
    // // int k;
    // // size_t strlen(litera);
    // // for(k=0,k<;){}



    // int returnSize[2];
    // int nums[4] = {2,7,11,15};
    // twoSum(nums, 4, 9, returnSize);
    // int i;
    // for(i=0;i<2;i++){
    //     printf("\n%d",returnSize[i]);
    // }
    