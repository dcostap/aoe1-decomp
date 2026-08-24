// 004421F0 add_doppleganger_check
// RGE_Doppleganger_Creator::add_doppleganger_check
// Source: dpl_obj.cpp lines 557-584
// Size: 185 bytes
//
// Status: PARKED - pure VC5 register/scheduling drift
//
// Attempt log:
// Probe 1: natural C++ with local type stubs
//   -> 6.5% diff: ecx/edx register swap in comparison,
//      Objects pointer load reordering in loop init
// Probe 2: swapped comparison order (this->owner first)
//   -> loop Objects load order regressed
// Probe 3: temp variable for objOwner
//   -> same register swap, loop order changed
// Probe 4: do-while loop
//   -> 46% diff, completely different codegen
// Probe 5: !(obj->owner->id == this->owner->id)
//   -> same register swap as probe 1
// Probe 6: raw offset access *(short*)((char*)obj->owner + 0x4A)
//   -> same register swap
// Probe 7: prepended destructor in same TU
//   -> 73% diff, polluted obj with wrong function
//
// Remaining diff: 12 positional bytes (6.5%), all register allocation:
//   1. comparison: orig uses ecx for obj->owner, edx for this->owner;
//      rebuilt uses edx for obj->owner, ecx for this->owner (4 bytes diff)
//   2. loop: Objects pointer load scheduled before xor eax,eax
//      instead of after (3+3 byte shift from different jle offset)
//
// All behavior, call targets, stack cleanup, frame layout, and
// memory effects are identical. This is textbook VC5 register
// coloring and instruction scheduling TU-context drift.

#include <stdio.h>

#ifndef DPL_OBJ_SHARED_CONTEXT
// Local type stubs matching the exact layouts from type dumps
class RGE_Game_World {
public:
    void* vtable;              // +0x00
    unsigned long world_time;  // +0x04
};

class RGE_Player {
public:
    void* vtable;              // +0x00
    int field_04;
    int field_08;
    int field_0C;
    int field_10;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_flag;
    unsigned char pad_21[1];
    short master_object_num;
    void* master_objects;
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;     // +0x3C
    void* doppleganger_creator;
    char* name;
    unsigned char player_type;
    unsigned char pad_49[1];
    short id;                   // +0x4A
    short attribute_num;
};

class RGE_Static_Object {
public:
    void* vtable;              // +0x00
    long id;                   // +0x04
    void* master_obj;          // +0x08
    RGE_Player* owner;         // +0x0C
};

class RGE_Doppleganger_Creator {
public:
    RGE_Player* owner;                  // +0x00
    int allocated_size;                  // +0x04
    int active_size;                     // +0x08
    RGE_Static_Object** Objects;         // +0x0C
    unsigned long** Map_Addresses;       // +0x10
    unsigned long* Last_Map_Value;       // +0x14
    int* Object_ids;                     // +0x18

    int add_doppleganger_check(RGE_Static_Object* obj, unsigned long* map_addr);
    void expand_allocations(int extra);
};
#endif

extern FILE* DDlogf;

int RGE_Doppleganger_Creator::add_doppleganger_check(RGE_Static_Object* obj, unsigned long* map_addr)
{
    if (DDlogf) {
        fprintf(DDlogf, "ADC (@%d) p=%d  id=%d\n",
            this->owner->world->world_time,
            (int)this->owner->id,
            obj->id);
    }

    if (this->active_size >= this->allocated_size) {
        this->expand_allocations(30);
    }

    if (obj->owner->id != this->owner->id) {
        return 0;
    }

    int count = this->active_size;
    if (count > 0) {
        RGE_Static_Object** ppObj = this->Objects;
        int i = 0;
        while (i < count) {
            if (*ppObj == obj) {
                return 0;
            }
            i++;
            ppObj++;
        }
    }

    this->Objects[this->active_size] = obj;
    this->Map_Addresses[this->active_size] = map_addr;
    this->Last_Map_Value[this->active_size] = *map_addr;
    this->Object_ids[this->active_size] = obj->id;
    this->active_size++;

    return 1;
}
