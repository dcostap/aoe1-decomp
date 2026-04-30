// RGE_Victory_Conditions::handle_destroy_multiple
// VA: 005323D0
// victory.cpp

struct RGE_Object_Node {
    void* node;              // +0x00
    RGE_Object_Node* next;   // +0x04
};

struct RGE_Object_List {
    char gap_00[4];
    RGE_Object_Node* list;   // +0x04
};

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

struct RGE_Game_World {
    char gap_00[0x3C];
    short player_num;         // +0x3C
    void** players;           // +0x40
};

struct RGE_Player {
    char gap_00[0x28];
    RGE_Object_List* objects; // +0x28
    char gap_2C[0x10];
    RGE_Game_World* world;    // +0x3C
    char gap_40[0x44];
    unsigned char relations[8]; // +0x84
};

struct RGE_Victory_Entry {
    unsigned char command;    // +0x00
    char gap_01[3];
    long obj_type;            // +0x04
    RGE_Player* target_player; // +0x08
    char gap_0C[0x10];
    long number;              // +0x1C
    long count;               // +0x20
    char gap_24[0x0A];
    unsigned char state;      // +0x2E
    char gap_2F;
    RGE_Victory_Entry* next;  // +0x30
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x04];
    RGE_Victory_Entry* victory_list; // +0x04
    char gap_08[4];
    RGE_Player* player;       // +0x0C

    void handle_destroy_multiple(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* entry) {
    if (entry->state != 0) return;

    if (entry->target_player != 0) {
        RGE_Object_Node* node = entry->target_player->objects->list;
        while (node != 0) {
            RGE_Static_Object* obj = (RGE_Static_Object*)node->node;
            if (obj->master_obj->copy_id == entry->obj_type && obj->object_state == 7) {
                entry->count++;
            }
            node = node->next;
        }
    } else {
        RGE_Player* self = this->player;
        RGE_Game_World* world = self->world;
        int num = world->player_num;
        void** players = world->players;
        for (int i = 0; i < num; i++) {
            if (self->relations[i] != 0) {
                RGE_Player* p = (RGE_Player*)players[i];
                RGE_Object_Node* node = p->objects->list;
                while (node != 0) {
                    RGE_Static_Object* obj = (RGE_Static_Object*)node->node;
                    if (obj->master_obj->copy_id == entry->obj_type && obj->object_state == 7) {
                        entry->count++;
                    }
                    node = node->next;
                }
                self = this->player;
            }
        }
    }

    if (entry->count >= entry->number) {
        entry->state = 2;
    }
}
