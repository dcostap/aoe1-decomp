// 00484D00 RGE_RMM_Elevation_Generator::base_elevation_generate
// Source: rmm_elev.cpp lines 290-403
//
// Natural reconstruction of the elevation clump seeding/expansion routine.
// The executable proves the map-row, search-map, stack, helper ABI, and four
// weighted neighbor-random branches below; keep those ownership facts explicit.
// Initial scratch was a raw direct reconstruction with 21 calls and a 992-byte
// body. This source restores the period typed surfaces and all five debug_rand
// sites before any codegen tuning.
// Matching claim: replacing the first seed do-loop with a natural while loop
// removed a duplicated pop_stack site and aligned all 23 direct calls. Reusing
// the pop cost out-home removed one redundant local and reached the original
// 0x988 frame; restoring the explicit cost local is retained as the more
// period-plausible final source because it preserves the real pop ABI. Named
// clumps/base-elevation locals, stack declaration order, and nested neighbor
// guards were codegen duplicates. Final gap: +14 bytes / 0x984 frame, with
// calls and target order aligned; no raw/asm scaffolding retained.
// Current claim probes: 34+ evidence-led probes retained a smaller natural
// basin at 796 differing bytes, 1273 rebuilt bytes, and 0x980 frame. The
// direct seed tile RMW matches its original LEA/address shape. The fairness
// expansion arm is written as positive expansion with mark reset in else;
// this matches the original cmp/jg layout better than the equivalent inverse.
// Full integer check results improve the test shape, but do not recover the
// original local frame. Saved max-y bounds, cached clump counts, countdown
// init, and score-local reuse were worse or duplicate. The retained source is
// the clearest natural nonexact basin; no asm or metric-only padding remains.
// Fresh shard probes (sa-3119f01e-r1): the original local head writes next and
// prev, leaves pop output homes uninitialized, and uses a 0x988 frame with the
// stack array at the proven boundary. Corrected head fields, declaration order,
// pointer walks, phase cursor order, mark-row aliases, and direct long
// comparisons were worse, duplicate, or moved to the known 0x984/0x988 basin.
// The clean 796-byte basin remains the best natural source. The reviewed
// Map_Stack ABI also confirms that cost is float, even though this function
// only passes stack addresses to the helpers.

#include <math.h>

#include "..\..\include\rmm_elev_context.h"

extern int __cdecl debug_rand(char* file, int line);
extern char s_C__msdev_work_age1_x1_rmm_elev_c[];

