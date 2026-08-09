// VA: 0053CAC0 RGE_Visible_Map::explore_terrain_sq
// Source: visible.cpp lines 775-883
// Attempt log:
// baseline candidate: canonical x/y rectangle ownership and natural symmetry with
// explore_terrain/unexplore_terrain_sq; the oracle traverses rows by y1 and columns
// from x1 through x2.
// Hoisting curVis/tile initialization before the checksum recovered the configured
// 550-byte size and the best current basin.  Canonical polymorphic surfaces were
// codegen-neutral; the remaining drift is local-slot/hash operand scheduling and
// the late result/tile tail.  No call or ownership discrepancy remains.
// Full typed RGE_Tile/RGE_Map records, top-level typed row cursors, and an unsigned
// checksum accumulator preserve canonical map ownership but emitted identically.
// Declaration order, initializer form, and p6/curVis zero-store order were likewise
// neutral. Remaining drift begins before the hash: the oracle homes Revealed at
// [ebp-8] and its checksum/visible cursor at [ebp-4], while the default donor basin
// selects the inverse homes; the later checksum/ally scheduling follows that split.

#include <stdlib.h>
#pragma intrinsic(_rotl)

extern int Map_Update_Suppresion;
extern unsigned long* unified_map_offsets[];

extern "C" void __cdecl log_map_call(int world_time, int player_id, int type,
                                     int p6, int x1, int y1, int x2, int y2,
                                     int suppression);

class RGE_Tile_List {
public:
    char gap_000[0x14];
    void add_node(int x, int y);
};

class RGE_Player;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_08[0x40 - 0x08];
    RGE_Player** players;
    char gap_44[0x7C - 0x44];
    short curr_player;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x46];
    short id;
    char gap_4C[0x0C];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    char gap_80[0x2C];
    int mutualAlly[32];
};

struct RGE_Tile {
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char flags_09;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0C[0x0C];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_0004[0x04];
    int map_width;
    int map_height;
    char gap_0010[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x40];
};

// Main-agent audit replaced raw absolute globals and retained canonical visible
// map ownership with natural square exploration.
class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;

    int explore_terrain_sq(int x1, int y1, int x2, int y2,
                           int update_tiles, int p6);
};

int RGE_Visible_Map::explore_terrain_sq(int x1, int y1, int x2, int y2,
                                        int update_tiles, int p6)
{
    unsigned char* p;
    unsigned long* unified;
    int Revealed = 0;
    RGE_Player* curVisPlayer;
    int isCurPlayer;
    unsigned long checksum;
    RGE_Tile* tile;

    log_map_call(this->world->world_time, (int)this->player->id, 2, p6,
                 x1, y1, x2, y2, Map_Update_Suppresion);

    if (Map_Update_Suppresion != 0) {
        return 0;
    }

    isCurPlayer =
        (this->world->players[this->world->curr_player]->
             mutualAlly[this->player->id] == 1);
    p6 = 0;
    curVisPlayer = 0;
    tile = 0;

    checksum = this->input_csum;
    checksum = _rotl(checksum, 3);
    checksum ^= 0x34343434;
    checksum = _rotl(checksum, 2);
    checksum ^= x1;
    checksum = _rotl(checksum, 4);
    checksum ^= y1;
    checksum = _rotl(checksum, 3);
    checksum ^= x2;
    checksum = _rotl(checksum, 3);
    checksum ^= y2;
    this->input_csum = checksum;

    if (isCurPlayer) {
        curVisPlayer =
            this->world->players[this->world->curr_player];
    }

    if ((x1 >= this->widthValue) || (x2 < 0) ||
        (y1 >= this->heightValue) || (y2 < 0)) {
        return 0;
    }
    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= this->widthValue) {
        x2 = this->widthValue - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= this->heightValue) {
        y2 = this->heightValue - 1;
    }

    for (; y1 <= y2; ++y1) {
        p = this->map_offsets[y1] + x1;
        unified = unified_map_offsets[y1] + x1;
        if (update_tiles != 0) {
            tile = this->map->map_row_offset[y1] + x1;
        }

        for (int x = x1; x <= x2; ++x) {
            unsigned char value = *p;
            ++value;
            if (value == 0) {
                ++Revealed;
                ++this->numberTilesExploredValue;
                this->player->tile_list.add_node(x, y1);
                if (isCurPlayer) {
                    curVisPlayer->diam_tile_list.add_node(x, y1);
                }
                *unified |= this->PlayerExploredMaskValue;
                value = 1;
            }
            if (value == 1) {
                if (update_tiles != 0) {
                    tile->flags_09 = 0x0F;
                }
                *unified |= this->PlayerVisibleMaskValue;
            }
            if (value == 0xFA) {
                value = 0xF9;
            }
            *p = value;
            ++p;
            ++unified;
            ++tile;
        }
    }
    return Revealed;
}
