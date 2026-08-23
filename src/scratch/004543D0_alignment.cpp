// VA: 004543D0 alignment (690B)
// m_s_obj.cpp, lines 1021-1088
// RGE_Master_Static_Object::alignment (vt[9], offset 0x24)
// Returns uchar, always 1
//
// ATTEMPT LOG (sa878e036b_r1):
// - baseline: natural named edge/map locals; 566B rebuilt, 614 strict diff.
// - layout: corrected the implicit-vptr gap so radius_x/radius_y are +30/+34;
//   this moved the first field hunk one byte deeper.
// - layout: declaration-order probes favored left/top/right/bottom, then the
//   x-min/x-max/y-min/y-max variant was retained as a small negative check.
// - behavior: replaced many edge/coordinate temporaries with the binary's
//   six-float plus short reuse family. This recovered the 4 short-width
//   __ftol conversions, the four-return topology, 640B rebuilt size, and
//   66.53% shape; best strict diff is 564B.
// - variant: four initialization-order cases did not change the best basin.
// - behavior: a transposed strict-less boundary interpretation was tested and
//   worsened the emitted CFG/size; restored the six-float reconstruction.
// - variant: boundary-topology combinations were swept after restoration;
//   none beat the retained natural six-float source. Remaining mismatch starts
//   with ESI/EDI parameter coloring and then the initial x87 load order/branch
//   topology. Paused at the bounded hypothesis budget; likely next lead is
//   donor TU/class surface or a focused parameter-liveness/context probe.
// - abi: changed the two coordinate parameters from references to pointers,
//   matching exact same-TU/class alignment declarations; emitted code was
//   unchanged, so this did not explain the ESI/EDI coloring.
// - context: typed the existing virtual surface through the same-TU/class
//   donor methods after alignment; emitted code was unchanged. No scheduling
//   locals or behavior changes were retained.
// - layout: left/top/right/bottom initialization improved the structural diff
//   from 564 to 553 bytes; reference ABI and top declarations were unchanged.
// - layout: literal-pool externs and x-min/x-max assignment order were rolled
//   back; both increased size or returned to the 564-byte basin.
// - behavior: explicit zeroing of each corrected negative minimum matched the
//   original zero-home/x87 topology; diff improved to 465 bytes and 15.51%
//   exact-block coverage.
// - control-flow: direct `right > map_width` and `bottom > map_height`
//   predicates improved the structural diff to 458 bytes and 73.88% shape.
// - liveness: reverse local declaration order worsened the structural result;
//   restored the natural fVar1..fVar6 order. ESI/EDI parameter coloring remains.
// - paused: best clean reconstruction keeps zeroed edge minima and direct
//   bound predicates; remaining drift is parameter register coloring, stack
//   home ordering, and later branch/x87 topology.
//
// REVISIT (sa-f9d2922f-r1):
// - baseline validation: 656B rebuilt, 458 strict diff, 73.88% shape,
//   4/4 direct __ftol calls, exact symbol, and frame 0x8.
// - donor search: no exact initial-x87 donor; one exact donor covered only
//   the repeated sign-normalization block.
// - context: reviewed DAT_00570618/30/34 externs changed size but not diff;
//   rolled back. The complete known post-alignment virtual surface was codegen
//   neutral. A narrow exact virtual alignment surface was also codegen neutral
//   and is retained to avoid invented slots.
// - behavior: updating edge minima during upper-bound correction worsened to
//   524B diff; the binary-supported six-float source does not retain that form.
// - control-flow: ordered upper-bound operands worsened to 465B diff. A
//   positive flag guard improved shape to 77.33% but worsened strict diff to
//   472B, so the clean direct guard remains authoritative.
// - ABI/layout/liveness: pointer ABI, map locals, map declaration order,
//   short declaration order, and compound remainder updates were neutral or
//   worse. The pointer ABI changed the decorated symbol and is not retained.
// - variant: a 9-case upper/lower guard sweep found four codegen groups and
//   no exact result. It confirmed the first mismatch is independent of those
//   guards. Twenty meaningful hypotheses are complete for this pass.
//
// REVISIT (sa-19ef3b8b-r1):
// - baseline: pinned source rebuilt to 656B, 458 strict diff, 73.88% shape,
//   4/4 __ftol calls, and 0x8 frame.
// - liveness: joined initializers, named map limits, local x/y aliases, and a
//   block-scoped correction temporary were codegen-neutral.
// - behavior: upper-edge local updates changed the basin or frame and were
//   rolled back. A combined corrected-edge model reached 462 diff but was not
//   retained because the smallest clean source was closer.
// - control-flow: the original upper-bound `fcomp` uses `test ah,1`, not the
//   unordered-safe `test ah,41` emitted by `>` guards. Negated strict-less
//   guards reproduce the C0-only form. Both guards reached 457 strict diff,
//   74.69% shape, and 19.59% exact-block coverage. Retain this source form.
// Context probe: an authentic owner-order wrapper with offset-equivalent,
// gap-only RGE_Game_World and RGE_Map declarations kept the 554-byte current
// diff, exact 0x8 frame, and four ordered calls. Shared world/map vptr context
// is not the initial FP/control-flow cause. The diagnostic variant was not
// retained.
//
// REVISIT (sa-c32269fe-r1):
// - PDB and the original symbol qualify this target as
//   RGE_Master_Static_Object::alignment in m_s_obj.cpp, lines 1021-1088.
//   Its original boundary is 004543D0-00454681. The next sibling is the
//   exact alignment_box at 00454690. Do not merge either boundary.
// - Canonical m_s_obj TU validation kept the alignment ABI, four __ftol calls,
//   0x8 frame, and all typed world/map and radius field accesses.
// - behavior: writing each negative correction as an addition of `-fVarN`
//   restored the shipped x87 correction topology. It improved the canonical
//   result from 554 to 457 strict-diff bytes and from 68.98% to 74.69% shape.
// - context: explicit `this->` field spelling, a typed map cursor, and typed
//   coordinate aliases were codegen-neutral. They are not retained.
// - control-flow: a positive flag guard gave a transient 452-byte diagnostic,
//   but it omitted required final coordinate publication. Restoring that
//   publication reached 471 bytes. The early zero guard remains authoritative.
// - behavior: retaining an upper-edge accumulator changed the frame and
//   damaged the topology. The original upper-edge locals remain unmodified.
// - final canonical validation remains MISMATCH: 656 rebuilt bytes versus 690,
//   457 strict-diff bytes, 74.69% shape, and 4/4 ordered __ftol calls.

