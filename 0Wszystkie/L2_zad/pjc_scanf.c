#include <stdio.h>
 int main(void)
 {
   int result, n;
   do
   {
     result = scanf("%d", &n);
     if (result==1)
     {
       printf("%d\n", n*n*n);
     }
     else if (!result) { /* !result to to samo co result==0 */
       result = scanf("%*s");
} }
   while (result!=EOF);
return 0; }