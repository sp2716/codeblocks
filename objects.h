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

typedef enum GenderTypes {
    Male = 0,
    Female = 1
} GenderItem;

typedef struct Person{
    char Name;
    int Age;
    enum GenderTypes Gender;
} person_t;

