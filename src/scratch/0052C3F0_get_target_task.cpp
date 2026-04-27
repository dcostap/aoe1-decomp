// ttsk_lst.cpp:41-294, 1201 bytes
// attempt 1: 16 bytes
// attempt 2: compile errors - bad gaps, vfunc syntax, missing base decl
// attempt 3: 1201 bytes, 96.8% diff, codegen basin problem
// attempt 4: fix class offsets, add FPU global: still 1201 bytes, 96.9% diff
// BLOCKER: deep codegen basin. VC5 picks eax for param_1 (orig: edx),
// cascades through entire 1201 bytes. Logic/size correct (1201/1201)
// but register allocation, instruction order, and loop layout differ.
// Original uses jump table for switch; VC5 uses if/else chain.
// Original uses fcomp [57733Ch] global; VC5 uses fcomp [0] inline.
// Left in scratch per AGENTS.md 10-probe rule for large sticky functions.
class TRIBE_Task_List;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;
class RGE_Player;
class RGE_Master_Static_Object;

class RGE_Task {
public:
    char gap_00[6];
    short action_type;      // +0x06
    short object_group;     // +0x08
    char gap_0A[0x48 - 0x0A];
    short attribute_type;   // +0x4A
};

class RGE_Task_List {
public:
    RGE_Task** tasks;       // +0x04
    short task_count;       // +0x08
    RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
};

class RGE_Action_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;  // +0x08
    RGE_Player* owner;                     // +0x0C
    char gap_10[0x34];
    float field_44;                        // +0x44
    char gap_48[0x04];
    short field_4A;                        // +0x4A
    short field_4C;                        // +0x4C
};

class RGE_Master_Static_Object {
public:
    char gap_00[4];
    char master_type;                      // +0x04
    char gap_05[0x0E];
    short id;                              // +0x06
    char gap_08[0x0C];
    short object_group;                    // +0x14
    char gap_16[0x08];
    short hp;                              // +0x1E (asm: +0x26 for object_group_2)
    short object_group_2;                  // +0x26
    char gap_28[0x61];
    char unit_level;                       // +0x89
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;  // +0x08
    RGE_Player* owner;                     // +0x0C
    char gap_10[0x20];
    float hp;                              // +0x30
    char gap_34[0x14];
    char object_state;                     // +0x48
};

class RGE_Player {
public:
    char gap_00[0x26];
    short id;                              // +0x26
    char gap_28[0x0C];
    virtual int is_in_same_group(short);   // vtbl slot at +0x1C
};

extern double global_float_57733c;

