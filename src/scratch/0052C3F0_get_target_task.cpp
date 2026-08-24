// ttsk_lst.cpp:41-294, 1201 bytes
// attempt 1: 16 bytes
// attempt 2: compile errors - bad gaps, vfunc syntax, missing base decl
// attempt 3: 1201 bytes, 96.8% diff, codegen basin problem
// attempt 4: fix class offsets, add FPU global: still 1201 bytes, 96.9% diff
// Fixed base class to RGE_Static_Object with correct vtable/master/owner/44/48/4C.
// Field offsets now match original EXE layout.
// Remaining 96.4%: register allocation cascade (param_1 in EDX orig vs EAX rebuilt).
// Original pushes esi before loading param_2; rebuilt loads param_2 early.
// This changes stack offsets and register assignments throughout 1201 bytes.
// Deep codegen basin — needs significant source restructuring.
// Left in scratch.
// Baseline reset: use typed task, object, master, player, and list surfaces
// from the exact task_lst.cpp and ttsk_lst.cpp donors.  Preserve the binary
// branch order and the seven player-relation calls.
// Probe: switch(sVar2) preserved the binary sparse dispatch and the jump-table
// shape. The lower-bound subtract is VC5 lowering; the natural switch is kept.
// Probe: moving the two -1 defaults into the group branch moved their stores
// to the original post-gate location and aligned the early CFG.
// Probe: positive list guards with a fall-through zero return merged the empty
// scans into the original common return block and reduced the size gap.
// Probe: branch-local int count values made every scan sign-extend list_num
// before its guard, matching the repeated oracle scan prologue.
// Probe: a named target alias and reordered short declarations produced no
// emitted change. Shared iVar8 loop state matched the decompiler evidence.
// Left in scratch: structural drift is 44 bytes, with the first hunk at the
// param_2 home/register load (original ESI, rebuilt EDI); all eight calls align.
// Follow-up probe: guarded do/while scans removed the 44-byte size gap but
// changed induction-register coloring and worsened the positional diff; restored.
// Follow-up probe: removing only the first scan guard also worsened the basin;
// the original single gate is not enough without the matching source context.
// Follow-up probe: materializing the target master id through short/int locals
// and an independent group-0x15 gate exposed one oracle block but worsened CFG;
// restored. Remaining lead is TU/source lifetime context, not register forcing.
// Pass 2 evidence:
// BINARY NOTE: The shipped first target-id compare sign-extends the short field
// to EAX and compares full-width ECX/EDI. Int alternate-id locals reproduced
// that width and reduced output by 4 bytes, but worsened positional diff.
// BINARY NOTE: Removing explicit positive list guards removed the 44-byte size
// gap, but changed the register basin and worsened positional similarity.
// Header additions, declaration order, local scope, and a register hint were
// unchanged or worse. The baseline below remains the clean natural source.
// Pass 3 evidence:
// BINARY NOTE: The original repeats target-null tests before later target
// policy blocks. Separate source blocks improved CFG coverage, but added 16
// bytes and worsened strict difference. The clean source remains restored.
// BINARY NOTE: A first-scan do/while reached the original 1201-byte size, but
// changed induction colors and worsened strict difference. VC5 canonicalized
// direct-index and typed-cursor forms to the same basin.
// Open: recover the source or translation-unit context that keeps param_2 in
// ESI and sVar7 in EDI before tuning the remaining list-scan topology.
// Pass 4 context:
// BINARY NOTE: The PDB source module is ttsk_lst.cpp.  The reviewed context
// header keeps the canonical task-list list/list_num alias and the player
// virtual slot used by all seven relation calls.  The target output stayed
// unchanged after this context move.  The unregistered module wrapper lists
// the PDB owner order and the 0052C8D0 exact anchor.
// Pass 5 audit:
// BINARY NOTE: The packet has 47 nonempty PDB boundary bands for this owner.
// Each band falls inside 0052C3F0..0052C8A1.  0052C8A1 is padding-only and
// 0052C8D0 is the separate exact is_attack_task owner.
// BINARY NOTE: Direct param_2 use and the prior target alias emit identical
// code.  Keep the direct spelling as the smaller natural source model.
// BINARY NOTE: The final wrapper compiles with all eight ordered calls and the
// correct owner symbol, but remains a positional mismatch at the first hunk.
#include "..\..\include\ttsk_lst_context.h"
RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    short sVar2, sVar7, sVar5;
    int iVar8;

    sVar2 = param_1->attribute_type_held;
    if (sVar2 != -1 && param_1->attribute_amount_held > DAT_0057733c && param_2 != 0 && param_2->object_state == 2) {
        short sVar1 = param_1->master_obj->object_group;
        if (sVar1 == 4 || sVar1 == 0x15) {
            sVar5 = -1;
            sVar7 = -1;
            if (sVar1 == 4) {
                switch (sVar2) {
                case 1:
                case 2:
                case 3:
                case 0x0F:
                case 0x11:
                    sVar5 = 0x6D;
                    sVar7 = 0x67;
                    break;
                case 0x10:
                    sVar5 = 0x6D;
                    sVar7 = 0x44;
                }
            } else if (sVar2 == 9 || sVar2 == 0x11) {
                sVar5 = 0x2D;
            }
                if ((param_2->master_obj->id == sVar5 ||
                 param_2->master_obj->id == sVar7) &&
                param_2->owner->id == param_1->owner->id) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->attribute_type == sVar2 &&
                            (task->action_type == 5 ||
                             task->action_type == 0x6E ||
                             task->action_type == 0x6F)) {
                            return task;
                        }
                    }
                }
            }
        }
    }

    if (param_2 != 0) {
        if (param_1 != 0 && param_2->owner == param_1->owner && param_2->master_obj->master_type == 'P' && param_2->object_state == 0) {
            int count = this->list_num;
            if (count > 0) {
                for (iVar8 = 0; iVar8 < count; iVar8++) {
                    RGE_Task* task = this->list[iVar8];
                    if (task->action_type == 0x65) return task;
                }
            }
            return 0;
        }
        if (param_2->owner == param_1->owner ||
            ((iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0 &&
             (iVar8 = param_2->owner->isAlly(param_1->owner->id)) != 0)) {
            if (param_2->object_state < 3 && param_2->master_obj->unit_level == 7) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 3) return task;
                    }
                }
                return 0;
            }
        }
        if (param_1 != 0) {
            if (param_2->owner == param_1->owner ||
                (iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0) {
                if (param_2->master_obj->master_type == 'P' && param_2->hp < (float)param_2->master_obj->hp && param_2->object_state < 3 && param_2->master_obj->id != 0x32) {
                    int count = this->list_num;
                    if (count > 0) {
                        for (iVar8 = 0; iVar8 < count; iVar8++) {
                            RGE_Task* task = this->list[iVar8];
                            if (task->action_type == 0x6A &&
                                (task->object_group == -1 || task->object_group == 0)) {
                                return task;
                            }
                        }
                    }
                    return 0;
                }
            }
        }
        if (param_2->owner == param_1->owner ||
            ((iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0 &&
             (iVar8 = param_2->owner->isAlly(param_1->owner->id)) != 0)) {
            sVar2 = param_2->master_obj->object_group;
            if ((sVar2 == 2 || sVar2 == 0x14 || sVar2 == 0x15 || sVar2 == 0x16) && param_2->hp < (float)param_2->master_obj->hp && param_2->object_state < 3) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 0x6A && task->object_group == sVar2) return task;
                    }
                }
                return 0;
            }
        }
    }

    if (param_1 != 0 && param_1->master_obj->object_group == 0x12) {
        if (param_2 != 0) {
            if (param_2->owner != param_1->owner &&
                param_2->object_state < 3 &&
                param_2->owner->id >= 1 &&
                param_1->owner->isAlly(param_2->owner->id) == 0 &&
                param_2->master_obj->object_group != 1) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 0x68) return task;
                    }
                }
            }
            if (param_2->owner == param_1->owner ||
                param_1->owner->isAlly(param_2->owner->id) != 0) {
                if (param_2->object_state < 3 && param_2->hp < (float)param_2->master_obj->hp) {
                    sVar2 = param_2->master_obj->object_group;
                    if (sVar2 != 0x15 && sVar2 != 2 && sVar2 != 0x14 &&
                        sVar2 != 0x16 && sVar2 != 1 && sVar2 != 0x1B &&
                        sVar2 != 3) {
                        int count = this->list_num;
                        if (count > 0) {
                            for (iVar8 = 0; iVar8 < count; iVar8++) {
                                RGE_Task* task = this->list[iVar8];
                                if (task->action_type == 0x69) return task;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    return RGE_Task_List::get_target_task(param_1, param_2, param_3, param_4, param_5);
}
