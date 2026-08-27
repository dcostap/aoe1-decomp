// PDB source module: C:\\msdev\\work\\age1_x1\\ttsk_lst.cpp.
// Definitions follow the original source-line and address order.
//
// Owners:
//   0052C3F0 TRIBE_Task_List::get_target_task (lines 41-294)
//   0052C8D0 TRIBE_Task_List::is_attack_task (lines 299-304)
//
// BINARY NOTE: 0052C8A1 is a switch-table and padding boundary. It is not a
// source owner. The first owner has seven ordered RGE_Player::isAlly calls and
// one direct RGE_Task_List::get_target_task call.

#include "../include/ttsk_lst.h"
#include "../include/task_lst.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/game_globals.h"

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1,
                                            RGE_Static_Object* param_2,
                                            float param_3, float param_4,
                                            float param_5) {
    short sVar2, sVar7, sVar5;
    int iVar8;

    sVar2 = param_1->attribute_type_held;
    if (sVar2 != -1 && param_1->attribute_amount_held > DAT_0057733c &&
        param_2 != 0 && param_2->object_state == 2) {
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
        if (param_1 != 0 && param_2->owner == param_1->owner &&
            param_2->master_obj->master_type == 'P' &&
            param_2->object_state == 0) {
            int count = this->list_num;
            if (count > 0) {
                for (iVar8 = 0; iVar8 < count; iVar8++) {
                    RGE_Task* task = this->list[iVar8];
                    if (task->action_type == 0x65)
                        return task;
                }
            }
            return 0;
        }
        if (param_2->owner == param_1->owner ||
            ((iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0 &&
             (iVar8 = param_2->owner->isAlly(param_1->owner->id)) != 0)) {
            if (param_2->object_state < 3 &&
                param_2->master_obj->unit_level == 7) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 3)
                            return task;
                    }
                }
                return 0;
            }
        }
        if (param_1 != 0) {
            if (param_2->owner == param_1->owner ||
                (iVar8 = param_1->owner->isAlly(param_2->owner->id)) != 0) {
                if (param_2->master_obj->master_type == 'P' &&
                    param_2->hp < (float)param_2->master_obj->hp &&
                    param_2->object_state < 3 &&
                    param_2->master_obj->id != 0x32) {
                    int count = this->list_num;
                    if (count > 0) {
                        for (iVar8 = 0; iVar8 < count; iVar8++) {
                            RGE_Task* task = this->list[iVar8];
                            if (task->action_type == 0x6A &&
                                (task->object_group == -1 ||
                                 task->object_group == 0)) {
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
            if ((sVar2 == 2 || sVar2 == 0x14 || sVar2 == 0x15 ||
                 sVar2 == 0x16) &&
                param_2->hp < (float)param_2->master_obj->hp &&
                param_2->object_state < 3) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 0x6A &&
                            task->object_group == sVar2)
                            return task;
                    }
                }
                return 0;
            }
        }
    }

    if (param_1 != 0 && param_1->master_obj->object_group == 0x12) {
        if (param_2 != 0) {
            if (param_2->owner != param_1->owner &&
                param_2->object_state < 3 && param_2->owner->id >= 1 &&
                param_1->owner->isAlly(param_2->owner->id) == 0 &&
                param_2->master_obj->object_group != 1) {
                int count = this->list_num;
                if (count > 0) {
                    for (iVar8 = 0; iVar8 < count; iVar8++) {
                        RGE_Task* task = this->list[iVar8];
                        if (task->action_type == 0x68)
                            return task;
                    }
                }
            }
            if (param_2->owner == param_1->owner ||
                param_1->owner->isAlly(param_2->owner->id) != 0) {
                if (param_2->object_state < 3 &&
                    param_2->hp < (float)param_2->master_obj->hp) {
                    sVar2 = param_2->master_obj->object_group;
                    if (sVar2 != 0x15 && sVar2 != 2 && sVar2 != 0x14 &&
                        sVar2 != 0x16 && sVar2 != 1 && sVar2 != 0x1B &&
                        sVar2 != 3) {
                        int count = this->list_num;
                        if (count > 0) {
                            for (iVar8 = 0; iVar8 < count; iVar8++) {
                                RGE_Task* task = this->list[iVar8];
                                if (task->action_type == 0x69)
                                    return task;
                            }
                        }
                    }
                }
            }
        }
        return 0;
    }

    return RGE_Task_List::get_target_task(param_1, param_2, param_3,
                                          param_4, param_5);
}

int TRIBE_Task_List::is_attack_task(RGE_Task* task) {
    if (task->action_type == 0x68) {
        return 1;
    }
    return RGE_Task_List::is_attack_task(task);
}
