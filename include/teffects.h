#ifndef AOE1_TEFFECTS_H
#define AOE1_TEFFECTS_H

#include "effects.h"

class TRIBE_Effects : public RGE_Effects {
public:
    virtual void do_effect(short current_effect, RGE_Player* player);

    TRIBE_Effects(int infile);
    TRIBE_Effects(char* effect_file);
    void do_tech_effect(short current_effect, RGE_Player* player);
};

typedef char teffects_tribe_effects_size_check[
    (sizeof(TRIBE_Effects) == 0x0C) ? 1 : -1];

#endif
