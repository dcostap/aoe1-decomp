// tried the direct decompiler-shaped nested loops first; the remaining mismatch moved into the loop-body indexing
// switching to explicit row-pointer walks for map_offsets and unified_map_offsets
// if it stays non-exact, the remaining gap is likely just loop/register shape
// Retry 2026-05-19 assigned pass:
// try 1: baseline revalidation 156/156 but broad 74.3590% positional, stack locals and wrong PlayerExploredMask offset (+0x30).
// try 2: fixed PlayerExploredMask to +0x2C and rewrote loops with rowOffset byte offset (not rowPtr/exploredPtr); improved to 51.9231% positional / 33.9744% edit, first mismatch +0x31.
// try 3: decompiler-style int row/explored casts; no codegen change from try 2.
// try 4: explicit slot local; no codegen change.
// try 5: direct (*slot)[x] condition forced different compare/load shape; edit diff improved but positional worsened, rolled back.
// try 6: volatile slot worsened badly; rolled back.
// try 7: register row and signed-char compare no change.
// try 8: ++numberTilesExplored no change.
// try 9: manual while/break loop shape no change; rolled back.
// try 10-11: /Ob0 and /G5 flag probes no change; flags removed.
// Retry 2026-05-20 assigned pass:
// try 12: revalidated current best: exact size 156B, 81 positional / 53 edit, first mismatch +49.
// try 13: C++ reference to row slot like accepted-drift recomputeExplored; destroyed prologue/register basin (first mismatch +0), rolled back.
// try 14: row_ptr = this->map_offsets + y reference/index form; worsened badly, rolled back.
// try 15: source call to add_node before row store to try early argument pushes; wrong behavior order and much worse codegen, rolled back.
// try 16: for-loop combined y/rowOffset and direct for headers; worsened from offset 0, rolled back.
// try 17: direct indexed `map_offsets[y]`/`unified_map_offsets[y]`; similar but slightly worse than baseline, rolled back.
// try 18: keep slot and row2 aliases to force extra LEA/slot lifetime; worsened from offset 0.
// try 19: signed-char condition and pointer arithmetic `*(row+x)`; worsened from offset 0.
// try 20: preload player and mask locals before inner loop; extra liveness worsened from offset 0.
// try 21: separate numberTilesExplored temp and separate add_node arg locals; optimized back to baseline, no improvement.
// GIVEUP: best kept is exact size 156B, 51.9231% positional / 33.9744% edit. Remaining mismatch is inner-loop register/address topology: original keeps row in EDX, emits extra LEA slot, schedules add_node pushes before store/or-mask; rebuilt uses EAX row and shorter body. Not accepted drift.

extern unsigned long* unified_map_offsets[256];
extern void __cdecl log_map_call(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9);

class RGE_Game_World {
public:
    void* vtable_ptr;
    unsigned long world_time;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void add_node(int x, int y);
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[0x0C];
    RGE_Tile_List tile_list;
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    void* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    char gap_20[0x08];
    unsigned long PlayerExploredMaskValue;

    void explore_all(void);
};

void RGE_Visible_Map::explore_all(void) {
    log_map_call(this->world->world_time, (int)this->player->id, 6, 0, 0, 0, 0, 0, 0);

    int y = 0;
    if (this->heightValue > 0) {
        int rowOffset = 0;
        do {
            int x = 0;
            if (this->widthValue > 0) {
                do {
                    unsigned char** slot = (unsigned char**)((char*)this->map_offsets + rowOffset);
                    unsigned char* row = *slot;
                    if (row[x] == 0xFF) {
                        slot = slot;
                        row[x] = 0;
                        this->numberTilesExploredValue++;
                        unsigned long* explored = *(unsigned long**)((char*)unified_map_offsets + rowOffset);
                        explored[x] |= this->PlayerExploredMaskValue;
                        this->player->tile_list.add_node(x, y);
                    }
                    x++;
                } while (x < this->widthValue);
            }
            y++;
            rowOffset += 4;
        } while (y < this->heightValue);
    }
    this->player->tile_list.collapse_list = 1;
}
