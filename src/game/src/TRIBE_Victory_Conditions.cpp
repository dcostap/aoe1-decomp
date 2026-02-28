#include "../include/TRIBE_Victory_Conditions.h"

#include "../include/RGE_Victory_Entry.h"
#include "../include/RGE_Victory_Point_Entry.h"
#include "../include/TRIBE_Player.h"
#include "../include/TRIBE_Player_Tech.h"

// Fully verified. Source of truth: tvictory.cpp.decomp @ 0x0052C920
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* param_1)
    : RGE_Victory_Conditions(param_1) {
}

// Fully verified. Source of truth: tvictory.cpp.decomp @ 0x0052C8F0
TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(RGE_Player* param_1, int param_2, long* param_3, uchar param_4)
    : RGE_Victory_Conditions(param_1, param_2, param_3, param_4) {
}

// Fully verified. Source of truth: tvictory.cpp.decomp @ 0x0052C940
TRIBE_Victory_Conditions::~TRIBE_Victory_Conditions() {}

// TODO: passthrough override retained for linkage; not present in tvictory.cpp.decomp.
void TRIBE_Victory_Conditions::handle_point_condition(RGE_Victory_Point_Entry* param_1) {
    RGE_Victory_Conditions::handle_point_condition(param_1);
}

// Fully verified. Source of truth: tvictory.cpp.decomp @ 0x0052C950
void TRIBE_Victory_Conditions::handle_condition(RGE_Victory_Entry* param_1) {
    if (param_1->command != 'd') {
        RGE_Victory_Conditions::handle_condition(param_1);
        return;
    }
    this->handle_tech(param_1);
}

// TODO: passthrough override retained for linkage; not present in tvictory.cpp.decomp.
char* TRIBE_Victory_Conditions::condition_description(RGE_Victory_Entry* param_1) {
    return RGE_Victory_Conditions::condition_description(param_1);
}

// TODO: passthrough override retained for linkage; not present in tvictory.cpp.decomp.
void TRIBE_Victory_Conditions::save(int param_1) {
    RGE_Victory_Conditions::save(param_1);
}

// Fully verified. Source of truth: tvictory.cpp.decomp @ 0x0052C970
void TRIBE_Victory_Conditions::handle_tech(RGE_Victory_Entry* param_1) {
    if (this->player == nullptr || param_1->state != '\0') {
        return;
    }

    TRIBE_Player* tribe_player = (TRIBE_Player*)this->player;
    short state = tribe_player->tech_tree->get_tech_state((short)param_1->count);
    if (state == 3) {
        param_1->state = '\x02';
    }
}

// Fully verified. Source of truth: tvictory.cpp.decomp @ 0x0052C9B0
uchar TRIBE_Victory_Conditions::add_tech(uchar param_1, long param_2) {
    RGE_Victory_Entry* entry = this->add(param_1, '\0');
    if (entry != nullptr) {
        entry->command = 'd';
        entry->count = param_2;
        return '\x01';
    }
    return '\0';
}
