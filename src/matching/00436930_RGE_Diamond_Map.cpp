// 00436930 ~RGE_Diamond_Map (137 bytes) — MATCHED
// PDB: diam_map.cpp (RGE_Diamond_Map::~RGE_Diamond_Map)

#include <stdlib.h>

class TPanel {
public:
    virtual ~TPanel();
};

class RGE_Diamond_Map : public TPanel {
public:
    virtual ~RGE_Diamond_Map();
    void delete_surfaces();

    char gap_04[0x124];   // from +0x04 to +0x127 (after implicit vtable at +0x00)
    int map_image_lines;   // +0x128
    int map_tile_rows;     // +0x12C
    char gap_130[0x34];    // +0x130 to +0x163
    int own_save_area;     // +0x164
    void* save_area;       // +0x168
};

RGE_Diamond_Map::~RGE_Diamond_Map()
{
    this->delete_surfaces();
    if (this->map_tile_rows != 0) {
        free((void*)this->map_tile_rows);
        this->map_tile_rows = 0;
    }
    if (this->map_image_lines != 0) {
        free((void*)this->map_image_lines);
        this->map_image_lines = 0;
    }
}
