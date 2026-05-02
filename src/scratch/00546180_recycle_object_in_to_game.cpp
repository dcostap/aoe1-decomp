// VA: 00546180 RGE_Game_World::recycle_object_in_to_game (250 bytes)
// PDB: World.cpp lines 3841-3898
//
// Status: PARKED — VC5 code sharing prevents match
//
// Attempt log:
// v1: Direct switch with 7 cases, struct access — 224 bytes (26 short)
// v2: Block-scoped cases — 224 bytes
// v3: return 0 per case instead of break — 224 bytes
// v4: Raw pointer math instead of struct member access — 224 bytes
// v5: /GX flag — 224 bytes
// v6: /O1 flag — 113 bytes
// v7: Different variable naming (lst/nod/result/obj) — 224 bytes
// v8: Different struct layout (RGE_Object_Node vs raw char*) — 224 bytes
// v9: stdlib.h include — 224 bytes
// v10: Combined result variable pattern — 224 bytes
//
// Key issue: VC5 merges all 7 identical case handler bodies into
// shared code with jump stubs (136 bytes) instead of inline code
// per case (180 bytes). The original has each case fully inlined.
//
// Root cause unknown. Possible axes to try:
// - Different compiler /O flags or per-file flag context
// - Including the remove_node definition in the TU
// - Adding a unique expression per case (volatile, dummy call, etc.)
// - Non-switch control flow (computed goto, if/else chain)
// - Different compilation TU context (World.cpp with all its includes)

struct RGE_Static_Object;

struct RGE_Object_Node {
    RGE_Static_Object* obj;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

struct RGE_Object_List {
    void* vtable_ptr;
    RGE_Object_Node* list;
    short number_of_objects;

    void remove_node(RGE_Static_Object* object, RGE_Object_Node* node);
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0xD4];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;

    RGE_Static_Object* recycle_object_in_to_game(unsigned char param_1);
};

RGE_Static_Object* RGE_Game_World::recycle_object_in_to_game(unsigned char param_1) {
    RGE_Static_Object* result = 0;
    RGE_Object_List* lst;
    RGE_Object_Node* nod;

    switch (param_1) {
    case 0x0A:
        lst = this->reusable_static_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;

    case 0x14:
        lst = this->reusable_animated_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;

    case 0x1E:
        lst = this->reusable_moving_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;

    case 0x28:
        lst = this->reusable_action_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;

    case 0x32:
        lst = this->reusable_combat_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;

    case 0x3C:
        lst = this->reusable_missile_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;

    case 0x19:
        lst = this->reusable_doppleganger_objects;
        nod = lst->list;
        if (nod) { lst->remove_node(nod->obj, 0); result = nod->obj; }
        break;
    }

    return result;
}
