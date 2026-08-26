// VA: 0053C490 RGE_Visible_Map::get_visible (59B)
// PDB source: visible.cpp lines 361-382

#include "../../include/visible_context.h"

#define unified_map_offsets ((unsigned long**)0x886808)

unsigned char RGE_Visible_Map::get_visible(int x, int y) const {
    unsigned long cell = unified_map_offsets[y][x];
    RGE_Player* p = this->player;
    if ((cell & p->mutualVisibleMask) != 0) return 0x0F;
    if ((cell & p->mutualExploredMask) != 0) return 0x80;
    return 0;
}

#undef unified_map_offsets
