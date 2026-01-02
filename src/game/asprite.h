#pragma once
#include "../common.h"

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;                             // 0x14
    float animate_interval;                  // 0x18
    float animate_last;                      // 0x1C
    short last_frame;                        // 0x20
    uchar frame_changed;                     // 0x22
    uchar frame_looped;                      // 0x23
    uchar animate_flag;                      // 0x24

    RGE_Active_Animated_Sprite(RGE_Sprite* param_1);
    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
    virtual ~RGE_Active_Animated_Sprite();
    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6);
    virtual short what_frame();
    virtual uchar is_animating();
    virtual void set_frame(short param_1);
    virtual uchar frame_passed(short param_1);
    virtual uchar looped();
    virtual short get_facetindex(short param_1);
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5);
    virtual void setToFirstFrame();
};

static_assert(sizeof(RGE_Active_Animated_Sprite) == 0x28, "RGE_Active_Animated_Sprite Size Mismatch");
static_assert(offsetof(RGE_Active_Animated_Sprite, animate_flag) == 0x24, "RGE_Active_Animated_Sprite Offset Mismatch");

class RGE_Active_Sprite {
public:
    RGE_Sprite* sprite;                      // 0x4
    uchar type;                              // 0x8
    long offset_x;                           // 0xC
    long offset_y;                           // 0x10

    RGE_Active_Sprite(RGE_Sprite* param_1);
    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
    virtual ~RGE_Active_Sprite();
    virtual void set_offset(long param_1, long param_2);
    virtual void save(int param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6);
    virtual short what_frame();
    virtual void set_frame(short param_1);
    virtual uchar is_animating();
    virtual uchar frame_passed(short param_1);
    virtual uchar looped();
    virtual short get_facetindex(short param_1);
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5);
    virtual uchar get_lowest_draw_level();
    virtual void setToFirstFrame();
    virtual int check_for_shadows();
};

static_assert(sizeof(RGE_Active_Sprite) == 0x14, "RGE_Active_Sprite Size Mismatch");
static_assert(offsetof(RGE_Active_Sprite, offset_y) == 0x10, "RGE_Active_Sprite Offset Mismatch");

