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
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void random_start();
    virtual void scenario_postload(int param_1, long* param_2, float param_3);
    virtual void save(int param_1);
    void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);

    float update_time;  // shadows TRIBE_Player::update_time at +0x848
    long update_nature;
    long last_count;
    long animal_max;
};
static_assert(sizeof(TRIBE_Gaia) == 0x858, "Size mismatch");
