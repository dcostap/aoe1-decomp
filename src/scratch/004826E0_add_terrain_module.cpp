// VA: 004826E0 RGE_RMM_Controller::add_terrain_module
// rmm_cntr.cpp lines 247-298
// Attempt log:
// 1: natural source from packet/decompiler with /GX: comparable but terrain record stride wrong and switch case order reversed.
// 2: fix terrain record stride to 0x20, put cases 3/4 first: switch body closer but global terrain_info gaps wrong.
// 3: fix terrain_info hot-spot/num offsets and land_info land array offsets; loop/new path now structurally close.
// 4: move terrain[1] zero/default fields after switch: improved edit diff, but VC5 tail-merged second-size computation.
// 5: swap local width/height field names and vary second-size expression: no change; expression reverted.
// tried flags /O2 no-/Oy, /Ox, /Ob0 same; /O1 too short.
// left in scratch: EH/new path, hot-spot copy loop, and data offsets are modeled; remaining broad drift is switch case tail-merge/load-order and later register scheduling, not accepted_drift-safe.
// 6: fresh baseline rebuilt the prior source with current inputs: exact size/frame/calls, but the terrain
//    multiply order, record field declaration order, switch body order, and loop constants differed.
// 7: canonical RGE terrain/land layouts and controller base offsets; natural switch and generator ownership.
// 8: canonical field assignment order fixed both first-record stores and improved the diff to 262 bytes.
// 9: raw dimension and no-op expression variants did not improve emitted code and were removed.
// 10: block-scoped area locals were a codegen duplicate; restored one natural local.
// 11: replaced the explicit shared-tail goto with natural switch breaks, matching the packet's line-268 break; emitted code was unchanged.
// 12: case-local direct dimension expressions followed the duplicated map loads at 00482757/004827C1 but worsened the diff to 277; restored the natural area local.
// 13: typed the terrain-generator constructor as RGE_Map*/RGE_Random_Map_Module*; emitted code was unchanged, but the call surface is canonical.
// 14: modeled the terrain generator as the typed random-map derived object with its proven 0x12CC layout; emitted code was unchanged.
// 15: direct map-dimension expressions for all four sizes worsened the block shape to 61.19% and diff 331; restored area temporary.
// 16: separate second-size temporary was codegen-neutral and was removed.
// 17: moving the first case's second-size assignment before type/clumps duplicated both case bodies and improved diff 262 -> 141, but grew the function to 440 bytes due loop/epilogue changes; diagnostic only.
// 18: a common defaults label did not change the reordered-case output.
// 19: reversing hot-spot count and common-default source order worsened the reordered case to diff 168/444 bytes.
// 20: byte-offset radius store, constant-product parentheses, and function-scope loop-counter variants gave no useful codegen lead; restored typed source.
// left in scratch: exact size/frame/call parity and canonical field ownership; switch tail merge and
//    loop constant hoisting remain broad VC5 codegen differences.
// Fresh worker pass: pinned the current source at diff 262, then tested nine
// source hypotheses. Reordering terrain[1].terrain_size before type/clumps in
// both arms stopped tail merge and reached diff 141, 440 bytes, and 137
// instructions. The extra 26 bytes came from EBX holding radius 12 in the
// hot-spot loop, then being cleared. One-arm reordering was a codegen duplicate.
// Typed hot-spot cursors, indexed stores, const or register zero locals,
// counter-update order, and <string.h> context did not restore the target.
// Restored the pinned source. Final clean check remains diff 262, size 414,
// frame none, two ordered calls, and four saved registers. The unresolved
// basin is switch tail merge plus loop constant register allocation.
// Natural-source follow-up: replaced the shifted long hot-spot cursor with a
// typed RGE_Terrain_Hot_Spots pointer and field assignments. This preserves
// the proven record ownership without raw cursor plumbing. The build keeps
// the exact 414-byte size, frame, saved registers, and ordered calls, but the
// compiler emits the hot-spot base at +0xC64 instead of the target's y-field
// anchor at +0xC68 and still hoists radius 12 into EBX. The natural typed
// loop is retained; the target's shifted-cursor basin is not policy-safe.
// Revisit: re-tested the no-tail-merge size-before-type order with the typed
// loop (diff 141, 440 bytes), indexed typed records (diff 194, 448 bytes),
// record references, scoped size locals, and the reviewed virtual destructor
// context. The last three were codegen duplicates; all probes were restored.
// Final policy-clean source remains diff 262, 414 bytes, no frame, four saved
// registers, and two ordered calls. Exactness still needs the target's switch
// body layout and y-field anchor; raw shifted cursors and compiler steering
// are not allowed. Rebuild-validated, pinned, and paused unresolved.
// Current worker probes: area*3*10/100 was codegen-neutral; PDB/decompiler
// case order 0/1/2 then 3/4 worsened shape and diff. A binary-supported
// default goto past terrain[1] defaults adds an exact default CFG island and
// preserves the target's uninitialized invalid-type path; it keeps diff 262.
// The exact same-TU y-field cursor improved shape to 83.72% but remains raw
// cursor plumbing, so the typed hot-spot loop is retained. The reviewed base
// destructor declaration was codegen-neutral and is retained for ABI context.
// Final current basin: diff 262, size 414, shape 80.62%, exact blocks 35.77%,
// no frame, four saved registers, and two ordered calls. First structural
// divergence remains the switch tail-merged second-size arithmetic.
// Fresh exact-finish audit: the size-before-type switch form reached 440 bytes
// and diff 119, but added a live radius register and 26 bytes after the target.
// Y-field pointers improved the loop anchor but retained the same overrun.
// Indexed records, update-order, integer-pointer, zero-liveness, and VC5 flag
// probes did not produce a smaller natural source. The shared context probe
// also emitted the wrong map-field order and a 412-byte function. All probes
// were restored to this policy-clean source.
// Fresh validation: 412 emitted bytes, 262 strict differing bytes, no frame,
// four saved registers, two ordered direct calls, and the original owner.
// Exact-finish follow-up: the canonical random-map base declaration replaced
// the duplicate local base surface without changing codegen. Branch-local
// area scopes and compound area assignments were codegen duplicates. Direct
// second-size products reached 404 bytes; helpers changed calls or load order.
// Keep the canonical base context and the direct area expressions.
// Wrapper repair: use the canonical controller context instead of repeating
// terrain, land, generator, and controller declarations. The body is unchanged.

