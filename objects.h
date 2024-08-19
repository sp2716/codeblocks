//objects.h
//Note ANSI C does not have class objects - c++ does.
#include <stdio.h>
//defines the structures of the flow meter in memory for calculations
//bit macros
#define set(a,n)   (a|=(1<<n))
#define reset(a,n) (a&=~(1<<n))
#define toggle(a,n)  (a^=(1<<n))

const int ARR_SIZE = 1024;
const int NUM_PATHS = 4;
const char FORMAT_HEX[] = "%02x\n"; //for single byte output in hex

unsigned char checksum(unsigned char *ptr, size_t sz) {
    unsigned char chk = 0;
    while (sz-- != 0){
        chk -= (*ptr)++;
    }
    return chk;
}

typedef unsigned char uint8_t;

typedef struct Path{
    double TUp;
    double TDn;
    double DeltaT;
    int Performance
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

