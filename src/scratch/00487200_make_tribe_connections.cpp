// VA: 00487200 make_tribe_connections
// rmm_shal.cpp lines 106-245

// Attempt log:
// - Baseline first-pass decompiler translation had exact size but 1153 differing bytes.
// - Correct map-row ownership and local stack size restored the 0xE0 frame and improved shape.
// - Switch order alone regressed; original fall-through cases 8->4 and 10->5 were required.
// - Canonical Map_Stack plus a single natural pop loop reached exact size and 964 differing bytes.
// - Calls remain 14/14 ordered and the current source keeps named map and stack ownership.
// - Paused: frame was 0xD8 versus 0xE0, with broad register and block-layout drift remaining.
// - Main-agent ABI audit restored typed Map_Stack helper calls and a separate
//   pop cost output. The frame improved to 0xDC and positional drift fell to 956 bytes.
// - Tried keeping the water-area row bound live across both natural loops; size grew
//   by 88 bytes and drift worsened, so restored the prior clean source.
// - Hoisted the initial y/ty2 carry before the bounds guard; this improved the
//   structural diff from 956 to 935 bytes and matched more loop blocks.
// - Reordered stack_cost before Map_Stack to model the original separate cost
//   home; VC5 kept the same frame and bytes, so the lead was rolled back.
// - Follow-up probes corrected the water-area upper bound and retained the
//   binary's stack.y helper surface. The clean bounded result is 1224 bytes,
//   frame 0xE0, shape 74.20%, and 991 differing bytes. The older 1144-byte
//   result had a known wrong outer-loop bound and is not the final behavior model.
// - A byte-offset row-table cursor reduced the result to 1172 bytes and 905
//   differing bytes. Main review rejected that metric-only cursor and kept
//   typed row ownership. The frame remains four bytes short without padding.
// - Binary assembly uses integer bounds for the random water-area loops;
//   changing in_zone from float to long removed an x87 sequence and restored
//   the 1172-byte size. The frame remains 0xDC versus the original 0xE0.
// - Repeating the inner water-tile member read improved resynchronization
//   (edit cost 621 versus 708) without changing the strict 906-byte drift.
// - A typed row-table pointer restored the 0xE0 frame but increased strict
//   drift and was rejected. Explicit pop-result, zero-local, declaration-order,
//   and next-row-local probes were neutral or worse and were restored.

#include "..\..\include\rmm_shal_context.h"