class RGE_Game_World;
class RGE_Map;
class RGE_Static_Object;
class RGE_Player;

#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual unsigned char alignment(float& param_1, float& param_2, RGE_Game_World* param_3, unsigned char param_4);

    char gap_04[0x2C];
    float radius_x;       // +0x30
    float radius_y;       // +0x34
    float radius_z;       // +0x38
    char gap_3C[0x7C];
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;         // +0x28
};

class RGE_Map {
public:
    char gap_00[0x8];
    int map_width;        // +0x8
    int map_height;       // +0xC
};
#endif

unsigned char RGE_Master_Static_Object::alignment(float& param_1, float& param_2, RGE_Game_World* param_3, unsigned char param_4)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    float fVar5;
    float fVar6;
    short sVar7;

    fVar1 = param_1 - radius_x;
    fVar2 = param_2 - radius_y;
    fVar3 = param_1 + radius_x;
    fVar4 = param_2 + radius_y;
    fVar5 = (float)param_3->map->map_width - 0.00001f;
    fVar6 = (float)param_3->map->map_height - 0.00001f;

    if (fVar1 < 0.0f) {
        fVar3 = fVar3 + (-fVar1);
        param_1 = param_1 + (-fVar1);
        fVar1 = 0.0f;
    }
    if (fVar2 < 0.0f) {
        fVar4 = fVar4 + (-fVar2);
        param_2 = param_2 + (-fVar2);
        fVar2 = 0.0f;
    }
    if (!(fVar3 < fVar5))
        param_1 = param_1 + (fVar5 - fVar3);
    if (!(fVar4 < fVar6))
        param_2 = param_2 + (fVar6 - fVar4);

    if (param_4 == 0)
        return 1;

    if (fVar1 < 0.0f) fVar1 = -fVar1;
    if (fVar2 < 0.0f) fVar2 = -fVar2;
    if (fVar3 < 0.0f) fVar3 = -fVar3;
    if (fVar4 < 0.0f) fVar4 = -fVar4;

    sVar7 = (short)(long)fVar1;
    fVar1 = fVar1 - (float)(int)sVar7;
    sVar7 = (short)(long)fVar2;
    fVar2 = fVar2 - (float)(int)sVar7;
    sVar7 = (short)(long)fVar3;
    fVar3 = 1.0f - (fVar3 - (float)(int)sVar7);
    sVar7 = (short)(long)fVar4;
    fVar4 = 1.0f - (fVar4 - (float)(int)sVar7);

    if (fVar3 + fVar1 < 1.0f) {
        fVar1 = param_1;
    } else if (fVar1 <= fVar3) {
        fVar1 = param_1 - (1.0f - fVar3);
    } else {
        fVar1 = (1.0f - fVar1) + param_1;
    }

    if (1.0f <= fVar4 + fVar2) {
        if (fVar4 < fVar2) {
            fVar3 = param_2;
            param_1 = fVar1;
            param_2 = (1.0f - fVar2) + fVar3;
            return 1;
        }
        fVar2 = param_2;
        param_1 = fVar1;
        param_2 = fVar2 - (1.0f - fVar4);
        return 1;
    }
    fVar2 = param_2;
    param_1 = fVar1;
    param_2 = fVar2;
    return 1;
}
