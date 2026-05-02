// RGE_Victory_Conditions::handle_destroy_multiple
// VA: 005323D0
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
    char gap_0C[0x10];
    long number;              // +0x1C
    long count;               // +0x20
    char gap_24[0x0A];
    unsigned char state;      // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    void* player;             // +0x0C

    void handle_destroy_multiple(struct RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* entry) {
    if (entry->state) return;

    if (entry->target_player) {
        // Count specific player's matching objects
        RGE_Object_Node* node = (*(RGE_Object_List**)((char*)(entry->target_player) + 0x28))->list;
        while (node) {
            if (node->node->master_obj->copy_id == entry->obj_type && node->node->object_state == 7)
                entry->count++;
            node = node->next;
        }
    } else {
        // Count all non-ally players' matching objects
        void* p = this->player;
        void* w = *(void**)((char*)p + 0x3C);
        void** pl = *(void***)((char*)w + 0x40);
        int cnt = *(short*)((char*)w + 0x3C);
        for (int i = 0; i < cnt; i++) {
            if (*(unsigned char*)((char*)p + 0x84 + i)) {
                RGE_Object_Node* node = (*(RGE_Object_List**)((char*)pl[i] + 0x28))->list;
                while (node) {
                    if (node->node->master_obj->copy_id == entry->obj_type && 
                        node->node->object_state == 7)
                        entry->count++;
                    node = node->next;
                }
            }
        }
    }

    if (entry->count >= entry->number) {
        entry->state = 2;
    }
}
