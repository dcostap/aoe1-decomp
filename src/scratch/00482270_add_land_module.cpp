// 00482270 RGE_RMM_Controller::add_land_module
// Baseline: period-plausible typed reconstruction from rmm_cntr.cpp's
// RGE_Land_Info / RGE_Land_Info_Line ownership and the original CFG.
// The old scratch attempt had the parameter order, return type, and land-line
// layout wrong; it was a pointer-returning scaffold rather than this void
// helper that fills an RGE_Land_Info reference.
// Attempt log:
// - Corrected the ABI to void add_land_module(RGE_Land_Info&, long, long),
//   restored the 0x34 RGE_Land_Info_Line layout, and modeled the natural
//   switch/random-placement/new expression. Baseline: 1090 bytes, 8 calls,
//   exact CFG/size, but 0x34 frame versus the oracle's 0x30.
// - An area-field cursor matched two additional addressing bytes (941-byte
//   diagnostic diff) but spilled the cursor and remained a raw decompiler
//   anchor; restored the cleaner typed line pointer for the living source.
// - Volatile dimension rereads, controller/info pointer aliases, header
//   context, and cursor-carry variants were nonproductive or diagnostic;
//   cursor-carry worsened the strict diff. No inline asm or status promotion.
// - Fresh natural ownership probe: used the period RGE_Random_Map_Module
//   parent/list and buffer types, plus the polymorphic land-generator surface
//   from exact same-module donors. The direct new/constructor path and typed
//   outer loop remained unchanged; emitted code was identical (943-byte diff,
//   0x34 frame). This is negative evidence against constructor/list context
//   as the first structural blocker.
// - Structural follow-up: direct indexed lines, register-qualified typed
//   cursors, indexed collision scans, declaration-order changes, and hoisted
//   locals were codegen duplicates or worse. The natural area cursor, original
//   guard operand order, and stored land count improved the clean source to
//   937 strict-diff bytes, 84.57% shape, and the 0x30 frame.
// - A 22-probe subagent pass tested scope, alias, register, width, volatility,
//   cursor, and declaration-order axes. Volatile found was a useful diagnostic:
//   it reached 926 bytes by forcing the dead land_num byte home. It is rejected
//   as fake source volatility, and the clean 937-byte source is restored.
//   Volatile height, named width, direct indexing, and explicit parameter-byte
//   aliases were worse or nonproductive. Calls and ownership remain aligned.
// - Follow-up probes used a literal rmm_cntr.cpp path, a base destructor
//   declaration, function-scope info/cursor/zero/inner/x/y locals, and a typed
//   land-line cursor. The literal and destructor were codegen-neutral. The
//   local variants were neutral; the typed cursor was worse.
// - PDB line order supports an inner switch order of cases 2/3/4, 1, and 0.
//   That order raised shape to 86.03% and exact blocks to 37.29%, but increased
//   strict diff from 937 to 945 bytes. It is not retained over the clean source.
// GIVEUP: unresolved VC5 register coloring keeps this in EBP/ESI/EDI shapes
// where the oracle uses EBX/EDI/ESI/EBP. The clean source remains pinned.

#include <math.h>
#include <new.h>

#include "../../include/rmm_cntr_context.h"

