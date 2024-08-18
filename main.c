#include <stdio.h>
#include "objects.h"
#define Bitset(var,bitno) ((var) |=1UL<<(bitno))
typedef unsigned char uint8_t;

const int ARR_SIZE = 1024;
const int NUM_PATHS = 4;

int main()
{
    printf("Initializing application\n");
    uint8_t bytes[256];
    int* bufptr = &bytes;
    printf("Initialized buffer\n");

    int test = 0;
    printf("%d\n",test);
    Bitset(test,0);
    printf("%d\n",test);
    Bitset(test,1);
    printf("%d\n",test);
    Bitset(test,0);
    printf("%d\n",test);


    int length = sizeof(bytes)/sizeof(bytes[0]);
    uint8_t j = 0;
    for(int i = 0; i < length; i++){
        Bitset(bytes[i],j);
        j++;
        if(j > 7){
            j = 0;
        }
    }
    printf("pointer of buffer is at %p and size is %d\n",bufptr, length);
    printf("Contents of buffer as follows:\n");
    ToHex(bufptr,length);
    return 0;


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

void ToHex(uint8_t buf[], int len){

    for(int i = 0; i < len; i++){
        printf("%02X", buf[i]); // 08X => 8 hex characters = 4 bytes
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
