#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

void TRIBE_World::base_save(int value) {
    RGE_Game_World::base_save(value);
    this->tech->save(value);
}
