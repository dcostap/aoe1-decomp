// RGE_Map::save_map (00457C50, map.cpp:1585-1622)
// Attempt log:
// 1 baseline: typed RGE_Map/RGE_Tile ownership, paired old/new tile formats,
// and direct zone/visibility save methods; 400B, structural mismatch.
// 2 handle local: duplicate codegen; retained the natural descriptor capture.
// 3 version-arm reversal: moved the old bulk-copy block to its late target;
// size became exact and the diff fell to 165B.
// 4 row-counter placement: initializing y inside the positive new-format arm
// after its local height pointer reached 403B with 5 differing bytes.
// 5 negated-less-than spelling: duplicate codegen.
// 6 height pointer/member split: same-size 262B diagnostic variant; rolled
// forward to the cleaner arm-local pointer shape.
// 7 y initialization before the height test: 5-byte best basin (100% shape,
// all calls/CFG/relocations exact); probes 8-10 arithmetic/pointer variants
// were codegen duplicates. Remaining drift is only old-format multiply operand
// order: original loads height then multiplies width, rebuilt reverses them.
// 8 common height pointer after the width write: old-format product became
// exact, but the loop tail swapped the y/map reload order (4 bytes remain).
// 9-10 direct-this and staged-product variants: codegen duplicates; retained
// the typed common-height form as the best period-plausible reconstruction.
// 11 hoisted x/tile declarations: codegen duplicate; restored the clean
// block-scoped form because the four-byte tail reload order did not move.
// 12 outer do-while changed to a for loop to test compiler loop-control
// scheduling at the four-byte tail; no codegen change; rolled back.
// 13 moved the outer increment into the do-while condition as ++y to test
// expression-tree scheduling at the four-byte tail; no codegen change; rolled
// back.
// 14 declared y in a canonical for loop to test scope/lifetime scheduling;
// no codegen change; rolled back.
// 15 hoisted y's declaration to function scope while keeping its branch-local
// initialization to test local lifetime and reload scheduling; no codegen
// change; rolled back.
// 16 restored source-level old-format-first ordering to test whether the
// compiler's branch layout also restores the target loop-tail load order;
// it changed the branch shape and grew the diff to 252 bytes; rolled back.
// 17 reversed the outer bound comparison to *height > y to test operand-order
// scheduling at the four-byte tail; it changed the comparison block and grew
// the diff to 6 bytes; rolled back.
// 18 no further source-backed axis remains after loop-form and scope probes;
// preserve the clean typed reconstruction for final validation.
// 19 direct this ownership for the row lookup was a codegen duplicate.
// 20 removing the explicit map alias throughout was a codegen duplicate.
// 21 moving y before the handle and map declarations was a codegen duplicate.
// 22 passing file directly instead of through handle was a codegen duplicate.
// 23 declaring width before map was a codegen duplicate.
// 24 using *width in both new-format loop bounds was a codegen duplicate.
// All six focused probes left the same four-byte y/map load-order gap; restore
// the clean source because no natural source axis remains evidence-backed.
// ACCEPTED_DRIFT: main-agent adjudication confirmed the four remaining bytes
// only reverse independent 32-bit reloads of initialized local y and map homes.
// Their later uses, call order, CFG, width, and loop control are identical.
// No alias or flags effect is possible for these valid local-stack loads.

extern "C" void __cdecl rge_write(int file, void* data, int size);
extern float save_game_version;
extern float DAT_005706a8;

#ifndef MAP_CONTEXT_H
class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    char gap_07[0x11];
};

class RGE_Zone_Map_List {
public:
    void save(int file);
};

class RGE_Unified_Visible_Map {
public:
    void save(int file);
};

class RGE_Map {
public:
    char gap_00[0x4];
    RGE_Tile* map;
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x28];
    unsigned char map_visible_flag;
    unsigned char fog_flag;
    char gap_8DBA[2];
    char gap_8DBC[8];
    RGE_Zone_Map_List* map_zones;
    RGE_Unified_Visible_Map* unified_vis_map;

    void save_map(int file);
};

#endif

void RGE_Map::save_map(int file)
{
    int handle = file;
    RGE_Map* map = this;
    int* width = &map->map_width;
    rge_write(handle, width, 4);

    int* height = &map->map_height;
    rge_write(handle, height, 4);
    map->map_zones->save(handle);
    rge_write(handle, &map->map_visible_flag, 1);
    rge_write(handle, &map->fog_flag, 1);

    if (!(save_game_version < DAT_005706a8)) {
        int y = 0;
        if (*height > 0) {
        do {
            int x = 0;
            RGE_Tile* tile = map->map_row_offset[y];
            if (map->map_width > 0) {
                do {
                    rge_write(handle, tile, 2);
                    rge_write(handle, &tile->screen_ypos, 2);
                    rge_write(handle, &tile->tile_type, 1);

                    unsigned char value = tile->terrain_type & 0x1f;
                    rge_write(handle, &value, 1);
                    value = tile->terrain_type >> 5;
                    rge_write(handle, &value, 1);
                    value = tile->border_type & 0x0f;
                    rge_write(handle, &value, 1);
                    value = tile->border_type >> 4;
                    rge_write(handle, &value, 1);

                    ++tile;
                    ++x;
                } while (x < map->map_width);
            }
            y++;
        } while (y < *height);
        }
    } else {
        int tile_count = *height;
        tile_count *= this->map_width;
        rge_write(handle, this->map, tile_count * 0x18);
    }

    map->unified_vis_map->save(handle);
}
