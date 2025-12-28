#pragma once
#include "../types.h"

struct VISIBLE_RESOURCE_REC {
    int object_id;
    uchar distance;
    uchar zone;
    uchar pos_x;
    uchar pos_y;
};

class Visible_Resource_Manager {
public:
    VISIBLE_RESOURCE_REC **VR_List;
    int *VR_ListSize;
    int *VR_ListUsed;
    class RGE_Player *owner;
    int num_visible_resource_lists;

    Visible_Resource_Manager(class RGE_Player *player, int num_lists);
    ~Visible_Resource_Manager();
};

static_assert(sizeof(Visible_Resource_Manager) == 20, "Visible_Resource_Manager size mismatch");
