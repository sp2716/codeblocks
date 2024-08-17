//objects.h
#include <stdio.h>
//defines the structures of the flow meter in memory for calculations

typedef struct Path{
    double TUp;
    double TDn;
    double DeltaT;
} path_t;

typedef struct {
    double MassFlow;
    double VolumeFlow;
} result_t;

typedef enum SexTypes{
    Male = 0,
    Female = 1
} SexItem;

typedef struct {
    char Name;
    int Age;
    enum SexTypes mySex;
} person_t;

