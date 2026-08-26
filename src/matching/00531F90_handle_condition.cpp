// RGE_Victory_Conditions::handle_condition
// VA: 00531F90
// victory.cpp:400-455
// MATCH: 0.0000% diff, 13 relocations masked
// - PDB line-order probe: the original source emits labels in the order 0,1,8,2,3,9,10,
//   4,5,6,7,12. Reordering the switch labels to that source order restores all 12 direct
//   call targets and exact bytes in the standalone check.

#include "../../include/game_globals.h"

#ifndef VICTORY_CONTEXT_H
struct RGE_Victory_Entry {
    unsigned char command; // +0x00
};

class RGE_Victory_Conditions {
public:
    void handle_capture(RGE_Victory_Entry* entry);
    void handle_create(RGE_Victory_Entry* entry);
    void handle_destroy(RGE_Victory_Entry* entry);
    void handle_destroy_multiple(RGE_Victory_Entry* entry);
    void handle_bring_area(RGE_Victory_Entry* entry);
    void handle_bring_object(RGE_Victory_Entry* entry);
    void handle_attribute(RGE_Victory_Entry* entry);
    void handle_explore(RGE_Victory_Entry* entry);
    void handle_create_in_area(RGE_Victory_Entry* entry);
    void handle_destroy_all(RGE_Victory_Entry* entry);
    void handle_destroy_player(RGE_Victory_Entry* entry);
    void handle_victory_points(RGE_Victory_Entry* entry);

    void handle_condition(RGE_Victory_Entry* entry);
};
#endif

void RGE_Victory_Conditions::handle_condition(RGE_Victory_Entry* entry) {
    switch (entry->command) {
    case 0:
        handle_capture(entry);
        return;
    case 1:
        handle_create(entry);
        return;
    case 8:
        handle_create_in_area(entry);
        return;
    case 2:
        handle_destroy(entry);
        return;
    case 3:
        handle_destroy_multiple(entry);
        return;
    case 9:
        handle_destroy_all(entry);
        return;
    case 10:
        handle_destroy_player(entry);
        return;
    case 4:
        handle_bring_area(entry);
        return;
    case 5:
        handle_bring_object(entry);
        return;
    case 6:
        handle_attribute(entry);
        return;
    case 7:
        handle_explore(entry);
        return;
    case 12:
        handle_victory_points(entry);
        return;
    }
}
