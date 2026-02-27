#pragma once
#include "common.h"

struct AIPlayGroup {
    uchar minValue[6];
    uchar maxValue[6];

    AIPlayGroup();
    uchar minimum(int index) const;
    void setMinimum(int index, int value);
    uchar maximum(int index) const;
    void setMaximum(int index, int value);

protected:
    void initialize();
};
static_assert(sizeof(AIPlayGroup) == 0xC, "Size mismatch");
