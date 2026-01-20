#pragma once
#include "common.h"

class RGE_Master_Player {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Master_Player(); // vt[0] (0x0)
    virtual void finish_init(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3); // vt[1] (0x4)
    virtual void load_master_object(int param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt[2] (0x8)
    virtual void create_master_object_space(short param_1); // vt[3] (0xC)
    virtual void load_object(FILE* param_1, uchar param_2, RGE_Sprite** param_3, RGE_Sound** param_4, short param_5); // vt[4] (0x10)
    virtual void save(int param_1); // vt[5] (0x14)

    char name[20];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    float* attributes;
    unsigned char culture;
    unsigned char type;
    short tribe_effect;
};
static_assert(sizeof(RGE_Master_Player) == 0x2C, "Size mismatch");
