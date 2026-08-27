// PDB source module: C:\\msdev\\work\\age1_x1\\tvictory.cpp.
// The six handwritten owners stay in PDB source order.

#include "../include/tvictory.h"
#include "../include/tplayer.h"
#include "../include/tech.h"

// 0052C8F0; tvictory.cpp lines 30-31.
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(
    RGE_Player* player, int value, long* data, unsigned char flag)
    : RGE_Victory_Conditions(player, value, data, flag) {
}

// 0052C920; tvictory.cpp lines 37-38.
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* player)
    : RGE_Victory_Conditions(player) {
}

// 0052C940; tvictory.cpp line 43.
TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions() {
}

// 0052C950; tvictory.cpp lines 49-59.
void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* entry) {
    if (entry->command != 'd') {
        RGE_Victory_Conditions::handle_condition(entry);
        return;
    }
    handle_tech(entry);
}

// 0052C970; tvictory.cpp lines 63-67.
void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* entry) {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->player);
    if ((player != 0) && (entry->state == 0)) {
        if (player->tech_tree->get_tech_state(entry->count) == 3) {
            entry->state = 2;
        }
    }
}

// 0052C9B0; tvictory.cpp lines 71-83.
unsigned char TRIBE_Victory_Conditions::add_tech(unsigned char id, long count) {
    RGE_Victory_Entry* entry;

    entry = this->add(id, 0);
    if (entry != 0) {
        entry->command = 0x64;
        entry->count = count;
        return 1;
    }
    return 0;
}
