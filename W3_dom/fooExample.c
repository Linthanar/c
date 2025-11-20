#include <stdio.h>
#include <stdbool.h>

bool a = true, b = true, c = true;

int doA(){
    if (a==true){ 
        return 1;}
    else{
        return 0;}
 }
int doB(){
    if (b==true){ 
        return 1;}
    else{
        return 0;}
 }
int doC(){
    if (c==true){ 
        return 1;}
    else{
        return 0;}
 }
void foo()
{
    if (!doA())
        goto exit;
    if (!doB())
        goto cleanupA;
    if (!doC())
        goto cleanupB;

    /* everything has succeeded */
    printf("true");
    return;

cleanupB:
    undoB();
cleanupA:
    undoA();
exit:
    return;
}

int main(){
foo();
return 0;
}