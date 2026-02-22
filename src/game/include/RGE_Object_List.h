#pragma once
#include "common.h"

class RGE_Object_List {
public:
    RGE_Object_List();

    // Virtuals (best-effort)
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // vt[0] (0x0)
    void rehook_list();
    void update();
    void draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    RGE_Object_Node* add_node(RGE_Static_Object* param_1);
    void remove_node(RGE_Static_Object* param_1, RGE_Object_Node* param_2);
    RGE_Static_Object* find_by_id(long param_1);

    RGE_Object_Node* list;
    short number_of_objects;
};
static_assert(sizeof(RGE_Object_List) == 0xC, "Size mismatch");
