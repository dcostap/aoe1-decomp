#pragma once
#include "common.h"
#include "TRIBE_Player.h"

class TRIBE_Gaia : public TRIBE_Player {
public:
    TRIBE_Gaia(RGE_Game_World* world, RGE_Master_Player* master, uchar player_id, char* name, uchar type);
    TRIBE_Gaia(int param_1, RGE_Game_World* world, uchar player_id);

    // Only overrides that TRIBE_Gaia actually implements go here.
    // All other virtuals are inherited from TRIBE_Player.
    virtual ~TRIBE_Gaia();
    virtual void update(); // overrides TRIBE_Player::update

    float update_time;  // shadows TRIBE_Player::update_time at +0x848
    long update_nature;
    long last_count;
    long animal_max;
};
static_assert(sizeof(TRIBE_Gaia) == 0x858, "Size mismatch");
