#pragma once
#include "../common.h"

class TRIBE_Diamond_Map_View : public RGE_Diamond_Map_View {
public:
    ulong last_attack_time;                  // 0x16C
    int flash_on;                            // 0x170

    TRIBE_Diamond_Map_View();
    virtual ~TRIBE_Diamond_Map_View();
    virtual void set_redraw(RedrawMode param_1);
    virtual void draw_objects();
    virtual void draw_object(short param_1, short param_2, uchar param_3, short param_4, RGE_Static_Object* param_5);
};

static_assert(sizeof(TRIBE_Diamond_Map_View) == 0x174, "TRIBE_Diamond_Map_View Size Mismatch");
static_assert(offsetof(TRIBE_Diamond_Map_View, flash_on) == 0x170, "TRIBE_Diamond_Map_View Offset Mismatch");

