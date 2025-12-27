#pragma once
#include "../types.h"

#pragma pack(push, 1)

struct RGE_Static_Object;

struct RGE_Object_Node {
    struct RGE_Static_Object *node;
    struct RGE_Object_Node *next;
    struct RGE_Object_Node *prev;
    uchar centered;
};

class RGE_Object_List {
public:
    // Virtual table alignment (vptr at 0x0000)
    virtual ~RGE_Object_List();

    struct RGE_Object_Node *list;
    short number_of_objects;
    short _pad;

    RGE_Object_List();
    void removeAllObjects();
    void remove_node(struct RGE_Static_Object *obj, struct RGE_Object_Node *node);
};

#pragma pack(pop)

static_assert(sizeof(RGE_Object_List) == 0xC, "RGE_Object_List size mismatch");
