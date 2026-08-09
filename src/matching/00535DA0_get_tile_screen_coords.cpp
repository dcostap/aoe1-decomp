// 00535DA0 RGE_View::get_tile_screen_coords
// view.cpp:2447-2480, 269 bytes, __thiscall, ret 14h
// Attempt log:
//   baseline: canonical map/tile ownership and natural validation body; the
//     early-failure gotos caused short branches to a local failure block.
//   control-flow: nested positive guards below model the source-level success
//     region so VC5 can place the shared return-0 block after it, as in the
//     original long branches.
//   main-agent audit: restored canonical RGE_Map/TPanel polymorphic ownership;
//     emitted code remains exact.

struct TileSize { short width; short height; short y_delta; };
struct RGE_Tile { short screen_xpos; short screen_ypos; unsigned char tile_type; unsigned char gap_05[19]; };
struct RGE_Map {
    virtual ~RGE_Map();
    void* map;
    int map_width;
    int map_height;
    unsigned char gap_10[8];
    TileSize tilesizes[32];
    unsigned char gap_8D8C[0x8D8C - 0x18 - 32 * 6];
    RGE_Tile** map_row_offset;
};
class TPanel { public: virtual ~TPanel(); unsigned char gap_04[0xF0]; };
class RGE_View : public TPanel {
public:
    unsigned char gap_F4[0x10];
    RGE_Map* map;
    unsigned char gap_108[4];
    short tile_half_wid;
    short tile_half_hgt;
    short elev_hgt;
    unsigned char gap_112[0x130 - 0x112];
    int map_scr_x_offset;
    int map_scr_y_offset;

    int get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust);
};

int RGE_View::get_tile_screen_coords(short col, short row, short* out_x, short* out_y, int adjust) {
    if (out_x != 0) *out_x = 0;
    if (out_y != 0) *out_y = 0;

    if (col >= 0) {
        RGE_Map* pMap = this->map;
        if (col < pMap->map_width) {
            if (row >= 0) {
                if (row < pMap->map_height) {
                    RGE_Tile* pTile = pMap->map_row_offset[row] + col;
                    if (pTile != 0) {
                        int screen_x = pTile->screen_xpos - this->map_scr_x_offset;
                        int screen_y = pTile->screen_ypos;
                        screen_y += pMap->tilesizes[pTile->tile_type].y_delta;
                        screen_y -= this->map_scr_y_offset;

                        if (adjust != 0) {
                            if (pTile->tile_type != 0) screen_y += this->elev_hgt / 2;
                            if (pTile->tile_type == 6) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 5) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 3) screen_y -= this->elev_hgt;
                            if (pTile->tile_type == 0x0B) screen_y -= this->elev_hgt;
                        }

                        *out_x = (short)screen_x;
                        *out_y = (short)screen_y;
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}
