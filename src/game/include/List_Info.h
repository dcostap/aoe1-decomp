#pragma once
#include "common.h"

struct List_Info {
    char text[100];
    short id;
};
static_assert(sizeof(List_Info) == 0x66, "Size mismatch");
