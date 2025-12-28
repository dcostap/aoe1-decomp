#pragma once
#include "../types.h"

struct RGE_Static_Object;

struct RGE_Object_Node {
    struct RGE_Static_Object *node;
    struct RGE_Object_Node *next;
    struct RGE_Object_Node *prev;
    uchar centered;
};

class RGE_Object_List {
public:
    // ========================================================================
    // Virtual Table (Strictly following layout.json)
    // ========================================================================
    
    // Index 0: load
    virtual void load(uchar param_1, int param_2, struct RGE_Game_World *param_3);

    // ========================================================================
    // Members (Offsets MUST match layout.json)
    // ========================================================================
    
    /* 0x0000 */ // vptr (automatically added)
    /* 0x0004 */ struct RGE_Object_Node *list;
    /* 0x0008 */ short number_of_objects;
    /* 0x000a */ short _pad;

    // ========================================================================
    // Non-virtual Methods
    // ========================================================================
    
    RGE_Object_List();
    ~RGE_Object_List(); // NOT virtual in layout.json!

    void removeAllObjects();
    void remove_node(struct RGE_Static_Object *obj, struct RGE_Object_Node *node);
};

// MANDATORY VERIFICATION
static_assert(sizeof(RGE_Object_List) == 0xC, "RGE_Object_List size mismatch");
static_assert(offsetof(RGE_Object_List, list) == 0x4, "list offset mismatch");
static_assert(offsetof(RGE_Object_List, number_of_objects) == 0x8, "number_of_objects offset mismatch");
