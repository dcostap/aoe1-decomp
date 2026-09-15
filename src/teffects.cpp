#include "../include/effects.h"
#include "../include/teffects.h"
#include "../include/tplayer.h"


TRIBE_Effects::TRIBE_Effects(int infile) : RGE_Effects(infile) {
}

TRIBE_Effects::TRIBE_Effects(char* effect_file) : RGE_Effects(effect_file) {
}

void TRIBE_Effects::do_effect(short current_effect, RGE_Player* player) {
    int index = current_effect;
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

    RGE_Effects::do_effect(current_effect, player);
}

void TRIBE_Effects::do_tech_effect(short current_effect, RGE_Player* player) {
    int index = current_effect;
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