// Main-agent audit confirmed canonical elevation/map-stack ownership and kept
// the natural typed clump-expansion source.
// Continuation (sa-ab4dd300-r1): rmm_land's verified pop_stack ABI exposed a
// real row/column transpose in the four neighbor bounds: y is the column and
// x is the row. Direct map_width/map_height guards replaced unproven carried
// max-bound locals, improving the frame basin and exact-block coverage. The
// phase-B source now has a separate stack_ptr plus countdown, matching the
// original stack[0] cursor and dec/jnz pass. Main-agent audit restored the
// pop cost output to its natural float owner rather than retaining a diagnostic
// long-slot type pun. Validation before that audit:
// 1109 differing bytes, 1287-byte code versus 1273, frame 0x984 versus 0x988,
// all 23 direct call sites aligned. Remaining gap starts in the prologue/local
// window and is structural; no asm or opaque register scaffolding retained.
// Current claim: rechecked the full packet, dossier, ABI donors, and the
// executable-supported helper surfaces. The prior 10-probe campaign already
// exhausted natural phase-loop/local-window leads; retain this readable source
// rather than repeat the 14-byte boundary/frame basin blindly.
// Context pass: PROVED PDB module rmm_elev.cpp, lines 290-403, and owner class
// RGE_RMM_Elevation_Generator. PROVED address order and all 23 direct-call
// anchors. LIKELY source declarations follow the nearby terrain generator.
// UNKNOWN original local-home allocation remains the grouped blocker.
// BINARY NOTE: pop_stack receives y output before x output in this owner.
// Keep that order to preserve the executable's adjacent coordinate homes.
unsigned char RGE_RMM_Elevation_Generator::base_elevation_generate(
    RGE_Elevation_Info_Line line)
{
    long x = 0;
    long y = 0;
    long chance;
    long clump_size;
    float stack_cost;
    float local_chance = 0.0f;
    unsigned char ok;
    char done;
    Map_Stack local_stack;
    Map_Stack stack[99];

    local_stack.x = this->map_width - 1;
    chance = 0;

    if (line.clumps > 0) {
        for (long i = 0; i < line.clumps; ++i) {
            this->init_stack(&stack[i]);
        }
    }

    local_stack.prev = 0;
    stack[0].x = 0;
    this->link_stack_randomly(&local_stack);

    clump_size = (long)sqrt((double)line.elevation_size / (double)line.clumps);
    clump_size /= 2;
    if (clump_size < 2) {
        clump_size = 2;
    }

    {
        long i = 0;
        while (i < line.clumps) {
            Map_Stack* node = this->pop_stack(&local_stack, &y, &x,
                &stack_cost);
            if (node == 0) {
                break;
            }

            if (this->search_map_rows[x][y] == 0
                && this->check_start_elevation(y, x,
                    (unsigned char)line.base_terrain_type,
                    (unsigned char)line.base_elevation,
                    (unsigned char)line.spacing) != 0) {
                this->remove_area_from_lists(y, x, clump_size);

                *((unsigned char*)this->map_row_offset[x] + y * 0x18 + 5) =
                    (unsigned char)(line.elevation << 5)
                    | (*((unsigned char*)this->map_row_offset[x]
                        + y * 0x18 + 5) & 0x1F);

                if (y > 0) {
                    this->push_stack(&stack[i], y - 1, x, 0.0f, 0.0f);
                }
                if (x > 0) {
                    this->push_stack(&stack[i], y, x - 1, 0.0f, 0.0f);
                }
                if (y < this->map_width - 1) {
                    this->push_stack(&stack[i], y + 1, x, 0.0f, 0.0f);
                }
                if (x < this->map_height - 1) {
                    this->push_stack(&stack[i], y, x + 1, 0.0f, 0.0f);
                }

                ++chance;
                ++i;
            }
        }
    }

    do {
        done = 1;
        if (line.clumps > 0) {
            Map_Stack* stack_ptr = stack;
            long phase_count = line.clumps;
            do {
                if (chance < line.elevation_size) {
                    Map_Stack* node = this->pop_stack(stack_ptr, &y, &x,
                        &stack_cost);
                    if (node != 0) {
                        done = 0;
                        unsigned char* mark = &this->search_map_rows[x][y];
                        long random_value = (debug_rand(
                            s_C__msdev_work_age1_x1_rmm_elev_c, 0x171) * 100)
                            / 0x7FFF;
                        if (*mark <= random_value) {
                            unsigned char* tile =
                                (unsigned char*)this->map_row_offset[x]
                                + y * 0x18;
                            long raw_ok = this->check_elevation(
                                (unsigned char)line.elevation, y, x,
                                line.spacing,
                                (unsigned char)line.base_terrain_type,
                                (unsigned char)line.base_elevation);
                            ok = (unsigned char)raw_ok;

                            if (((tile[5] >> 5)
                                == (unsigned char)line.base_elevation)
                                && raw_ok > 0) {
                                local_chance = this->fig_chance(ok, y, x);
                                tile[5] = (unsigned char)(line.elevation << 5)
                                    | (tile[5] & 0x1F);

                                if (y > 0) {
                                    if ((tile[-0x13] >> 5)
                                        == (unsigned char)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x17D) * 100) / 0x7FFF;
                                        this->push_stack(stack_ptr, y - 1, x,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (y < this->map_width - 1) {
                                    if ((tile[0x1D] >> 5)
                                        == (unsigned char)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x17F) * 100) / 0x7FFF;
                                        this->push_stack(stack_ptr, y + 1, x,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (x > 0) {
                                    if ((tile[-this->map_width * 0x18 + 5] >> 5)
                                        == (unsigned char)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x181) * 100) / 0x7FFF;
                                        this->push_stack(stack_ptr, y, x - 1,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }
                                if (x < this->map_height - 1) {
                                    if ((tile[this->map_width * 0x18 + 5] >> 5)
                                        == (unsigned char)line.base_elevation) {
                                        long random_value = (debug_rand(
                                            s_C__msdev_work_age1_x1_rmm_elev_c,
                                            0x183) * 100) / 0x7FFF;
                                        this->push_stack(stack_ptr, y, x + 1,
                                            0.0f,
                                            (float)random_value + local_chance);
                                    }
                                }

                                ++chance;
                            }
                        } else {
                            *mark = 0x65;
                        }
                    }
                }
                ++stack_ptr;
                --phase_count;
            } while (phase_count != 0);
        }
    } while (done == 0);

    if (line.clumps > 0) {
        for (long i = 0; i < line.clumps; ++i) {
            this->deinit_stack(&stack[i]);
        }
    }
    return 1;
}
