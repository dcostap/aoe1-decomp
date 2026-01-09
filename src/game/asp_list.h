#pragma once
#include "common.h"

class RGE_Active_Sprite_List {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    RGE_Active_Sprite_Node* list;            // 0x4
    RGE_Static_Object* owner;                // 0x8

    virtual short frame(RGE_Sprite* param_1);               // vt0[1]+0x4=0x41AB20
    virtual void update(float param_1, float param_2);      // vt0[2]+0x8=0x41AA20
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7); // vt0[3]+0xC=0x41AA50
    virtual void normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5); // vt0[4]+0x10=0x41AAA0
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6); // vt0[5]+0x14=0x41AAE0
    virtual uchar is_animating(RGE_Sprite* param_1);        // vt0[6]+0x18=0x41AB60
    virtual void set_frame(RGE_Sprite* param_1, short param_2); // vt0[7]+0x1C=0x41AB90
    virtual uchar frame_passed(RGE_Sprite* param_1, short param_2); // vt0[8]+0x20=0x41ABC0
    virtual uchar looped(RGE_Sprite* param_1);              // vt0[9]+0x24=0x41AC00
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2); // vt0[10]+0x28=0x41AC30
    virtual uchar load_node(int param_1, uchar param_2, RGE_Sprite** param_3); // vt0[11]+0x2C=0x41A6F0
    RGE_Active_Sprite_List(RGE_Static_Object* param_1);
    ~RGE_Active_Sprite_List();
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