void RGE_RMM_Controller::add_land_module(RGE_Land_Info& land_info,
                                          long type, long land_num)
{
    long radius;

    land_info.land_num = land_num;

    switch (type) {
    default:
        radius = 0;
        land_info.base_terrain = 0;
        land_info.wall_1_avoidance_line = 0;
        land_info.wall_2_avoidance_line = 0;
        land_info.wall_3_avoidance_line = 0;
        land_info.wall_4_avoidance_line = 0;
        land_info.wall_fade = 0;
        break;
    case 3:
        radius = 90;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 0;
        land_info.wall_2_avoidance_line = 0;
        land_info.wall_3_avoidance_line = 0;
        land_info.wall_4_avoidance_line = 0;
        land_info.wall_fade = 0;
        break;
    case 2:
        radius = 70;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 4;
        land_info.wall_2_avoidance_line = 4;
        land_info.wall_3_avoidance_line = this->map_width - 5;
        land_info.wall_4_avoidance_line = this->map_height - 5;
        land_info.wall_fade = 0x22;
        break;
    case 1:
        radius = 50;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 6;
        land_info.wall_2_avoidance_line = 6;
        land_info.wall_3_avoidance_line = this->map_width - 7;
        land_info.wall_4_avoidance_line = this->map_height - 7;
        land_info.wall_fade = 0x14;
        break;
    case 0:
        radius = 30;
        land_info.base_terrain = 1;
        land_info.wall_1_avoidance_line = 8;
        land_info.wall_2_avoidance_line = 8;
        land_info.wall_3_avoidance_line = this->map_width - 9;
        land_info.wall_4_avoidance_line = this->map_height - 9;
        land_info.wall_fade = 0x14;
        break;
    }

    long land_tile_num = radius * this->map_width * this->map_height / 100;
    float land_radius = ((float)(this->map_width - 16) /
                         sqrt((float)land_num)) * 0.8;
    float bound_square = land_radius * land_radius;
    long mid_x2 = (long)(this->map_width / 2 - land_radius * 0.9);
    long index2 = (long)(this->map_height / 2 - land_radius * 0.9);
    long mid_y1 = (long)(this->map_width / 2 + land_radius * 0.9);
    long mid_y2 = (long)(this->map_height / 2 + land_radius * 0.9);

    if (mid_x2 < 9) {
        mid_x2 = 9;
    }
    if (index2 < 9) {
        index2 = 9;
    }
    if (mid_y1 >= this->map_width - 9) {
        mid_y1 = this->map_width - 10;
    }
    if (mid_y2 >= this->map_height - 9) {
        mid_y2 = this->map_height - 10;
    }

    long index = 0;
    if (0 < land_num) {
        long* land = &land_info.land[0].area;
        do {
            switch (type) {
            case 0:
                land[-4] = 0;
                *land = 7;
                goto set_land_defaults;
            case 1:
                land[-4] = 0;
                *land = 4;
            set_land_defaults:
                land[-1] = 5;
                ((uchar*)land)[4] = (uchar)index;
                break;
            case 2:
            case 3:
            case 4:
                land[-4] = 0;
                *land = 3;
                land[-1] = 5;
                ((uchar*)land)[4] = 0;
                break;
            default:
                break;
            }

            uchar found = 0;
            long x;
            long y;
            do {
                found = 0;
                x = debug_rand(rmm_cntr_cpp_path, 0xD1) *
                    (this->map_width - 16) / 0x7fff + 8;
                y = debug_rand(rmm_cntr_cpp_path, 0xD2) *
                    (this->map_height - 16) / 0x7fff + 8;

                if ((x > mid_x2) && (x < mid_y1) &&
                    (y > index2) && (y < mid_y2)) {
                    found = 1;
                }
                else {
                    long inner = 0;
                    if (0 < index) {
                        long* previous = &land_info.land[0].x;
                        do {
                            long dx = x - previous[0];
                            if (dx < 0) {
                                dx = -dx;
                            }
                            long dy = y - previous[1];
                            if (dy < 0) {
                                dy = -dy;
                            }
                            if ((float)(dx * dx + dy * dy) <= bound_square) {
                                if ((!found) && (inner == index - 1)) {
                                    previous[1] = y;
                                    previous[0] = x;
                                }
                                found = 1;
                            }
                            ++inner;
                            previous += 13;
                        } while (inner < index);
                    }
                }
            } while (found);

            land[-3] = x;
            land[-2] = y;
            land[-4] = land_tile_num / land_info.land_num;
            ++index;
            land += 13;
        } while (index < land_info.land_num);
    }

    new RGE_RMM_Land_Generator(this->map, this, &land_info);
}
