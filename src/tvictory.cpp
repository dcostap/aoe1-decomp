
#include "../include/tvictory.h"
#include "../include/tplayer.h"
#include "../include/tech.h"

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(
    RGE_Player* player, int value, long* data, unsigned char flag)
    : RGE_Victory_Conditions(player, value, data, flag) {
}

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* player)
    : RGE_Victory_Conditions(player) {
}

TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions() {
}

void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* entry) {
    if (entry->command != 'd') {
        RGE_Victory_Conditions::handle_condition(entry);
        return;
    }
    handle_tech(entry);
}

void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* entry) {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->player);
    if ((player != 0) && (entry->state == 0)) {
        if (player->tech_tree->get_tech_state(entry->count) == 3) {
            entry->state = 2;
        }
    }
}

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
