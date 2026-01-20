#pragma once
#include "common.h"

struct AIPlayPhaseCommand {
    uchar groupValue;
    uchar typeValue;
    int value1Value;
    int value2Value;
    int value3Value;
};
static_assert(sizeof(AIPlayPhaseCommand) == 0x10, "Size mismatch");
