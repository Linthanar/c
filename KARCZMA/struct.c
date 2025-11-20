#include <stdio.h>
#include <string.h>

typedef struct{
    char name[50];
    char id[10];
    int age;
    int grades[5];

}student;

int main(){

    student fresnel;

    strcpy(fresnel.name, "fresnel");
    strcpy(fresnel.id, "16121815");
    
    fresnel.age = 40;
    fresnel.grades[0]=4;
 
    printf("Age %d\n",fresnel.age);
    printf("name: %s\n",fresnel.name);
    printf("id %s\n",fresnel.id);


    return 0;
}