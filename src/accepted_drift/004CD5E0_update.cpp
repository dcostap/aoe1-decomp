// VA: 004CD5E0 TRIBE_Action_Build::update
// Attempt log:
// try 1-10: prior decompiler-shaped source reached the original 724-byte size,
// but used fabricated action classes, wrong task states, and misnamed virtual
// calls; its broad switch drift was not a useful source reconstruction.
// baseline: canonical TRIBE_Action_Build/RGE_Action ownership with natural
// target checks and state dispatch; exact size, but the old local surfaces still
// produced broad call and layout drift.
// probe 2: restored the period action/static/moving/building hierarchy and the
// observed direct/virtual helper ownership; this is the clean structural lead.
// probe 3: corrected the player command ABI to five integer, four float, and
// three integer arguments; this removed three __ftol calls and restored 724B.
// probe 4: binary fcomp/test evidence requires the active target gate at
// timer == 0.0f, not timer != 0.0f; the branch and early body now align.
// probe 5: push order proves target id precedes target-owner id in command().
// probe 6: PDB/source handler order is 0x0B, 4, 6, 7, 1, 0x0D; restoring it
// reduced the mismatch to a localized nested-switch region.
// probe 7: status-3 arms do not clear the target; adding those calls was a
// broad negative result and was rolled back.
// probe 8: quick_build's positive arm is the inline 1000.0f path; reversing
// the source guard reproduced the original cold work-rate branch.
// probes 9-10: explicit shared-label and nested-case-order variants were
// codegen duplicates; retained the natural direct switch spelling.
// probe 15: moving the state-0x0B target-reset arm before its status-3 arm
// was a codegen duplicate; restored the clean natural switch order.
// retry 18: making the state-0x0B status-3 arm fall through was a duplicate.
// retry 19: an incorrect shared-tail label layout grew the function to 824B;
// it was rolled back.
// retry 21: explicit state-3 and reset/state-0x0B tails reduced drift to 24B.
// retry 24: placing state-4 reset cases before state-6 cases aligned all 24
// calls and reduced drift to 3B; this is the current source candidate.
// retries 25-31: named list/status locals, moved work scope, and register
// locals were codegen duplicates; all were rolled back.
// current best: 724B, 3 differing bytes at the second sub-action vtable
// load (EDX versus original EAX); call targets, order, CFG, and size align.
// r3 probe 1: braces around the state-4 nested switch were a codegen duplicate.
// r3 probe 2: an explicit state-4 default break was a codegen duplicate.
// r3 probe 3: unsigned-int promotion of the state-4 update result was a
// codegen duplicate. Exact donors confirm the same natural switch family;
// retain the shared-tail candidate and pause at the isolated register drift.

unsigned char TRIBE_Action_Build::update()
{
    float work;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            this->set_target_obj(0);
            if (this->state != 2) {
                this->set_state(3);
                return 0;
            }
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    if (this->target_obj != 0 && this->target_obj->object_state != 0 &&
        this->timer == 0.0f) {
        if (this->target_obj->hp <
            (float)(int)this->target_obj->master_obj->hp) {
            this->obj->removeAllFromPathingGroup();
            this->obj->owner->command(
                this->obj->owner->id,
                this->obj->id,
                0x2CE,
                this->target_obj->id,
                this->target_obj->owner->id,
                this->target_obj->world_x,
                this->target_obj->world_y,
                this->target_obj->world_z,
                1.0f,
                1,
                0,
                100);
            return 0;
        }

        this->set_target_obj(0);
        if (this->state != 2) {
            this->set_state(3);
            return 0;
        }
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
            goto state3_common;
        case 4:
            goto reset_common;
        }
        break;

    case 4:
        switch (this->sub_actions->update()) {
        case 4:
        case 5:
            goto reset_common;
        case 3:
            goto state3_common;
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        }
        break;

    case 6:
        if (this->obj->turn_towards(this->target_obj, 0, 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7:
        if (this->timer < 0.0f && this->target_obj != 0 &&
            this->target_obj->attribute_amount_held > 0.0f) {
            this->obj->removeAllFromPathingGroup();
            this->obj->setWaitingToMove(1);
            this->obj->do_command(this->target_obj,
                                  this->target_obj->world_x,
                                  this->target_obj->world_y,
                                  0);
            return 0;
        }

        if (rge_base_game->quick_build != 0) {
            work = 1000.0f;
        } else {
            work = this->task->work_val1 *
                ((RGE_Master_Action_Object*)this->obj->master_obj)->work_rate *
                this->obj->owner->world->world_time_delta_seconds;
        }

        if (this->target_obj == 0 ||
            ((TRIBE_Building_Object*)this->target_obj)->build(work) != 0) {
            if (this->target_obj != 0 &&
                this->target_obj->master_obj->id == 0x32) {
                this->timer = -1.0f;
                return 0;
            }
            goto state3_common;
        }
        break;

    case 1:
        return 1;

    case 0x0D:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x25A, 0, 0);
        this->set_state(2);
        return 3;
    }

return_zero:
    return 0;

state3_common:
    this->set_state(3);
    goto return_zero;

reset_common:
    this->set_target_obj(0);
    this->set_state(0x0B);
    goto return_zero;
}
