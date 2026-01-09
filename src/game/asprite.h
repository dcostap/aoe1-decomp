#pragma once
#include "common.h"

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite {
public:
    short frame;                             // 0x14
    float animate_interval;                  // 0x18
    float animate_last;                      // 0x1C
    short last_frame;                        // 0x20
    uchar frame_changed;                     // 0x22
    uchar frame_looped;                      // 0x23
    uchar animate_flag;                      // 0x24

    virtual void save(int param_1);                         // vt0[2]+0x8=0x41B210
    virtual void update(float param_1, float param_2);      // vt0[3]+0xC=0x41B290
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // vt0[4]+0x10=0x41B430
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // vt0[5]+0x14=0x41B4A0
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // vt0[6]+0x18=0x41B4F0
    virtual short what_frame();                             // vt0[7]+0x1C=0x41B520
    virtual uchar is_animating();                           // vt0[8]+0x20=0x41B530
    virtual void set_frame(short param_1);                  // vt0[9]+0x24=0x41B550
    virtual uchar frame_passed(short param_1);              // vt0[10]+0x28=0x41B560
    virtual uchar looped();                                 // vt0[11]+0x2C=0x41B590
    virtual short get_facetindex(short param_1);            // vt0[12]+0x30=0x41B5A0
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5); // vt0[13]+0x34=0x41B5D0
    virtual void setToFirstFrame();                         // vt0[14]+0x38=0x41B600
    RGE_Active_Animated_Sprite(RGE_Sprite* param_1);
    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);
    ~RGE_Active_Animated_Sprite();
};

static_assert(sizeof(RGE_Active_Animated_Sprite) == 0x28, "RGE_Active_Animated_Sprite Size Mismatch");

class RGE_Active_Sprite {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Sprite* sprite;                      // 0x4
    uchar type;                              // 0x8
    long offset_x;                           // 0xC
    long offset_y;                           // 0x10

    virtual void set_offset(long param_1, long param_2);    // vt0[1]+0x4=0x41ADE0
    virtual void save(int param_1);                         // vt0[2]+0x8=0x41AE00
    virtual void update(float param_1, float param_2);      // vt0[3]+0xC=0x41AE50
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // vt0[4]+0x10=0x41AE60
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // vt0[5]+0x14=0x41AEB0
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // vt0[6]+0x18=0x41AEF0
    virtual short what_frame();                             // vt0[7]+0x1C=0x41AF30
    virtual uchar is_animating();                           // vt0[8]+0x20=0x41AF50
    virtual void set_frame(short param_1);                  // vt0[9]+0x24=0x41AF40
    virtual uchar frame_passed(short param_1);              // vt0[10]+0x28=0x41AF60
    virtual uchar looped();                                 // vt0[11]+0x2C=0x41AF70
    virtual short get_facetindex(short param_1);            // vt0[12]+0x30=0x41AF80
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5); // vt0[13]+0x34=0x41AFB0
    virtual void setToFirstFrame();                         // vt0[14]+0x38=0x41AFF0
    RGE_Active_Sprite(RGE_Sprite* param_1);
    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);
    ~RGE_Active_Sprite();
    uchar get_lowest_draw_level();
    int check_for_shadows();
};

static_assert(sizeof(RGE_Active_Sprite) == 0x14, "RGE_Active_Sprite Size Mismatch");



// ----------------------------------------------------------------
// RGE_Active_Sprite_Node
// Size: 0xC
struct RGE_Active_Sprite_Node {
    RGE_Active_Sprite * node; // 0x0
    uchar order; // 0x4
    uchar count; // 0x5
    RGE_Active_Sprite_Node * next; // 0x8
};