#include <new.h>
#include "../../include/rmm_cntr_context.h"

void RGE_RMM_Controller::add_terrain_module(RGE_Terrain_Info& terrain_info,
                                              RGE_Land_Info& land_info,
                                              long type)
{
    int area;

    terrain_info.terrain_num = 2;

    switch (type) {
    case 3:
    case 4:
        area = this->map_height * this->map_width;
        terrain_info.terrain[0].terrain_type = 10;
        terrain_info.terrain[0].clumps = 30;
        terrain_info.terrain[0].base_terrain_type = 0;
        terrain_info.terrain[0].terrain_generated = 0;
        terrain_info.terrain[0].terrain_size = area * 20 / 100;
        terrain_info.terrain[0].spacing = 2;

        area = this->map_height * this->map_width;
        terrain_info.terrain[1].terrain_type = 6;
        terrain_info.terrain[1].clumps = 17;
        terrain_info.terrain[1].terrain_size = area * 30 / 100;
        break;

    case 0:
    case 1:
    case 2:
        area = this->map_height * this->map_width;
        terrain_info.terrain[0].terrain_type = 10;
        terrain_info.terrain[0].clumps = 20;
        terrain_info.terrain[0].base_terrain_type = 0;
        terrain_info.terrain[0].terrain_generated = 0;
        terrain_info.terrain[0].terrain_size = area * 20 / 100;
        terrain_info.terrain[0].spacing = 2;

        area = this->map_height * this->map_width;
        terrain_info.terrain[1].terrain_type = 6;
        terrain_info.terrain[1].clumps = 7;
        terrain_info.terrain[1].terrain_size = area * 30 / 100;
        break;

    default:
        goto after_terrain_defaults;
    }

    terrain_info.terrain[1].base_terrain_type = 0;
    terrain_info.terrain[1].terrain_generated = 0;
    terrain_info.terrain[1].spacing = 0;

after_terrain_defaults:
    int i = 0;
    terrain_info.hot_spot_num = land_info.land_num;
    if (terrain_info.hot_spot_num > 0) {
        RGE_Land_Info_Line* land = land_info.land;
        RGE_Terrain_Hot_Spots* hot_spot = terrain_info.hot_spots;
        do {
            hot_spot->x = land->x;
            ++i;
            hot_spot->y = land->y;
            hot_spot->radius = 12;
            hot_spot->fade = 20;
            ++land;
            ++hot_spot;
        } while (i < terrain_info.hot_spot_num);
    }

    new RGE_RMM_Terrain_Generator(this->map, this, &terrain_info);
}
