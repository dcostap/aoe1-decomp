// VA: 004D1BB0 TRIBE_Action_Repair::update
// Attempt log:
// baseline: reconstructed the inherited action fields, object/world/player ownership,
// nested state/sub-action dispatch, and repair-distance paths from tact_rep.cpp evidence.
// ABI probe: replaced decompiler-shaped object_delta/command shims with the period
// RGE_Static_Object distance_to_object/heal/notify, RGE_Action_Object turn_towards,
// RGE_Player isAlly, and RGE_Base_Game notification surfaces; calls became 29/29.
// control-flow probe: corrected the state table to the binary's source-order handlers
// 10, 12, 4, 13, 6, 7, 9, 1, 11; state 4 shares the state-13 distance tail.
// liveness probe: retained the nested target recheck, one heal result for both ==1/==2
// tests, global-before-threshold FPU comparisons, and direct three-factor repair rate.
// duplicate probes: state-4 goto versus ordinary inner-switch fall-through and a
// scoped sub-action pointer/result local emitted the same or a worse basin; rolled back.
// final best: a named state-13 target alias restores the original target/object load
// order and leaves 35 positional bytes (96.37% shape, exact call/size/frame parity).
// timer assignment-in-condition probe: the natural x87 source form emitted the
// same bytes as the separate decrement statement; restored the cleaner form.
// focused follow-up: reversed the timer predicate, tested state-4 case-group order,
// compound-case scope, and an int sub-action result; the first worsened size, the
// latter three were codegen duplicates or broad negative results and were restored.
// ABI-width cast and a nine-variant state-4/timer lab produced no EDX vtable match;
// the direct typed form remains the clean source reconstruction.
// revisit pass: replacing the state-9 DAT_00575278 reference with the proven zero
// literal recovered the original fcom/fstp order and reduced the masked diff 35->27.
// Owner-first world_delta and master_rate locals recovered 12 of the 14 repair-rate
// drift bytes and reduced the diff 27->16. More than 30 distinct follow-up probes
// covered timer scope/predicate forms, state-4 dispatch forms, ABI spellings, and
// rate-local layouts; no further source form changed the best emitted code.
// remaining localized drift: state-4 vtable-register coloring (two bytes) and
// repair-rate FPU operand/push scheduling (14 bytes); all 19 relocations are masked.
// left in scratch after the sustained revisit; no inline asm or custom flags.
// Type/layout revisit: the ground-truth master-action hierarchy is polymorphic;
// restoring a local vptr surface at unchanged work_rate offset +E4 emitted the
// same 16-byte result. Reversed local declaration order and handler order were
// also tested; the former duplicated codegen and the latter worsened call order.
// Accepted-drift audit: do not promote the repair-rate hunk. The executable
// reads task->work_rate before owner->world and its time delta. The rebuild
// dereferences owner->world first and reverses the first x87 multiply operands.
// This changes pointer-fault order, concurrent rereads, and NaN payload behavior
// before the value is passed to the virtual heal call.
// TU context audit: same-module tact_rep.cpp owners were tested in address order.
// No tested authentic nearest-one or cumulative multi-owner prefix compiled
// with this standalone class surface. No context change is validated.
// Direct left-product float grouping restored the executable's task, world,
// then master x87 order without caching any owner field. It reduced drift to
// the two state-4 vtable-register bytes. A canonical tact_rep declaration
// surface and grouped prior functions did not change those bytes.
// Exact-finish pass (sa-e60ccc0c): fresh probes kept 29 ordered calls, 828-byte
// size, three saved registers, and the rebuilt update owner symbol.
// A reference receiver for state 4, reversed pointer declarations, and a
// case-scoped state-13 target alias all emitted the same two-byte drift.
// Reusing the proven check-target local for state 13 also emitted the same drift.
// The proven derived byte at +40 also emitted the same two-byte drift.
// Restore the clean source after each probe. Do not use register hints.
// The remaining bytes are the state-4 action-list vtable load: EDX is original;
// EAX is rebuilt. No natural source change found in this pass selects EDX.

#include "../../include/tact_rep_context.h"

uchar TRIBE_Action_Repair::update()
{
    RGE_Static_Object* check_target;
    RGE_Static_Object* target;

    if (this->targetID != -1) {
        if (this->obj->owner->world->object(this->targetID) == 0) {
            goto invalid_target;
        }
    }

    if (this->target2ID != -1) {
        if (this->obj->owner->world->object(this->target2ID) == 0) {
            this->set_target_obj2(0);
        }
    }

    check_target = this->target_obj;
    if (check_target != 0) {
        if (check_target->object_state != 2) {
            goto invalid_target;
        }
        if (this->target_obj != 0 &&
            this->obj->owner->isAlly(this->target_obj->owner->id) == 0) {
            goto invalid_target;
        }
    }

    switch (this->state) {
    case 10:
        switch (this->sub_actions->update()) {
        case 4:
            this->set_target_obj(0);
            this->set_state(0x0B);
            return 0;
        case 1:
        case 2:
        case 3:
        case 5:
            this->set_state(1);
            return 0;
        }
        break;

    case 12:
        this->set_state(1);
        return 0;

    case 4:
        switch (this->sub_actions->update()) {
        case 1:
        case 2:
        case 3:
            break;
        case 4:
        case 5:
            goto invalid_target;
        default:
            goto update_done;
        }

    case 13:
        target = this->target_obj;
        DAT_0086bc08 = this->obj->distance_to_object(target) - DAT_0057526c;
        if (DAT_0086bc08 <= DAT_00575270) {
            this->set_state(6);
            return 0;
        }
        this->set_state(10);
        return 0;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(1);
            return 0;
        }
        if (this->obj->turn_towards(this->target_obj, 0, 0) != 0) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        if (this->target_obj == 0) {
            this->set_state(1);
            return 0;
        }
        if (this->target_obj->world_x != this->target_x ||
            this->target_y != this->target_obj->world_y) {
            DAT_0086bc08 = this->obj->distance_to_object(this->target_obj) - DAT_0057526c;
            if (DAT_0086bc08 > DAT_00575270) {
                this->set_state(3);
                return 0;
            }
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
            return 0;
        }

        uchar result = this->target_obj->heal(
                (float)(this->task->work_rate *
                        this->obj->owner->world->world_time_delta_seconds) *
                this->obj->master_obj->work_rate);
        if (result == 1) {
            this->set_state(1);
            return 0;
        }
        if (result == 2) {
            this->obj->notify(this->obj->id, this->obj->id,
                              0x1FB, 0x26A, 0, 0);
            rge_base_game->notification(0x6B, this->obj->owner->id,
                                        this->target_obj->id, 0, 0);
            this->set_state(2);
            return 0;
        }
        break;
    }

    case 9:
        if (this->target_obj == 0) {
            break;
        }
        this->timer -= this->obj->owner->world->world_time_delta_seconds;
        if (this->timer <= 0.0f) {
            DAT_0086bc08 = this->obj->distance_to_object(this->target_obj) - DAT_0057526c;
            if (DAT_0086bc08 <= DAT_00575270) {
                this->set_state(6);
                return 0;
            }
            this->timer = 1.0f;
            return 0;
        }
        break;

    case 1:
        return 1;

    case 11:
        this->obj->notify(this->obj->id, this->obj->id,
                          0x1F9, 0x26A, 0, 0);
        this->set_state(2);
        return 3;
    }

update_done:
    return 0;

invalid_target:
    this->set_target_obj(0);
    this->set_state(1);
    return 0;
}
