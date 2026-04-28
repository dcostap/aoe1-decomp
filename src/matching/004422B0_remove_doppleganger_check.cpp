// 004422B0 RGE_Doppleganger_Creator::remove_doppleganger_check (dpl_obj.cpp:589-623)
// Attempt 1: natural C++ with class layout from type dump

#include <stdio.h>

// Forward declare RGE_Game_World for world_time access
struct RGE_Game_World {
    char gap_00[4];              // +0x00: vtable ptr
    unsigned long world_time;    // +0x04
};

// RGE_Player stub — only fields we access
struct RGE_Player {
    char gap_00[0x3C];           // +0x00 to +0x3B
    RGE_Game_World* world;       // +0x3C
    char gap_40[0x0A];           // +0x40 to +0x49
    short id;                    // +0x4A
};

// RGE_Static_Object stub — only field we access: id at +0x04
struct RGE_Static_Object {
    char gap_00[4];              // +0x00: vtable ptr
    long id;                     // +0x04
};

// RGE_Doppleganger_Creator class
class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;              // +0x00
    int allocated_size;             // +0x04
    int active_size;                // +0x08
    RGE_Static_Object** Objects;    // +0x0C
    unsigned long** Map_Addresses;  // +0x10
    unsigned long* Last_Map_Value;  // +0x14
    int* Object_ids;                // +0x18

    int remove_doppleganger_check(RGE_Static_Object* obj);
};

extern FILE* DDlogf;  // 62E638h

int RGE_Doppleganger_Creator::remove_doppleganger_check(RGE_Static_Object* obj)
{
    if (DDlogf) {
        fprintf(DDlogf, "RDC (@%d)  p=%d  id=%d\n",
                owner->world->world_time, owner->id, obj->id);
    }

    if (active_size <= 0)
        return 0;

    for (int i = 0; i < active_size; i++) {
        if (Objects[i] == obj) {
            active_size--;
            if (i < active_size) {
                Objects[i] = Objects[active_size];
                Map_Addresses[i] = Map_Addresses[active_size];
                Last_Map_Value[i] = Last_Map_Value[active_size];
                Object_ids[i] = Object_ids[active_size];
            }
            Objects[active_size] = 0;
            Map_Addresses[active_size] = 0;
            Last_Map_Value[active_size] = 0;
            Object_ids[active_size] = 0;
            return 1;
        }
    }

    return 0;
}
