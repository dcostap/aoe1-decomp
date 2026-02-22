#pragma once
#include "common.h"

class RGE_Active_Sprite {
public:
    RGE_Active_Sprite(RGE_Sprite* param_1);
    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);

    // Virtuals (best-effort)
    virtual ~RGE_Active_Sprite(); // vt[0] (0x0)
    virtual void set_offset(long param_1, long param_2); // vt[1] (0x4)
    virtual void save(int param_1); // vt[2] (0x8)
    virtual void update(float param_1, float param_2); // vt[3] (0xC)
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // vt[4] (0x10)
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // vt[5] (0x14)
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // vt[6] (0x18)
    virtual short what_frame(); // vt[7] (0x1C)
    virtual uchar is_animating(); // vt[8] (0x20)
    virtual void set_frame(short param_1); // vt[9] (0x24)
    virtual uchar frame_passed(short param_1); // vt[10] (0x28)
    virtual uchar looped(); // vt[11] (0x2C)
    virtual short get_facetindex(short param_1); // vt[12] (0x30)
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5); // vt[13] (0x34)
    virtual void setToFirstFrame(); // vt[14] (0x38)

    int check_for_shadows();
    unsigned char get_lowest_draw_level();

    RGE_Sprite* sprite;
    unsigned char type;
    long offset_x;
    long offset_y;
};
static_assert(sizeof(RGE_Active_Sprite) == 0x14, "Size mismatch");
