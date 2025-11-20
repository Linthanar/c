#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
 
    const char *test = "[2,7,11,15]";
    long int x;
    char *end_ptr;
    x = strtol(&test[1],&end_ptr,10);
    printf("%ld\n",x);
    printf("%p\n",(void*)end_ptr);
    printf("%p\n",&test[2]);

    // const char *string = "  11oho1";
    // char tab_str[256] = "oo11oho1";
    // printf("%zu %d", (size_t)(unsigned)strlen(tab_str), atoi(string));
    return 0;
}