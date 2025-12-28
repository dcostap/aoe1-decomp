#pragma once
#include "../types.h"

struct RGE_Static_Object;

class RGE_Doppleganger_Creator {
public:
    class RGE_Player *owner;
    int allocated_size;
    int active_size;
    RGE_Static_Object **Objects;
    ulong **Map_Addresses;
    ulong *Last_Map_Value;
    int *Object_ids;

    RGE_Doppleganger_Creator(class RGE_Player *player, int size);
    ~RGE_Doppleganger_Creator();
};

static_assert(sizeof(RGE_Doppleganger_Creator) == 28, "RGE_Doppleganger_Creator size mismatch");
