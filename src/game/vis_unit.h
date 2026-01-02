#pragma once
#include "../common.h"

class Visible_Resource_Manager {
public:
    int* VR_ListSize;                        // 0x4
    int* VR_ListUsed;                        // 0x8
    RGE_Player* owner;                       // 0xC
    int num_visible_resource_lists;          // 0x10

    Visible_Resource_Manager(RGE_Player* param_1, int param_2);
    Visible_Resource_Manager(int param_1, RGE_Player* param_2);
    virtual ~Visible_Resource_Manager();
    virtual void save(int param_1);
    virtual void Process_New_Tiles(RGE_Tile_List* param_1);
    virtual void AddResource(int param_1, int param_2);
    virtual int Remove_Resource(int param_1, int param_2);
    virtual VISIBLE_RESOURCE_REC* Get_Closest_Resource(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6);
};

static_assert(sizeof(Visible_Resource_Manager) == 0x14, "Visible_Resource_Manager Size Mismatch");
static_assert(offsetof(Visible_Resource_Manager, num_visible_resource_lists) == 0x10, "Visible_Resource_Manager Offset Mismatch");

class Visible_Unit_Manager {
public:
    VISIBLE_UNIT_REC* Return_Buffer[5];      // 0x4
    int Player_Count;                        // 0x18
    int Category_Count;                      // 0x1C
    uchar* distanceTable;                    // 0x20

    Visible_Unit_Manager(int param_1, int param_2);
    virtual ~Visible_Unit_Manager();
    virtual void Build_Distance_Table();
    virtual void Update_Unit_Info(int param_1, int param_2, int param_3, int param_4, int param_5, ulong param_6, ulong param_7, VISIBLE_UNIT_REC** param_8);
    virtual int GetVisibleUnits(int param_1, int param_2, int param_3, int param_4, int* param_5, int param_6, int* param_7);
};

static_assert(sizeof(Visible_Unit_Manager) == 0x24, "Visible_Unit_Manager Size Mismatch");
static_assert(offsetof(Visible_Unit_Manager, distanceTable) == 0x20, "Visible_Unit_Manager Offset Mismatch");

