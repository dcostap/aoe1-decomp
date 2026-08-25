// VA: 00405850 RGE_Action_Move_To::update
// PDB source: act_move.cpp
//
// Attempt log:
// - 1st pass: extern "C" free function -> 686/890 diff
// - 2nd pass: member function, extern function pointers -> 717/890 diff
// - 3rd pass: direct extern declarations -> 1035 positional diff in the fresh baseline
// - probe 2 source reset: restored the period RGE_Action/RGE_Static_Object/RGE_Moving_Object
//   ownership and real member/virtual call surfaces; removed raw helper wrappers and reused
//   one doMove result. The binary's two final +0x28 calls are modeled as virtual update calls.
// - probes 3-6 switch-handler ordering/label placement: 207-byte diagnostic basin; the
//   compiler keeps case 1 eight bytes before the original default/tail despite equivalent
//   source arrangements.
// - probe 7 removed the duplicated set_state(1) from state_done; this restored all 31
//   ordered call sites and the direct behavior-backed state-13/doMove-zero split.
// - probe 8 scoped the waypoint aggregate (rolled back: it removed the 0x8 frame).
// - probe 9 used a union overlay for the proven waypoint/first-distance ESP reuse
//   (209-byte diagnostic result, not retained as source); probe 10 external bound symbols
//   was codegen-identical. Natural source is restored; remaining drift is switch-table
//   relocation identity, case-tail placement, x87 bound relocation bytes, and one return
//   register/epilogue ordering hunk.
// - 2026-08-10 orch-actmove-02 pass: independently confirmed the paused clean source and
//   binary evidence. A default-return label, implicit default, case-1-first, target_lost-inside-switch,
//   sibling-shaped case-1-last, and explicit sparse-default case labels did not reproduce the original
//   cold case-1 tail (the explicit sparse labels instead made the switch dense). A five-variant
//   case-1 return-spelling lab found no exact group. Retained natural source; blocker remains VC5 switch-handler
//   placement plus the resulting late x87/return displacement drift.
// - 2026-08-13 tu-actmove-405850 pass: case-1-as-post-switch-return worsened to 706 bytes and changed the
//   dispatch range; an explicit late case-1 goto and equivalent switch(state - 1) spelling were codegen-identical
//   to the clean 212-byte mismatch. Restored the natural state switch; the sparse case-1 tail remains unresolved.
// - 2026-08-17 sa-f38c1d93 pass: twenty new probes kept the natural 890-byte/0x8-frame source as the clean
//   reconstruction. Scoping move_result, caching state, declaration reordering, case-label reordering,
//   return spellings, stdlib context, and inline/size pragmas did not improve it. A typed union overlay for
//   the proven waypoint/first-distance ESP reuse improved 212 to 209 bytes and exact body coverage, but was
//   discarded as compiler-steering rather than canonical source. External bound symbols were codegen-identical.
//   Remaining evidence-led blockers are the unmasked local switch-table relocations, cold case-1 epilogue
//   placement, and the original absolute x87 bound relocations.
// - 2026-08-24 exact-finish continuation: routing case 1 through a label after
//   the switch, moving target_lost before case 1 inside the switch, and placing
//   case 1 before default all reproduced the 212-byte/31-call natural basin.
//   Restored this source after each test.
// - 2026-08-24 exact-finish audit: fresh canonical-TU checks kept 00405510,
//   004055A0, and 00405620 exact at 0.0000%. This update kept its 890-byte
//   boundary, owner symbol, 31 ordered calls, frame, and x87 compare topology,
//   but remained 212 bytes nonexact. The first drift is the switch-table
//   relocation ([ecx+405BE0]/[edx*4+405BCC] versus local table relocations).
//   Later drift is the cold case-one tail, x87-bound relocation, and the
//   [esp+8] versus [esp+0xc] difference scratch home. No variant was retained.
// Accepted-drift review: the residual is local switch-table relocation, cold
// case-one return placement, equivalent x/y-difference stack homes, and return
// epilogue scheduling. Both versions recompute target differences after doMove.
// x87 compare order, all 31 calls and arguments, notifications, state changes,
// recursive updates, and return values match.
// Canonical-TU pass: the shared owner surface supplies the reviewed player,
// world, static-object, and action types.

#ifndef ACT_MOVE_CANONICAL_TU
#include "../../include/act_move_context.h"
#endif

unsigned char RGE_Action_Move_To::update()
{
    XYZBYTEPoint waypoint;
    int move_result;

    if (this->targetID != -1 && this->obj->owner->world->object(this->targetID) == 0) {
        this->set_target_obj(0);
        goto target_lost;
    }

    if (this->target2ID != -1 && this->obj->owner->world->object(this->target2ID) == 0) {
        this->set_target_obj2(0);
    }

    if (this->target_obj != 0 && this->target_obj->object_state >= 7) {
        this->set_target_obj(0);
        goto target_lost;
    }

    switch (this->state) {
    case 3:
        if (this->target_obj != 0 && this->obj->inRange(this->target_obj, this->range) != 0) {
            this->set_state(1);
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x262, 0, 0);
            }
            this->obj->setWaitingToMove(0);
            this->obj->pathingGroupMembers.numberValue = 0;
            return 2;
        }

        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }

        this->obj->setGoal(this->target_x, this->target_y, 1.0f);
        waypoint.x = (unsigned char)this->target_x;
        waypoint.y = (unsigned char)this->target_y;
        waypoint.z = (unsigned char)this->target_z;
        if (this->obj->finalUserDefinedWaypoint == 0) {
            this->obj->addUserDefinedWaypoint(&waypoint, 0);
            this->obj->setFinalUserDefinedWaypoint();
        }
        this->obj->setActionRange(this->range);

        if (this->target_obj != 0) {
            this->obj->setTargetID(this->target_obj->id);
            this->obj->setTargetRadius(this->target_obj->master_obj->radius_x,
                                       this->target_obj->master_obj->radius_y);
        } else {
            this->obj->setTargetID(-1);
            this->obj->setTargetRadius(0.0f, 0.0f);
        }

        if (this->obj->findPath() == 0) {
            this->set_state(4);
            return 0;
        }
        break;

    case 4:
        if (this->target_obj != 0) {
            float x_diff = this->target_x - this->target_obj->world_x;
            float y_diff = this->target_y - this->target_obj->world_y;
            if (x_diff < -1.0 || x_diff > 1.0 ||
                y_diff < -1.0 || y_diff > 1.0) {
                goto reached_target;
            }
        }

        move_result = this->obj->doMove();
        if (move_result == 0) {
            this->set_state(1);
            goto state_done;
        }
        if (move_result == 2) {
            if (this->target_obj != 0) {
                float x_diff = this->target_x - this->target_obj->world_x;
                float y_diff = this->target_y - this->target_obj->world_y;
                if (x_diff < -1.0 || x_diff > 1.0 ||
                    y_diff < -1.0 || y_diff > 1.0) {
                    goto reached_target;
                }
            }
            if (this->subActionValue == 0) {
                this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x262, 0, 0);
            }
            this->set_state(1);
            return 2;
        }
        break;

    case 13:
        goto state_done;

    default:
        return 0;

reached_target:
    this->obj->notify(this->obj->id, this->obj->id, 0x1FC, 0, 0, 0);
    this->set_state(3);
    this->update();
    this->update();
    return 0;

state_done:
    if (this->subActionValue == 0) {
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x262, 0, 0);
    }
    return 3;

    case 1:
        return 1;
    }

    return 0;

target_lost:
    if (this->subActionValue == 1) {
        return 5;
    }
    this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x262, this->targetID, 0);
    return 4;
}
