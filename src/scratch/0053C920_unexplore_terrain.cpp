// VA: 0053C920 RGE_Visible_Map::unexplore_terrain
// Source: visible.cpp lines 665-767
// Attempt log:
// baseline candidate: canonical visible-map/world/player/map ownership and natural
// LOS-table traversal paired with unexplore_terrain_sq.
// /Oy- moved the candidate into the correct EBP basin and to 384 bytes; absolute
// binary-proven LOS table bases improved relocation/edit alignment, while canonical
// polymorphic map/player surfaces were codegen-neutral.
// Player-id ordering, checksum naming, and LOS skip/control-flow variants were
// nonproductive.  The remaining gap is the original three-local frame and its
// parameter-home reuse; no call or field ownership mismatch is indicated.
// Typed LOSTBL records, sized unified-map rows, and full canonical RGE_Tile/
// RGE_Map surfaces emitted identically to the clean source. A typed player owner
// local and a center-y copy likewise produced no codegen movement. The original
// EBP frame and reuse of the square/p6 homes remain an ABI/codegen-context blocker;
// diagnostic forms were restored rather than retained as scaffolding.
// Follow-up session: swapping checksum/player-id assignment order, retaining a
// self alias, splitting a checksum temporary, and lifting cursor locals were
// codegen-duplicates under default /O2 /Oy. Narrow volatile player-id/tile
// diagnostics moved emitted code but did not recover the EBP frame and were
// rolled back. A temporary /Oy- response file improved the frame basin to 394
// bytes/320 strict diff, but still had an 8-byte frame and remained a flag-only
// diagnostic; it was removed. The clean typed source is restored below.
// Additional pass: direct-this and reference-self spellings, C++ versus C
// linkage for log_map_call, a sized unified-map declaration, string.h context,
// function-scope cursor declarations, named radius/x locals, and guard polarity
// were either codegen duplicates or flag-only diagnostics. An ambient declaration
// sweep of 256 samples was also one codegen basin. The /Oy- basin remained
// 394 bytes with an 8-byte frame, versus the oracle's 401 bytes and 0xC frame.
// Restore the default canonical source and seek original TU/flag evidence for
// the saved-this, player-id, and parameter-home topology.
// Final source keeps the symbol-backed LOSTBL* declarations and full typed map/tile
// records even though VC5 emitted the same bytes; the prior validation metrics remain
// authoritative for this canonical-source correction.
// Fresh pass: restore the decorated C++ log_map_call symbol and the reviewed
// 256-row unified-map declaration. Direct this expressions and checksum load order
// remain codegen duplicates. A natural negative-bound continue reached 388 bytes
// and a 380-byte diff, but worsened CFG shape, so it was rolled back. The clean
// typed traversal remains 376 bytes with a 385-byte strict diff. The saved-this,
// plNum, and parameter-home basin still needs original TU evidence.
// Revisit: the paired explore_terrain_sq type surface, the complete player field
// surface, guarded plNum scope, split tile initialization, and a branch-local
// self alias all remained in the 376-byte default basin. The original /Oy- probe
// remained 394 bytes with an 8-byte frame and a 320-byte diff. These are diagnostic
// basins only. No policy-valid exact source was found in this pass.
// Current claim: function-local /Oy- remained the best shape diagnostic at 394
// bytes, a 0x08 frame, and a 320-byte diff. Reordered plNum/tile declarations,
// player-id initialization, and a separate checksum accumulator were duplicates.
// A volatile player-id spill reached 398 bytes and a 315-byte diff, but it did
// not create the oracle 0x0C frame, so it is not retained. Reusing clipped x2 as
// the inner countdown worsened the structure to 384 bytes and 342 bytes. The
// unsigned-count form duplicated the /Oy- basin. The pinned default typed source
// is restored; final validation is 376 bytes, 385-byte strict diff, and no
// policy-valid exact source.

#include "../../include/visible_context.h"

void RGE_Visible_Map::unexplore_terrain(int x, int y, int radius, int square,
                                        int update_tiles, int p6)
{
    RGE_Tile* tile = 0;
    int plNum;

    log_map_call(this->world->world_time, (int)this->player->id, 3, p6,
                 x, y, radius, square, Map_Update_Suppresion);

    if (Map_Update_Suppresion == 0) {
        p6 = this->input_csum;
        plNum = (int)this->player->id;
        p6 = _rotl(p6, 3);
        p6 ^= 0x20202020;
        p6 = _rotl(p6, 2);
        p6 ^= plNum;
        p6 = _rotl(p6, 3);
        p6 ^= x;
        p6 = _rotl(p6, 4);
        p6 ^= y;
        p6 = _rotl(p6, 3);
        p6 ^= radius;
        p6 += square;
        this->input_csum = p6;

        if (radius > 0x10) {
            radius = 0x10;
        }

        LOSTBL* offsets;
        if (square != 0) {
            offsets = SquareLOS[radius];
        } else {
            offsets = NormalLOS[radius];
        }

        int off_y = offsets->y;
        while (off_y != 999) {
            off_y += y;
            if ((off_y >= 0) && (off_y < this->heightValue)) {
                int x1 = offsets->x1 + x;
                if (x1 < 0) {
                    x1 = 0;
                }
                int x2 = offsets->x2 + x;
                if (x2 >= this->widthValue) {
                    x2 = this->widthValue - 1;
                }

                unsigned char* visible = this->map_offsets[off_y] + x1;
                unsigned long* explored = unified_map_offsets[off_y] + x1;
                if (update_tiles != 0) {
                    tile = this->map->map_row_offset[off_y] + x1;
                }

                if (x1 <= x2) {
                    int count = x2 - x1 + 1;
                    do {
                        unsigned char value = *visible;
                        --value;
                        if (value == 0xff) {
                            value = 0;
                        }
                        if (value == 0) {
                            if (update_tiles != 0) {
                                tile->flags_09 = 0x80;
                            }
                            *explored &= this->PlayerVisibleMaskInvertValue;
                        }
                        *visible = value;
                        ++visible;
                        ++explored;
                        ++tile;
                        --count;
                    } while (count != 0);
                }
            }

            ++offsets;
            off_y = offsets->y;
        }
    }
}
