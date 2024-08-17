#include <stdio.h>
#include "objects.h"

const int NUM_PATHS = 4;
const int ARR_SIZE = 1024;
int main()
{
    char* bytes = (char*)malloc(ARR_SIZE);
    char* bufptr = &bytes;

    int j = 0;

    printf("pointer of buffer is at %p and size is %p\n",bufptr, sizeof(bytes));
    printf("Contents of buffer as follows:\n");
        for(int i = 0; i < ARR_SIZE; i++){
        j++;
        bytes[i] = j;
    }
    ToHex(bytes, ARR_SIZE);
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

void ToHex(char* buf, int length){
    int len = sizeof(buf);
    char* result = (char*)malloc(len * 2 * sizeof(char));
    int resPos = 0;
    for(int i = 0; i < length; i++){
        printf("%02X", buf[i]);
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
