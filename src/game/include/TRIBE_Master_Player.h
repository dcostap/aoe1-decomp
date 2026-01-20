#pragma once
#include "common.h"
#include "RGE_Master_Player.h"

class TRIBE_Master_Player : public RGE_Master_Player {
public:
    // Virtuals (best-effort)
    virtual ~TRIBE_Master_Player(); // vt[0] (0x0)
    virtual void finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3); // vt[1] (0x4)
    virtual void load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt[2] (0x8)
    virtual void create_master_object_space(short param_1); // vt[3] (0xC)
    virtual void load_object(FILE* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt[4] (0x10)
    virtual void save(int param_1); // vt[5] (0x14)

};
static_assert(sizeof(TRIBE_Master_Player) == 0x2C, "Size mismatch");
