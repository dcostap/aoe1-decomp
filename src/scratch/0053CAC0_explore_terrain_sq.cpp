// VA: 0053CAC0 RGE_Visible_Map::explore_terrain_sq
// Source: visible.cpp lines 775-883
// Attempt log:
// baseline candidate: canonical x/y rectangle ownership and natural symmetry with
// explore_terrain/unexplore_terrain_sq; the oracle traverses rows by y1 and columns
// from x1 through x2.
// Hoisting curVis/tile initialization before the checksum recovered the configured
// 550-byte size and the best current basin.  Canonical polymorphic surfaces were
// codegen-neutral; the remaining drift is local-slot/hash operand scheduling and
// the late result/tile tail.  No call or ownership discrepancy remains.
// Full typed RGE_Tile/RGE_Map records, top-level typed row cursors, and an unsigned
// checksum accumulator preserve canonical map ownership but emitted identically.
// Declaration order, initializer form, and p6/curVis zero-store order were likewise
// neutral. Remaining drift begins before the hash: the oracle homes Revealed at
// [ebp-8] and its checksum/visible cursor at [ebp-4], while the default donor basin
// selects the inverse homes; the later checksum/ally scheduling follows that split.
// split the x-axis and y-axis rejection tests to mirror the two original source
// line bands and preserve the height value for the following y clamp.
// Follow-up probes: checksum-before-Revealed declaration order, dead-p6 checksum
// reuse, removal of the explicit _rotl pragma, an explicit zero carried into the
// negative-bound tests, an explicit inner while loop, and an array-backed checksum
// all emitted the same 544-byte code.  The stack spill remains a source/context
// blocker, not a proven ownership or control-flow difference.
// Current pass: typed unified_map_offsets[256], named width/height bounds, and
// the pretested inner while form preserve the terrain-array ownership and 550-byte
// basin.  Claim follow-up moved the x declaration before tile setup, then moved
// unconditional tile advancement after the visible, unified, and x updates.
// These binary-supported lifetime and update-order changes recover 69.00% exact
// blocks and 89.00% shape at the staged-hash basin. Main review rejected a
// nested hash expression that only reduced positional byte differences. Keep
// the clear checksum stages. The remaining blocker is pre-hash local and
// parameter-home scheduling. No call or ownership discrepancy remains.

#include "../../include/visible_context.h"

int RGE_Visible_Map::explore_terrain_sq(int x1, int y1, int x2, int y2,
                                        int update_tiles, int p6)
{
    unsigned char* p;
    unsigned long* unified;
    int Revealed;
    RGE_Player* curVisPlayer;
    int isCurPlayer;
    unsigned long checksum;
    RGE_Tile* tile;

    Revealed = 0;
    log_map_call(this->world->world_time, (int)this->player->id, 2, p6,
                 x1, y1, x2, y2, Map_Update_Suppresion);

    if (Map_Update_Suppresion != 0) {
        return 0;
    }

    isCurPlayer =
        (this->world->players[this->world->curr_player]->
             mutualAlly[this->player->id] == 1);
    p6 = 0;
    curVisPlayer = 0;
    tile = 0;

    checksum = this->input_csum;
    checksum = _rotl(checksum, 3);
    checksum ^= 0x34343434;
    checksum = _rotl(checksum, 2);
    checksum ^= x1;
    checksum = _rotl(checksum, 4);
    checksum ^= y1;
    checksum = _rotl(checksum, 3);
    checksum ^= x2;
    checksum = _rotl(checksum, 3);
    checksum ^= y2;
    this->input_csum = checksum;

    if (isCurPlayer) {
        curVisPlayer =
            this->world->players[this->world->curr_player];
    }

    int width = this->widthValue;
    int height = this->heightValue;

    if ((x1 >= width) || (x2 < 0)) {
        return 0;
    }
    if (y1 >= height) {
        return 0;
    }
    if (y2 < 0) {
        return 0;
    }
    if (x1 < 0) {
        x1 = 0;
    }
    if (x2 >= width) {
        x2 = width - 1;
    }
    if (y1 < 0) {
        y1 = 0;
    }
    if (y2 >= height) {
        y2 = height - 1;
    }

    for (; y1 <= y2; ++y1) {
        p = this->map_offsets[y1] + x1;
        unified = unified_map_offsets[y1] + x1;
        int x = x1;
        if (update_tiles != 0) {
            tile = this->map->map_row_offset[y1] + x1;
        }

        while (x <= x2) {
            unsigned char value = *p;
            ++value;
            if (value == 0) {
                ++Revealed;
                ++this->numberTilesExploredValue;
                this->player->tile_list.add_node(x, y1);
                if (isCurPlayer) {
                    curVisPlayer->diam_tile_list.add_node(x, y1);
                }
                *unified |= this->PlayerExploredMaskValue;
                value = 1;
            }
            if (value == 1) {
                if (update_tiles != 0) {
                    tile->flags_09 = 0x0F;
                }
                *unified |= this->PlayerVisibleMaskValue;
            }
            if (value == 0xFA) {
                value = 0xF9;
            }
            *p = value;
            ++p;
            ++unified;
            ++x;
            ++tile;
        }
    }
    return Revealed;
}
