#pragma once
#include "common.h"

struct Visible_Resource_Manager {
    VISIBLE_RESOURCE_REC** VR_List;
    int* VR_ListSize;
    int* VR_ListUsed;
    RGE_Player* owner;
    int num_visible_resource_lists;
};
static_assert(sizeof(Visible_Resource_Manager) == 0x14, "Size mismatch");
