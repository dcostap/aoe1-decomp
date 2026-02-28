#pragma once
#include "common.h"

class RGE_Static_Object;

class RGE_Object_List {
public:
    RGE_Object_List();
    ~RGE_Object_List();

    // Virtuals (best-effort)
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // vt[0] (0x0)
    void removeAllObjects();
    void rehook_list();
    void update();
    void draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    void shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4, uchar param_5);
    void normal_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    RGE_Object_Node* sort();
    RGE_Static_Object* find_by_group(long param_1);
    RGE_Static_Object* find_by_group(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6);
    RGE_Object_Node* add_node(RGE_Static_Object* param_1);
    void remove_node(RGE_Static_Object* param_1, RGE_Object_Node* param_2);
    RGE_Static_Object* find_by_id(long param_1);
    RGE_Static_Object* find_by_master_id(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6);
    RGE_Static_Object* find_by_master_ids(long param_1, long param_2, float param_3, float param_4, uchar param_5, uchar param_6, RGE_Static_Object* param_7);
    RGE_Static_Object* find_by_type(uchar param_1, float param_2, float param_3, uchar param_4, uchar param_5);
    void save(int param_1);
    void load_list(int param_1, RGE_Game_World* param_2);

protected:
    void invert();

public:
    RGE_Object_Node* list;
    short number_of_objects;
};
static_assert(sizeof(RGE_Object_List) == 0xC, "Size mismatch");
