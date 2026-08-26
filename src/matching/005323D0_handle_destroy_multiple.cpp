// RGE_Victory_Conditions::handle_destroy_multiple
// VA: 005323D0
// victory.cpp
// Attempt log:
// - Baseline raw player/world pointer scaffolding matched size but added a stack home and
//   produced a 189-byte positional mismatch.
// - Typed RGE_Player/RGE_Game_World ownership with direct player/players traversal removed
//   the artificial stack home and reached 110 differing bytes with 98.67% exact-block coverage.
// - Declaring the current player-array cursor inside the positive count guard preserved the
//   original post-jle mov ebp,edi and produced an exact match.
// - Replacing the proven target-player object-list offset cast with the typed objects member
//   was codegen-neutral; final source uses named ownership and default flags.

#ifndef VICTORY_CONTEXT_H
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

struct RGE_Game_World;

struct RGE_Player {
    char gap_00[0x28];
    RGE_Object_List* objects; // +0x28
    char gap_2C[0x10];
    RGE_Game_World* world;     // +0x3C
    char gap_40[0x44];
    unsigned char* relations;  // +0x84
};

struct RGE_Game_World {
    char gap_00[0x3C];
    short player_num;          // +0x3C
    char gap_3E[2];
    RGE_Player** players;      // +0x40
};

struct RGE_Victory_Entry {
    char gap_00[4];
    long obj_type;            // +0x04
    RGE_Player* target_player; // +0x08
    char gap_0C[0x10];
    long number;              // +0x1C
    long count;               // +0x20
    char gap_24[0x0A];
    unsigned char state;      // +0x2E
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x0C];
    RGE_Player* player;       // +0x0C

protected:
    void handle_destroy_multiple(struct RGE_Victory_Entry* entry);
};
#endif

void RGE_Victory_Conditions::handle_destroy_multiple(RGE_Victory_Entry* entry) {
    if (entry->state) return;

    if (entry->target_player) {
        // Count specific player's matching objects
        RGE_Object_Node* node = entry->target_player->objects->list;
        while (node) {
            if (node->node->master_obj->copy_id == entry->obj_type && node->node->object_state == 7)
                entry->count++;
            node = node->next;
        }
    } else {
        // Count all non-ally players' matching objects
        RGE_Player* player = this->player;
        RGE_Player** players = player->world->players;
        int i = 0;
        if (i < player->world->player_num) {
            RGE_Player** current_players = players;
            do {
                if (player->relations[i]) {
                    RGE_Object_Node* node = current_players[0]->objects->list;
                    while (node) {
                        if (node->node->master_obj->copy_id == entry->obj_type &&
                            node->node->object_state == 7)
                            entry->count++;
                        node = node->next;
                    }
                }
                player = this->player;
                i++;
                current_players++;
            } while (i < player->world->player_num);
        }
    }

    if (entry->count >= entry->number) {
        entry->state = 2;
    }
}
