// Attempt log for 004828B0 RGE_RMM_Controller::add_object_module
// try 1: manual object_info stack buffer/stores from packet plus natural new/ctor; too small 672B.
// try 2: /GX flag probe; unchanged too small 672B.
// try 3: /Oy- flag probe; too small 656B.
// try 4: /O1 flag probe; too small 625B.
// try 5: added placement-new surface for natural ctor; compiles but no size improvement.
// try 6: reviewed stack-frame target 0x18D0 and local object_info offset; broad alloca/EH frame likely close.
// try 7: reviewed constants/register reuse; manual stores likely too expression-collapsed vs original scheduled register constants.
// try 8: reviewed land-copy loop; source loop shape matches behavior but not validated.
// try 9: reviewed final operator new/ctor argument order; plausible but size short.
// try 10: left in scratch; current source is a behavior scaffold, not exact-size.
// BLOCKER: rebuilt .text 672B vs original 695B; missing exact large aggregate initialization schedule/register-lifetime and ctor/EH state shape. Not accepted_drift-safe.
// try 11: restored typed RGE_Object_Info/RGE_Map/RGE_Random_Map_Module ownership and a natural new-expression; test the constructor ABI and /GX EH state against the oracle.
// try 12: restored the polymorphic 0x30-byte RGE_Random_Map_Module base and inherited generator size so natural new has the period class surface.
// try 13: coalesced the natural allocation result onto object_info's proven first dword instead of a separate pointer local; this should restore the 0x18dc frame/home topology.
// try 14: preserve the proven object_info.obj_id null guard with typed operator-new plus placement construction; natural new optimized away that observable first-dword home.
// try 15: restore the period RGE_Object_Info_Line field/byte-pair ownership and PDB initialization order instead of a raw offset/constant scaffold.
// try 16: represent the binary-proven group/scale/short flag word as one union dword store while retaining named byte ownership.
// try 17: corrected the count owner to RGE_Land_Info::land_num at +0x141c; the oracle loads the lands parameter before the copy loop, not world->land_num.
// try 18: restored the full RGE_Land_Info record layout and canonical interior y-field cursors; the oracle's +0x0c/+0x34 loop is a typed field anchor, not an arbitrary byte buffer.
// try 19: pass the object-module's proven terrain-record owner directly instead of a raw byte offset; this matches the oracle's &object_info.objects[0].terrain call surface.
// result 19: no emitted-code change; the first mismatch remains the compiler's __chkstk versus original __alloca_probe call replacement at +0x1f.
// fresh session: baseline rebuilt 658 effective bytes with no EH/new ABI; typed natural new restored the constructor relocation, EH frame, 0x1920 allocation, exact 137-instruction count, and 0x18d0/0x18dc stack sizes.
// fresh probes: full object-record ownership plus the group-flag dword union closed the initialization instruction count; correcting land_num to the second parameter at +0x141c recovered the loop owner and 18.98% exact-block coverage.
// final state: current typed source is 687 effective bytes vs 695 original, 137 instructions, 3 calls, exact frame allocation, and 589 strict differing bytes; the best emitted-code diagnostic was 584 bytes before restoring the full typed land anchors.
// BLOCKER: remaining mismatch begins in the EH handler/stack-home and saved-this/register schedule (rebuilt uses __chkstk/local EH label and spills this before callee-save pushes; oracle uses __alloca_probe/55E63E and delayed [esp+0Ch] home). No productive hypotheses remain in this bounded session; left the canonical typed reconstruction in scratch.
// revisit probes: the oracle initializes the loop index before CMP/JLE; moving
// `i = 0` before the positive-count guard improved the natural source to 582
// strict differing bytes, 65.69% shape, and 20.44% exact-block coverage.
// revisit probe: the oracle keeps object[2].object_number_varience at the
// earlier value 6. Removing the later source overwrite to 3 reduced the
// strict difference to 488 bytes.
// revisit probe: writing object[3]/object[4] exclusion before outer radius
// recovers the oracle's 15-then-9 constant setup and reduced the difference
// to 486 bytes.
// Same-TU ABI, full base surface, record-field, header, receiver-alias,
// constant-local, typed-loop, and allocation-result-home probes did not improve
// that basin. Explicit operator-new plus placement construction removed the
// EH frame and lost the target boundary, so it was rejected.
// H1/H4: count/i/object_info declaration permutations were neutral at 486 bytes.
// H2: a real land-info reference alias was codegen-neutral.
// H3: a temporary reference-signature header test was codegen-neutral; the
// canonical pointer declaration is restored.
// H5: reversing object[3]/object[4] outer and exclusion assignments worsened
// the result to 488 bytes; retain the shipped source order.
// H6/H7: named 6/4 locals and long count/index types did not improve output.
// H8/H9: period stdlib and new headers were codegen-neutral and removed.

