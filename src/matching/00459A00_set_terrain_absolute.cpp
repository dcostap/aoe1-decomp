// VA: 00459A00 RGE_Map::set_terrain_absolute — EXACT MATCH
// Source: map.cpp lines 2603-2629
// FLAGS: /nologo /c /O2 /Oy
//
// Key matching details:
// - RGE_Game_World::players at +0x40, loaded as *players (dereferenced to get players[0]).
// - RGE_Map::map_row_offset at +0x8D8C (int**), indexed: [col][row*6] gives tile address.
//   Each tile is 24 bytes (row * 24 via row*3*8 LEA pattern).
// - Terrain XOR manipulation: tile[5] = (terrain ^ tile[5]) & 0x1F ^ tile[5].
// - clear_terrain_object(gw, col, row, -1, 1, param5, param6) — 7 stack params + this.
// - place_terrain_object(players[0], gw, col, row, result, 1) — 6 stack params + this.
// - get_border_type(row, col) — 2 stack params + this.
// - Short parameters are sign-extended (movsx) before use in indexing.

#include <string.h>

#ifndef MAP_CONTEXT_H
class RGE_Game_World {
public:
    char gap_40[0x40];
    void** players;     // +0x40
};

class RGE_Player;

class RGE_Map {
public:
    char gap_00[0x8D8C];
    int** map_row_offset;   // +0x8D8C

    void set_terrain_absolute(RGE_Game_World* gw, short row, short col, unsigned char terrain, int param5, int param6);
    int clear_terrain_object(RGE_Game_World* gw, short col, short row, int v1, int v2, int param5, int param6);
    void place_terrain_object(RGE_Player* player, RGE_Game_World* gw, short col, short row, int val, int flag);
    void get_border_type(short row, short col);
};

#endif

void RGE_Map::set_terrain_absolute(RGE_Game_World* gw, short row, short col, unsigned char terrain, int param5, int param6)
{
    RGE_Player* p0;
    unsigned char* tile;

    p0 = (RGE_Player*)*gw->players;
    tile = (unsigned char*)this->map_row_offset[col] + (int)row * 24;
    tile[5] = (terrain ^ tile[5]) & 0x1F ^ tile[5];

    if (p0 != 0) {
        int result = clear_terrain_object(gw, col, row, -1, 1, param5, param6);
        place_terrain_object(p0, gw, col, row, result, 1);
    }

    get_border_type(row, col);
}
