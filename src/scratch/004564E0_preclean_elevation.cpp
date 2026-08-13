// 004564E0 RGE_Map::preclean_elevation
// map.cpp
// Attempt log:
// try 1: replaced elevation helpers and int flags with typed tile access, short
// neighbor offsets, and direct byte updates; first clean reconstruction probe.
// try 2: changed the elevation temporaries to unsigned short, made the conflict
// result explicit, and used function-scope loop indices to mirror stack homes.
// try 3: ordered the eight short flag locals by their observed stack homes and
// reversed neighbor comparisons; this reached the original frame and size.
// try 4: split the tile byte from the signed short elevation; this moved all
// loop setup registers into the original coloring and reduced edit drift.
// try 5: changed elevation and neighbor levels to signed short; all comparison
// branch conditions now match the original signed word branches.
// try 6: redundant row-offset copies were codegen duplicates; removed for the
// final clean candidate. Remaining drift starts at the original row-offset spill.
// shard baseline: packet, dossier, same-TU donors, and ABI evidence confirm the
// natural owner model and the 0x48 frame; no codegen tuning started in this pass.
// orch probe 1: function-scope tile cursor, then split row lookup and offset;
// codegen duplicate, so the row-entry spill is not caused by cursor scope.
// orch probe 2: hoisted row and tile cursors; codegen duplicate.
// orch probe 3: hoisted short neighbor flags to match Ghidra local topology;
// codegen duplicate. Restored the clean typed candidate.
// paused: original has an isolated mov [esp+4c],ecx before map-row lookup;
// no natural typed cursor or flag-lifetime variant reproduced this store.

struct RGE_Tile {
    char gap_00[5];
    unsigned char screen_xpos;
    char gap_06[0x12];
};

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
    char gap_10[0x8d8c - 0x10];
    RGE_Tile** map_row_offset;

    void preclean_elevation(long x1, long y1, long x2, long y2,
                            unsigned char max_elevation);
};

void RGE_Map::preclean_elevation(long x1, long y1, long x2, long y2,
                                  unsigned char max_elevation)
{
    short width = (short)this->map_width;
    short offset_northwest = -1 - width;
    short offset_north = -width;
    short offset_northeast = 1 - width;
    short offset_southeast = width + 1;
    short offset_southwest = width - 1;
    short offset_south = width;
    long tile_offset = x1 * sizeof(RGE_Tile);
    long index2;
    long index1;
    unsigned char change_flag;

    do {
        change_flag = 0;
        if (x1 > 0) {
            --x1;
            tile_offset -= sizeof(RGE_Tile);
        }
        if (y1 > 0)
            --y1;
        if (x2 < this->map_width - 1)
            ++x2;
        if (y2 < this->map_height - 1)
            ++y2;

        for (index2 = y1; index2 <= y2; ++index2) {
            RGE_Tile* row = this->map_row_offset[index2];
            RGE_Tile* tile = (RGE_Tile*)((char*)row + tile_offset);
            for (index1 = x1; index1 <= x2; ++index1, ++tile) {
                unsigned char tile_byte = tile->screen_xpos;
                short northwest = 0;
                short northeast = 0;
                short east = 0;
                short southeast = 0;
                short south = 0;
                short southwest = 0;
                short west = 0;
                short north = 0;
                short elevation = (short)(tile_byte >> 5);

                if (index2 > 0 &&
                    ((tile + offset_north)->screen_xpos >> 5) > elevation)
                    north = 1;
                if (index2 < this->map_height - 1 &&
                    ((tile + offset_south)->screen_xpos >> 5) > elevation)
                    south = 1;
                if (index1 > 0 &&
                    (tile[-1].screen_xpos >> 5) > elevation)
                    west = 1;
                if (index1 < this->map_width - 1 &&
                    (tile[1].screen_xpos >> 5) > elevation)
                    east = 1;
                if (index2 > 0) {
                    if (index1 > 0 &&
                        ((tile + offset_northwest)->screen_xpos >> 5) > elevation)
                        northwest = 1;
                    if (index1 < this->map_width - 1 &&
                        ((tile + offset_northeast)->screen_xpos >> 5) > elevation)
                        northeast = 1;
                }
                if (index2 < this->map_height - 1) {
                    if (index1 > 0 &&
                        ((tile + offset_southwest)->screen_xpos >> 5) > elevation)
                        southwest = 1;
                    if (index1 < this->map_width - 1 &&
                        ((tile + offset_southeast)->screen_xpos >> 5) > elevation)
                        southeast = 1;
                }

                unsigned char conflict = 0;
                if (north && south)
                    conflict = 1;
                if (east && west)
                    conflict = 1;
                if (conflict) {
                    if (elevation >= max_elevation) {
                        if (northwest)
                            (tile + offset_northwest)->screen_xpos =
                                (unsigned char)(elevation << 5) |
                                ((tile + offset_northwest)->screen_xpos & 0x1f);
                        if (north)
                            (tile + offset_north)->screen_xpos =
                                (unsigned char)(elevation << 5) |
                                ((tile + offset_north)->screen_xpos & 0x1f);
                        if (northeast)
                            (tile + offset_northeast)->screen_xpos =
                                (unsigned char)(elevation << 5) |
                                ((tile + offset_northeast)->screen_xpos & 0x1f);
                        if (east)
                            tile[1].screen_xpos =
                                (unsigned char)(elevation << 5) |
                                (tile[1].screen_xpos & 0x1f);
                        if (southeast)
                            (tile + offset_southeast)->screen_xpos =
                                (unsigned char)(elevation << 5) |
                                ((tile + offset_southeast)->screen_xpos & 0x1f);
                        if (south)
                            (tile + offset_south)->screen_xpos =
                                (unsigned char)(elevation << 5) |
                                ((tile + offset_south)->screen_xpos & 0x1f);
                        if (southwest)
                            (tile + offset_southwest)->screen_xpos =
                                (unsigned char)(elevation << 5) |
                                ((tile + offset_southwest)->screen_xpos & 0x1f);
                        if (west)
                            tile[-1].screen_xpos =
                                (unsigned char)(elevation << 5) |
                                (tile[-1].screen_xpos & 0x1f);
                    } else {
                        tile->screen_xpos = (unsigned char)((elevation + 1) << 5) ^
                                               (tile->screen_xpos & 0x1f);
                    }
                    change_flag = 1;
                }
            }
        }
    } while (change_flag);
}
