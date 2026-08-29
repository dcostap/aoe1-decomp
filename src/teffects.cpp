#include "../include/effects.h"
#include "../include/teffects.h"
#include "../include/tplayer.h"


TRIBE_Effects::TRIBE_Effects(int param) : RGE_Effects(param) {
}

TRIBE_Effects::TRIBE_Effects(char* param) : RGE_Effects(param) {
}

void TRIBE_Effects::do_effect(short param_1, RGE_Player* player) {
    int index = param_1;
    if (index >= this->effect_num) {
        return;
    }

    RGE_Effect* record = &this->effects[index];
    if (record == 0) {
        return;
    }

    int i = 0;
    if (record->effect_list_num > 0) {
        do {
            RGE_Effect_Command* effect = &record->effect_list[i];
            switch (effect->command) {
            case 0x65:
                break;
            case 0x66:
                ((TRIBE_Player*)player)->tech_abling((long)effect->change_amount, 0);
                break;
            }
            i++;
        } while (i < record->effect_list_num);
    }

    RGE_Effects::do_effect(param_1, player);
}

void TRIBE_Effects::do_tech_effect(short tech_id, RGE_Player* player) {
    int index = tech_id;
    RGE_Effect* record = &this->effects[index];
    int i = 0;

    if (record->effect_list_num > 0) {
        do {
            RGE_Effect_Command* effect = &record->effect_list[i];
            switch (effect->command) {
            case 0x65:
                break;
            case 0x66:
                ((TRIBE_Player*)player)->tech_abling((long)effect->change_amount, 0);
                break;
            }
            i++;
        } while (i < record->effect_list_num);
    }
}
