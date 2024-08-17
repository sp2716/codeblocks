#include <stdio.h>
#include "objects.h"

const int NUM_PATHS = 4;
const int ARR_SIZE = 1024;
int main()
{
    unsigned int ints[1024];
    int* bufptr = &ints;
    int length = sizeof(ints)/sizeof(ints[0]);
    for(unsigned int i = 0; i < length; i++){
        ints[i] = i;
    }
    printf("pointer of buffer is at %p and size is %d\n",bufptr, length);
    printf("Contents of buffer as follows:\n");
    ToHex(bufptr,length);
    person_t Vinny;
    Vinny.Name = "Vincent";
    Vinny.Age = 5;
    Vinny.Gender = Male;
    Birthday(&Vinny);
    SexChange(&Vinny);
    printf("birthday made him %d years old %d",Vinny.Age,Vinny.Gender);

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
    };

    printf("%f",Results.MassFlow);
    return 0;
}

void ToHex(int buf[], int len){

    for(int i = 0; i < len; i++){
        printf("%08X", buf[i]); // 08X => 8 hex characters = 4 bytes
    }
    printf("\n");
}
//Passing/manipulating a variable by reference here using pointers
//Remember that the arrow can be overridden but (*person).propertyName cannot be overridden
void Birthday(person_t* person){
    (*person).Age++;
}

void SexChange(person_t* person){
    if(person->Gender == Male){
        person->Gender = Female; //don't need the GenderTypes.Female like c#
    } else{
        (*person).Gender = Male; //this is the same as person->Gender = Male;
    }
}
