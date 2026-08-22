// 00481000 RGE_Random_Map_Module::find_path(Map_Stack&, long, long, long&, long&, float*)
// Baseline reconstruction: the search operates on named row arrays and the
// RGE_Tile terrain bitfield; the byte-cursor form from the decompiler is not
// retained as the living source.
// Attempt log:
// - Established the +0x10 RGE_Tile row table, +0x20 search byte map, and
//   +0x24 search-map row pointers from the module's exact donor cluster.
// - Named map_h as the reused next-row index and retained the natural eight
//   cardinal/diagonal expansion order; this moved the reconstruction to the
//   63-65% VC5 shape basin with all 10 direct calls aligned.
// - Split width/height decrement statements and kept ty as the float cost
//   returned by pop_stack; the original frame and all four saved registers
//   now match.
// - Tested inline cardinal hcost, an explicit tile/terrain-cost union, and
//   positive terrain guards; they either collapsed the frame or worsened the
//   structural basin, so they were rolled back.
// - Kept explicit byte state flag assignments because they preserve direct
//   setne-to-stack stores without an artificial zero-extension local.
// - Audited the PDB ABI and executable call sites: this is Map_Stack&, two
//   signed long coordinates, two long& outputs, and float* terrain costs;
//   clear_stack, eight push_stack calls (five arguments each), and pop_stack
//   (four arguments) remain ordered and relocation-identical.
// - Corrected the proven boundary topology: the right cardinal and both right
//   diagonals, including the y+1 arm, are guarded by x < map_width - 1.
//   Independently rereading the row state after forming its named cell pointer
//   recovered the binary pointer-before-state schedule and two bytes.
// - Scoped hcost to each directional group. This keeps the natural x87
//   directional cost live across the neighbor-state/terrain gate and lets VC5
//   reuse the tile-cost scratch slot; the best current shape is 68.96% with
//   the exact frame and call set (2355 vs 2418 bytes).
// 2026-08-06 sa-67ed5ee1 session (10 probes):
// - Confirmed binary branch polarity for ALL 8 terrain gates: the original
//   emits `test ah,41h; jne <impassable>` with the passable block inline, so
//   the source gates are positive-passable-first
//   (if (terrain_cost[tile_type] > 0.0) { push } else { *cell = 1; flag = 0; })
//   for every cardinal and diagonal. The prior <=-first form produced the
//   inverted layout (`je` to passable). This alone moves the y+1 arm into the
//   binary's exact block order.
// - Y-arm gates compare against double 0.0 (`fcomp qword [571E40h]`), x-arm
//   gates and the initial target-tile check against float 0.0f
//   (`fcomp dword [571E38h]`); the distance check uses double 0.0. Modeled
//   with `> 0.0` in the y arms and `> 0.0f` elsewhere.
// - Loop structure is `map_h; cost = sqrt(map_h); while (cost != 0.0) {...}`
//   with the full map_h/sqrt/check duplicated in the loop bottom (binary
//   004817E5-00481826 recomputes and re-checks; the previous while(1)+top-check
//   form made VC5 jump back into the shared pre-loop computation, losing ~37
//   bytes). The bottom block's `je <loop top>` and the pre-loop `jne <found>`
//   now match the original exactly.
// - Initial target-tile gate is a positive guard wrapping the whole body
//   (if (terrain_cost[tile_type] > 0.0f) { ... } return 0;) so the shared
//   return-0 epilogue is the jump target at the end instead of being inlined
//   (saved ~39 bytes; size now -4 instead of +43).
// - Modeled the three direction flags as a 4-byte byte array at +0x10
//   (calc_cost[4], with up=calc_cost[1], right=calc_cost[2], down=
//   calc_cost[3]); Ghidra names the binary's +0x11/+0x12/+0x13 flag bytes
//   calc_cost+1/+2/+3. This fixed the flag slot order and raised shape to
//   71.8% (best so far; the prior separate uchar declarations had the flags in
//   the wrong order).
// - Local homes now match: calc_cost+0x10, tcost+0x14, tile_type+0x18,
//   ty+0x24, map_h+0x28, map_w+0x2C, local_4+0x30. Remaining slot drift: the
//   binary keeps hcost at +0x1C and cost at +0x20; scoped hcost makes VC5 put
//   cost at +0x1C and hcost at +0x20, and function-scope hcost moves
//   tile_type to +0x1C. No declaration order/spelling found to reproduce the
//   binary's hcost-below-cost packing.
// - Remaining drift is register coloring (binary keeps y in ecx and x in edx
//   across the loop; rebuilt keeps them swapped), the x87 tcost operand order
//   (binary `fld ty; fadd tilecost` in y-arms and x+1 but `fld tilecost;
//   fadd ty` in x-1; VC5 ignored both spellings and always loads tilecost
//   first), the total-cost idiom (binary fstp/fld/fadd st1 reload vs rebuilt
//   fadd [mem]), and a +4 tail overhang from slightly longer found-tails.
//   Tried: function-scope hcost, declaration reorders, ternary hcost
//   initializer, named dx/dy distance temps, per-arm tcost addend spellings -
//   none changed codegen; all rolled back.
// Paused: size -4 (2422/2418), shape 71.8% (best), calls 10/10 aligned,
//   frame and saved registers exact. Structure is binary-correct; the gap is
//   allocator/scheduler level (slots +0x1C/+0x20, x/y coloring, x87 operand
//   order) which the checker flags as post-structural. Next leads: reproduce
//   the hcost/cost home order (try declaring cost last among floats with
//   hcost scoped, or a variant-lab on the passable-block FPU scheduling), or
//   flip the x/y loop coloring via the distance expression register basin.
// - Tested passable-first guards, reference parameter spellings, ty-first
//   cardinal addition, swapped distance-term order, and function-scope hcost;
//   they produced no improvement or worsened the structural basin and were
//   rolled back. No volatility, raw cursor ownership, or asm scaffolding kept.
// Paused: remaining drift is structural FPU argument/scratch scheduling and
// distance-register coloring, not a map ownership, boundary, signedness, or
// call-ABI blocker.
// 2026-08-09 sa-fd4bc279-r1-81000 follow-up (8 meaningful probes):
// - Tested extern zero-rdata declarations for the binary's 571E38/571E40
//   constants; unresolved local relocations worsened the basin (2012 bytes,
//   44.68% shape), so the literal-zero form remains the clean candidate.
// - Tested a typed aggregate/reference wrapper for the contiguous FPU locals;
//   it added 28 code bytes and disturbed the frame-local schedule (2121-byte
//   diff, 50.84% shape), so it was rolled back. Scoped cost and compound
//   cardinal additions were codegen-neutral.
// - Normalized the compiler-facing stack argument declarations to the PDB's
//   Map_Stack& surface for find_path, push_stack, and pop_stack; VC5 emitted
//   identical bytes, but the reference form is the more plausible source ABI.
// Final retained candidate: typed row/tile ownership, byte flag array, exact
//   frame/call set, and natural eight-direction search; unresolved drift is
//   the previously documented VC5 local-slot/register/FPU scheduler basin.
// - tu-rmmbase-481000: dossier and donors reconfirm the five map fields, ten
//   ordered calls, exact frame, and typed path ownership. No supported natural
//   source lead remains for the FPU/local-slot scheduler gap.
// 2026-08-17 sa-032a8cec-r1 follow-up (20 meaningful probes):
// - The clean baseline is 2422 bytes, 0x24 frame, four saved registers, all ten
//   ordered calls aligned, 2011 strict differing bytes, and 71.82% shape.
// - Target-left spellings for the y+ and x+ heuristic comparisons, including both
//   x+ diagonal adjustments, are natural and raise shape to 72.08% without changing
//   size, frame, calls, or behavior. Retained in the source.
// - Plain byte terrain/border fields and a non-pure same-TU generate declaration are
//   period-plausible. Both are codegen-neutral and retained as simpler ownership.
// - Removed unused unnamed-constant declarations. This is codegen-neutral.
// - Rejected direct absolute zero/heuristic constants, named target-y and long-typed
//   ty aliases, separate flag locals, extra terrain locals, header additions, and
//   neutral ambient declarations. They either worsened the basin or changed nothing.
// 2026-08-22 sa-1fbd32c7-r1 follow-up:
// - Restored the protected method and reference-output ABI from the PDB symbol
//   and Ghidra declarations. The emitted body did not change.
// - Restored protected stack-helper declarations. Reference outputs for pop_stack
//   also compiled identically and preserve the proven helper ABI.
// - Tested separate uchar flags, bool flags, three-byte arrays, and declaration
//   permutations. They reached 2008 bytes but lost structural shape.
// - Tested cost declaration order, full class method context, state order, split
//   distance statements, and scoped tcost locals. They were neutral or worse.
// - The four-byte flag array remains the best structural basin at 72.08% shape.
//   Its unused first byte is still a source-recovery question.
// BINARY NOTE: The target has ten direct calls in fixed order, a 0x24 frame, and
// four saved registers. The remaining mismatch starts at the post-gate distance
// block: VC5 colors the x/y working registers opposite the executable and places
// cost/hcost at opposite float homes.
// LIKELY INTENT: The source performs an eight-neighbor path search with a shared
// stack and a byte search map. The shipped FPU/local scheduler gap is unresolved.
// Final unresolved candidate: 2422 bytes, 72.08% shape, 2011 differing bytes.