class TRIBE_Task_List : public RGE_Task_List {
public:
    RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
};

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    short sVar2, sVar5 = -1, sVar7 = -1;
    int iVar8;
    RGE_Task* pRVar4;
    RGE_Master_Static_Object* pRVar3;

    sVar2 = param_1->field_4C;
    if (sVar2 != -1 && param_1->field_44 > global_float_57733c && param_2 != 0 && param_2->object_state == 2) {
        short sVar1 = param_1->master_obj->object_group;
        if (sVar1 == 4 || sVar1 == 0x15) {
            if (sVar1 == 4) {
                if (sVar2 == 1 || sVar2 == 2 || sVar2 == 3 || sVar2 == 0xF || sVar2 == 0x11) {
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
            short id = param_2->owner->id;
            if ((id == sVar5 || id == sVar7) && param_2->master_obj->id == param_1->field_4A) {
                if (this->task_count > 0) {
                    int* p = (int*)this->tasks;
                    for (int i = 0; i < this->task_count; i++) {
                        pRVar4 = (RGE_Task*)*p;
                        if (pRVar4->attribute_type == sVar2) {
                            if (pRVar4->action_type == 5 || pRVar4->action_type == 0x6E || pRVar4->action_type == 0x6F) {
                                return pRVar4;
                            }
                        }
                        p++;
                    }
                }
            }
        }
    }

    if (param_2 != 0) {
        if (param_1 != 0 && param_2->owner == param_1->owner && param_2->master_obj->master_type == 'P' && param_2->object_state == 0) {
            if (this->task_count < 1) return 0;
            int* p = (int*)this->tasks;
            for (int i = 0; i < this->task_count; i++) {
                pRVar4 = (RGE_Task*)*p;
                if (pRVar4->action_type == 0x65) return pRVar4;
                p++;
            }
            return 0;
        }
        if (param_2->owner == param_1->owner || ((iVar8 = param_1->owner->is_in_same_group(param_2->owner->id)) != 0 && (iVar8 = param_2->owner->is_in_same_group(param_1->field_4A)) != 0)) {
            if (param_2->object_state < 3 && param_2->master_obj->unit_level == 7) {
                if (this->task_count < 1) return 0;
                int* p = (int*)this->tasks;
                for (int i = 0; i < this->task_count; i++) {
                    pRVar4 = (RGE_Task*)*p;
                    if (pRVar4->action_type == 3) return pRVar4;
                    p++;
                }
                return 0;
            }
        }
        if (param_1 != 0) {
            if (param_2->owner == param_1->owner || (iVar8 = param_1->owner->is_in_same_group(param_2->owner->id)) != 0) {
                if (param_2->master_obj->master_type == 'P' && param_2->hp < (float)param_2->master_obj->hp && param_2->object_state < 3 && param_2->master_obj->id != 0x32) {
                    if (this->task_count < 1) return 0;
                    int* p = (int*)this->tasks;
                    for (int i = 0; i < this->task_count; i++) {
                        pRVar4 = (RGE_Task*)*p;
                        if (pRVar4->action_type == 0x6A) {
                            if (pRVar4->object_group == -1 || pRVar4->object_group == 0) return pRVar4;
                        }
                        p++;
                    }
                    return 0;
                }
            }
        }
        if (param_2->owner == param_1->owner || ((iVar8 = param_1->owner->is_in_same_group(param_2->owner->id)) != 0 && (iVar8 = param_2->owner->is_in_same_group(param_1->field_4A)) != 0)) {
            sVar2 = param_2->master_obj->object_group_2;
            if ((sVar2 == 2 || sVar2 == 0x14 || sVar2 == 0x15 || sVar2 == 0x16) && param_2->hp < (float)param_2->master_obj->hp && param_2->object_state < 3) {
                if (this->task_count < 1) return 0;
                int* p = (int*)this->tasks;
                for (int i = 0; i < this->task_count; i++) {
                    pRVar4 = (RGE_Task*)*p;
                    if (pRVar4->action_type == 0x6A && pRVar4->object_group == sVar2) return pRVar4;
                    p++;
                }
                return 0;
            }
        }
    }

    if (param_1 != 0 && param_1->master_obj->object_group == 0x12) {
        if (param_2 != 0) {
            if (param_2->owner == param_1->owner || (short)param_2->owner->id < 1 || (iVar8 = param_1->owner->is_in_same_group(param_2->owner->id)) != 0) {
                if (param_2->object_state < 3 && param_2->hp < (float)param_2->master_obj->hp) {
                    sVar2 = param_2->master_obj->object_group;
                    if (sVar2 != 0x15 && sVar2 != 2 && sVar2 != 0x14 && sVar2 != 0x16 && sVar2 != 1 && sVar2 != 0x1B && sVar2 != 3) {
                        if (this->task_count > 0) {
                            int* p = (int*)this->tasks;
                            for (int i = 0; i < this->task_count; i++) {
                                pRVar4 = (RGE_Task*)*p;
                                if (pRVar4->action_type == 0x69) return pRVar4;
                                p++;
                            }
                        }
                        return 0;
                    }
                }
            } else {
                if (this->task_count > 0) {
                    int* p = (int*)this->tasks;
                    for (int i = 0; i < this->task_count; i++) {
                        pRVar4 = (RGE_Task*)*p;
                        if (pRVar4->action_type == 0x68) return pRVar4;
                        p++;
                    }
                    return 0;
                }
            }
        }
        return 0;
    }

    return RGE_Task_List::get_target_task(param_1, param_2, param_3, param_4, param_5);
}
