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
// - Fresh pass: dossier/ABI/donor evidence confirmed no calls, frame, or
//   layout blocker. Rechecked local aliases, scoped comparison values, guard
//   spellings, full polymorphic class/entry surfaces, and 32 register-qualified
//   local variants; all emitted the same register basin (best diagnostic diff
//   25, no exact variant).
// - Paused: remaining drift is entry/callee-save and related register coloring
//   from offset 0; no call, frame, size, or behavior/layout blocker found.
// - Main-agent audit restored canonical polymorphic world/player/master/static
//   and victory ownership; the natural object-list scans remain.
// - New worker revalidated the audited source after the prior 39-probe pass; no
//   new natural source/ABI lead emerged. The remaining 25 bytes begin at entry
//   register allocation (original EBX home vs rebuilt EDX), with size/frame/CFG
//   and all typed memory effects already aligned.
// - Fresh bounded pass: dossier, same-TU donor ranking, and ABI evidence found
//   no call, frame, size, or ownership blocker.  Ghidra-vtable corrections for
//   the nonvirtual Victory_Conditions destructor, polymorphic Object_List, and
//   canonical Game_World surface were each emitted-code duplicates and were
//   restored to the pinned clean reconstruction.
// - Fresh probes: Ghidra local declaration-order variants, donor game-global
//   header context, and an eight-case declaration-order lab all emitted the same
//   199-byte/25-byte-diff basin.  A natural while-loop was 32 bytes (worse); a
//   pre-increment for was a codegen duplicate.  No new source-plausible lead
//   remains; the localized entry/callee-save allocation drift is retained as
//   the next worker's lead.
// - Final worker probes: a reference entry alias, saved-this alias, full object-list
//   and victory-helper declaration context, canonical master-static naming, a
//   redundant proven-null guard, explicit target/all-player labels, and a diagnostic
//   virtual-helper declaration were neutral or worse. Restored the clean natural
//   source; remaining drift is still the 25-byte entry/callee-save color from offset 0.
// - Wave20: split entry-alias declaration/assignment and a top-level const
//   parameter qualifier were emitted-code duplicates. A nine-case targeted
//   alias lab (target/all branch aliases, declaration timing) produced one
//   199-byte group, so no entry-home change is supported by those forms.
// - Wave20: a state-only top-level entry alias and moving the all-player index
//   out of the for header were neutral. A function-scope obj_type assigned
//   before the node test swapped entry/player into EBP/EBX but broke size/CFG;
//   assigning it only inside the proven node loops collapsed back to the clean
//   25-byte group. Six declaration-order/storage variants found no EBX-home
//   group; a register-qualified obj_type was also a duplicate.
// - Wave20 final: restored the pinned natural typed source; remaining evidence
//   is still the localized original EBX entry home versus rebuilt EDX, with
//   exact size/frame/CFG and canonical list/victory ownership intact.

struct RGE_Player;

struct RGE_World {
    virtual ~RGE_World();
    char gap_04[0x38];
    short player_num;             // +0x3C
    char gap_3E[2];
    RGE_Player** players;         // +0x40
};

struct RGE_Master_Object {
    virtual ~RGE_Master_Object();
    char gap_04[0x0E];
    short copy_id;                // +0x12
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char gap_04[4];
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
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;     // +0x28
    char gap_2C[0x10];
    RGE_World* world;             // +0x3C
    char gap_40[0x0A];
    short id;                     // +0x4A
    char gap_4C[0x38];
    unsigned char* relations;     // +0x84
};

struct RGE_Victory_Entry {
    unsigned char command;       // +0x00
    char gap_01[3];
    long obj_type;                // +0x04
    RGE_Player* target_player;    // +0x08
    float x0;                     // +0x0C
    float y0;                     // +0x10
    float x1;                     // +0x14
    float y1;                     // +0x18
    long number;                  // +0x1C
    long count;                   // +0x20
    RGE_Static_Object* this_obj;  // +0x24
    RGE_Static_Object* target_obj; // +0x28
    unsigned char victory_group;  // +0x2C
    unsigned char ally_flag;      // +0x2D
    unsigned char state;          // +0x2E
    unsigned char checked_flag;   // +0x2F
    RGE_Victory_Entry* next;      // +0x30
};

struct RGE_Victory_Point_Entry;

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    virtual void handle_point_condition(RGE_Victory_Point_Entry* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);

    RGE_Victory_Entry* victory_list; // +0x04
    long list_num;                   // +0x08
    RGE_Player* player;              // +0x0C
    unsigned char victory;           // +0x10
    char gap_11[3];
    RGE_Victory_Point_Entry* victory_point_list; // +0x14
    long point_list_num;            // +0x18
    long tot_victory_points;        // +0x1C

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
