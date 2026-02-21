#pragma once
#include "common.h"
#include "VISIBLE_RESOURCE_REC.h"

struct RGE_Tile_List;

struct Visible_Resource_Manager {
    void Process_New_Tiles(RGE_Tile_List* param_1);
    void AddResource(int param_1, int param_2);
    int Remove_Resource(int param_1, int param_2);

    VISIBLE_RESOURCE_REC** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;
};
static_assert(sizeof(Visible_Resource_Manager) == 0x14, "Size mismatch");
