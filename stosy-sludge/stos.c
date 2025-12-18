#include <stdio.h>
#include <stdlib.h>

typedef struct {    /*struktura pomocnicza o nazwie t_info*/
    int val;        /*taka aby można było modyfikować typ elementow stosu.*/
    } t_info;

typedef struct node {       /*struktura ktora stworzy stos*/
    t_info info;            /*przechowuje zmienną nieznanego typu*/
    struct node *nastepny;  /*tak*/
  } t_elem;              /* i gdzies dalej  t_elem *lista */

void init(struct node* head)    /*inicjacja stosu, przyjmuje argument stos / "t_elem"*/
{
    head = NULL;
}
int main(){

 
    t_elem *lista, *pom;

   init(lista);

    
    
    
    
    t_info info;                    /*potrzeba deklaracji struktury info*/
    info.val = 4;                   /*zapis wartości */
    t_elem stos;                    /*potrzeba deklaracji struktury stos*/
    stos.info = info;               /*zapis (wartości) (zmiennej info o strukturze t_info) jako struktury info*/
    printf("%1d",stos.info.val);    /*dereferencja stos->info->val*/


    return 0;
}
