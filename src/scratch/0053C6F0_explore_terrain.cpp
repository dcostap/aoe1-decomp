// VA: 0053C6F0 RGE_Visible_Map::explore_terrain
// Source: visible.cpp lines 521-658
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map ownership and the
// natural paired explore/unexplore loops.
// External LOS/unified-map declarations recover the same-TU register/local basin;
// the remaining mismatch is the checksum spill/suppression compare and a short
// late-loop schedule.  A polymorphic full-class context was codegen-neutral.
// Default /O2 /Oy was tested and regressed to 571 bytes/64.1% shape; retain the
// existing narrow /Oy- donor-context flag while this target remains unresolved.
// Main-agent audit replaced raw absolute globals and byte tile cursors with
// canonical symbols and typed map/tile ownership.

#include <stdlib.h>
#pragma intrinsic(_rotl)

extern int Map_Update_Suppresion;
extern int* unified_map_offsets[];

extern int* NormalLOS[17];
extern int* SquareLOS[17];

void __cdecl log_map_call(int world_time, int player_id, int type,
                          int p6, int x, int y, int radius, int square,
                          int suppression);

class RGE_Map;

class RGE_Tile_List {
public:
    char gap_000[0x14];
    void add_node(int x, int y);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_004[0x46];
    short id;
    char gap_4C[0x0C];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    char gap_80[0x2C];
    int mutualAlly[32];
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    int world_time;
    char gap_008[0x40 - 0x08];
    RGE_Player** players;
    char gap_44[0x7C - 0x44];
    short curr_player;
};

struct RGE_Tile {
    char gap_00[9];
    unsigned char flags_09;
    char gap_0A[0x18 - 0x0A];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_004[0x8D88];
    RGE_Tile** map_row_offset;
};

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

    int explore_terrain(int x, int y, int radius, int square,
                       int update_tiles, int p6);
};

int RGE_Visible_Map::explore_terrain(int x, int y, int radius, int square,
                                     int update_tiles, int p6)
{
    int Revealed;
    int checksum;
    RGE_Player* curPlayer;
    int VisibleToCurPlayer;
    RGE_Player* curVisPlayer;
    int* offsets;
    int offY;
    int y2;
    int x1;
    int x2;
    unsigned char* vis;
    int* unified;
    RGE_Tile* tile;
    unsigned char v;

    Revealed = 0;
    log_map_call(this->world->world_time, this->player->id, 1, p6,
                 x, y, radius, square, Map_Update_Suppresion);
    checksum = 0;
    if (Map_Update_Suppresion != checksum) {
        return 0;
    }

        p6 = this->input_csum;
        checksum = (int)this->player->id;
        p6 = _rotl(p6, 3);
        p6 ^= 0x01010101;
        p6 = _rotl(p6, 2);
        p6 ^= checksum;
        p6 = _rotl(p6, 3);
        p6 ^= x;
        p6 = _rotl(p6, 4);
        p6 ^= y;
        p6 = _rotl(p6, 3);
        p6 ^= radius;
        p6 += square;
        this->input_csum = p6;

        curPlayer = this->world->players[this->world->curr_player];
        if (curPlayer != 0) {
            VisibleToCurPlayer =
                (curPlayer->mutualAlly[this->player->id] == 1);
        } else {
            VisibleToCurPlayer = 0;
        }

        tile = 0;
        curVisPlayer = 0;
        if (VisibleToCurPlayer) {
            curVisPlayer = curPlayer;
        }

        if (radius > 0x10) {
            radius = 0x10;
        }

        if (square != 0) {
            offsets = SquareLOS[radius];
        } else {
            offsets = NormalLOS[radius];
        }

        offY = offsets[0];
        while (offY != 999) {
            y2 = y + offY;
            if ((y2 >= 0) && (y2 < this->heightValue)) {
                x1 = x + offsets[1];
                if (x1 < 0) {
                    x1 = 0;
                }
                x2 = x + offsets[2];
                if (x2 >= this->widthValue) {
                    x2 = this->widthValue - 1;
                }

                vis = this->map_offsets[y2] + x1;
                unified = unified_map_offsets[y2] + x1;
                if (update_tiles != 0) {
                    tile = this->map->map_row_offset[y2] + x1;
                }

                while (x1 <= x2) {
                    v = (unsigned char)(*vis + 1);
                    if (v == 0) {
                        Revealed++;
                        this->numberTilesExploredValue++;
                        this->player->tile_list.add_node(x1, y2);
                        if (VisibleToCurPlayer) {
                            curVisPlayer->diam_tile_list.add_node(x1, y2);
                        }
                        v = 1;
                        *unified |= this->PlayerExploredMaskValue;
                    }
                    if (v == 1) {
                        if (update_tiles != 0) {
                            tile->flags_09 = 0x0F;
                        }
                        *unified |= this->PlayerVisibleMaskValue;
                    }
                    if (v == 0xFA) {
                        v = 0xF9;
                    }
                    *vis = v;
                    ++vis;
                    ++unified;
                    x1++;
                    if (update_tiles != 0) {
                        ++tile;
                    }
                }
            }
            offsets += 3;
            offY = offsets[0];
        }
    return Revealed;
}
