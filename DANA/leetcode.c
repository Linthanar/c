#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    /*nums = (int*) malloc(numsSize * sizeof *nums);*/
    int i,j;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){
            if(nums[i]+nums[j] == target){
                returnSize[0] = i;
                returnSize[1] = j;
            }
        }
    }
    /*free (nums);*/
    return returnSize;
}

int main(int argc, char *argv[]){  
    /*gdy nie zostaną podane dwie tablice 1[./a.out] 2[plik] to zwroć błąd do stderr i zakończ "return 1;"*/
    if (argc != 2) {
        fprintf(stderr, "Użycie: %s <nazwa_pliku>\n", argv[0]);
        return 1;} 
    /*otworz plik z tablicy 2[plik] -> jeśli tablica pusta to zakończ "return 1"*/    
    FILE *plik_t = fopen(argv[1], "r");
    if (plik_t == NULL) { return 1; }

    
    return 0;
}