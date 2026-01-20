#pragma once
#include "common.h"

struct TCommunications_Services {
    SPs Service[100];
    int ServiceCount;
};
static_assert(sizeof(TCommunications_Services) == 0x2584, "Size mismatch");
