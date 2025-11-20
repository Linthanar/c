#include<stdio.h>
#include<math.h>
double pace_sec_per_km(int czas_s, double dystans_km){
    if(dystans_km<=0){
        return 0.0;
    }
    double tempo = czas_s / dystans_km;
   return tempo;}
void best_day(void){
    int i, n, max = 0;
    double suma_km, best=10000000;
    int suma_czas_s; 
    printf("Podaj liczbę dni, liczba musi byc większa od 0\n");
    if(scanf("%d", &n)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return;
    }
    for(i=0;i<n;i++)
    {
        printf("Podaj czas w sekundach, wartość musi być większa od zera\n");
        if(scanf("%d", &suma_czas_s)!=1){ 
            printf("Błędne dane\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        if(suma_czas_s<=0){
            printf("Błędne dane\n");
            continue;
        }
        printf("Podaj dystans w km, wartość musi byc większa od 0\n");
        if(scanf("%lf", &suma_km)!=1){
            printf("Błędne dane\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        if(suma_km<=0){
            printf("Błędne dane\n");
            continue;
        }
        
        double tempo = pace_sec_per_km(suma_czas_s, suma_km);
        if (tempo > 0 && best > tempo)
        {
            best=tempo;
            max=i+1;
        }
    }
    if(max ==0){printf("Nie wprowadzonożadnych poprawnych danych\n");}
    else{printf("Numer dnia z nejlepszym wynikiem %d\n", max);}
}
int cal_burn_simple(int czas_min, double v_kmh ){
 int kcal;
 kcal = czas_min * (5 + 0.5 * v_kmh);
    return kcal;
}
double hydration_simple(int czas_min){
    return (0.5 + 0.02 *czas_min);
    }
void injuty_risk_index(void)
{
    int n; 
    int treningi_w_dzień;
    int treningi_w_tygodniu = 0; 
    int liczba_zliczonych_tygodni = 0;
    int liczb_niebezp_wart_indeksu = 0;

    float kilometry_w_dzień;
    float kilometry_w_tygodniu = 0.0; 
    float aktualny_risk_factor = 0.0;
    float poprzedni_risk_factor = 0.0;
    float wzrost_procentowy_ryzyka = 0.0;

    
    printf("Podaj łączną liczbę DNI do analizy (program analizuje tylko pełne tygodnie min.2): \n");
    if(scanf("%d", &n)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return;
    }

    
    if (n < 14) {
        printf("Do analizy są potrzebne minimum 2 tygodnie (14 dni).\n");
    }
    else {
        
        for (int i = 0; i < n; i++)
        {
            printf("Podaj dane dla dnia %d (treningi dystans): ", i + 1);
            if(scanf("%d %f", &treningi_w_dzień, &kilometry_w_dzień)!=2){
                printf("Błędne dane formatu\n");
                while(getchar() != '\n');
                i--;
                continue;
            }
                        
            if (treningi_w_dzień < 0 || kilometry_w_dzień < 0)
            {
                printf(" -> Błędne dane (ujemne), dzień pominięty w sumie.\n");
                
            }
            else
            {
                treningi_w_tygodniu += treningi_w_dzień;
                kilometry_w_tygodniu += kilometry_w_dzień;
            }
                                             
            
            if ((i + 1) % 7 == 0)
            {
                printf("--- Koniec tygodnia %d ---\n", (i + 1) / 7);
                liczba_zliczonych_tygodni++; 

                
                if (treningi_w_tygodniu > 0) {
                    aktualny_risk_factor = kilometry_w_tygodniu / (float)treningi_w_tygodniu;
                } else {
                    aktualny_risk_factor = 0.0;
                }
                printf(" -> Wskaźnik dla tego tygodnia: %.2f\n", aktualny_risk_factor);

                
                if (liczba_zliczonych_tygodni > 1 && poprzedni_risk_factor > 0) 
                {
                    wzrost_procentowy_ryzyka = (aktualny_risk_factor - poprzedni_risk_factor) / poprzedni_risk_factor;
                    printf(" -> Wzrost ryzyka vs poprz. tydzień: %.2f%%\n", (wzrost_procentowy_ryzyka * 100.0));

                    
                    if (wzrost_procentowy_ryzyka > 0.30) {
                        liczb_niebezp_wart_indeksu++;
                        printf("   -> UWAGA: Wzrost powyżej 30%%!\n");
                    }
                } 
            
                else if (liczba_zliczonych_tygodni > 1 && aktualny_risk_factor > 0) { 
                     printf(" -> Wzrost z zera (nie liczony jako procentowy).\n");
                }

                poprzedni_risk_factor = aktualny_risk_factor;
                treningi_w_tygodniu = 0;         
                kilometry_w_tygodniu = 0.0;
                
                printf("-----------------------------------------\n");
            }
        } 

        printf("\n======================================================\n");
        printf("Koniec analizy.\n");
        printf("Liczba zliczeń niebezpiecznych wzrostów ryzyka (>30%%): %d\n", liczb_niebezp_wart_indeksu);
    }
}
double intensity_factor(char rodzaj_treningu){
    switch(rodzaj_treningu){
        case 'S': {
            return 0.80;
        }
        case 'E': {
            return 0.85;
        }
        case 'M': {
            return 0.90;
        }
        case 'T': {
            return 0.95;
        }
        case 'I': {
            return 1.05;
        }
        default: {
            return 0;
        }

    }
}
double lap_avg_pace(void)
{
    int n, i;
    double minuta, sekunda, km, suma_czas_s=0, suma_km=0, tempo_sr;
    printf("Podaj liczbę okrazeń (musi być wieksza od 0\n)");
    if(scanf("%i",&n)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return 0.0;
    }
    if(n<=0){
        printf("Za mała ilość\n");
        return 0.0;
    }
    for(i=0;i<n;i++)
    {
        printf("Podaj czas okrażenia oraz dystans w foramcie: minuty:sekundy dystans\n");
        printf("Dystans musi byc większy od 0\n");
        if(scanf("%lf:%lf %lf", &minuta, &sekunda, &km)!=3){
            printf("Błędny format!\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        if(km<=0){
            printf("Błędne dane\n");
            continue;
        }
        suma_czas_s+=(60*minuta+sekunda);
        suma_km+=km;
    }
    if (suma_km == 0.0) {
        printf("Nie wprowadzono żadnych poprawnych okrążeń (suma km = 0). Nie można obliczyć tempa.\n");
        return 0.0;
    }
    tempo_sr = suma_czas_s/suma_km;
    return tempo_sr;
}
void monthly_progress(void){
    int i; 
    int j; 
    int akualna_seria = 0; 
    int seria_min_3_dni = 0; 
    int liczba_miesięcy; 
    double tempo[30]; 
   printf("Podaj liczbę pełnych miesięcy (minimum 1)\n");
   if(scanf("%d",&liczba_miesięcy)!=1){
    printf("Błędne dane\n");
    while(getchar() != '\n');
    return;
    }
    else if(liczba_miesięcy<= 0) {
    printf("Błędne dane (liczba musi być dodatnia)!\n");
    }
    else{
        int ilość_serii_3x_w_miesiącu[liczba_miesięcy]; 
        for(j=0;j<liczba_miesięcy;j++){ 
            for(i=0;i<30;i++){  
                printf("podaj tempo\n"); 
                if(scanf("%lf",&tempo[i])!=1){
                    printf("Błędne dane\n");
                    while(getchar() != '\n');
                    i--;
                    continue;  
                }
                if(tempo[i]<=0){
                    printf("Błędne dane\n");
                    i--;
                    continue;
                }
                
            }
            for(i=0;i<29;i++){  
                if(tempo[i+1]<tempo[i]){
                akualna_seria++; 
                }
                else{
                    if(akualna_seria>=3){
                        seria_min_3_dni++; 
                        akualna_seria = 0;
                    }
                    else{
                        akualna_seria = 0; 
                    }
                }
            
        }
        if (akualna_seria>=3){ 
            seria_min_3_dni++; 
        }
        ilość_serii_3x_w_miesiącu[j] = seria_min_3_dni; 
        seria_min_3_dni = 0;
        akualna_seria = 0;
        }
        for(j=0;j<liczba_miesięcy;j++){ 
            printf("Liczba serii min 3 dni z rzędu w miesiącu %d wynosi %d\n",j+1,ilość_serii_3x_w_miesiącu[j]);
        }
    }
}
const char* pace_category(double pace_sec_per_km){
    if(pace_sec_per_km <= 0){
        return "niepoprawne dane";
    }
    else{
         if(pace_sec_per_km>=420){
            return "bardzo wolno"; 
         }
         else if(pace_sec_per_km>=360 && pace_sec_per_km<420){
            return "wolno";
         }
         else if(pace_sec_per_km>=300 && pace_sec_per_km<360){ 
            return "umiarkowane";
         }  
         else if(pace_sec_per_km>=240 && pace_sec_per_km<300){
            return "szybko";  
         }
         else if(pace_sec_per_km<240){
            return "bardzo szybko";
         }
    }
}
void pace_differences(){
    int n;
    printf("Podaj liczbe dni:\n");
    if(scanf("%d", &n)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return;
    }

    if (n < 2) {
        printf("Wymagane są minimum 2 dni");
        return;
    }

    int i;
    int liczba_sytąpienia_róznicy = 0;
    double dystans_km[n];
    int czas_s[n];
    double tempo[n];

    for(i=0; i<n; i++){
        printf("Dzien %d: Podaj czas w sekundach i dystans w km\n", i + 1);
        if(scanf("%d %lf", &czas_s[i], &dystans_km[i])!=2){
            printf("Błędne dane\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        
        if (dystans_km[i] <= 0) {
            printf("Dystans musi byc dodatni. Wpisz dane ponownie.\n");
            i--;
            continue;
        }
        
        tempo[i] = pace_sec_per_km(czas_s[i], dystans_km[i]); 
    }

    for(i=0; i < n - 1; i++){
        if(fabs(tempo[i+1] - tempo[i]) < 1.0){
            liczba_sytąpienia_róznicy++;
        }
    }

    printf("Znaleziono %d dni, w których tempo było prawie identyczne jak dzień wcześniej (różnica < 1s/km).\n", liczba_sytąpienia_róznicy);
}
double session_load_tss(int czas_min, char intensity_code){
    double tss = czas_min * pow(intensity_factor(intensity_code),2);
    return tss;
}
double speed_kmh(int czas_s, double dystans_km){
    if(czas_s<=0){
        printf("Błędne dane\n");
        return 0;
    }
    double v = (dystans_km/czas_s) *3600;
    return v;
}
void streak_target_zone(double tempo_docelowe)
{
    int i, streak=0, max=0;
    int n;
    printf("Podaj liczbę dni do analizy (minimum 1)\n");
    if(scanf("%i", &n)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return;
    }
    if(n<1){
        printf("Wymagany minimum 1 dzień\n");
        return;
    }
    double suma_czas_s[n], suma_km[n];
    for(i=0;i<n;i++)
    {
        printf("Podaj czas biegu w sekundach\n");
        if(scanf("%lf", &suma_czas_s[i])!=1){
            printf("Błędne dane\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        if(suma_czas_s[i]<=0){
            printf("Czas musi być wiekszy od 0\n");
            i--;
            continue;
        }
        printf("Podaj dystans biegu w km\n");
        if(scanf("%lf", &suma_km[i])!=1){
            printf("Błędne dane\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        if(suma_km[i]<=0){
            printf("Dystans musi być większy od 0\n");
            i--;
            continue;
        }

        if ((suma_czas_s[i]/suma_km[i]) >= 0.9*tempo_docelowe && (suma_czas_s[i]/suma_km[i]) <= 1.1*tempo_docelowe)
        {
            streak+=1;
        }
        else
        {
            if (streak > max)
            {
                max=streak;
            }
            streak=0;
        }
    }
    if (streak > max)
        {
            max=streak;
        }
    printf("Najdłuższa seria gdzie byłeś bardzo blisko tempa docelowego wyniosła %i dni\n", max);
}
void weekly_variability(void){
    int n;
    int liczba_tygodni_spełniająca_warunek = 0;
    int i, j;                                                                 
    int liczba_dni_spełniająca_warunek;
    printf("Podaj liczbę dni do analizy (minimum 7 dni)\n");
    if(scanf("%d",&n)!=1) {
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return;
    }
    if(n<7){
        printf("Liczba dni musi wynosić minimum 7\n");
        return;
    }
    int liczba_tygodni = n / 7;
    for(i=0;i<liczba_tygodni;i++){  
        float tempo_dzienne[7];
        float suma_tygodniowa = 0;
        liczba_dni_spełniająca_warunek = 0;
        for(j=0;j<7;j++){ 
            printf("Podaj tempo z dnia %d\n",j+1);
            if(scanf("%f",&tempo_dzienne[j])!=1){
                printf("Błędne dane\n");
                while(getchar() != '\n');
                j--;
                continue;
            }
            if(tempo_dzienne[j]<=0){
                printf("Tempo musi być większe od 0\n");
                j--;
                continue;
            }
            suma_tygodniowa += tempo_dzienne[j];
        }
        float średnie_tempo = suma_tygodniowa/7; 
        for(j=0;j<7;j++){ 
            if(fabs(średnie_tempo-tempo_dzienne[j]) <= 0.05 * fabs(średnie_tempo)){
                liczba_dni_spełniająca_warunek++;
            }
        }
        if(liczba_dni_spełniająca_warunek >= 3){
            liczba_tygodni_spełniająca_warunek++;                                         
        }
    }
    printf("Liczba tygodni, w których minimum 3 dni miały tempo bardzo zbliżone do tempa średniego z danego tygodnia wyniosła: %d\n", liczba_tygodni_spełniająca_warunek);
}
void training_anomaly(void){
int i; 
int j; 
double liczba_km[7];
char intensivity_znak[7];
int licznik_anomalii =0;
int tygodnie_z_anomalią = 0;
double intensywność[7];
int liczba_tygodni=0;
printf("Podaj liczbę tygodni do analizy (min1 )\n");
if(scanf("%d",&liczba_tygodni)!=1){
    printf("Błędne dane\n");
    while(getchar() != '\n');
    return;
}
if(liczba_tygodni<=0){
    printf("Liczba tygodni musi być większa od 0");
    return;
}
    for(j=0;j<liczba_tygodni;j++){
        for(i=0;i<7;i++){
        printf("rodzaj treningu: S-spokojny, E-lekki bieg, M-umiarkowany, T-szybki bieg progowy, I-interwały\n");
        printf("Podaj dystans i wskaźnik intensywności w formacie: np. 11.5 M\n");
        if(scanf("%lf %c",&liczba_km[i],&intensivity_znak[i])!=2){
            printf("Błędne dane\n");
            while(getchar() != '\n');
            i--;
            continue;
        }
        intensywność[i] = intensity_factor(intensivity_znak[i]);
        }
        for(i=0;i<6;i++){ 
            if(liczba_km[i+1] >0 && liczba_km[i] > 0){
                if(fabs(liczba_km[i+1]-liczba_km[i])>10){
                    licznik_anomalii++;
                }
            }
        }
            if(licznik_anomalii>1 && licznik_anomalii<3){
                tygodnie_z_anomalią++;
            }
                            licznik_anomalii = 0;
        
    }
    printf("Liczba tygodni spełniających warunek: %d\n",tygodnie_z_anomalią);
}
void training_balance(void){
    int liczba_miesięcy;
    int i;
    int j;
    int typ_treningu;
    int liczba_easy = 0;
    int liczba_tempo =0;
    int liczba_long = 0;
    int liczba_interwał = 0;
    int liczba_miesięcy_przeciążonych = 0;
    printf("Podaj liczbę miesięcy (min 1)\n");
    if(scanf("%d",&liczba_miesięcy)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n');
        return;
    }
    if(liczba_miesięcy<=0){
        printf("Lliczba miesięcy musi być wieksza od 0\n");
        return;
    }
    for(j=0;j<liczba_miesięcy;j++){
        for(i=0;i<30;i++){
            printf("Podaj typ treningu: 1-easy, 2-tempo, 3-long, 4-interwał\n");
            if(scanf("%d",&typ_treningu)!=1){
                printf("Błędne dane, wpisz liczbę 1-4\n");
                while(getchar() != '\n');
                i--;
                continue;
            }
            switch(typ_treningu){
                case 1: 
                    liczba_easy++; 
                    break;
                case 2: 
                    liczba_tempo++;
                    break;
                case 3: 
                    liczba_long++;
                    break;
                case 4: 
                    liczba_interwał++;
                    break;
                default: 
                    printf("błędne dane (liczba poza zakresem 1-4)\n");
                    i--;
                    break;
            }
        }
        if(liczba_easy>=15 && liczba_interwał<=6){
                printf("Obciążenie treningowe w tym miesiącu było dobre!\n");
            }
            else{
                printf("Obciażenie treningowe w tym miesiącu było zbyt duże!\n");
                liczba_miesięcy_przeciążonych++;
            }
        liczba_easy = 0;
        liczba_interwał = 0;
        liczba_long = 0;
        liczba_tempo = 0;

    }
    printf("Liczba przeciążonych miesięcy wynosi %d",liczba_miesięcy_przeciążonych);
}
void weekly_summary() {
    int n;
    int i;
    printf("Podaj liczbę dni do analizy\n");
    if(scanf("%d",&n)!=1){
        printf("Błędne dane!\n");
        while(getchar() != '\n');
        return;
    }
    if(n < 7){ 
        printf("Minimalna liczba dni do analizy wynosi 7\n");
        return;
    }
    
    int suma_czas_s[n]; 
    double suma_km[n];
    
    
    for (i = 0; i < n; i++) {
        printf("Podajczas w sekundach i dystans w km:\n");
        if(scanf("%d %lf", &suma_czas_s[i], &suma_km[i])!=2){
            printf("Błędne dane formatu\n");
            while(getchar() != '\n');
            i--;
            continue;
        }

        if (suma_km[i] < 0 || suma_czas_s[i] < 0) {
             printf("Dane nie moga byc ujemne. Wpisz ten dzien ponownie.\n");
             i--;
        }
    }

    int ilosc_tygodni = n / 7; 

    for (int tydzien = 0; tydzien < ilosc_tygodni; tydzien++) { 
        
        double calkowita_suma_km = 0;
        int calkowita_suma_czasu_s = 0;
        double max_dystans_dnia = -1;
        int dzien_z_max_dystansem = -1;

        int start_index = tydzien * 7; 
        int end_index = start_index + 7; 

        for (i = start_index; i < end_index; i++) { 
            calkowita_suma_km += suma_km[i];
            calkowita_suma_czasu_s += suma_czas_s[i];

            if (suma_km[i] > max_dystans_dnia) {  
                max_dystans_dnia = suma_km[i];
                dzien_z_max_dystansem = i;
            }
        }

        double srednie_tempo_tygodnia = pace_sec_per_km(calkowita_suma_czasu_s, calkowita_suma_km);

        
        printf("\n--- Podsumowanie Tygodnia %d (Dni %d-%d) ---\n", 
tydzien + 1, start_index + 1, end_index); 
        
        printf("Calkowita suma kilometrow: %.2f km\n", calkowita_suma_km); 

        if (srednie_tempo_tygodnia > 0) { 
            printf("Srednie tempo tygodnia: %.2f s/km\n", srednie_tempo_tygodnia);
        } else {
            printf("Błędne dane\n");
        }
        
        printf("Dzien z najwiekszym dystansem: Dzien %d (%.2f km)\n",dzien_z_max_dystansem + 1, max_dystans_dnia); 
    }
    
    int start_index_reszty = ilosc_tygodni * 7; 
    
    if (start_index_reszty < n) { 
    
        double calkowita_suma_km = 0;
        int calkowita_suma_czasu_s = 0;
        double max_dystans_dnia = -1;
        int dzien_z_max_dystansem = -1;
        
        for (i = start_index_reszty; i < n; i++) { 
            calkowita_suma_km += suma_km[i];
            calkowita_suma_czasu_s += suma_czas_s[i];

            if (suma_km[i] > max_dystans_dnia) {  
                max_dystans_dnia = suma_km[i];
                dzien_z_max_dystansem = i;
            }
        }
        
        double srednie_tempo_tygodnia = pace_sec_per_km(calkowita_suma_czasu_s, calkowita_suma_km);

        printf("\n--- Podsumowanie Tygodnia %d (Dni %d-%d) ---\n", 
               ilosc_tygodni + 1, start_index_reszty + 1, n); 
        
        printf("Calkowita suma kilometrow: %.2f km\n", calkowita_suma_km); 

        if (srednie_tempo_tygodnia > 0) { 
            printf("Srednie tempo tygodnia: %.2f s/km\n", srednie_tempo_tygodnia);
        } else {
            printf("Błędne dane\n");
        }
        
        printf("Dzien z najwiekszym dystansem: Dzien %d (%.2f km)\n",dzien_z_max_dystansem + 1, max_dystans_dnia); 
    }
}
void menu_kalkulatory(){
    int znacznik_menu_kalkulatory =0;
while(znacznik_menu_kalkulatory!=9){
printf("Wybierz program:\n");
printf("1.Oblicz tempo biegu (s/km)\n");
printf("2.Oblicz średnią prędkość (km/h)\n");
printf("3.Oblicz średnie tempo z okrążeń\n");
printf("4.Oblicz spalone kalorie w trakcie biegu\n");
printf("5.Oblicz zapotrzebowanie na nawodnienie\n");
printf("6.Oblicz współczynnik obciążenia\n");
printf("7.Ocena tempa biegowego\n");
printf("8.Oblicz Współczynnik intensywności\n");
printf("9.Wróć do menu głównego\n");
if(scanf("%d",&znacznik_menu_kalkulatory)!=1){
    printf("Błędne dane\n");
    while(getchar() != '\n');
    continue;
}

switch (znacznik_menu_kalkulatory)
{
case 1:{
int czas_1;
double dystans_1;
printf("Podaj czas w sekundach\n");
if(scanf("%d",&czas_1)!=1){
    printf("Błędne dane\n");
    break;
}
printf("Podaj dystans w km\n");
if(scanf("%lf",&dystans_1)!=1){
    printf("Błędne dane\n");
    break;
}
double tempo = pace_sec_per_km(czas_1,dystans_1);
printf("Tempo jest równe: %lf\n",tempo);
break;;
}
case 2:{
int czas_2;
double dystans_2;
printf("Podaj dystans w km\n");
if(scanf("%lf",&dystans_2)!=1){
    printf("Błędne dane\n");
    break;
}
printf("Podaj czas w sekundach\n");
if(scanf("%d",&czas_2)!=1){
    printf("Błędne dane\n");
    break;;
}
double prędkość_średnia = speed_kmh(czas_2,dystans_2);
printf("Średnia prędkość wyniosła: %lf",prędkość_średnia);
break;
}
case 3:{
double średnie_tempo = lap_avg_pace();
printf("Średnie tempo biegu wyniosło: %lf",średnie_tempo);
break;
}
case 4:{
int kalorie;
int czas_4;
double prędkość_4;
printf("Podaj czas biegu w minutach\n");
if(scanf("%d",&czas_4)!=1){
    printf("Błędne dane\n");
    break;
}
printf("Podaj prędkość w kilometrach na godzinę\n");
if(scanf("%lf",&prędkość_4)!=1){
    printf("Błędne dane\n");
    break;
}
kalorie = cal_burn_simple(czas_4,prędkość_4);
printf("Liczba spalonych kalorii wyniosła %d\n",kalorie);
break;
}
case 5:{
double nawodnienie;
int czas_5;
printf("Podaj czas treningu w minutach\n");
if(scanf("%d",&czas_5)!=1){
    printf("Błędne dane\n");
    break;
}
 nawodnienie = hydration_simple(czas_5);
 printf("Sugerowana ilość wody do wypicia wyniosła: %lfL",nawodnienie);
    break;
}
case 6:{
printf("Rodzaje treningu:S-spokojny, E-lekki, M-umiarkowany, T-szybki bieg progowy, I-interwały\n");
int czas_6;
char typ_treningu;
printf("Podaj czas treningu w minutach\n");
if(scanf("%d",&czas_6)!=1){
    printf("Błędne dane\n");
    break;
}
printf("Podaj rodzaj treningu za pomocą wielkiej litery\n");
if(scanf(" %c",&typ_treningu)!=1){
    printf("Błędne dane\n");
    break;
}
double intensywność = session_load_tss(czas_6,typ_treningu);
printf("Współczynnik intensywności wyniósł: %lf\n", intensywność);
break;
}
case 7:{
double tempo_biegu;
printf("Podaj tempo biegu (s/km)\n");
if(scanf("%lf",&tempo_biegu)!=1){
    printf("Błędne dane\n");
    break;
}
printf("%s",pace_category(tempo_biegu));
break;
}
case 8:{
char typ_treningu;
printf("Podaj rodzaj treningu: S-spokojny, E-lekki bieg, M-umiarkowany, T-szybki bieg progowy, I-interwały\n");
scanf(" %c",&typ_treningu);
double obliczony_IF = intensity_factor(typ_treningu);
printf("Współczynnik intensywności wynosi:%lf\n",obliczony_IF);
break;
}
case 9:{
break;
}
default:
    break;
}
    if (znacznik_menu_kalkulatory != 9) {
            printf("\n...Wciśnij Enter, aby kontynuować w tym menu...");
            while(getchar() != '\n'); 
            getchar(); 
        }
}
}
void menu_analizy_dzienne(){
    int znacznik_menu_analizy_dzienne =0;
    while(znacznik_menu_analizy_dzienne!=4){
printf("Wybierz program:\n");
printf("1.Znajdź najlepszy dzień (najszybsze tempo)\n");
printf("2.Znajdź najdłuższą serię w strefie tempa docelowego\n");
printf("3.Oblicz ilość dni o podobnym tempie\n");
printf("4.Wróć do menu głównego\n");

if(scanf("%d",&znacznik_menu_analizy_dzienne)!=1){
    printf("Błędne dane\n");
    while(getchar() != '\n');
    continue;
}
switch(znacznik_menu_analizy_dzienne){
    case 1:{
        best_day();
        break;
    }
    case 2:{
        double tempo_docelowe;
        printf("Podaj tempo docelowe\n");
        if(scanf("%lf",&tempo_docelowe)!=1){
            printf("Błędne dane!\n");
            break;
            
        }
        if(tempo_docelowe<=0){
            printf("Tempo musi być większe od 0\n");
            break;
        }
        streak_target_zone(tempo_docelowe);
        break;
    }
    case 3:{
        pace_differences();
        break;
    }
    case 4:{
        
        break;
    }
    default:{
        break;
    }
}
if (znacznik_menu_analizy_dzienne != 4) {
            printf("\n...Wciśnij Enter, aby kontynuować\n");
            while(getchar() != '\n'); 
            getchar(); 
        }
}
}
void menu_analizy_tygodniowe(){
    int znacznik_menu_analizy_tygodniowe =0;
    while(znacznik_menu_analizy_tygodniowe!=4){
printf("Wybierz program:\n");
printf("1.Podsumowanie tygodniowe\n");
printf("2.Analiza zmienności tempa w tygodniu\n");
printf("3.Wykryj tygodnie z anomalią dystansu (>10km)\n");
printf("4.Wróć do menu głównego\n");
if(scanf("%d",&znacznik_menu_analizy_tygodniowe)!=1){
    printf("Błędne dane\n");
    while(getchar() != '\n');
    continue;
}
switch(znacznik_menu_analizy_tygodniowe){
    case 1:{
        weekly_summary();
        break;
    }
    case 2:{
        weekly_variability();
        break;
    }
    case 3:{
        training_anomaly();
        break;
    }
    case 4:{
        
        break;
    }
    default:{
        break;
    }
}
if (znacznik_menu_analizy_tygodniowe != 4) {
            printf("\n...Wciśnij Enter, aby kontynuować w tym menu...");
            while(getchar() != '\n'); 
            getchar(); 
        }
}
}
void menu_analizy_miesięczne_i_ryzyko(){
        int znacznik_menu_analizy_miesięczne_i_ryzyko=0;
        while(znacznik_menu_analizy_miesięczne_i_ryzyko!=4){
printf("Wybierz program:\n");
printf("1.BIlans miesięczny\n");
printf("2.Analizuj miesięczny postęp\n");
printf("3.Oblicz wskaźnik ryzyka kontuzji\n");
printf("4.Wróć do menu głównego\n");
if(scanf("%d",&znacznik_menu_analizy_miesięczne_i_ryzyko)!=1){
    printf("Błędne dane\n");
    while(getchar() != '\n');
    continue;
}
switch(znacznik_menu_analizy_miesięczne_i_ryzyko){
    case 1:{
        training_balance();
        break;
    }
    case 2:{
        monthly_progress();
        break;
    }
    case 3:{
        injuty_risk_index();
        break;
    }
    case 4:{
        
        break;
    }
    default:{
        break;
    }
}
        if (znacznik_menu_analizy_miesięczne_i_ryzyko != 4) {
            printf("\n...Wciśnij Enter, aby kontynuować w tym menu...");
            while(getchar() != '\n'); 
            getchar(); 
        }
}
}
void menu_główne(){
    int znacznik_kategorii;
    while(1){
    printf("APLIKACJA-FITNESS\n");
    printf("Wybierz kategorię:\n");
    printf("1.Proste kalkulatory\n");
    printf("2.Analizy dzienne\n");
    printf("3.Analizy tygodniowe\n");
    printf("4.Analizy miesięczne i ryzyko kontuzji\n");
    printf("5.Zakończ program\n");
    if(scanf("%d",&znacznik_kategorii)!=1){
        printf("Błędne dane\n");
        while(getchar() != '\n'); 
        continue;
    }
    switch (znacznik_kategorii)
    {
    case 1:{
        menu_kalkulatory();
        break;
    }
    case 2:{
        menu_analizy_dzienne();
        break;
    }
    case 3:{
        menu_analizy_tygodniowe();
        break;
    }
    case 4:{
        menu_analizy_miesięczne_i_ryzyko();
        break;
    }   
    case 5:{
    return;
    }
    default:
    printf("Błędne polecenie\n");
    break;
    }    
    }   
}
int main(){
menu_główne();
return 0;
}
