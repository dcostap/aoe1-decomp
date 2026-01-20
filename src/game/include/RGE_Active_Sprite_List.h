#pragma once
#include "common.h"

class RGE_Active_Sprite_List {
public:
    // Virtuals (best-effort)
    virtual ~RGE_Active_Sprite_List(); // vt[0] (0x0)
    virtual short frame(RGE_Sprite* param_1); // vt[1] (0x4)
    virtual void update(float param_1, float param_2); // vt[2] (0x8)
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // vt[3] (0xC)
    virtual void normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // vt[4] (0x10)
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // vt[5] (0x14)
    virtual uchar is_animating(RGE_Sprite* param_1); // vt[6] (0x18)
    virtual void set_frame(RGE_Sprite* param_1, short param_2); // vt[7] (0x1C)
    virtual uchar frame_passed(RGE_Sprite* param_1, short param_2); // vt[8] (0x20)
    virtual uchar looped(RGE_Sprite* param_1); // vt[9] (0x24)
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2); // vt[10] (0x28)
    virtual uchar load_node(int param_1, uchar param_2, RGE_Sprite** param_3); // vt[11] (0x2C)

    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;
};
static_assert(sizeof(RGE_Active_Sprite_List) == 0xC, "Size mismatch");
