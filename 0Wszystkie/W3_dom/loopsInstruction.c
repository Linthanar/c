#include <stdio.h>
#include <stdbool.h>

int main(){
int b=0;
int i;
for (i = 0; i<3 ; i++){
    printf("for loop: %d\n",i);
}
int j=0;

printf("\n____________\n");
while (j<3){
    printf(">>for loop: %d\n",j);
    j++; 
    if(j==3){/*continue;*/}
    printf("for loop: %d\n",j);
} 

j=0;
printf("\n____________\n");
while (j<3){
    printf(">>for loop: %d\n",j);
    j++; 
    if(j==3){continue;}
    printf("for loop: %d\n",j);
} 

for(;;){
    printf("Hello world!!!\n");    
    goto BrakeToReturn;
}


BrakeToReturn:
return 0;
}