#include "../../include/rmm_cntr_context.h"

void RGE_RMM_Controller::add_object_module(RGE_Game_World* world, RGE_Land_Info* lands)
{
    int count;
    int i;
    RGE_Object_Info object_info;
    object_info.lands[0].x = 6;
    object_info.objects[1].object_exclusion_zone = 4;
    object_info.objects[2].object_number_varience = 6;
    object_info.objects[3].object_number_varience = 6;
    object_info.objects[3].player_id = 4;
    object_info.objects[4].object_number_varience = 6;

    object_info.objects[0].terrain = 0x6d;
    object_info.objects[0].initial_flags.group_flags = 0;
    object_info.objects[0].object_number_per_group._0_1_ = 0;
    object_info.objects[0].object_number_per_group._1_1_ = 0;
    object_info.objects[0].object_number_varience = 1;
    object_info.objects[0].number_of_groups = 0;
    object_info.objects[0].group_area = 1;
    object_info.objects[0].land_id = -1;
    object_info.objects[0].land_inner_radius = 0;
    object_info.objects[0].land_outer_radius = 0;
    object_info.objects[0].object_exclusion_zone = 0;

    object_info.objects[1].terrain = 0x53;
    object_info.objects[1].initial_flags.group_flags = 0;
    object_info.objects[1].object_number_per_group._0_1_ = 0;
    object_info.objects[1].object_number_per_group._1_1_ = 0;
    object_info.objects[1].object_number_varience = 1;
    object_info.objects[1].number_of_groups = 0;
    object_info.objects[1].group_area = 3;
    object_info.objects[1].land_id = -1;
    object_info.objects[1].land_inner_radius = 0;
    object_info.objects[1].land_outer_radius = 2;

    object_info.objects[2].terrain = 0x41;
    object_info.objects[2].initial_flags.group_flags = 0;
    object_info.objects[2].object_number_per_group._0_1_ = 1;
    object_info.objects[2].object_number_per_group._1_1_ = 1;
    // ORIGINAL BUG: The shipped code keeps the earlier variance value 6.
    object_info.objects[2].number_of_groups = 3;
    object_info.objects[2].group_area = 10;
    object_info.objects[2].player_id = 3;
    object_info.objects[2].land_id = 0;
    object_info.objects[2].land_inner_radius = -1;
    object_info.objects[2].land_outer_radius = -1;
    object_info.objects[2].object_exclusion_zone = -1;

    object_info.objects[3].terrain = 0x66;
    object_info.objects[3].initial_flags.group_flags = 0xffffffff;
    object_info.objects[3].object_number_per_group._0_1_ = 2;
    object_info.objects[3].object_number_per_group._1_1_ = 0;
    object_info.objects[3].number_of_groups = 2;
    object_info.objects[3].group_area = 1;
    object_info.objects[3].land_id = 0;
    object_info.objects[3].land_inner_radius = 0;
    object_info.objects[3].object_exclusion_zone = 15;
    object_info.objects[3].land_outer_radius = 9;

    object_info.objects[4].terrain = 0x42;
    object_info.objects[4].initial_flags.group_flags = 0xffffffff;
    object_info.objects[4].object_number_per_group._0_1_ = 2;
    object_info.objects[4].object_number_per_group._1_1_ = 0;
    object_info.objects[4].number_of_groups = 2;
    object_info.objects[4].group_area = 1;
    object_info.objects[4].player_id = 4;
    object_info.objects[4].land_id = 0;
    object_info.objects[4].land_inner_radius = 0;
    object_info.objects[4].object_exclusion_zone = 15;
    object_info.objects[4].land_outer_radius = 9;

    object_info.objects[5].terrain = 0x3b;
    object_info.objects[5].initial_flags.group_flags = 0xffffffff;
    object_info.objects[5].object_number_per_group._0_1_ = 1;
    object_info.objects[5].object_number_per_group._1_1_ = 0;
    object_info.objects[5].object_number_varience = 5;
    object_info.objects[5].number_of_groups = 2;
    object_info.objects[5].group_area = 1;
    object_info.objects[5].player_id = 3;
    object_info.objects[5].land_id = 0;
    object_info.objects[5].land_inner_radius = 0;
    object_info.objects[5].land_outer_radius = 9;
    object_info.objects[5].object_exclusion_zone = 15;
    count = lands->land_num;
    i = 0;
    if (count > 0) {
        long* dst = &object_info.lands[0].y;
        long* src = &lands->land[0].y;
        do {
            ++i;
            dst[-1] = src[-1];
            dst[0] = src[0];
            dst[1] = 0;
            dst[2] = i;
            src += 13;
            dst += 4;
        } while (i < count);
    }
    object_info.objects[0].obj_id = (long)new RGE_RMM_Object_Generator(
        this->map, this, world,
        (RGE_Object_Info*)&object_info.objects[0].terrain, 1);
}
