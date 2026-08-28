// RGE_Action_Enter::update (00402740)
// Canonical action-object hierarchy restored from the exact act_entr.cpp donors.
// The target is a virtual RGE_Action update with inherited RGE_Action fields;
// object/world/player/static-object calls use their period ABI surfaces.
//
// Attempt log:
// - baseline: prior flat-field source compiled to a constant-return stub because
//   same-TU method stubs let VC5 fold every call; it was not a useful structural
//   baseline.
// - typed reconstruction: restored the prior act_entr.cpp donor-shaped source,
//   real virtual slots, inherited action layout, and declaration-only external
//   calls. The source-level target validation keeps the binary's redundant null
//   test and target-object/action-list ownership.
// - control-flow probes: case-3-first nested dispatch plus positive distance
//   guards restored 954-byte size/frame, 94.20% shape, and 97.30% ordered-call
//   alignment. Inclusive distance/operand variants were compared; the current
//   task-left form is the best structural basin and keeps the real call ABI.
// - liveness alias probe was codegen-identical and rolled back to the clean
//   typed form. Remaining binary gap is localized: the second object lookup is
//   load-first instead of the oracle's push-first schedule, and VC5 merges one
//   of two proven enter_obj sites (36/37 calls). No productive source lead
//   remains within this assignment budget.
// - direct positive compound target guards, reconstructed from the decompiler's
//   short-circuit shape, were codegen-identical and rolled back.
// - a correct distance-first negative inner guard preserved both enter_obj calls
//   but VC5 merged the two state-2 calls. Task-left and negated compare forms
//   were either behaviorally inverted or returned to the same 36-call basin.
//   Explicit else and scoped action aliases were also unchanged. Clean source
//   restored; the remaining lead is the original call-site scheduling/context.
// - sustained follow-up probes (20 meaningful hypotheses) confirmed the same
//   basin. Lookup null-literal, compound-guard, cached-id, cached-world,
//   cached-object, separate-result, typed-null, and explicit-else forms were
//   codegen-identical. A switch-to-if rewrite restored 37/37 calls but added
//   47 bytes and broke the proven switch CFG. A 32-sample ambient declaration
//   sweep produced one code group. Distance-left polarity improved block
//   coverage but traded the missing enter_obj for a missing set_state call;
//   asymmetric polarity and call-local aliases did not solve both gaps.
//   The pinned task-left source is therefore retained as the smallest clean
//   natural reconstruction. No shared files were changed.
// - fresh follow-up probes tested explicit early distance failures, operand
//   reversal, full outer target-validation nesting, comma-condition lookup,
//   base casts, derived virtual declarations, and state-2 receiver aliases.
//   These either worsened the CFG or emitted the same 36-call group. The
//   clean source remains pinned; the unresolved facts are the second lookup's
//   push-first schedule and one merged vslot+D0 enter_obj call.
// - current captain probes: removing the target2 lookup temporary and caching
//   target2ID were codegen-identical. A distance-first state-4 guard restored
//   both enter_obj calls and reduced the positional diff to 446 bytes, but
//   added 58 bytes and changed call/block order; it was rolled back. A
//   redundant target guard and reversed comparison were worse. The final
//   source is restored and validated at 663 differing bytes.

#include "../../include/act_entr.h"
#include "../../include/act_list.h"
#include "../../include/act_move.h"
#include "../../include/act_obj.h"
#include "../../include/game_globals.h"
#include "../../include/player.h"
#include "../../include/task.h"
#include "../../include/world.h"
#include "../../include/xy_point.h"

unsigned char RGE_Action_Enter::update(void) {
    RGE_Action* action;
    XYPoint start;
    XYPoint dest;
    XYPoint rVal;
    RGE_Static_Object* pRVar6;
    int iVar7;

    if (this->targetID != -1) {
        pRVar6 = this->obj->owner->world->object(this->targetID);
        if (!pRVar6) goto invalid_target;
    }
    if (this->target2ID != -1) {
        pRVar6 = this->obj->owner->world->object(this->target2ID);
        if (!pRVar6)
            this->set_target_obj2(pRVar6);
    }
    iVar7 = (int)this->target_obj;
    if ((iVar7 == 0) ||
        ((((RGE_Static_Object*)iVar7)->object_state < 3) &&
         ((this->target_obj == 0) ||
              ((iVar7 = this->obj->owner->isAlly((int)(short)((RGE_Static_Object*)iVar7)->owner->id)),
               iVar7 != 0)))) {
            goto handle_state;
        }

invalid_target:
    this->set_state(1);
    this->set_target_obj(0);
    this->obj->notify(this->obj->id, this->obj->id, 0x1FB, 0x269, 0, 0);
    return 4;

handle_state:
    switch (this->state) {
    case 4:
        if ((this->target_obj != 0) && (this->target_obj->is_dying() == 0)) {
            switch (this->sub_actions->update()) {
            case 3:
                this->set_state(2);
                return 0;

            case 1:
            case 2:
                if (this->task->work_range >= this->obj->distance_to_object(this->target_obj) - DAT_0056e1a4) {
                    this->obj->enter_obj(this->target_obj);
                    goto entered_target;
                }
                this->set_state(2);
                return 0;

            case 4:
            case 5:
                break;

            default:
                return 0;
            }
        }

        this->set_target_obj(0);
        this->set_state(0x0D);
        return 0;

    case 2:
        this->timer = this->timer - this->obj->owner->world->world_time_delta_seconds;
        if (this->timer > DAT_0056e1a8) {
            return 0;
        }

        if (this->task->work_range >= this->obj->distance_to_object(this->target_obj) - DAT_0056e1a4) {
            this->obj->enter_obj(this->target_obj);
            goto entered_target;
        }

        if (this->target_obj->actionState() == 2) {
            dest.x = (int)this->obj->world_x;
            dest.y = (int)this->obj->world_y;
            start.x = (int)this->target_obj->world_x;
            start.y = (int)this->target_obj->world_y;
            if (this->obj->firstTileAlongLine(&dest, &start, &rVal, 2, 2, 1) == 1) {
                float tile_x;
                float tile_y;

                tile_x = (float)rVal.x - DAT_0056e1a0;
                tile_y = (float)rVal.y - DAT_0056e1a0;
                if ((this->target_x == tile_x) && (tile_y == this->target_y)) {
                    this->target_x = this->target_obj->world_x;
                    this->target_y = this->target_obj->world_y;
                    this->set_state(4);
                    return 0;
                }

                this->target_x = tile_x;
                this->target_y = tile_y;
                this->target_obj->moveTo((float)rVal.x, (float)rVal.y, this->target_obj->world_z, 0, 1);
            } else {
                this->target_x = this->target_obj->world_x;
                this->target_y = this->target_obj->world_y;
                this->target_obj->moveTo(this->obj->world_x, this->obj->world_y, this->target_obj->world_z, 0.5f, 1);
            }
        } else if (this->target_obj->actionState() == 0x0B) {
            action = ((RGE_Action_Object*)this->target_obj)->actions->get_action();
            this->target_x = action->targetX();
            action = ((RGE_Action_Object*)this->target_obj)->actions->get_action();
            this->target_y = action->targetY();
        }

        this->set_state(4);
        return 0;

entered_target:
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1FA, 0x269, 0, 0);
        }
        this->set_state(1);
        return 2;

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id, 0x1F9, 0x269, 0, 0);
        return 3;

    default:
        return 0;
    }
}
