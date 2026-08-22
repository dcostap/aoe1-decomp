// 004864F0 RGE_RMM_Object_Generator::place_objects
// Attempt log:
// 1: initial natural implementation from packet/decompiler and rmm_obj neighbor stubs: exact size but 78% diff; compiler emitted counted byte loop and used edi=this.
// 2: use memset plus explicit self local to try original rep stosd clear and ebp=this register: first 74 bytes match; count kept in esi and player load scheduled later.
// 3: make count volatile to force stack local and memory test/dec: edit diff improved to 16.7%, but world/player load still scheduled after mask and stack arg LEAs shifted.
// 4: split world load to a separate local before player-id mask: no codegen change.
// 5: use <= -1 spelling for player-id mask to match cmp -1/setle: improved to 13.4%; remaining early mismatch is world load scheduled after mask and pop_stack arg order.
// 6: split players pointer load before mask: no codegen change.
// 7: store player id in a temp before indexing to probe load scheduling: no codegen change.
// 8: volatile world local to force load before mask: worsened to 27% edit diff with extra stack store; rolled back.
// 9: restored the proven Map_Stack/pop_stack ABI, long coordinate outputs, and
//    natural while(pop_stack && count > 0) tail; this reached exact size/CFG and
//    a 43-byte positional diff, with only the early setup hunk unresolved.
// 10: a focused 15-variant pre-loop lab (world/player declaration forms and
//     loop predicates) collapsed to duplicate codegen groups; reversing the
//     commutative mask operands was also a duplicate. The remaining drift is
//     VC5 world/mask/register and pop-argument scheduling, not behavior/calls.
// 11: ABI audit replaced the fake float cast at pop_stack with the proven
//     float cost output. Emitted bytes are unchanged; retain the safe typed form.
// 12: direct typed world local before the player-id mask plus swapped pop_stack
//     output order moved 10 bytes farther and lost aligned blocks; rolled back.
// 13: hoisted the typed master lookup before the placement loop to test the
//     original pre-pop lifetime; frame grew by 4 bytes and diff widened to 462,
//     so restored the clean loop-local lookup.
// 14: materialized the initial and bottom pop_stack result as next_stack to
//     mirror the decompiler's pMVar7 loop state; this widened the diff to 158
//     bytes and added one byte, so restored the direct natural while form.
// 15: tested the signed-negative conditional mask spelling; diff widened to
//     428 bytes, so restored the proven <= -1 form.
// 16: hoisted a typed world local to the function-local declarations; diff
//     widened to 88 bytes and moved the mismatch into the clear loop.
// 17: routed all record accesses through a natural info pointer alias; codegen
//     stayed at 43 bytes, so kept the simpler direct record accesses.
// 18: bound a typed world reference before the player lookup; codegen was an
//     unchanged 43-byte duplicate.
// 19: tested the exact decompiler mask idiom ((player_id < 0) - 1); diff widened
//     to 428 bytes, so restored the conditional mask.
// 20: modeled the high-confidence Random_Map_Module base layout; codegen stayed
//     at 43 bytes and confirmed the existing offsets.
// 21: added the virtual base declaration with a duplicate explicit vtable slot;
//     this produced a 46-byte diff and was rejected.
// 22: removed the duplicate vtable slot from the virtual base; diff was 45
//     bytes with changed operand scheduling, so restored the known stub shape.
// 23: tested the equivalent nonnegative mask idiom; diff widened to 428 bytes.
// 24: replaced the mask with an explicit negative-to-zero clamp; CFG and size
//     diverged and diff widened to 429 bytes.
// 25: combined a world local with a materialized masked index; codegen stayed
//     at 43 bytes.
// 26: added an explicit players-table local to that combination; codegen stayed
//     at 43 bytes.
// 27: moved count assignment before player lookup; diff improved from 43 to 31
//     bytes while size, frame, CFG, and calls stayed exact.
// 28: cached world before the improved count-before-player order; codegen stayed
//     at the 31-byte best.
// 29: restored the high-confidence base ownership with the 31-byte source; the
//     result stayed unchanged. Remaining drift is setup register scheduling.
// 30: direct this->world access with count-first setup was a 31-byte duplicate;
//     the simpler direct member form is now canonical.
// 31: long count, a named player index, the integer decompiler mask, and a
//     declaration-local count were all codegen duplicates or worse. The typed
//     while/pop loop and 31-byte clean result remain authoritative.
// Fresh bounded pass: explicit mask lifetimes with count-after-player widened
// the mismatch to 43 bytes. Players-slot, players-reference, and function-scope
// player locals reproduced the 31-byte basin. The remaining schedule changes
// world, info-field, player-table, and count read order. Keep this in scratch.
// Fresh claim pass: count-after-player with the direct mask widened to 43 bytes;
// top-scope player, world/table aliases, direct initialization, and reference
// Map_Stack helpers were 31-byte duplicates. A reference players alias, a
// loop-local count, an info alias, and reference helpers with count-after-player
// were 43-byte results. string.h changed the clear order and memory.h was the
// 31-byte basin. Restore the 31-byte direct-pointer clean source.