void RGE_RMM_Shallows_Generator::make_tribe_connections(long param_1, long param_2) {
    int iVar2;
    int iVar4;
    long lVar6;
    float* pfVar7;
    long lVar8;
    int iVar9;
    long y;
    long ty2;
    long end_x;
    long tx1;
    long end_y;
    long ty;
    long done;
    long tx2;
    long in_zone;
    Map_Stack stack;
    float terrain[40];
    terrain[1] = 0.0f;
    end_x = this->info.shallows[param_1].x;
    done = this->info.shallows[param_1].y;
    iVar2 = this->info.shallows[param_2].x;
    iVar9 = this->info.shallows[param_2].y;

    // zero out terrain[2..40]
    pfVar7 = terrain + 2;
    iVar4 = 0x27;
    while (iVar4 != 0) {
        *pfVar7 = 0.0f;
        pfVar7++;
        iVar4--;
    }

    tx1 = iVar2;
    ty = iVar9;

    // BINARY NOTE: The shipped caller passes the sentinel through stack.y.
    this->init_stack((Map_Stack*)&stack.y);

    terrain[1] = 1.0f;
    terrain[3] = 1.0f;
    terrain[2] = 7.0f;
    terrain[0x17] = 14.0f;
    terrain[5] = 2.0f;

    this->find_path(end_x, done, &tx1, &ty, &terrain[1]);

    if (tx1 != iVar2 || ty != iVar9) return;

    // Keep the first step coordinates live before the bounds guard. The
    // original loop carries these values across its back edge.
    ty2 = ty;
    y = tx1;

    if (tx1 < 0 || tx1 >= this->map_width) return;
    if (ty < 0 || ty >= this->map_height) return;

    stack.prev = 0;
    terrain[0] = 0.0f;
    tx2 = 0;

    while (1) {
        unsigned char tile_type = this->search_map_rows[ty][tx1];

        switch (tile_type) {
        case 7: // tile type 7
            --ty2;
            break;
        case 6: // tile type 6
            ++ty2;
            break;
        case 11: // tile type 11
            --ty2;
            --y;
            break;
        case 9: // tile type 9
            --ty2;
            ++y;
            break;
        case 10: // tile type 10
            ++ty2;
        case 5: // tile type 5
            --y;
            break;
        case 8: // tile type 8
            ++ty2;
        case 4: // tile type 4
            ++y;
            break;
        default:
            tx2 = 1;
            break;
        }

        if (y < 0 || y >= this->map_width || ty2 < 0 || ty2 >= this->map_height) {
            tx2 = 1;
        }

        if (tx2 != 0) {
            // Pop from stack and modify terrain tiles
            // BINARY NOTE: pop_stack receives stack.y, but its cost output aliases stack.
            while (this->pop_stack((Map_Stack*)&stack.y, &y, &ty2, (float*)&stack) != 0) {
                RGE_Tile& tile = this->map_row_offset[ty2][y];
                tile.terrain = (tile.terrain & 0xE4) | 4;
            }
            this->deinit_stack((Map_Stack*)&stack.y);
            return;
        }

        // Check current tile terrain
        RGE_Tile** rows3 = this->map_row_offset;
        unsigned char terrain_type = rows3[ty2][y].terrain & 0x1F;

        if (terrain_type == 1 || terrain_type == 0x16) {
            // Water tile - generate random area around it
            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xC6);
            end_y = (y - (iVar2 * 2) / 0x7FFF) - 1;
            if (end_y < 0) end_y = 0;
            lVar6 = end_y;

            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xCA);
            lVar8 = (ty2 - (iVar2 * 2) / 0x7FFF) - 1;
            if (lVar8 < 0) lVar8 = 0;

            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xCE);
            in_zone = (iVar2 * 2) / 0x7FFF + 1 + y;
            if (in_zone >= this->map_width) in_zone = this->map_width - 1;

            iVar2 = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_shal.cpp", 0xD2);
            // BINARY NOTE: This bound remains live for the outer row loop.
            end_x = (iVar2 * 3) / 0x7FFF + 1 + ty2;
            if (end_x >= this->map_height) end_x = this->map_height - 1;

            done = lVar8;
            if (lVar8 <= end_x) {
                iVar2 = lVar8;
                do {
                    if (end_y <= in_zone) {
                        iVar9 = end_y;
                        done = lVar8;
                        do {
                            if ((this->map_row_offset[iVar2][iVar9].terrain & 0x1F) == 1 ||
                                (this->map_row_offset[iVar2][iVar9].terrain & 0x1F) == 0x16) {
                                this->push_stack((Map_Stack*)&stack.y, lVar6, lVar8, 0.0f, 0.0f);
                                lVar8 = done;
                            }
                            lVar6++;
                            ++iVar9;
                        } while (lVar6 <= in_zone);
                    }
                    lVar8++;
                    ++iVar2;
                    lVar6 = end_y;
                    done = lVar8;
                } while (lVar8 <= end_x);
            }
        } else {
            // Land tile - push adjacent water tiles to stack
            if (y > 0) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2][y - 1].terrain & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack((Map_Stack*)&stack.y, y - 1, ty2, 0.0f, 0.0f);
                }
            }
            if (y < this->map_width - 1) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2][y + 1].terrain & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack((Map_Stack*)&stack.y, y + 1, ty2, 0.0f, 0.0f);
                }
            }
            if (ty2 > 0) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2 - 1][y].terrain & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack((Map_Stack*)&stack.y, y, ty2 - 1, 0.0f, 0.0f);
                }
            }
            if (ty2 < this->map_height - 1) {
                RGE_Tile** rows5 = this->map_row_offset;
                unsigned char adj = rows5[ty2 + 1][y].terrain & 0x1F;
                if (adj == 1 || adj == 0x16) {
                    this->push_stack((Map_Stack*)&stack.y, y, ty2 + 1, 0.0f, 0.0f);
                }
            }
        }

        // Mark current tile on block map
        unsigned char** block_rows = (unsigned char**)this->search_map_rows;
        block_rows[ty][tx1] = 0xFF;

        tx1 = y;
        ty = ty2;
    }
}
