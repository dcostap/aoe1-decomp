// RGE_Victory_Conditions::handle_destroy_all
// VA: 005324A0
// victory.cpp
//
// Initial reconstruction: the player/world/list ownership is modeled from the
// observed member offsets.  Keep the loop and exit structure ordinary; the
// compiler's register reuse is part of the matching evidence, not source ABI.
//
// Attempt log:
// - Typed ownership baseline reached 199 bytes, 26 positional differences,
//   97.65% instruction-shape similarity, and 83.53% exact-block coverage.
// - Register-qualified entry, shared function-scope locals, an explicit entry
//   alias, and matched sibling player/world/entry type surfaces were codegen
//   duplicates; the baseline remains the clean source.
// - Inverting the outer guard and explicit current-player cursors worsened CFG
//   and size parity. A two-case relation-gate variant lab also produced one
//   emitted group with no improvement.
// - Paused: remaining drift is entry/callee-save and related register coloring
//   from offset 0; no call, frame, size, or behavior/layout blocker found.

struct RGE_Player;

struct RGE_World {
    char gap_00[0x3C];
    short player_num;             // +0x3C
    char gap_3E[2];
    RGE_Player** players;         // +0x40
};

struct RGE_Master_Object {
    char gap_00[0x12];
    short copy_id;                // +0x12
};

struct RGE_Static_Object {
    char gap_00[8];
    RGE_Master_Object* master_obj; // +0x08
};

struct RGE_Object_Node {
    RGE_Static_Object* node;      // +0x00
    RGE_Object_Node* next;        // +0x04
};

struct RGE_Object_List {
    char gap_00[4];
    RGE_Object_Node* list;        // +0x04
};

struct RGE_Player {
    char gap_00[0x28];
    RGE_Object_List* objects;     // +0x28
    char gap_2C[0x10];
    RGE_World* world;             // +0x3C
    char gap_40[0x0A];
    short id;                     // +0x4A
    char gap_4C[0x38];
    unsigned char* relations;     // +0x84
};

struct RGE_Victory_Entry {
    char gap_00[4];
    long obj_type;                // +0x04
    RGE_Player* target_player;    // +0x08
    char gap_0C[0x22];
    unsigned char state;          // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    RGE_Player* player;           // +0x0C

    void handle_destroy_all(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_destroy_all(RGE_Victory_Entry* entry) {
    if (entry->target_player != 0) {
        RGE_Object_Node* node = entry->target_player->objects->list;
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

    RGE_Player* player = this->player;
    int num = player->world->player_num;
    RGE_Player** players = player->world->players;

    for (int i = 0; i < num; i++) {
        if (player->relations[i] == 0 || i == player->id) {
            continue;
        }

        RGE_Object_Node* node = players[i]->objects->list;
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
