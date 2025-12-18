#include <stdio.h>
#include <math.h>

int main() {
    float a = 0.1; /*jest tak poniewaz float jest nie dokładny*/
    if (fabs(a-0.1)< 1e-6) {

        printf("a jest równe 0.1\n");
    } else {
        printf("a nie jest równe 0.1\n");
    }
    return 0;
}
