#pragma once
#include "common.h"

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    ulong last_attack_time;                  // 0x16C
    int flash_on;                            // 0x170

    virtual void set_redraw(RedrawMode param_1);            // vt0[8]+0x20=0x52CA30
    virtual void draw_objects();                            // vt0[57]+0xE4=0x52CA60
    virtual void draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5); // vt0[59]+0xEC=0x52CAB0
    TRIBE_Diamond_Map_View();
    ~TRIBE_Diamond_Map_View();
};

static_assert(sizeof(TRIBE_Diamond_Map_View) == 0x174, "TRIBE_Diamond_Map_View Size Mismatch");

