#pragma once
#include "common.h"

struct Tile_FogEdge_Table {
    VSpanMiniList* normal_draw;
    VSpanMiniList* fog_draw;
};
static_assert(sizeof(Tile_FogEdge_Table) == 0x8, "Size mismatch");
