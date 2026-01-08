#pragma once
#include "../common.h"


class RGE_Object_List      {
public:
    RGE_Object_Node* list;                   // 0x4
    short number_of_objects;                 // 0x8

    RGE_Object_List();

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual void load(uchar param_1, int param_2, RGE_Game_World* param_3); // Ghidra: load

    // --- Non-Virtual Destructor ---
    ~RGE_Object_List() noexcept(false);
    // --- Non-Virtual Members ---
    void removeAllObjects();
    RGE_Object_Node* add_node(RGE_Static_Object* param_1);
    void remove_node(RGE_Static_Object* param_1, RGE_Object_Node* param_2);
    void invert();
    void draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    void shadow_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4, uchar param_5);
    void normal_draw(TDrawArea* param_1, short param_2, short param_3, uchar param_4);
    void update();
    RGE_Object_Node* sort();
    RGE_Static_Object* find_by_group(long param_1);
    RGE_Static_Object* find_by_group(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6);
    RGE_Static_Object* find_by_id(long param_1);
    RGE_Static_Object* find_by_master_id(long param_1, float param_2, float param_3, uchar param_4, uchar param_5, RGE_Static_Object* param_6);
    RGE_Static_Object* find_by_master_ids(long param_1, long param_2, float param_3, float param_4, uchar param_5, uchar param_6, RGE_Static_Object* param_7);
    RGE_Static_Object* find_by_type(uchar param_1, float param_2, float param_3, uchar param_4, uchar param_5);
    void save(int param_1);
    void load_list(int param_1, RGE_Game_World* param_2);
    void rehook_list();
};

static_assert(sizeof(RGE_Object_List) == 0xC, "RGE_Object_List Size Mismatch");
static_assert(offsetof(RGE_Object_List, number_of_objects) == 0x8, "RGE_Object_List Offset Mismatch");
