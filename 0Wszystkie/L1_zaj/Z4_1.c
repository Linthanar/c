#include <stdio.h>


int main() {
    int x = 5;
    if (x == 5) {
        x = 10;  /*pokręcone ale działa */
    } else if (x == 10) {
        printf("x jest równe 10\n");
    }
    return 0;
}
