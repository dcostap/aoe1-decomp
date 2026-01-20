#pragma once
#include "common.h"

struct Tile_BlackEdge_Table {
    VSpanMiniList* black_UNdraw;
};
static_assert(sizeof(Tile_BlackEdge_Table) == 0x4, "Size mismatch");
