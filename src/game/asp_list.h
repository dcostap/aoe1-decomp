#pragma once
#include "../common.h"

class RGE_Active_Sprite_List       {
public:
    RGE_Active_Sprite_Node* list;            // 0x4
    RGE_Static_Object* owner;                // 0x8

    RGE_Active_Sprite_List(RGE_Static_Object* param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual  ~RGE_Active_Sprite_List() noexcept(false); // Ghidra: `vector_deleting_destructor'

    // [Slot 01] Offset 0x04 (Override)
    virtual short frame(RGE_Sprite* param_1); // Ghidra: frame

    // [Slot 02] Offset 0x08 (Override)
    virtual void update(float param_1, float param_2); // Ghidra: update

    // [Slot 03] Offset 0x0C (Override)
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // Ghidra: draw

    // [Slot 04] Offset 0x10 (Override)
    virtual void normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // Ghidra: normal_draw

    // [Slot 05] Offset 0x14 (Override)
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // Ghidra: shadow_draw

    // [Slot 06] Offset 0x18 (Override)
    virtual uchar is_animating(RGE_Sprite* param_1); // Ghidra: is_animating

    // [Slot 07] Offset 0x1C (Override)
    virtual void set_frame(RGE_Sprite* param_1, short param_2); // Ghidra: set_frame

    // [Slot 08] Offset 0x20 (Override)
    virtual uchar frame_passed(RGE_Sprite* param_1, short param_2); // Ghidra: frame_passed

    // [Slot 09] Offset 0x24 (Override)
    virtual uchar looped(RGE_Sprite* param_1); // Ghidra: looped

    // [Slot 10] Offset 0x28 (Override)
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2); // Ghidra: get_facetindex

    // [Slot 11] Offset 0x2C (Override)
    virtual uchar load_node(int param_1, uchar param_2, RGE_Sprite** param_3); // Ghidra: load_node

    // [Slot 12] Offset 0x30 WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 13] Offset 0x34 WARNING: Function body missing in analysis
    // virtual void set_offset();

    // [Slot 14] Offset 0x38 WARNING: Function body missing in analysis
    // virtual void save();

    // [Slot 15] Offset 0x3C WARNING: Function body missing in analysis
    // virtual void update();

    // [Slot 16] Offset 0x40 WARNING: Function body missing in analysis
    // virtual void draw();

    // [Slot 17] Offset 0x44 WARNING: Function body missing in analysis
    // virtual void normal_draw();

    // [Slot 18] Offset 0x48 WARNING: Function body missing in analysis
    // virtual void shadow_draw();

    // [Slot 19] Offset 0x4C WARNING: Function body missing in analysis
    // virtual void what_frame();

    // [Slot 20] Offset 0x50 WARNING: Function body missing in analysis
    // virtual void is_animating();

    // [Slot 21] Offset 0x54 WARNING: Function body missing in analysis
    // virtual void set_frame();

    // [Slot 22] Offset 0x58 WARNING: Function body missing in analysis
    // virtual void frame_passed();

    // [Slot 23] Offset 0x5C WARNING: Function body missing in analysis
    // virtual void looped();

    // [Slot 24] Offset 0x60 WARNING: Function body missing in analysis
    // virtual void get_facetindex();

    // [Slot 25] Offset 0x64 WARNING: Function body missing in analysis
    // virtual void get_frame();

    // [Slot 26] Offset 0x68 WARNING: Function body missing in analysis
    // virtual void setToFirstFrame();

    // --- Non-Virtual Members ---
    void load(int param_1, RGE_Sprite** param_2);
    void save(int param_1);
    void delete_list();
    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* param_1);
    void add_sprite(RGE_Sprite* param_1, uchar param_2, long param_3, long param_4);
    void remove_sprite(RGE_Sprite* param_1);
    uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, RGE_Sprite* param_5, long param_6);
    uchar get_lowest_draw_level();
    int check_for_shadows();
};

static_assert(sizeof(RGE_Active_Sprite_List) == 0xC, "RGE_Active_Sprite_List Size Mismatch");
static_assert(offsetof(RGE_Active_Sprite_List, owner) == 0x8, "RGE_Active_Sprite_List Offset Mismatch");

