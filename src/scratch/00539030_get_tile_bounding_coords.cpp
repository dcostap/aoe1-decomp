// 00539030 RGE_View::get_tile_bounding_coords
// view.cpp:4862-4947, 147 bytes, __thiscall, ret 18h

struct TileSize { short width; short height; short pad; };
struct RGE_Tile { short screen_xpos; short screen_ypos; unsigned char tile_type; unsigned char gap_05[19]; };
struct RGE_Map { unsigned char gap_00[0x18]; TileSize tilesizes[32]; unsigned char gap_8D8C[0x8D8C - 0x18 - 32 * 6]; RGE_Tile** map_row_offset; };
class TPanel { public: unsigned char gap_00[0xF4]; };
class RGE_View : public TPanel { public: unsigned char gap_F4[0x10]; RGE_Map* map; unsigned char gap_108[4]; short tile_half_wid; short tile_half_hgt; short elev_hgt; void get_tile_bounding_coords(int param_1, int param_2, int& param_3, int& param_4, int& param_5, int& param_6); };

void RGE_View::get_tile_bounding_coords(int param_1, int param_2, int& param_3, int& param_4, int& param_5, int& param_6) {
    RGE_Tile* pRVar3 = this->map->map_row_offset[param_2];
    short sVar2 = pRVar3[param_1].screen_xpos;
    byte bVar1 = pRVar3[param_1].tile_type;
    param_3 = sVar2;
    param_5 = this->map->tilesizes[bVar1].width + sVar2 - 1;
    param_4 = pRVar3[param_1].screen_ypos - this->tile_half_hgt;
    this->tile_half_hgt = 0;
    this->tile_half_wid = 0;
    this->elev_hgt = 0;
    param_6 = this->map->tilesizes[bVar1].height + param_4 - 1;
}
