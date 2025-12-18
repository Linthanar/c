typedef struct {
    int sze;            
    int wys;
    char pusty;
    char niepusty;
    char **tablica;
} plansza;
/*PRE: przyjmuje strukturę plansza*/
int alokacja(plansza *obiekt);
/*POST: alokuje miejsce na tablicę "planszę" zgodnie z parametrami sze i wys*/
/*PRE: z - znak jaki zostanie zapisany, w -  w ktrym wierszu, k - w ktorej kolumnie*/
int fill(plansza *obiekt, char z, int w, int k);
/*POST: wypełnia komorkę w tablicy znakiem*/
/*PRE: przyjmuje strukturę plansza i znak*/
int fill_all(plansza *obiekt, char z);
/*POST: zapisuje całą tablicę tym znakiem*/
/*PRE: */
int show(plansza *obiekt);
/*POST pokazuje zawartość tablicy*/