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
// Probe: a natural switch for the sparse attribute dispatch improved shape
// and exact-block coverage, but increased the byte diff and code size. Restored
// the typed if-chain as the cleaner source reconstruction.
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
    short sVar2, sVar5 = -1, sVar7 = -1;
    int iVar8;

    sVar2 = param_1->attribute_type_held;
    if (sVar2 != -1 && param_1->attribute_amount_held > DAT_0057733c && param_2 != 0 && param_2->object_state == 2) {
        short sVar1 = param_1->master_obj->object_group;
        if (sVar1 == 4 || sVar1 == 0x15) {
            if (sVar1 == 4) {
                if (sVar2 == 1 || sVar2 == 2 || sVar2 == 3 ||
                    sVar2 == 0x0F || sVar2 == 0x11) {
                    sVar5 = 0x6D;
                    sVar7 = 0x67;
                }
                if (sVar2 == 0x10) {
                    sVar5 = 0x6D;
                    sVar7 = 0x44;
                }
            } else if (sVar2 == 9 || sVar2 == 0x11) {
                sVar5 = 0x2D;
            }
            if ((param_2->master_obj->id == sVar5 ||
                 param_2->master_obj->id == sVar7) &&
                param_2->owner->id == param_1->owner->id) {
                if (this->list_num > 0) {
                    for (int i = 0; i < this->list_num; i++) {
                        RGE_Task* task = this->list[i];
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
            if (this->list_num < 1) return 0;
            for (int i = 0; i < this->list_num; i++) {
                RGE_Task* task = this->list[i];
                if (task->action_type == 0x65) return task;
            }
            return 0;
        }
        if (param_2->owner == param_1->owner ||
            ((iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0 &&
             (iVar8 = param_2->owner->isAlly(param_1->owner->id)) != 0)) {
            if (param_2->object_state < 3 && param_2->master_obj->unit_level == 7) {
                if (this->list_num < 1) return 0;
                for (int i = 0; i < this->list_num; i++) {
                    RGE_Task* task = this->list[i];
                    if (task->action_type == 3) return task;
                }
                return 0;
            }
        }
        if (param_1 != 0) {
            if (param_2->owner == param_1->owner ||
                (iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0) {
                if (param_2->master_obj->master_type == 'P' && param_2->hp < (float)param_2->master_obj->hp && param_2->object_state < 3 && param_2->master_obj->id != 0x32) {
                    if (this->list_num < 1) return 0;
                    for (int i = 0; i < this->list_num; i++) {
                        RGE_Task* task = this->list[i];
                        if (task->action_type == 0x6A &&
                            (task->object_group == -1 || task->object_group == 0)) {
                            return task;
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
                if (this->list_num < 1) return 0;
                for (int i = 0; i < this->list_num; i++) {
                    RGE_Task* task = this->list[i];
                    if (task->action_type == 0x6A && task->object_group == sVar2) return task;
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
                if (this->list_num < 1) return 0;
                for (int i = 0; i < this->list_num; i++) {
                    RGE_Task* task = this->list[i];
                    if (task->action_type == 0x68) return task;
                }
            }
            if (param_2->owner == param_1->owner ||
                param_1->owner->isAlly(param_2->owner->id) != 0) {
                if (param_2->object_state < 3 && param_2->hp < (float)param_2->master_obj->hp) {
                    sVar2 = param_2->master_obj->object_group;
                    if (sVar2 != 0x15 && sVar2 != 2 && sVar2 != 0x14 &&
                        sVar2 != 0x16 && sVar2 != 1 && sVar2 != 0x1B &&
                        sVar2 != 3) {
                        if (this->list_num < 1) return 0;
                        for (int i = 0; i < this->list_num; i++) {
                            RGE_Task* task = this->list[i];
                            if (task->action_type == 0x69) return task;
                        }
                    }
                }
            }
        }
        return 0;
    }

    return RGE_Task_List::get_target_task(param_1, param_2, param_3, param_4, param_5);
}
