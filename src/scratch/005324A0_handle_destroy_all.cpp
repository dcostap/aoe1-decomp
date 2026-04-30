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

struct RGE_Victory_Entry {
    char gap_00[4];
    long obj_type;            // +0x04
    void* target_player;      // +0x08
    char gap_0C[0x22];
    unsigned char state;      // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player;             // +0x0C

    void handle_destroy_all(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Entry* entry) {
    if (entry->target_player != 0) {
        // Check specific player
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

    // Check all non-ally players
    void* p = this->player;
    void* world = *(void**)((char*)p + 0x3C);
    int num = *(short*)((char*)world + 0x3C);
    void** players = *(void***)((char*)world + 0x40);
    short my_id = *(short*)((char*)p + 0x4A);

    for (int i = 0; i < num; i++) {
        unsigned char* rels = (unsigned char*)((char*)p + 0x84);
        if (rels[i] == 0) continue;  // ally, skip
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
