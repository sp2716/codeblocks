#include <stdio.h>
#include "objects.h"

const int NUM_PATHS = 4;

int main()
{



    path_t paths[NUM_PATHS];
    paths[0].DeltaT = 1000.123;
    paths[2].TDn = 100000.234;

    result_t Results;

    Results.MassFlow = 0xF0E9 >> 0xFF;


    for(int i = 0; i < NUM_PATHS; i++){
        printf("Path %d Delta: %f \r\n",i+1,paths[i].DeltaT);
        printf("Path %d TDn: %f \r\n",i+1,paths[i].TDn);
        printf("Path %d TUp: %f \r\n",i+1,paths[i].TUp);
        printf("the path %d object is at memory address %08x\r\n",i+1,&paths[i]);
        Deliver(&paths[i]);
    };

    printf("%f",Results.MassFlow);

    return 0;
}

void Deliver(path_t path){
    printf("memory address of function is %x\r\n",&path);
    if(path.DeltaT > 1000){
        printf("Here is a DeltaT > 1000: %f\r\n",path.DeltaT);
    }
}