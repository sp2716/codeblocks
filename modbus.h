//modbus header file provides definitions for modbus.c
#include <stdio.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;

typedef struct modbus_query{

    uint8_t id;
    uint8_t fnc;

}modbus_query_t;
