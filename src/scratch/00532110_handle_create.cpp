// RGE_Victory_Conditions::handle_create
// VA: 00532110
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
    char gap_40[0x0A];
    short id;                 // +0x4A
    char gap_4C[0x38];
    unsigned char* relations; // +0x84
    char gap_88[0x7C];
    unsigned char allied_victory; // +0x104
};

struct RGE_Victory_Entry {
    unsigned char command;    // +0x00
    char gap_01[3];
    long obj_type;            // +0x04
    char gap_08[0x14];
    long number;              // +0x1C
    char gap_20[0x0A];
    unsigned char ally_flag;  // +0x2A... wait, we need to be more careful
    unsigned char state;      // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[4];
    void* list_or_something;  // +0x04
    char gap_08[4];
    RGE_Player* player;       // +0x0C

    void handle_create(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_create(RGE_Victory_Entry* entry) {
    RGE_Player* self = this->player;
    int count = 0;

    RGE_Object_Node* node = self->objects->list;
    while (node != 0) {
        RGE_Static_Object* obj = node->node;
        if (obj->master_obj->copy_id == entry->obj_type && obj->object_state == 2) {
            count++;
        }
        node = node->next;
    }

    if (*(char*)((char*)entry + 0x2D) != 0 && self->allied_victory != 0) {
    //if (entry->ally_flag != 0 && self->allied_victory != 0) {
        short self_id = self->id;
        int num = self->world->player_num;
        for (int i = 1; i < num; i++) {
            RGE_Player* p = (RGE_Player*)self->world->players[i];
            if (self->relations[i] == 0 && 
                p->relations[self_id] == 0 && 
                i != self_id && 
                p->allied_victory != 0) {
                RGE_Object_Node* an = p->objects->list;
                while (an != 0) {
                    RGE_Static_Object* obj = an->node;
                    if (obj->master_obj->copy_id == entry->obj_type && obj->object_state == 2) {
                        count++;
                    }
                    an = an->next;
                }
            }
        }
    }

    if (count >= entry->number) {
        *(char*)((char*)entry + 0x2E) = 2;
    } else {
        *(char*)((char*)entry + 0x2E) = 0;
    }
}
