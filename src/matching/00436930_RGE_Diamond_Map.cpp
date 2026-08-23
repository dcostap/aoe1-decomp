#include "../../include/diam_map_context.h"

// 00436930 ~RGE_Diamond_Map (137 bytes) — MATCHED
// PDB: diam_map.cpp (RGE_Diamond_Map::~RGE_Diamond_Map)

#include <stdlib.h>

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
