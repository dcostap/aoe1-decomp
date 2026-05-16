// VA: 0053CAC0 RGE_Visible_Map::explore_terrain_sq
// Source: visible.cpp lines 775-883
// Attempt log:
// 1: natural reconstruction from packet/original asm, mirroring unexplore_terrain_sq sibling and using _rotl for checksum.
// FLAGS: config/flags/0053CAC0_explore_terrain_sq.rsp
// 2: add narrow /Oy- because original has EBP frame and default omitted EBP immediately; prologue/frame now matches, first drift is y1/x1 register coloring.
// 3: forced x1 through its parameter stack slot for the row loop; worsened early prologue/register setup, rolled back.
// 4: swapped formal parameter names x1/y1 while preserving argument positions; no codegen change.
// 5: introduced explicit checksum local to try original stack spill/reload for hash lines; no codegen change.
// 6: reused incoming p6 stack slot as optional tile pointer like original [ebp+1Ch]; small positional improvement but edit diff worsened.
// 7: tried /O2 /Oy- /Ob0 flag probe; no change.
// 8: tried /O1 /Oy- flag probe; object shrank to 473 and failed configured size, restored /O2 /Oy-.
// 9: final validation still mismatches broadly; best state has correct configured 550-byte size and EBP frame, but first mismatch remains EBX/EDI x/y register allocation at log-call setup.
// 10: left in scratch: behavior modeled and loop/call surfaces mostly identified, but not accepted_drift-safe because x/y register coloring and checksum/local-slot scheduling cascade through bounds and nested loops.

#include <stdlib.h>
#pragma intrinsic(_rotl)

#define Map_Update_Suppresion (*(int*)0x00886C08)
#define unified_map_offsets ((unsigned long**)0x00886808)

extern "C" void __cdecl log_map_call(int world_time, int player_id, int type, int p6, int y1, int x1, int x2, int y2, int suppression);

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
    void add_node(int col, int row);
};

class RGE_Game_World {
public:
    void* vtable;
    int world_time;
    char gap_08[0x40 - 0x08];
    class RGE_Player** players;
    char gap_44[0x7C - 0x44];
    short curr_player;
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[0x58 - 0x4C];
    RGE_Tile_List tile_list;
    RGE_Tile_List cur_tile_list;
    char gap_80[0xAC - 0x80];
    int mutualAlly[32];
};

struct RGE_Tile {
    char gap_00[9];
    unsigned char flags_09;
    char gap_0A[0x18 - 0x0A];
};

class RGE_Map {
public:
    char gap_0000[0x8D8C];
    RGE_Tile** rows;
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets; // +00
    RGE_Game_World* world;       // +04
    RGE_Player* player;          // +08
    RGE_Map* map;                // +0C
    char gap_10[4];
    int widthValue;              // +14
    int heightValue;             // +18
    int numberTilesExploredValue;// +1C
    char gap_20[4];
    unsigned long visible_mask;  // +24
    char gap_28[4];
    unsigned long explored_mask; // +2C
    char gap_30[4];
    int checksum;                // +34

    int explore_terrain_sq(int y1, int x1, int x2, int y2, int update_tiles, int p6);
};

int RGE_Visible_Map::explore_terrain_sq(int y1, int x1, int x2, int y2, int update_tiles, int p6)
{
    int Revealed = 0;
    log_map_call(this->world->world_time,
                 (int)this->player->id,
                 2,
                 p6,
                 y1,
                 x1,
                 x2,
                 y2,
                 Map_Update_Suppresion);

    if (Map_Update_Suppresion) {
        return 0;
    }

    RGE_Player* curVisPlayer = 0;
    int isCurPlayer = (this->world->players[this->world->curr_player]->mutualAlly[this->player->id] == 1);
    p6 = 0;

    int checksum = this->checksum;
    checksum = _rotl(checksum, 3);
    checksum ^= 0x34343434;
    checksum = _rotl(checksum, 2);
    checksum ^= y1;
    checksum = _rotl(checksum, 4);
    checksum ^= x1;
    checksum = _rotl(checksum, 3);
    checksum ^= x2;
    checksum = _rotl(checksum, 3);
    checksum ^= y2;
    this->checksum = checksum;

    if (isCurPlayer) {
        curVisPlayer = this->world->players[this->world->curr_player];
    }

    if (y1 >= this->widthValue || x2 < 0 || x1 >= this->heightValue || y2 < 0) {
        return 0;
    }
    if (y1 < 0) y1 = 0;
    if (x2 >= this->widthValue) x2 = this->widthValue - 1;
    if (x1 < 0) x1 = 0;
    if (y2 >= this->heightValue) y2 = this->heightValue - 1;

    for (; x1 <= y2; ++x1) {
        unsigned char* p = this->map_offsets[x1] + y1;
        unsigned long* unified = unified_map_offsets[x1] + y1;
        if (update_tiles) {
            p6 = (int)(this->map->rows[x1] + y1);
        }
        for (int x = y1; x <= x2; ++x) {
            unsigned char v = *p;
            ++v;
            if (v == 0) {
                ++Revealed;
                ++this->numberTilesExploredValue;
                this->player->tile_list.add_node(x, x1);
                if (isCurPlayer) {
                    curVisPlayer->cur_tile_list.add_node(x, x1);
                }
                *unified |= this->explored_mask;
                v = 1;
            }
            if (v == 1) {
                if (update_tiles) {
                    ((RGE_Tile*)p6)->flags_09 = 0x0f;
                }
                *unified |= this->visible_mask;
            }
            if (v == 0xfa) {
                v = 0xf9;
            }
            *p = v;
            ++p;
            ++unified;
            if (update_tiles) {
                p6 += sizeof(RGE_Tile);
            }
        }
    }
    return Revealed;
}
