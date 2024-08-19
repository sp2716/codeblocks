#include <stdio.h>
#include <stdlib.h>
#include "objects.h"
#include <pthread.h>
#include <string.h>

int main()
{

    int i, n;
    n = 256;
    uint8_t* ptr = (uint8_t*)calloc(n, sizeof(*ptr));
    if(ptr == NULL){
        return 0;
    }
    printf("Allocated at %p\n",ptr);
    //memset(ptr,255,n); //way quicker than initializing or setting blocks with loop

        // Print the elements of the array
        printf("The elements of the %d element array are: \n",n);
        for (i = 0; i < n; i++) {
            printf("%02x", ptr[i]);
        }

        free(ptr);
    return 0;
    int test = 0;

    printf("Bit set test\n");
    for(int i = 0; i < 8; i++){
            set(test,i);
            printf(FORMAT_HEX,test); //leading zero causes that in output
    }
    printf("bit reset test\n");
    for(int i = 7; i > -1; i--){
        reset(test, i);
        printf(FORMAT_HEX, test);
    }
    printf("toggle on test\n");
    for(int i = 0; i < 8; i++){
        toggle(test, i);
        printf("%x\n", test);
    }
    printf("toggle off test\n");
    for(int i = 7; i > -1; i--){
        toggle(test, i);
        printf("%x\n", test);
    }



    person_t Vinny;
    Vinny.Name = "Vincent";
    Vinny.Age = 5;
    Vinny.Gender = Male;
    Birthday(&Vinny);
    GenderChange(&Vinny);
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

void GenderChange(person_t* person){
    if(person->Gender == Male){
        person->Gender = Female; //don't need the GenderTypes.Female like c#
    } else{
        (*person).Gender = Male; //this is the same as person->Gender = Male;
    }
}
