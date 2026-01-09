#pragma once
#include "common.h"

class TRIBE_Master_Player : public RGE_Master_Player {
public:

    virtual void load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt0[2]+0x8=0x511830
    virtual void load_object(_iobuf* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt0[4]+0x10=0x511990
    TRIBE_Master_Player(_iobuf* param_1);
    TRIBE_Master_Player(int param_1);
    ~TRIBE_Master_Player();
};

static_assert(sizeof(TRIBE_Master_Player) == 0x2C, "TRIBE_Master_Player Size Mismatch");

