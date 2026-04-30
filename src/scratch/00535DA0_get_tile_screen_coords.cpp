// 00535DA0 RGE_View::get_tile_screen_coords
// view.cpp:2447-2480, 269 bytes, __thiscall, ret 14h
// PAUSED: Closest attempt used goto fail pattern with shared failure tail.
// Generated 256 bytes of tight code (short rel8 branches, correct reg usage).
// Original has 269 bytes because shared failure exit is at END of function,
// forcing long rel32 branches (6B each x5 = 30B vs our 2B x5 = 10B).
// Can't force compiler to place failure exit at function end from source level.
// Also: tile_type spill to [esp+14h] (mov [esp+14h],bl; mov eax,[esp+14h])
// vs original's mov eax,ebx (2B vs 6B). Not controllable from C++ without asm.

struct TileSize { short width; short height; short pad; };
struct RGE_Tile { short screen_xpos; short screen_ypos; unsigned char tile_type; unsigned char gap_05[19]; };
struct RGE_Map {
    unsigned char gap_00[8];
    int map_width;
    int map_height;
    unsigned char gap_10[8];
    TileSize tilesizes[32];
    unsigned char gap_8D8C[0x8D8C - 0x18 - 32 * 6];
    RGE_Tile** map_row_offset;
};
class TPanel { public: unsigned char gap_00[0xF4]; };
class RGE_View : public TPanel {
public:
    unsigned char gap_F4[0x10];
    RGE_Map* map;
    unsigned char gap_108[4];
    short tile_half_wid;
    short field_10E;
    short tile_half_hgt;
    unsigned char gap_112[0x130 - 0x112];
    int x_offset;
    int y_offset;
    
    int get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust);
};

int RGE_View::get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust) {
    if (out_x != 0) *out_x = 0;
    if (out_y != 0) *out_y = 0;
    RGE_Map* pMap;
    if (col < 0) goto fail;
    pMap = this->map;
    if (col >= pMap->map_width) goto fail;
    if (row < 0) goto fail;
    if (row >= pMap->map_height) goto fail;
    {
        RGE_Tile* pTile = pMap->map_row_offset[row] + col;
        if (pTile == 0) goto fail;
        
        int screen_x = pTile->screen_xpos - this->x_offset;
        int screen_y = pMap->tilesizes[pTile->tile_type].pad + pTile->screen_ypos - this->y_offset;
        
        if (adjust != 0) {
            if (pTile->tile_type == 0) screen_y += this->tile_half_hgt / 2;
            if (pTile->tile_type == 6) screen_y -= this->tile_half_hgt;
            if (pTile->tile_type == 5) screen_y -= this->tile_half_hgt;
            if (pTile->tile_type == 3) screen_y -= this->tile_half_hgt;
            if (pTile->tile_type == 0x0B) screen_y -= this->tile_half_hgt;
        }
        
        *out_x = (short)screen_x;
        *out_y = (short)screen_y;
        return 1;
    }
fail:
    return 0;
}
