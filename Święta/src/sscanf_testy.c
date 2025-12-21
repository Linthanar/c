#include <stdio.h>
#include <string.h>

void test1() {
   char data[] = "(2,11)";
   char * option = data;
   int x, y;
   if(sscanf(option, "(%d,%d)", &x, &y) == 2) {
       printf("--%d--%d--\n", x, y);
   }
}


int main(){

    test1();
    return 0;
}