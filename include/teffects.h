#ifndef AOE1_TEFFECTS_H
#define AOE1_TEFFECTS_H

#include "effects.h"

class TRIBE_Effects : public RGE_Effects {
public:
    virtual ~TRIBE_Effects();
    virtual void save(int file);
    virtual void do_effect(short effect_id, RGE_Player* player);

    TRIBE_Effects(int file);
    TRIBE_Effects(char* path);
    void do_tech_effect(short effect_id, RGE_Player* player);
};

typedef char teffects_tribe_effects_size_check[
    (sizeof(TRIBE_Effects) == 0x0C) ? 1 : -1];

#endif
