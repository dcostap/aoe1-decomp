#ifndef AOE1_TEFFECTS_H
#define AOE1_TEFFECTS_H

#include "effects_context.h"

class RGE_Player;

// This module only needs the direct tech_abling call surface.  The complete
// TRIBE_Player layout belongs to the player source modules.
class TRIBE_Player {
public:
    void tech_abling(long tech_value, unsigned char enable);
};

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
