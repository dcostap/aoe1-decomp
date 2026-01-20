#pragma once
#include "common.h"

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};
static_assert(sizeof(Map_Stack) == 0x18, "Size mismatch");
