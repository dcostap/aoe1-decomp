#pragma once
#include "../common.h"

class RGE_Object_List {
public:
    RGE_Object_Node* list;                   // 0x4
    short number_of_objects;                 // 0x8

    RGE_Object_List();
    virtual ~RGE_Object_List();
    virtual void removeAllObjects();
    virtual RGE_Object_Node* add_node(RGE_Static_Object* param_1);
    virtual void remove_node(RGE_Static_Object* param_1, RGE_Object_Node* param_2);
    virtual void invert();
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    virtual void shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4, uchar param_5);
    virtual void normal_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    virtual void update();
    virtual RGE_Object_Node* sort();
    virtual RGE_Static_Object* find_by_group(long param_1);
    virtual RGE_Static_Object* find_by_group(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6);
    virtual RGE_Static_Object* find_by_id(long param_1);
    virtual RGE_Static_Object* find_by_master_id(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6);
    virtual RGE_Static_Object* find_by_master_ids(long param_1, long param_2, float param_3, float param_4, uchar param_5, uchar param_6, RGE_Static_Object* param_7);
    virtual RGE_Static_Object* find_by_type(uchar param_1, float param_2, float param_3, uchar param_4, uchar param_5);
    virtual void save(int param_1);
    virtual void load_list(int param_1, RGE_Game_World* param_2);
    virtual void rehook_list();
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3);
};

static_assert(sizeof(RGE_Object_List) == 0xC, "RGE_Object_List Size Mismatch");
static_assert(offsetof(RGE_Object_List, number_of_objects) == 0x8, "RGE_Object_List Offset Mismatch");

