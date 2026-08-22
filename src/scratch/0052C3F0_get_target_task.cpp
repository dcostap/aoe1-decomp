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
#include "..\..\include\game_globals.h"
class TRIBE_Task_List;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;
class RGE_Player;
class RGE_Master_Static_Object;

class RGE_Task {
public:
    char gap_00[0x06];
    short action_type;               // +0x06
    short object_group;              // +0x08
    short object_id;                 // +0x0A
    unsigned char combat_level;      // +0x0C
    unsigned char combat_level_flag; // +0x0D
    short terrain_id;                // +0x0E
    unsigned char owner_type;        // +0x10
    unsigned char holding_attr;      // +0x11
    unsigned char state_building;    // +0x12
    unsigned char gap_13;
    short attribute_type;            // +0x14
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, short);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
    virtual int is_attack_task(RGE_Task*);
    virtual int check_task(RGE_Task*, RGE_Action_Object*, RGE_Static_Object*);
    virtual ~RGE_Task_List();

    RGE_Task** list;                 // +0x04
    short list_num;                  // +0x08
};

// RGE_Static_Object base provides field offsets at original EXE positions
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();

    int id;                                 // +0x04
    RGE_Master_Static_Object* master_obj;   // +0x08
    RGE_Player* owner;                      // +0x0C
    char gap_10[0x20];                      // +0x10..+0x2F
    float hp;                               // +0x30
    char gap_34[0x10];                      // +0x34..+0x43
    float attribute_amount_held;            // +0x44
    unsigned char object_state;             // +0x48
    char gap_49[3];                         // +0x49..+0x4B
    short attribute_type_held;              // +0x4C
};

class RGE_Action_Object : public RGE_Static_Object {
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    unsigned char master_type;             // +0x04
    char gap_05[0x0B];                      // +0x05..+0x0F
    short id;                               // +0x10
    short copy_id;                          // +0x12
    short object_group;                     // +0x14
    char gap_16[0x10];                      // +0x16..+0x25
    short hp;                               // +0x26
    char gap_28[0x67];                      // +0x28..+0x8E
    unsigned char unit_level;              // +0x8F
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(long);
    virtual int isAlly(long);              // vtbl slot at +0x1C

    char gap_04[0x46];
    short id;                               // +0x4A
};

class TRIBE_Task_List : public RGE_Task_List {
public:
    RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
};

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    short sVar2, sVar7, sVar5;
    int iVar8;

    sVar2 = param_1->attribute_type_held;
    RGE_Static_Object* target = param_2;
    if (sVar2 != -1 && param_1->attribute_amount_held > DAT_0057733c && target != 0 && target->object_state == 2) {
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
                if ((target->master_obj->id == sVar5 ||
                 target->master_obj->id == sVar7) &&
                target->owner->id == param_1->owner->id) {
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

    if (target != 0) {
        if (param_1 != 0 && target->owner == param_1->owner && target->master_obj->master_type == 'P' && target->object_state == 0) {
            int count = this->list_num;
            if (count > 0) {
                for (iVar8 = 0; iVar8 < count; iVar8++) {
                    RGE_Task* task = this->list[iVar8];
                    if (task->action_type == 0x65) return task;
                }
            }
            return 0;
        }
        if (target->owner == param_1->owner ||
            ((iVar8 = param_1->owner->isAlly(target->owner->id)) != 0 &&
             (iVar8 = target->owner->isAlly(param_1->owner->id)) != 0)) {
            if (target->object_state < 3 && target->master_obj->unit_level == 7) {
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
            if (target->owner == param_1->owner ||
                (iVar8 = param_1->owner->isAlly(target->owner->id)) != 0) {
                if (target->master_obj->master_type == 'P' && target->hp < (float)target->master_obj->hp && target->object_state < 3 && target->master_obj->id != 0x32) {
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
        if (target->owner == param_1->owner ||
            ((iVar8 = param_1->owner->isAlly(target->owner->id)) != 0 &&
             (iVar8 = target->owner->isAlly(param_1->owner->id)) != 0)) {
            sVar2 = target->master_obj->object_group;
            if ((sVar2 == 2 || sVar2 == 0x14 || sVar2 == 0x15 || sVar2 == 0x16) && target->hp < (float)target->master_obj->hp && target->object_state < 3) {
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
        if (target != 0) {
            if (target->owner != param_1->owner &&
                target->object_state < 3 &&
                target->owner->id >= 1 &&
                param_1->owner->isAlly(target->owner->id) == 0 &&
                target->master_obj->object_group != 1) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 0x68) return task;
                    }
                }
            }
            if (target->owner == param_1->owner ||
                param_1->owner->isAlly(target->owner->id) != 0) {
                if (target->object_state < 3 && target->hp < (float)target->master_obj->hp) {
                    sVar2 = target->master_obj->object_group;
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
