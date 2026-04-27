// 00442100 RGE_Doppleganger_Creator::RGE_Doppleganger_Creator
// Source: dpl_obj.cpp lines 515-533
// Size: 119 bytes
//
// Attempt log:
// Probe 1: natural C++

#include "..\..\include\game_globals.h"

extern void* __cdecl calloc(int num, int size);
extern int __cdecl initSomething(char* str1, char* str2);

class RGE_Doppleganger_Creator {
public:
    void* player;               // +0x00
    int maxCount;               // +0x04
    int field08;                // +0x08
    int* array0C;               // +0x0C
    int* array10;               // +0x10
    int* array14;               // +0x14
    int* array18;               // +0x18

    RGE_Doppleganger_Creator(void* player, int count);
};

RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(void* player, int count)
{
    this->array0C = (int*)calloc(4, count);
    this->array10 = (int*)calloc(4, count);
    this->array14 = (int*)calloc(4, count);
    this->array18 = (int*)calloc(4, count);
    this->maxCount = count;
    this->field08 = 0;
    this->player = player;
}
