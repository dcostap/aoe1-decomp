// tried local row/value/player/mask variants and direct repeated-expression variants.
// Best source shape still misses early load/register order: VC5 wants either
// mov eax,[ecx+8] first or keeps the map cell in ecx/edx instead of the original
// y -> eax, player -> ecx, row -> edx, value -> eax sequence. Boolean 0x80 fold also
// stays in eax (neg/sbb eax,eax) instead of original ecx/cl fold.
extern unsigned long* unified_map_offsets[];

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
    if ((unified_map_offsets[y][x] & this->player->mutualVisibleMask) != 0) {
        return 0x0F;
    }
    return (unsigned char)(-((this->player->mutualExploredMask & unified_map_offsets[y][x]) != 0) & 0x80);
}
