// VA: 0053C6F0 RGE_Visible_Map::explore_terrain
// Source: visible.cpp lines 521-658
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map ownership and the
// natural paired explore/unexplore loops.
// External LOS/unified-map declarations recover the same-TU register/local basin;
// the remaining mismatch is the checksum spill/suppression compare and a short
// late-loop schedule.  A polymorphic full-class context was codegen-neutral.
// Default /O2 /Oy was tested and regressed to 571 bytes/64.1% shape; retain the
// existing narrow /Oy- donor-context flag while this target remains unresolved.
// Main-agent audit replaced raw absolute globals and byte tile cursors with
// canonical symbols and typed map/tile ownership.
// Binary symbol evidence confirms unified_map_offsets is unsigned long*[] and
// NormalLOS/SquareLOS are LOSTBL*[]; typed those globals/locals and the complete
// RGE_Tile/RGE_Map layout without changing emitted instructions. Making tile advance
// unconditional, as the oracle's post-store stride proves, improved the typed source
// to 466 positional bytes / 90.91% shape / 85.16% resync similarity.
// A radius_value local was source-plausible but codegen-neutral; a positive
// suppression-success wrapper worsened CFG and was rolled back. Remaining drift
// starts at the zero-register suppression cmp (oracle xor/cmp versus rebuilt test)
// and the checksum parameter-home spill; no raw byte cursor is retained.
// Follow-up probes: wrapping the full success body in the binary je-to-body
// guard reproduced the prior 457-byte basin and was restored. Direct player-id
// hashing, an unsigned checksum accumulator, local declaration reordering, and
// a dedicated zero guard local were all emitted-code duplicates of the clean
// source. The new blocker lead is therefore the old-TU local-lifetime/context
// split that spills checksum to [ebp-14] and reuses the p6 home; do not retain
// artificial stack or volatile steering.
// Revisit probes: an explicit in-body Revealed return preserved the two-return
// CFG but stayed in the 457-byte basin; an early curVisPlayer initializer
// regressed to 531 bytes. A default-zero ally guard reached 468 bytes and was
// also restored. The canonical typed source remains the clean owner.
// Accepted-drift audit: do not promote this candidate. Before the ally lookup,
// the original reloads this->player after publishing input_csum. The rebuild
// reuses the player pointer read during checksum calculation. Concurrent player
// pointer mutation can therefore change the ally test and later tile-list call.
// Current claim probes: zero-valued guard locals, fresh player aliases, checksum
// declaration scope/order, and a complete world map member all rebuilt the same
// 527-byte basin. Moving radius initialization before the log moved to 533 bytes
// but worsened CFG and shape. Restore the pinned typed source; no new owner fact
// was established.

#include "../../include/visible_context.h"

int RGE_Visible_Map::explore_terrain(int x, int y, int radius, int square,
                                     int update_tiles, int p6)
{
    int Revealed;
    int checksum;
    int radius_value;
    RGE_Player* curPlayer;
    int VisibleToCurPlayer;
    RGE_Player* curVisPlayer;
    LOSTBL* offsets;
    int offY;
    int y2;
    int x1;
    int x2;
    unsigned char* vis;
    unsigned long* unified;
    RGE_Tile* tile;
    unsigned char v;

    Revealed = 0;
    log_map_call(this->world->world_time, this->player->id, 1, p6,
                 x, y, radius, square, Map_Update_Suppresion);
    if (Map_Update_Suppresion != 0) {
        return 0;
    }

        p6 = this->input_csum;
        checksum = (int)this->player->id;
        p6 = _rotl(p6, 3);
        p6 ^= 0x01010101;
        p6 = _rotl(p6, 2);
        p6 ^= checksum;
        p6 = _rotl(p6, 3);
        p6 ^= x;
        p6 = _rotl(p6, 4);
        p6 ^= y;
        p6 = _rotl(p6, 3);
        p6 ^= radius;
        p6 += square;
        this->input_csum = p6;

        curPlayer = this->world->players[this->world->curr_player];
        if (curPlayer != 0) {
            VisibleToCurPlayer =
                (curPlayer->mutualAlly[this->player->id] == 1);
        } else {
            VisibleToCurPlayer = 0;
        }

        tile = 0;
        curVisPlayer = 0;
        if (VisibleToCurPlayer) {
            curVisPlayer = curPlayer;
        }

        radius_value = radius;
        if (radius_value > 0x10) {
            radius_value = 0x10;
        }

        if (square != 0) {
            offsets = SquareLOS[radius_value];
        } else {
            offsets = NormalLOS[radius_value];
        }

        offY = offsets->y;
        while (offY != 999) {
            y2 = y + offY;
            if ((y2 >= 0) && (y2 < this->heightValue)) {
                x1 = x + offsets->x1;
                if (x1 < 0) {
                    x1 = 0;
                }
                x2 = x + offsets->x2;
                if (x2 >= this->widthValue) {
                    x2 = this->widthValue - 1;
                }

                vis = this->map_offsets[y2] + x1;
                unified = unified_map_offsets[y2] + x1;
                if (update_tiles != 0) {
                    tile = this->map->map_row_offset[y2] + x1;
                }

                while (x1 <= x2) {
                    v = (unsigned char)(*vis + 1);
                    if (v == 0) {
                        Revealed++;
                        this->numberTilesExploredValue++;
                        this->player->tile_list.add_node(x1, y2);
                        if (VisibleToCurPlayer) {
                            curVisPlayer->diam_tile_list.add_node(x1, y2);
                        }
                        v = 1;
                        *unified |= this->PlayerExploredMaskValue;
                    }
                    if (v == 1) {
                        if (update_tiles != 0) {
                            tile->flags_09 = 0x0F;
                        }
                        *unified |= this->PlayerVisibleMaskValue;
                    }
                    if (v == 0xFA) {
                        v = 0xF9;
                    }
                    *vis = v;
                    ++vis;
                    ++unified;
                    x1++;
                    ++tile;
                }
            }
            ++offsets;
            offY = offsets->y;
        }
    return Revealed;
}
