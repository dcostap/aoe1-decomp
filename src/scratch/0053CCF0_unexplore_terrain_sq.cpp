// VA: 0053CCF0 RGE_Visible_Map::unexplore_terrain_sq
// Source: visible.cpp lines 891-975
// Attempt log:
// 1: natural reconstruction from packet/decompiler; /Oy- needed for original EBP frame, but hash emitted shifts instead of rol and arg push order drifted.
// 2: use _rotl intrinsic for checksum update; fixed rol family under /Oy-, but register/order drift remains.
// 3: introduce log-call locals to probe y1/x2 register coloring; no change.
// 4: force checksum through p6 stack slot via volatile pointer; moved hash closer (stores/reloads p6) but register coloring still off.
// 5: use volatile pointer for x2 accesses to discourage carrying x2 in ESI; fixed early y1/x2 coloring, remaining drift starts at bounds register choice.
// 6: use volatile pointer for y2 hash/bounds to avoid carrying y2 in ECX across checksum; edit diff improved and hash/bounds closer.
// 7: force y1 parameter-slot store before row loop like original; row setup closer, inner loop still used conditional tile increment/count stack.
// 8: unconditional tile increment regressed prologue/register coloring; rolled back.
// 9: /Oy- probe gave EBP frame and best edit diff (~31.2%) but is a custom-flag crutch and still broad; removed flag.
// Left in scratch: behavior modeled, but default build is wrong frame/register basin and loop scheduling remains broad.

#include <stdlib.h>
#pragma intrinsic(_rotl)

#define Map_Update_Suppresion (*(int*)0x00886C08)
#define unified_map_offsets ((unsigned long**)0x00886808)

extern "C" void __cdecl log_map_call(int world_time, int player_id, int type, int p6, int x1, int y1, int x2, int y2, int suppression);

class RGE_Game_World {
public:
    void* vtable;
    int world_time;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void add_node(int col, int row);
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[0x0C];
    RGE_Tile_List tile_list;
    char gap_6C[0x64];
    unsigned long explored_mask; // +D0
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
    int numberTilesExploredValue;// +1C maybe unused
    int numberTotalTilesValue;   // +20
    char gap_24[4];
    unsigned long explored_mask; // +28
    char gap_2C[8];
    int checksum;                // +34

    void unexplore_terrain_sq(int x1, int y1, int x2, int y2, int update_tiles, int p6);
};

void RGE_Visible_Map::unexplore_terrain_sq(int x1, int y1, int x2, int y2, int update_tiles, int p6)
{
    RGE_Visible_Map* self = this;
    RGE_Tile* tile = 0;
    volatile int* p_x2 = &x2;
    volatile int* p_y1 = &y1;
    volatile int* p_y2 = &y2;

    int log_y1 = y1;
    int log_x2 = x2;
    log_map_call(this->world->world_time,
                 (int)this->player->id,
                 4,
                 p6,
                 x1,
                 log_y1,
                 *p_x2,
                 y2,
                 Map_Update_Suppresion);

    if (Map_Update_Suppresion) {
        return;
    }

    volatile int* p_hash = &p6;
    *p_hash = this->checksum;
    p6 = _rotl(p6, 3);
    p6 ^= 0x56565656;
    p6 = _rotl(p6, 2);
    p6 ^= x1;
    p6 = _rotl(p6, 4);
    p6 ^= y1;
    p6 = _rotl(p6, 3);
    p6 ^= *p_x2;
    p6 = _rotl(p6, 3);
    p6 ^= *p_y2;
    this->checksum = p6;

    if (x1 >= this->widthValue || *p_x2 < 0 || y1 >= this->heightValue || *p_y2 < 0) {
        return;
    }
    if (x1 < 0) x1 = 0;
    if (*p_x2 >= this->widthValue) x2 = this->widthValue - 1;
    if (y1 < 0) y1 = 0;
    if (*p_y2 >= this->heightValue) y2 = this->heightValue - 1;
    *p_y1 = y1;

    for (; y1 <= y2; ++y1) {
        unsigned char* row = this->map_offsets[y1];
        unsigned char* p = row + x1;
        unsigned long* explored = unified_map_offsets[y1] + x1;
        if (update_tiles) {
            RGE_Tile* rowTile = this->map->rows[y1];
            tile = rowTile + x1;
        }
        int count = *p_x2 - x1 + 1;
        while (count != 0) {
            unsigned char v = *p;
            --v;
            if (v == 0xff) {
                v = 0;
            }
            if (v == 0) {
                if (update_tiles) {
                    tile->flags_09 = 0x80;
                }
                *explored &= this->explored_mask;
            }
            *p = v;
            ++p;
            ++explored;
            if (update_tiles) {
                ++tile;
            }
            --count;
        }
    }
}
