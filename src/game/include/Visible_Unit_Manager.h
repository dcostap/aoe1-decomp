#pragma once
#include "common.h"
#include "VISIBLE_UNIT_PTR.h"
#include "VISIBLE_UNIT_REC.h"

struct Visible_Unit_Manager {
    Visible_Unit_Manager(int param_1, int param_2);
    ~Visible_Unit_Manager();

    void Build_Distance_Table();
    void Update_Unit_Info(int param_1, int param_2, int param_3, int param_4, int param_5, ulong param_6, ulong param_7, VISIBLE_UNIT_REC** param_8);
    int GetVisibleUnits(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6, int* param_7);

    VISIBLE_UNIT_PTR** PlayerDataPtrs;
    VISIBLE_UNIT_REC* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    uchar* distanceTable;
};
static_assert(sizeof(Visible_Unit_Manager) == 0x24, "Size mismatch");
