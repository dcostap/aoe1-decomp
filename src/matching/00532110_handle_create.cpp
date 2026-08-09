// RGE_Victory_Conditions::handle_create
// VA: 00532110
// victory.cpp
// Attempt log:
// - Baseline raw offset scaffolding was 8 bytes too large and kept player/entry
//   in the wrong registers; it was retained only as prior evidence.
// - Probe 2: restored proven player/object/world/relation ownership and a
//   period-plausible typed list traversal; size/frame/CFG became exact, with
//   three localized address/register bytes remaining.
// - Probe 3: declared the world player-array cursor before the loop locals;
//   this recovered the original ECX cursor and reduced the drift to one byte.
// - Probes 4-6: commuted pointer/subscript relation spellings and ran a focused
//   relation-address variant lab; VC5 emitted the same [eax+esi] SIB each time.
// - Probes 7-9: restored a natural self alias, tested an integer-address form,
//   and tested a loop-local relation pointer; none changed the one-byte drift.
//   The integer-address and loop-local forms were rolled back as diagnostic only.
// - Probe 10: donor/decompiler declaration order reproduced the earlier three
//   byte result, so the best source below restores the probe-3 cursor order.
// - Final paused gap: original uses cmp byte [esi+eax],0 while VC5 emits the
//   behavior-identical cmp byte [eax+esi],0; size, frame, CFG, and all other
//   258 bytes match under default flags.
// - Main-agent audit restored canonical virtual ownership for the master,
//   object-list, player, and world surfaces. That declaration context changed
//   VC5's final SIB choice and produced an exact match.

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0E];
    short copy_id; // +0x12
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x08
    char gap_0C[0x3C];
    unsigned char object_state; // +0x48
};

struct RGE_Object_Node {
    RGE_Static_Object* node; // +0x00
    RGE_Object_Node* next; // +0x04
};

struct RGE_Object_List {
    virtual ~RGE_Object_List();
    RGE_Object_Node* list; // +0x04
};

struct RGE_Game_World;

struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects; // +0x28
    char gap_2C[0x10];
    RGE_Game_World* world; // +0x3C
    char gap_40[0x0A];
    short id; // +0x4A
    char gap_4C[0x38];
    unsigned char* relations; // +0x84
    char gap_88[0x7C];
    unsigned char allied_victory; // +0x104
};

struct RGE_Game_World {
    virtual unsigned char data_load_world(void* file);
    char gap_04[0x38];
    short player_num; // +0x3C
    char gap_3E[2];
    RGE_Player** players; // +0x40
};

struct RGE_Victory_Entry {
    char gap_00[4];
    long obj_type; // +0x04
    char gap_08[0x14];
    long number; // +0x1C
    char gap_20[0x0D];
    unsigned char ally_flag; // +0x2D
    unsigned char state; // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    RGE_Player* player; // +0x0C

    void handle_create(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_create(RGE_Victory_Entry* entry) {
    RGE_Player* self = this->player;
    int count = 0;
    RGE_Object_Node* node = self->objects->list;

    while (node != 0) {
        if (node->node->master_obj->copy_id == entry->obj_type &&
            node->node->object_state == 2) {
            count++;
        }
        node = node->next;
    }

    if (entry->ally_flag != 0 && self->allied_victory != 0) {
        RGE_Game_World* world = self->world;
        RGE_Player** players = world->players;
        int i = 1;
        int num = world->player_num;

        if (i < num) {
            do {
                if (self->relations[i] == 0 &&
                    players[i]->relations[self->id] == 0 &&
                    i != self->id &&
                    players[i]->allied_victory != 0) {
                    RGE_Object_Node* n = players[i]->objects->list;
                    while (n != 0) {
                        if (n->node->master_obj->copy_id == entry->obj_type &&
                            n->node->object_state == 2) {
                            count++;
                        }
                        n = n->next;
                    }
                }
                i++;
            } while (i < num);
        }
    }

    if (count >= entry->number) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}
