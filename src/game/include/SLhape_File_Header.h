#pragma once
#include "common.h"

struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};
static_assert(sizeof(SLhape_File_Header) == 0x20, "Size mismatch");
