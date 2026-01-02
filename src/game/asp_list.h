#pragma once
#include "../common.h"

class RGE_Active_Sprite_List {
public:
    RGE_Active_Sprite_Node* list;            // 0x4
    RGE_Static_Object* owner;                // 0x8

    RGE_Active_Sprite_List(RGE_Static_Object* param_1);
    virtual ~RGE_Active_Sprite_List();
    virtual void load(int param_1, RGE_Sprite** param_2);
    virtual uchar load_node(int param_1, uchar param_2, RGE_Sprite** param_3);
    virtual void save(int param_1);
    virtual void delete_list();
    virtual RGE_Active_Sprite_Node* copy_sprite_list();
    virtual void use_sprite_list(RGE_Active_Sprite_Node* param_1);
    virtual void add_sprite(RGE_Sprite* param_1, uchar param_2, long param_3, long param_4);
    virtual void remove_sprite(RGE_Sprite* param_1);
    virtual void update(float param_1, float param_2);
    virtual void draw(short param_1, short param_2, short param_3, short param_4, short param_5, RGE_Color_Table* param_6, TDrawArea* param_7);
    virtual void normal_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5);
    virtual void shadow_draw(short param_1, short param_2, short param_3, RGE_Color_Table* param_4, TDrawArea* param_5, uchar param_6);
    virtual short frame(RGE_Sprite* param_1);
    virtual uchar is_animating(RGE_Sprite* param_1);
    virtual void set_frame(RGE_Sprite* param_1, short param_2);
    virtual uchar frame_passed(RGE_Sprite* param_1, short param_2);
    virtual uchar looped(RGE_Sprite* param_1);
    virtual short get_facetindex(RGE_Sprite* param_1, short param_2);
    virtual uchar get_frame(short* param_1, short* param_2, short* param_3, short* param_4, RGE_Sprite* param_5, long param_6);
    virtual uchar get_lowest_draw_level();
    virtual int check_for_shadows();
};

static_assert(sizeof(RGE_Active_Sprite_List) == 0xC, "RGE_Active_Sprite_List Size Mismatch");
static_assert(offsetof(RGE_Active_Sprite_List, owner) == 0x8, "RGE_Active_Sprite_List Offset Mismatch");

