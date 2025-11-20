#include <stdio.h>

int cal_burn_simple(int czas_min, double v_kmh ){
 int kcal;
 kcal = czas_min * (5 + 0.5 * v_kmh);
    return kcal;
}



int main(){
    int k;
    
    k = cal_burn_simple(2,7);
    printf("%d\n", k);
}