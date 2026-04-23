// tried direct Ghidra spelling; VC5 kept shifting the player load / final mask fold
// tried local player/mask temps and a row temp; mismatch moved earlier into the first load-order bytes
// leaving this in scratch: remaining gap is early register/load ordering plus the 0x80 boolean fold

extern unsigned long* unified_map_offsets[256];

class RGE_Player {
public:
    char gap_00[0xD0];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
};

class RGE_Visible_Map {
public:
    char gap_00[8];
    RGE_Player* player;

    unsigned char get_visible(int x, int y);
};

unsigned char RGE_Visible_Map::get_visible(int x, int y) {
    unsigned long value = unified_map_offsets[y][x];
    if ((value & this->player->mutualVisibleMask) != 0) {
        return 0x0F;
    }
    return (unsigned char)(-(int)((value & this->player->mutualExploredMask) != 0) & 0x80);
}
