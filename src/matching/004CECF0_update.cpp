// 004CECF0 TRIBE_Action_Heal::update
// Source: tact_hea.cpp lines 175-365
// Size: 739 bytes, no EH
//
// Attempt log:
// Probe 1 (baseline): restored the period typed action/static-object/player/world
// surfaces, the target/task/master ownership, and the two natural nested switches.
// The previous scratch file was only an old metric note; this is the clean source
// reconstruction before codegen probes.
// Probe 2: combined shared transition labels and one expression rewrite moved the
// compiler into an EBX-framed 824-byte basin; rolled back.
// Probe 3: separating the target-state invalid guard from the ally guard preserved
// the binary's redundant target null test and improved the source to 840 bytes.
// Probe 4: the same guard plus a shared state-D tail reached 739 bytes and the
// current best 92.16% shape; the remaining gap is switch-table/block placement.
// Probes 5-8: state-D/early/state-6 label permutations and the derived set_state
// declaration did not improve the emitted basin; retained the best labeled CFG.
// Probes 9-10: the effective TU view must expose the float heal call at vslot
// +0x8C; hiding the unused int overload from this local surface changes the call
// from +0x88 to +0x8C without changing behavior or size.
// Probe 11: a separate declaration-only state view did not prevent VC5 tail
// merging; removed from the living source after recording the negative result.
// Session shardA6-4CECF0-r1 baseline: restored the typed tactical-health
// ownership surface before changing the switch topology.
// Ordered source correction: the binary/PDB bands place state 0x0B before
// state 4. Direct natural case bodies entered an 840-byte basin and were
// rolled back as a codegen-only variant.
// Current source keeps that binary-backed order and shares only the proven
// state-D and target-reset tails. Removing inner defaults, using the common
// final return, and placing the state-0x0B state-3 tail before state 4 were
// duplicate emissions. The source now has the correct typed state behavior,
// but VC5 still merges its state-3 call with the state-6 null guard.
// Best current check: 739-byte output, 469 positional diff bytes, 26/27 calls;
// remaining structural gap is one merged +0x5C state-3 call and local switch
// data placement. Leave in scratch for a later worker rather than forcing a
// match.
// Current pass (sa-c2091eb6-r1): H1 break after the state-0x0B state-3 call;
// H2 inner default break; H3 uchar return cast; H4 moved outer case 6;
// H5 named uchar sub-action result; H6 named int result; H7 scoped result
// cases; H8 outer default break; H9 base-typed set_state receiver; H10 const
// state local; H11 reversed inner case 3/4 order; H12 mixed direct/shared
// target reset; H13 inner default return; H14 positive state-6 guard; H15
// scoped outer cases; H16 inherited set_state surface; H17 typed state-6 target
// local. H1-H3, H5-H11, and H13-H17 emitted the same 739-byte, 26-call basin.
// H4, H12, and H14 worsened control-flow alignment. All were rolled back.
// Ambient-declaration lab: 32 context variants formed one identical group.
// Flag lab: default, /Ob0, /Ob1, /Og-, and /Oy- formed three groups; no exact
// result. The default group retained the current 739-byte, 26-call basin.
// Final clean validation remains 739 bytes, 469 positional diff bytes, and
// 26/27 calls. The missing call is the state-0x0B state-3 +0x5C tail, which
// VC5 merges with the state-6 null-target tail under every tested source form.
// Current pass (sa-f5708c34-r1): H18 reversed the state-4 result 3/4/5 source
// order and moved the target-reset block before the state-done block, improving
// the checkpoint to 448 bytes. H19 then placed state-4 results 4/5, 3, 1/2 in
// the binary handler order, reaching 460 bytes with 96.30% call alignment but
// retaining the missing duplicate +5C call. H20-H32 tested labels, case scopes,
// narrow arguments, receiver typing, declaration scope, and local aliases;
// these either duplicated H19 or worsened the source shape. An outer case-4
// first variant reached 431 bytes, but assigned the proven state-4 and state-0B
// handlers to the opposite source cases, so it was not retained. Restored the
// clean typed source, retained H19's natural state-4 handler order, and left
// the unresolved source in scratch. No accepted-drift residue is proved.
// Accepted-drift audit: do not promote. The executable has a distinct virtual
// set_state(3) call site for the state-0B handler. VC5 merges it with the state-6
// null-target call. The runtime target can match, but the callee-visible return
// address and caller stack identify a different owning call site.
// TU context audit: same-module tact_hea.cpp owners were tested in address order.
// No tested authentic nearest-one or cumulative multi-owner prefix compiled
// with this standalone class surface. No context change is validated.
// Exact finish (sa-0aec391d-r1): the exact tact_cnv.cpp update donor proves
// direct nested-switch transition bodies and RGE_Action_Object::turn_towards
// at slot +0x1F0. Restoring those forms gave all 27 ordered call sites.
// The canonical tactical hierarchy then reduced the result to one commuted
// x87 multiply. The full RGE_Player virtual surface plus the complete sibling
// tactical-action declaration group restored the shipped operand order.
// Removing the broad context lost both required x87 operand orders. Removing
// the sibling group, or restoring TRIBE_Action_Build alone, lost the final
// stack-first multiply. These context parts form one required VC5 group.
// Expanded assignment, double casts, a branch-local product, a float reference,
// and a conditional expression were duplicate nine-byte mismatches.
// The reduced source uses ordinary compound multiplication and direct fields.

#include "../../include/tact_hea_context.h"

extern float DAT_005750e0;
extern double DAT_005750e8;

class TRIBE_Action_Heal : public RGE_Action {
public:
    virtual void set_state(uchar);
    virtual uchar update();
};

uchar TRIBE_Action_Heal::update()
{
    float work;

    if (this->targetID != -1 &&
        this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target2ID != -1 &&
        this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 2) {
        this->set_target_obj(0);
        this->set_state(3);
        return 0;
    }

    if (this->target_obj != 0 &&
        this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
        this->set_state(1);
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1FB, 0x25B, 0, 0);
        return 4;
    }

    switch (this->state) {
    case 0x0B:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            this->set_state(0x0D);
            return 0;
        case 4:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        case 3:
            this->set_state(0x0D);
            return 0;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0.0f, 0.0f) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }

        if (this->target_obj->world_x != this->target_x ||
            this->target_y != this->target_obj->world_y) {
            float distance = this->obj->distance_to_object(this->target_obj);
            if (this->task->range < distance && DAT_005750e8 < distance) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        work = this->task->work_rate * this->obj->master_obj->work_rate;
        work *= this->obj->owner->world->world_time_delta_seconds;
        if (this->obj->owner->attributes[0x38] > DAT_005750e0) {
            work *= this->obj->owner->attributes[0x38];
        }

        uchar result = this->target_obj->heal(work);
        if (result == 1) {
            this->set_state(3);
            return 0;
        }
        if (result == 2) {
            this->obj->notify(this->obj->id, this->obj->id,
                              0x1FB, 0x25B, 0, 0);
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x25B, 0, 0);
        this->set_state(2);
        return 3;
    }

    return 0;
}