extern "C" void* __cdecl memset(void*, int, unsigned int);

struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};
struct RGE_Tile { char gap[5]; unsigned char terrain; char rest[18]; };
struct RGE_Object_Info_Line {
    int obj_id;                    // +00
    int terrain;                   // +04
    unsigned char group_flag;      // +08
    char pad09[0x14 - 0x09];
    int number_of_groups;          // +14
    char pad18[0x1c - 0x18];
    int player_id;                 // +1c
    char pad20[0x2c - 0x20];
    int object_exclusion_zone;     // +2c
};

class RGE_Player;
class RGE_Master_Static_Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual unsigned char can_place(RGE_Player*, float, float, int, int, int, int, int, int, int);
    char pad04[0x30-4];
    float radius_x;
    float radius_y;
};

class RGE_Player {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36();
    virtual void place_object(int obj_id, float x, float y, int, int);
    char pad04[0x24-4];
    RGE_Master_Static_Object** master_objects;
};

struct RGE_World { char pad00[0x40]; RGE_Player** players; };

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
    RGE_Random_Map_Module* parent;
    void* list;
    void* base_map;
    RGE_Tile** map;                // +10
    int width;                     // +14
    int height;                    // +18
    float schedule;                // +1c
    unsigned char* byte_map;       // +20
    void* search_map_rows;         // +24
    void* stack_array;             // +28
    void* stack_offsets;           // +2c

    void init_stack(Map_Stack* s);
    void deinit_stack(Map_Stack* s);
    void make_placement_stack(Map_Stack* s, long x, long y, int unk, int area);
    Map_Stack* pop_stack(Map_Stack* s, long* out_col, long* out_x, float* out_cost);
};

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module {
public:
    RGE_World* world;              // +30

    void remove_area_from_lists(long left, long right, long y);
    void place_group(RGE_Object_Info_Line& info, long x, long y, RGE_Player* player);
    void place_cluster(RGE_Object_Info_Line& info, long x, long y, RGE_Player* player);
    void place_objects(RGE_Object_Info_Line& info);
};

void RGE_RMM_Object_Generator::place_objects(RGE_Object_Info_Line& info)
{
    long x;
    long col;
    float cost;
    int count;
    float fx;
    float fy;
    int zone;
    Map_Stack obj_stack;

    // clear occupancy byte map to 1
    memset(this->byte_map, 1, this->width * this->height);

    this->init_stack(&obj_stack);
    this->make_placement_stack(&obj_stack, -1, -1, -1, -1);

    count = info.number_of_groups;
    RGE_Player* player;
    player = this->world->players[
        info.player_id & (info.player_id <= -1 ? 0 : -1)];

    while (pop_stack(&obj_stack, &col, &x, &cost) && count > 0) {
            if (info.terrain < 0 || ((this->map[x][col].terrain & 0x1f) == (unsigned int)info.terrain)) {
                fx = (float)col;
                fy = (float)x;
                RGE_Master_Static_Object* master = player->master_objects[info.obj_id];
                zone = (short)(int)master->radius_x;
                if (0.0f < master->radius_x - (float)zone) {
                    fx = fx - -0.5f;
                }
                zone = (short)(int)master->radius_y;
                if (0.0f < master->radius_y - (float)zone) {
                    fy = fy - -0.5f;
                }
                if (!master->can_place(player, fx, fy, 0, 0, 1, 1, 1, 0, 1)) {
                    remove_area_from_lists(col, x, info.object_exclusion_zone);
                    switch (info.group_flag) {
                    case 0:
                        player->place_object(info.obj_id, fx, fy, 0, 1);
                        break;
                    case 1:
                        place_group(info, col, x, player);
                        break;
                    case 2:
                        place_cluster(info, col, x, player);
                        break;
                    }
                    count--;
                }
            }
        }
    this->deinit_stack(&obj_stack);
}
