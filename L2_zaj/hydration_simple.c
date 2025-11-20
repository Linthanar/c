#include <stdio.h>
double hydration_simple(int czas_min){
    return (0.5 + 0.02 *czas_min);
    }

int main(){
    double litry = hydration_simple(2);
    printf("Ilosc litrow wody do wypicia po treningu: %lf\n", litry);
    return 0;
}