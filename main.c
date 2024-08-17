#include <stdio.h>
#include "objects.h"

const int NUM_PATHS = 4;

int main()
{
    person_t Vinny;
    Vinny.Name = "Vincent";
    Vinny.Age = 5;
    Vinny.Gender = Male;
    Birthday(&Vinny);
    SexChange(&Vinny);
    printf("birthday made him %d years old %d",Vinny.Age,Vinny.Gender);
    return 0;

    path_t paths[NUM_PATHS];
    paths[0].DeltaT = 1234.123;
    paths[2].TDn = 100000.234;

    result_t Results;

    printf("%f",Results.MassFlow);

    for(int i = 0; i < NUM_PATHS; i++){
        printf("Path %d Delta: %f \r\n",i+1,paths[i].DeltaT);
        printf("Path %d TDn: %f \r\n",i+1,paths[i].TDn);
        printf("Path %d TUp: %f \r\n",i+1,paths[i].TUp);
        printf("the path %d object is at memory address %p\r\n",i+1,&paths[i]);
        Deliver(&paths[i]);
    };

    printf("%f",Results.MassFlow);

    return 0;
}

void Birthday(person_t* person){
    person->Age++;
}

void SexChange(person_t* person){
    if(person->Gender == Male){
        person->Gender = Female; //don't need the GenderTypes.Female like c#
    } else{
        (*person).Gender = Male; //this is the same as person->Gender = Male;
    }
}
