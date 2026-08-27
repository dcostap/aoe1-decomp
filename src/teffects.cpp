#include "../include/teffects.h"

// PDB source order for C:\\msdev\\work\\age1_x1\\teffects.cpp.

TRIBE_Effects::TRIBE_Effects(int param) : RGE_Effects(param) {
}

TRIBE_Effects::TRIBE_Effects(char* param) : RGE_Effects(param) {
}

void TRIBE_Effects::do_effect(short param_1, RGE_Player* player) {
    int index = param_1;
    if (index >= this->effect_num) {
        return;
    }

    unsigned char* base = (unsigned char*)this->effects;
    int scaled = index + index * 4;
    int recIndex = index + scaled * 2;
    unsigned char* record = base + recIndex * 4;
    if (record == 0) {
        return;
    }

    int i = 0;
    if (*(short*)(record + 0x24) > 0) {
        int offset = 0;
        do {
            unsigned char* effect = *(unsigned char**)(record + 0x28) + offset;
            unsigned int kind = *effect;
            switch (kind) {
            case 0x65:
                break;
            case 0x66:
                ((TRIBE_Player*)player)->tech_abling((long)*(float*)(effect + 8), 0);
                break;
            }
            i++;
            offset += 0x0C;
        } while (i < *(short*)(record + 0x24));
    }

    RGE_Effects::do_effect(param_1, player);
}

void TRIBE_Effects::do_tech_effect(short tech_id, RGE_Player* player) {
    int index = tech_id;
    unsigned char* base = (unsigned char*)this->effects;
    int scaled = index + index * 4;
    int recIndex = index + scaled * 2;
    unsigned char* record = base + recIndex * 4;
    int i = 0;

    if (*(short*)(record + 0x24) > 0) {
        int offset = 0;
        do {
            unsigned char* effect = *(unsigned char**)(record + 0x28) + offset;
            unsigned int kind = *effect;
            switch (kind) {
            case 0x65:
                break;
            case 0x66:
                ((TRIBE_Player*)player)->tech_abling((long)*(float*)(effect + 8), 0);
                break;
            }
            i++;
            offset += 0x0C;
        } while (i < *(short*)(record + 0x24));
    }
}
