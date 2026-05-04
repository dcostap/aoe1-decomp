// VA: 0053C490 RGE_Visible_Map::get_visible (59B)
// PDB source: visible.cpp lines 361-382
// Define unified_map_offsets as inline cast to embed address in instruction.

#define unified_map_offsets ((unsigned long**)0x886808)

class RGE_Player {
public:
    char gap_00[0xD0];
    unsigned long mutualExploredMask;   // +0xD0
    unsigned long mutualVisibleMask;    // +0xD4
};

class RGE_Visible_Map {
public:
    char gap_00[8];
    RGE_Player* player;                // +0x08

    unsigned char get_visible(int x, int y);
};

unsigned char RGE_Visible_Map::get_visible(int x, int y) {
    unsigned long cell = unified_map_offsets[y][x]; 
    RGE_Player* p = this->player;
    if ((cell & p->mutualVisibleMask) != 0) return 0x0F;
    if ((cell & p->mutualExploredMask) != 0) return 0x80;
    return 0;
}
