// RGE_Victory_Conditions::handle_points_high_attribute_amount
// VA: 00533410
// victory.cpp:1489-1507
// 95/99 bytes match (4.04% diff). 4 bytes = register swap (ecx↔eax)
// for this->some_ptr and entry->some_index loads at start of body.
// 5+ source forms tried (void* cast, typed struct, float** index,
// load order reversal, local temps) — register allocation invariant.
// 2 relocations masked (__ftol calls).

#include "../../include/game_globals.h"

// Local stubs from inventory analysis
class RGE_Victory_Point_Entry {
public:
    char gap_00;
    unsigned char state;          // +0x01
    char gap_02[2];
    int some_index;               // +0x04
    int initial_amount;           // +0x08
    int points;                   // +0x0C
    int curr_points;              // +0x10
    float curr_attribute_amount;  // +0x14
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* some_ptr;               // +0x0C
    char gap_10[0x0C];
    int tot_victory_points;       // +0x1C

    void handle_points_high_attribute_amount(RGE_Victory_Point_Entry* entry);
};

void RGE_Victory_Conditions::handle_points_high_attribute_amount(RGE_Victory_Point_Entry* entry) {
    if (entry->state != 0) {
        return;
    }

    // Get float from (this->some_ptr->array + entry->some_index)
    int idx = *(int*)((char*)entry + 4);
    float val = *(float*)(*(int*)(*(int*)((char*)this + 0x0C) + 0x50) + idx * 4);
    
    int intVal = (int)val;
    if (entry->curr_attribute_amount < (float)intVal) {
        entry->curr_attribute_amount = (float)intVal;
    }

    int result = (int)(entry->curr_attribute_amount / (float)entry->initial_amount) * entry->points;
    if (result != entry->curr_points) {
        this->tot_victory_points += result - entry->curr_points;
        entry->curr_points = result;
    }
}
