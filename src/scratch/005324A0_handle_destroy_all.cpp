// RGE_Victory_Conditions::handle_destroy_all
// VA: 005324A0
// victory.cpp

struct RGE_Master_Object {
    char gap_00[0x12];
    short copy_id;           // +0x12
};

struct RGE_Static_Object {
    char gap_00[8];
    RGE_Master_Object* master_obj; // +0x08
    char gap_0C[0x3C];
    unsigned char object_state; // +0x48
};

struct RGE_Object_Node {
    RGE_Static_Object* node; // +0x00
    RGE_Object_Node* next;   // +0x04
};

struct RGE_Object_List {
    char gap_00[4];
    RGE_Object_Node* list;   // +0x04
};

// Make entry a struct, not a class, for easier access
struct RGE_Victory_Entry_ForDestroy {
    char gap_00[4];
    long obj_type;            // +0x04
    void* target_player;      // +0x08
    char gap_0C[0x22];
    unsigned char state;      // +0x2E
};

// Use a standalone function that doesn't need 'this' saved
void __fastcall handle_destroy_all(void* _this, int _, RGE_Victory_Entry_ForDestroy* entry) {
    if (entry->target_player != 0) {
        RGE_Object_List* obj_list = *(RGE_Object_List**)((char*)(entry->target_player) + 0x28);
        RGE_Object_Node* node = obj_list->list;
        while (node != 0) {
            if (node->node->master_obj->copy_id == entry->obj_type) {
                entry->state = 0;
                return;
            }
            node = node->next;
        }
        entry->state = 2;
        return;
    }

    void* p = *(void**)((char*)_this + 0x0C);
    void* world = *(void**)((char*)p + 0x3C);
    int num = *(short*)((char*)world + 0x3C);
    void** players = *(void***)((char*)world + 0x40);
    short my_id = *(short*)((char*)p + 0x4A);

    for (int i = 0; i < num; i++) {
        if (*(unsigned char*)((char*)p + 0x84 + i) == 0) continue;
        if (i == my_id) continue;

        RGE_Object_List* obj_list = *(RGE_Object_List**)((char*)players[i] + 0x28);
        RGE_Object_Node* node = obj_list->list;
        while (node != 0) {
            if (node->node->master_obj->copy_id == entry->obj_type) {
                entry->state = 0;
                return;
            }
            node = node->next;
        }
    }

    entry->state = 2;
}
