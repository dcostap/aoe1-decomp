// VA: 00449440 RGE_Effects::~RGE_Effects
// effects.cpp lines 134-149
// 99 bytes

#include "../../include/effects_context.h"

extern void free(void* p);

RGE_Effects::~RGE_Effects() {
    for (short i = 0; i < effect_num; i++) {
        if (effects[i].effect_list != 0) {
            free(effects[i].effect_list);
        }
        effects[i].effect_list = 0;
    }
    if (effects != 0) {
        free(effects);
        effects = 0;
    }
    effect_num = 0;
}
