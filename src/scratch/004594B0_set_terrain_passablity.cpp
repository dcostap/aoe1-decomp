// VA: 004594B0 RGE_Map::set_terrain_passablity
//
// Binary-supported ownership: the method clips a rectangle to the map, then
// replaces the low five terrain bits in every covered tile with the selected
// terrain set's passable or impassable value.
//
// Attempt log:
// - Baseline: typed rectangle loops matched size (303B) and saved registers;
//   the prologue and loop register/stack-home topology remained broad drift.
// - Explicit row/column offset-count cursors and a typed row base preserved
//   the observed map-row/0x18-tile ownership but initially worsened structure.
// - Reversing each swap to use the upper bound as the temporary was a useful
//   local lead; a full-width x temporary gave the best emitted result (291
//   positional bytes differing), but did not repair the opening stack home.
// - Shared swap temporary, named min/max locals, and declaration-order
//   variants were duplicate or broader basins; restored the best typed source.
// - Remaining mismatch is broad VC5 register allocation and local stack-home
//   placement (target begins with push ecx and keeps distinct row/column
//   counters). No calls or behavior/layout facts remain unresolved.
// - Main-agent audit restored ordinary row/column subscripting and named tile
//   ownership; byte-offset cursors from the codegen experiments were removed.

class RGE_Tile {
public:
    char gap_00[5];
    unsigned char terrain_type;
    char gap_06[0x12];
};

class RGE_Tile_Set {
public:
    char gap_00[0x2D];
    unsigned char passable_terrain;
    unsigned char impassable_terrain;
    char gap_2F[0x198 - 0x2F];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    RGE_Tile* map;
    int map_width;
    int map_height;
    char gap_10[0x7C];
    RGE_Tile_Set terrain_types[32];
    char gap_338C[0x5A00];
    RGE_Tile** map_row_offset;

    void set_terrain_passablity(short x1, short y1, short x2, short y2,
                                unsigned char passable);
};

void RGE_Map::set_terrain_passablity(short x1, short y1, short x2, short y2,
                                     unsigned char passable)
{
    if (y1 > y2) {
        short temp = y2;
        y2 = y1;
        y1 = temp;
    }
    if (x1 > x2) {
        int temp = x2;
        x2 = x1;
        x1 = (short)temp;
    }

    if (y1 < 0) {
        y1 = 0;
    }
    if ((int)y2 >= this->map_height) {
        y2 = (short)this->map_height - 1;
    }
    if (x1 < 0) {
        x1 = 0;
    }
    if ((int)x2 >= this->map_width) {
        x2 = (short)this->map_width - 1;
    }

    if (y1 <= y2) {
        for (int y = y1; y <= y2; ++y) {
            if (x1 <= x2) {
                for (int x = x1; x <= x2; ++x) {
                    RGE_Tile* tile = &this->map_row_offset[y][x];
                    unsigned char old_terrain = tile->terrain_type;
                    short terrain_type = (short)(old_terrain & 0x1F);
                    unsigned char replacement;

                    if (passable != 0) {
                        replacement = this->terrain_types[terrain_type].passable_terrain;
                    } else {
                        replacement = this->terrain_types[terrain_type].impassable_terrain;
                    }
                    tile->terrain_type =
                        (unsigned char)((replacement ^ old_terrain) & 0x1F) ^ old_terrain;
                }
            }
        }
    }
}
