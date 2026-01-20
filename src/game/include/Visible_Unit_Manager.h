#pragma once
#include "common.h"

struct Visible_Unit_Manager {
    VISIBLE_UNIT_PTR** PlayerDataPtrs;
    VISIBLE_UNIT_REC* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    uchar* distanceTable;
};
static_assert(sizeof(Visible_Unit_Manager) == 0x24, "Size mismatch");
