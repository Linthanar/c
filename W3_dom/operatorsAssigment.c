#include <stdio.h>

int main(){

    int a=1, b=1, c=4,d=5, i=0;

    i+=1;
    if(a==b){
        printf("%d: TRUE\n",i);}
    else{
        printf("%d: FALSE\n",i);}    

    i+=1;
    if(c==d){
        printf("%d: TRUE\n",i);}
    else{
        printf("%d: FALSE\n",i);}    

    i+=1;
    if(a&=b){
        printf("%d: TRUE\n",i);}
    else{
        printf("%d: FALSE\n",i);}
    printf("%d\n",a&=b);

    i+=1;
    if(c&=d){
        printf("%d: TRUE\n",i);}
    else{
        printf("%d: FALSE\n",i);}
    printf("%d\n",c&=d);

    return 0;
}