#include <string.h>

extern "C" double sqrt(double value);
#pragma intrinsic(sqrt)

extern float DAT_00571e50;

class RGE_Tile {
public:
    short screen_xpos;
    short screen_ypos;
    unsigned char tile_type;
    unsigned char terrain_type;
    unsigned char border_type;
    unsigned char last_drawn_as;
    unsigned char last_drawn_shape;
    unsigned char draw_as;
    unsigned char draw_attribute;
    unsigned char last_drawn_shape2;
    char gap_0C[0x0C];
};

class Map_Stack {
public:
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    virtual unsigned char generate();
    RGE_Random_Map_Module* parent;
    void* list;
    void* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

protected:
    void clear_stack();
    void push_stack(Map_Stack& path_stack, long x, long y, float cost, float total_cost);
    Map_Stack* pop_stack(Map_Stack& path_stack, long& x, long& y, float& cost);
    unsigned char find_path(Map_Stack& path_stack, long x, long y,
                            long& target_x, long& target_y, float* terrain_cost);
};

unsigned char RGE_Random_Map_Module::find_path(Map_Stack& path_stack, long x, long y,
                                                long& target_x, long& target_y,
                                                float* terrain_cost) {
    unsigned char calc_cost[4];  // [1]=up, [2]=right, [3]=down
    float tcost;
    unsigned char tile_type;
    float cost;
    float ty;
    long map_h;
    long map_w;
    long local_4;
    unsigned char state;
    unsigned char* cell;

    ty = 0.0f;
    local_4 = this->map_width;
    --local_4;
    map_w = this->map_height;
    --map_w;
    this->clear_stack();
    memset(this->search_map, 0, this->map_height * this->map_width);

    this->search_map_rows[y][x] = 3;
    tile_type = this->map_row_offset[target_y][target_x].terrain_type & 0x1F;
    this->search_map_rows[target_y][target_x] = 2;

    if (terrain_cost[tile_type] > 0.0f) {
        map_h = (x - target_x) * (x - target_x)
            + (y - target_y) * (y - target_y);
        cost = (float)sqrt((double)map_h);

        while (cost != 0.0) {
            if (y < map_w) {
                float hcost;
                if (target_y <= y) {
                    hcost = cost - -1.0f;
                } else {
                    hcost = cost - 1.0f;
                }
    
                cell = this->search_map_rows[y + 1] + x;
                state = this->search_map_rows[y + 1][x];
                if (state == 0) {
                    tile_type = this->map_row_offset[y + 1][x].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0) {
                        tcost = ty + terrain_cost[tile_type];
                        *cell = 7;
                        this->push_stack(path_stack, x, y + 1,
                                         tcost, tcost + hcost);
                        calc_cost[2] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[2] = 0;
                    }
                } else if (state == 2) {
                    *cell = 7;
                    target_x = x;
                    target_y = y + 1;
                    return 1;
                } else {
                    if (state == 1) calc_cost[2] = 0;
                    else calc_cost[2] = 1;
                }
            } else {
                calc_cost[2] = 0;
            }
    
            if (y > 0) {
                float hcost;
                if (target_y < y) {
                    hcost = cost - 1.0f;
                } else {
                    hcost = cost - -1.0f;
                }
    
                cell = this->search_map_rows[y - 1] + x;
                state = this->search_map_rows[y - 1][x];
                if (state == 0) {
                    tile_type = this->map_row_offset[y - 1][x].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0) {
                        tcost = ty + terrain_cost[tile_type];
                        *cell = 6;
                        this->push_stack(path_stack, x, y - 1,
                                         tcost, tcost + hcost);
                        calc_cost[1] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[1] = 0;
                    }
                } else if (state == 2) {
                    *cell = 6;
                    target_x = x;
                    target_y = y - 1;
                    return 1;
                } else {
                    if (state == 1) calc_cost[1] = 0;
                    else calc_cost[1] = 1;
                }
            } else {
                calc_cost[1] = 0;
            }
    
            if (x > 0) {
                float hcost;
                if (target_x < x) {
                    hcost = cost - 1.0f;
                } else {
                    hcost = cost - -1.0f;
                }
    
                cell = this->search_map_rows[y] + x - 1;
                state = this->search_map_rows[y][x - 1];
                if (state == 0) {
                    tile_type = this->map_row_offset[y][x - 1].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0f) {
                        tcost = terrain_cost[tile_type] + ty;
                        *cell = 4;
                        this->push_stack(path_stack, x - 1, y,
                                         tcost, tcost + hcost);
                        calc_cost[3] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[3] = 0;
                    }
                } else if (state == 2) {
                    *cell = 4;
                    target_x = x - 1;
                    target_y = y;
                    return 1;
                } else {
                    if (state == 1) calc_cost[3] = 0;
                    else calc_cost[3] = 1;
                }
    
                if (y > 0) {
                    map_h = y - 1;
                    cell = this->search_map_rows[map_h] + x - 1;
                    state = this->search_map_rows[map_h][x - 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x - 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[1] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 8;
                                if (target_y < y) {
                                    hcost = hcost - 0.41f;
                                } else {
                                    hcost = hcost - -0.41f;
                                }
                                this->push_stack(path_stack, x - 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 8;
                        target_x = x - 1;
                        target_y = y - 1;
                        return 1;
                    }
                }
    
                if (y < map_w) {
                    map_h = y + 1;
                    cell = this->search_map_rows[map_h] + x - 1;
                    state = this->search_map_rows[map_h][x - 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x - 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[2] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 9;
                                if (target_y < y) {
                                    hcost = hcost - 0.41f;
                                } else {
                                    hcost = hcost - -0.41f;
                                }
                                this->push_stack(path_stack, x - 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 9;
                        target_x = x - 1;
                        target_y = y + 1;
                        return 1;
                    }
                }
            }
    
            if (x < local_4) {
                float hcost;
                if (target_x <= x) {
                    hcost = cost - -1.0f;
                } else {
                    hcost = cost - 1.0f;
                }
    
                cell = this->search_map_rows[y] + x + 1;
                state = this->search_map_rows[y][x + 1];
                if (state == 0) {
                    tile_type = this->map_row_offset[y][x + 1].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0f) {
                        tcost = ty + terrain_cost[tile_type];
                        *cell = 5;
                        this->push_stack(path_stack, x + 1, y,
                                         tcost, tcost + hcost);
                        calc_cost[3] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[3] = 0;
                    }
                } else if (state == 2) {
                    *cell = 5;
                    target_x = x + 1;
                    target_y = y;
                    return 1;
                } else {
                    if (state == 1) calc_cost[3] = 0;
                    else calc_cost[3] = 1;
                }
    
                if (y > 0) {
                    map_h = y - 1;
                    cell = this->search_map_rows[map_h] + x + 1;
                    state = this->search_map_rows[map_h][x + 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x + 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[1] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 10;
                                if (target_y <= y) {
                                    hcost = hcost - -0.41f;
                                } else {
                                    hcost = hcost - 0.41f;
                                }
                                this->push_stack(path_stack, x + 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 10;
                        target_x = x + 1;
                        target_y = y - 1;
                        return 1;
                    }
                }
    
                if (y < map_w) {
                    map_h = y + 1;
                    cell = this->search_map_rows[map_h] + x + 1;
                    state = this->search_map_rows[map_h][x + 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x + 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[2] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 11;
                                if (target_y <= y) {
                                    hcost = hcost - -0.41f;
                                } else {
                                    hcost = hcost - 0.41f;
                                }
                                this->push_stack(path_stack, x + 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 11;
                        target_x = x + 1;
                        target_y = y + 1;
                        return 1;
                    }
                }
            }
    
            if (this->pop_stack(path_stack, x, y, ty) == 0) {
                return 0;
            }
    
            map_h = (x - target_x) * (x - target_x)
                + (y - target_y) * (y - target_y);
            cost = (float)sqrt((double)map_h);
        }

        if (path_stack.next != 0) {
            path_stack.next->prev = 0;
        }
        return 1;
    }
    return 0;
}
