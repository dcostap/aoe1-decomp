#pragma once
#include "../common.h"

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite       {
public:
    char _pad_0x4[0x10];
    short frame;                             // 0x14
    float animate_interval;                  // 0x18
    float animate_last;                      // 0x1C
    short last_frame;                        // 0x20
    uchar frame_changed;                     // 0x22
    uchar frame_looped;                      // 0x23
    uchar animate_flag;                      // 0x24

    RGE_Active_Animated_Sprite(RGE_Sprite* param_1);
    RGE_Active_Animated_Sprite(int param_1, RGE_Sprite** param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Active_Animated_Sprite() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 WARNING: Function body missing in analysis
    // virtual void set_offset();

    // [Slot 02] Offset 0x08 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 03] Offset 0x0C (Override)
    virtual void update(float param_1, float param_2); // Ghidra: update

    // [Slot 04] Offset 0x10 (Override)
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // Ghidra: draw

    // [Slot 05] Offset 0x14 (Override)
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // Ghidra: normal_draw

    // [Slot 06] Offset 0x18 (Override)
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // Ghidra: shadow_draw

    // [Slot 07] Offset 0x1C (Override)
    virtual short what_frame(); // Ghidra: what_frame

    // [Slot 08] Offset 0x20 (Override)
    virtual uchar is_animating(); // Ghidra: is_animating

    // [Slot 09] Offset 0x24 (Override)
    virtual void set_frame(short param_1); // Ghidra: set_frame

    // [Slot 10] Offset 0x28 (Override)
    virtual uchar frame_passed(short param_1); // Ghidra: frame_passed

    // [Slot 11] Offset 0x2C (Override)
    virtual uchar looped(); // Ghidra: looped

    // [Slot 12] Offset 0x30 (Override)
    virtual short get_facetindex(short param_1); // Ghidra: get_facetindex

    // [Slot 13] Offset 0x34 (Override)
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5); // Ghidra: get_frame

    // [Slot 14] Offset 0x38 (Override)
    virtual void setToFirstFrame(); // Ghidra: setToFirstFrame

};

static_assert(sizeof(RGE_Active_Animated_Sprite) == 0x28, "RGE_Active_Animated_Sprite Size Mismatch");
static_assert(offsetof(RGE_Active_Animated_Sprite, animate_flag) == 0x24, "RGE_Active_Animated_Sprite Offset Mismatch");

class RGE_Active_Sprite       {
public:
    RGE_Sprite* sprite;                      // 0x4
    uchar type;                              // 0x8
    long offset_x;                           // 0xC
    long offset_y;                           // 0x10

    RGE_Active_Sprite(RGE_Sprite* param_1);
    RGE_Active_Sprite(int param_1, RGE_Sprite** param_2);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Active_Sprite() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual void set_offset(long param_1, long param_2); // Ghidra: set_offset

    // [Slot 02] Offset 0x08 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 03] Offset 0x0C (Override)
    virtual void update(float param_1, float param_2); // Ghidra: update

    // [Slot 04] Offset 0x10 (Override)
    virtual void draw(short param_1, long param_2, long param_3, long param_4, long param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // Ghidra: draw

    // [Slot 05] Offset 0x14 (Override)
    virtual void normal_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // Ghidra: normal_draw

    // [Slot 06] Offset 0x18 (Override)
    virtual void shadow_draw(short param_1, long param_2, long param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // Ghidra: shadow_draw

    // [Slot 07] Offset 0x1C (Override)
    virtual short what_frame(); // Ghidra: what_frame

    // [Slot 08] Offset 0x20 (Override)
    virtual uchar is_animating(); // Ghidra: is_animating

    // [Slot 09] Offset 0x24 (Override)
    virtual void set_frame(short param_1); // Ghidra: set_frame

    // [Slot 10] Offset 0x28 (Override)
    virtual uchar frame_passed(short param_1); // Ghidra: frame_passed

    // [Slot 11] Offset 0x2C (Override)
    virtual uchar looped(); // Ghidra: looped

    // [Slot 12] Offset 0x30 (Override)
    virtual short get_facetindex(short param_1); // Ghidra: get_facetindex

    // [Slot 13] Offset 0x34 (Override)
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, long param_5); // Ghidra: get_frame

    // [Slot 14] Offset 0x38 (Override)
    virtual void setToFirstFrame(); // Ghidra: setToFirstFrame

    // --- Non-Virtual Members ---
    uchar get_lowest_draw_level();
    int check_for_shadows();
};

static_assert(sizeof(RGE_Active_Sprite) == 0x14, "RGE_Active_Sprite Size Mismatch");
static_assert(offsetof(RGE_Active_Sprite, offset_y) == 0x10, "RGE_Active_Sprite Offset Mismatch");


// ----------------------------------------------------------------
// RGE_Active_Sprite_Node
// Size: 0xC
struct RGE_Active_Sprite_Node {
    RGE_Active_Sprite * node; // 0x0
    uchar order; // 0x4
    uchar count; // 0x5
    RGE_Active_Sprite_Node * next; // 0x8
};
