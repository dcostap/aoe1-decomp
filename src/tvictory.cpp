
#include "../include/tvictory.h"
#include "../include/tplayer.h"
#include "../include/tech.h"

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(
    RGE_Player* in_player, int infile, long* player_id_hash, unsigned char version_control
) : RGE_Victory_Conditions(in_player, infile, player_id_hash, version_control) {
}

TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* in_Player) : RGE_Victory_Conditions(in_Player) {
}

TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions() {
}

void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* node) {
    if (node->command != 'd') {
        RGE_Victory_Conditions::handle_condition(node);
        return;
    }
    handle_tech(node);
}

void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* node) {
    TRIBE_Player* player = static_cast<TRIBE_Player*>(this->player);
    if ((player != 0) && (node->state == 0)) {
        if (player->tech_tree->get_tech_state(node->count) == 3) {
            node->state = 2;
        }
    }
}

unsigned char TRIBE_Victory_Conditions::add_tech(unsigned char v_group, long tech_id) {
    RGE_Victory_Entry* entry;

    entry = this->add(v_group, 0);
    if (entry != 0) {
        entry->command = 0x64;
        entry->count = tech_id;
        return 1;
    }
    return 0;
}
