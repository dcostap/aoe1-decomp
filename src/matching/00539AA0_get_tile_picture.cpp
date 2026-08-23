// 00539AA0 protected RGE_View::get_tile_picture
// PDB: view.cpp:5559-5610, ?get_tile_picture@RGE_View@@IAEFEEFF@Z.
// Body: 00539AA0-00539B8D. Padding: 00539B8E-00539B8F. Next: 00539B90.
// BINARY NOTE: The original writes rows and cols to the byte parameter homes.
// This source reuses those parameters for modulo remainders and preserves fault order.
// Exact-finish note: public access kept bytes exact but lost the PDB access qualifier.

struct RGE_TOB_Picts { short count; short animations; short shape_index; };
struct RGE_Tile_Set { unsigned char gap_00[0x20]; void* shape; unsigned char gap_24[0x22]; RGE_TOB_Picts tiles[19]; short terrain_to_draw; short rows; short cols; unsigned char gap_BE[0x198 - 0xBE]; };
struct RGE_Map { unsigned char gap_00[0x8C]; RGE_Tile_Set terrain_types[32]; };
class TPanel { public: unsigned char gap_00[0xF4]; };
class RGE_View : public TPanel { public: unsigned char gap_F4[0x10]; RGE_Map* map; protected: short get_tile_picture(unsigned char param_1, unsigned char param_2, short param_3, short param_4); };

short RGE_View::get_tile_picture(unsigned char param_1, unsigned char param_2, short param_3, short param_4) {
    RGE_Tile_Set* ts = &this->map->terrain_types[param_1];
    if (ts->shape == 0) return -1;

    RGE_TOB_Picts* tile = &ts->tiles[param_2];
    if (tile->count == 0) return -1;

    short result = 0;
    if (tile->count > 1) {
        unsigned char rows = (unsigned char)ts->rows;
        unsigned char cols = (unsigned char)ts->cols;
        param_1 = rows;
        param_2 = cols;
        if (rows > 1 || cols > 1) {
            if (rows > 0) param_1 = (unsigned char)(param_4 % rows); else param_1 = 0;
            if (cols > 0) param_2 = (unsigned char)(param_3 % cols); else param_2 = 0;
            result = (unsigned short)param_1 * (unsigned short)cols + (unsigned short)param_2;
        }
    }

    if (result > tile->count - 1) result = 0;
    return (short)(tile->animations * result + tile->shape_index);
}
