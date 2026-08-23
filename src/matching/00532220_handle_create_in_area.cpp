// RGE_Victory_Conditions::handle_create_in_area
// VA: 00532220
// victory.cpp
// Attempt log:
// - Baseline: typed self/player/world/entry ownership with shared object-list
//   cursor and pointer-walk ally scan; size/frame/CFG are close, but self/count
//   use EBX/EBP opposite the original and 121 bytes remain.
// - Declaration-order probe: declare the count before the saved player owner so
//   VC5 can assign the original EBX count / EBP self register roles.
// - Cursor-preheader/layout probe: initialize a separate players+1 cursor after
//   the count guard, advance it in the loop increment, and correct the proven
//   Victory_Entry ally/state tail gap to place state at +0x2E.
// - Nested relation guard recovered 97.06% exact-block coverage and a 15-byte
//   edit/resync gap; a 9-variant owner/cursor surface lab kept this group as the
//   best natural basin. Direct world->players+1 and base-then-increment variants
//   regressed the setup; remaining drift is setup register/order plus prologue
//   self/count coloring.
// - Main-agent audit restored canonical polymorphic master/static/world/player
//   and victory ownership while retaining the typed ally/object scans.
// - New worker baseline retained the audited polymorphic surface. Naming the
//   world and declaring players before num was a natural source-order probe;
//   the latter recovered the original players-in-ECX/LEA setup, leaving 100%
//   exact-block coverage and 189 positional bytes.
// - Relation pointer/index spellings, signedness, a loop relation alias, and
//   loop-index declaration order were codegen duplicates. Removing the proven
//   virtual surface regressed offsets/registers and was restored. Remaining
//   drift is the one-byte relation SIB/base-order choice plus resulting branch
//   displacements and trailing padding.
// - Combined the self-relation and allied-player guards to test the exact
//   sibling short-circuit shape; it worsened the block coverage and was
//   restored. The localized [eax+ebp] versus [ebp+eax] SIB gap remains.
// - An explicit relation-element pointer at the loop head was codegen-neutral;
//   restored the direct indexed access for the clean source.
// - A polymorphic object-list with its list directly after the vptr preserves
//   the proven +0x04 field, unlike the padded version; test exact-TU context.
//   It was codegen-neutral; restored the pinned non-polymorphic padded source.
// - tu-victory-532220 dossier and sibling review: the typed own/allied scans retain
//   100% exact-block coverage and the 0xC frame. The only source-independent gap is
//   the behavior-equivalent relation SIB encoding at +0x7F; no natural new lead remains.
// - orch-532220-a baseline reconfirmed the pinned clean source at 189 bytes.
// - Reversed, explicit-pointer, integer-address, and cast-pointer relation
//   expressions all emitted the same [eax+ebp] SIB. A helper added a call and
//   regressed structure. A volatile relation pointer was also codegen-neutral.
// - A four-case focused relation-expression lab produced one emitted-code group;
//   no natural source spelling changed the +0x7F SIB. Restored the clean source.
// - Worker recheck: the clean source still builds to 388 bytes with the 0xC
//   frame, all 25 blocks, and the same single relation SIB mismatch at +0x7F;
//   no new natural lead was found. Keep this source pending compiler-context or
//   original-source evidence rather than using an opaque codegen workaround.
// - Follow-up probes: typed relation tables/records, signedness, inline
//   accessors, pointer-expression order, local references, and canonical
//   virtual class surfaces all preserved the same 189-byte SIB basin. Splitting
//   or reusing the counters changed the frame body and was restored. The clean
//   typed reconstruction remains authoritative.
// - Revisit probe: nested the allied relation, self-id, and allied-victory
//   tests in the decompiler's natural short-circuit shape. VC5 emitted the
//   same 388-byte function and the same 189-byte relation-SIB drift. The
//   original `cmp byte [ebp+eax],0` and rebuilt `cmp byte [eax+ebp],0` read
//   the same relation byte; the original encoding is one byte longer. No
//   policy-valid source lead remains. Keep this source and pause for compiler
//   context or original-source evidence.
// ACCEPTED DRIFT: the SIB operands are commutative and compute the same byte
// address. That one-byte encoding length changes seven later branch or address
// displacements. The rebuild adds one trailing NOP, so both boundaries remain
// 388 bytes. All 35 original blocks, 25 predicates, object reads, count updates,
// result stores, returns, memory order, and fault order match. There are no
// calls, x87 operations, or SEH. Nineteen focused probes found no natural
// source spelling that selects the original base/index encoding.

struct RGE_Master_Object {
    virtual ~RGE_Master_Object();
    char gap_04[0x0E];
    short copy_id;           // +0x12
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Object* master_obj; // +0x08
    char gap_0C[0x2C];
    float world_x;           // +0x38
    float world_y;           // +0x3C
    char gap_40[0x08];
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

struct RGE_Player;

struct RGE_Game_World {
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;         // +0x3C
    RGE_Player** players;     // +0x40
};

struct RGE_Player {
    virtual ~RGE_Player();
    char gap_04[0x24];
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
    char gap_08[4];
    float x0;                 // +0x0C
    float y0;                 // +0x10
    float x1;                 // +0x14
    float y1;                 // +0x18
    long number;              // +0x1C
    char gap_20[0x0D];
    unsigned char ally_flag;  // +0x2D
    unsigned char state;      // +0x2E (actually at 0x2E based on save asm)
};

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    void* list_or_thing;      // +0x04
    char gap_08[4];
    RGE_Player* player;       // +0x0C

    void handle_create_in_area(RGE_Victory_Entry* entry);
};

void RGE_Victory_Conditions::handle_create_in_area(RGE_Victory_Entry* entry) {
    int count = 0;
    RGE_Player* player = this->player;

    // Count own objects of matching type in area with state==2
    RGE_Object_Node* node = player->objects->list;
    while (node != 0) {
        RGE_Static_Object* obj = node->node;
        if (obj->master_obj->copy_id == entry->obj_type && 
            obj->object_state == 2 &&
            obj->world_x >= entry->x0 &&
            obj->world_x <= entry->x1 &&
            obj->world_y >= entry->y0 &&
            obj->world_y <= entry->y1) {
            count++;
        }
        node = node->next;
    }

    // Add allied objects
    if (entry->ally_flag != 0 && player->allied_victory != 0) {
        RGE_Game_World* world = player->world;
        int i = 1;
        RGE_Player** players = world->players;
        int num = world->player_num;
        if (i < num) {
            RGE_Player** current = players + 1;
            do {
                if (player->relations[i] == 0) {
                    RGE_Player* p = *current;
                    if (p->relations[player->id] == 0 &&
                        i != player->id &&
                        p->allied_victory != 0) {
                        node = p->objects->list;
                        while (node != 0) {
                            RGE_Static_Object* obj = node->node;
                            if (obj->master_obj->copy_id == entry->obj_type &&
                                obj->object_state == 2 &&
                                obj->world_x >= entry->x0 &&
                                obj->world_x <= entry->x1 &&
                                obj->world_y >= entry->y0 &&
                                obj->world_y <= entry->y1) {
                                count++;
                            }
                            node = node->next;
                        }
                    }
                }
                ++i;
                ++current;
            } while (i < num);
        }
    }

    if (count >= entry->number) {
        entry->state = 2;
    } else {
        entry->state = 0;
    }
}
