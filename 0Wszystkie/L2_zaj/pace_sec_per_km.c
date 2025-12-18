#include<stdio.h>
double pace_sec_per_km(int czas_s, double dystans_km){
   double tempo = czas_s / dystans_km;
   return tempo; 
}
int main(){
    int czas = 4;
    double dystans =5;
    double tempo_biegu = pace_sec_per_km(czas,dystans);
    printf("Tempo jest równe: %lf",tempo_biegu);
    return 0;
}
