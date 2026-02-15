#include "../include/TRIBE_Task_List.h"

#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"

RGE_Task* TRIBE_Task_List::create_task(short param_1, short param_2) {
    return this->RGE_Task_List::create_task(param_1, param_2);
}

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    // Source of truth: ttsk_lst.cpp.decomp @ 0x0052C3F0.

    if (this->list != nullptr && this->list_num > 0 && param_1 != nullptr) {
        const short carried_attr = param_1->attribute_type_held;

        if (carried_attr != -1 && param_1->attribute_amount_held > 0.0f &&
            param_2 != nullptr && param_2->object_state == 2 &&
            param_1->master_obj != nullptr) {
            const short actor_group = param_1->master_obj->object_group;
            if (actor_group == 4 || actor_group == 0x15) {
                short target_id_a = -1;
                short target_id_b = -1;

                if (actor_group == 4) {
                    switch (carried_attr) {
                    case 1:
                    case 2:
                    case 3:
                    case 0x0F:
                    case 0x11:
                        target_id_a = 0x6D;
                        target_id_b = 0x67;
                        break;
                    case 0x10:
                        target_id_a = 0x6D;
                        target_id_b = 0x44;
                        break;
                    default:
                        break;
                    }
                } else if (carried_attr == 9 || carried_attr == 0x11) {
                    target_id_a = 0x2D;
                }

                if (param_2->master_obj != nullptr && param_2->owner != nullptr && param_1->owner != nullptr) {
                    const short target_master_id = param_2->master_obj->id;
                    if ((target_master_id == target_id_a || target_master_id == target_id_b) &&
                        param_2->owner->id == param_1->owner->id) {
                        for (short i = 0; i < this->list_num; ++i) {
                            RGE_Task* task = this->list[i];
                            if (task != nullptr && task->attribute_type == carried_attr) {
                                if (task->action_type == 5 || task->action_type == 0x6E || task->action_type == 0x6F) {
                                    return task;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (param_2 != nullptr) {
            if (param_1->owner != nullptr && param_2->owner == param_1->owner &&
                param_2->master_obj != nullptr && param_2->master_obj->master_type == 'P' &&
                param_2->object_state == 0) {
                for (short i = 0; i < this->list_num; ++i) {
                    RGE_Task* task = this->list[i];
                    if (task != nullptr && task->action_type == 0x65) {
                        return task;
                    }
                }
                return nullptr;
            }

            if (param_1->owner != nullptr && param_2->owner != nullptr &&
                ((param_2->owner == param_1->owner) ||
                 (param_1->owner->isAlly((int)param_2->owner->id) != 0 &&
                  param_2->owner->isAlly((int)param_1->owner->id) != 0)) &&
                param_2->object_state < 3 && param_2->master_obj != nullptr &&
                param_2->master_obj->unit_level == 7) {
                for (short i = 0; i < this->list_num; ++i) {
                    RGE_Task* task = this->list[i];
                    if (task != nullptr && task->action_type == 3) {
                        return task;
                    }
                }
                return nullptr;
            }

            if (param_1->owner != nullptr && param_2->owner != nullptr && param_2->master_obj != nullptr &&
                ((param_2->owner == param_1->owner) ||
                 (param_1->owner->isAlly((int)param_2->owner->id) != 0)) &&
                param_2->master_obj->master_type == 'P' &&
                param_2->hp < (float)(int)param_2->master_obj->hp &&
                param_2->object_state < 3 &&
                param_2->master_obj->id != 0x32) {
                for (short i = 0; i < this->list_num; ++i) {
                    RGE_Task* task = this->list[i];
                    if (task != nullptr && task->action_type == 0x6A) {
                        if (task->object_group == -1 || task->object_group == 0) {
                            return task;
                        }
                    }
                }
                return nullptr;
            }

            if (param_1->owner != nullptr && param_2->owner != nullptr && param_2->master_obj != nullptr &&
                ((param_2->owner == param_1->owner) ||
                 (param_1->owner->isAlly((int)param_2->owner->id) != 0 &&
                  param_2->owner->isAlly((int)param_1->owner->id) != 0))) {
                const short target_group = param_2->master_obj->object_group;
                if ((target_group == 2 || target_group == 0x14 || target_group == 0x15 || target_group == 0x16) &&
                    param_2->hp < (float)(int)param_2->master_obj->hp &&
                    param_2->object_state < 3) {
                    for (short i = 0; i < this->list_num; ++i) {
                        RGE_Task* task = this->list[i];
                        if (task != nullptr && task->action_type == 0x6A && task->object_group == target_group) {
                            return task;
                        }
                    }
                    return nullptr;
                }
            }
        }

        if (param_1->master_obj != nullptr && param_1->master_obj->object_group == 0x12) {
            if (param_2 != nullptr) {
                int allow_outer = 0;
                if (param_1->owner != nullptr && param_2->owner != nullptr) {
                    if (param_2->owner == param_1->owner || param_2->object_state > 2 || param_2->owner->id < 1) {
                        allow_outer = 1;
                    } else if (param_1->owner->isAlly((int)param_2->owner->id) != 0) {
                        allow_outer = 1;
                    } else if (param_2->master_obj != nullptr && param_2->master_obj->object_group == 1) {
                        allow_outer = 1;
                    }
                }

                if (allow_outer != 0 && param_1->owner != nullptr && param_2->owner != nullptr && param_2->master_obj != nullptr) {
                    const short target_group = param_2->master_obj->object_group;
                    if ((param_2->owner == param_1->owner || param_1->owner->isAlly((int)param_2->owner->id) != 0) &&
                        param_2->hp < (float)(int)param_2->master_obj->hp &&
                        param_2->object_state < 3 &&
                        target_group != 0x15 && target_group != 2 && target_group != 0x14 &&
                        target_group != 0x16 && target_group != 1 && target_group != 0x1B && target_group != 3) {
                        for (short i = 0; i < this->list_num; ++i) {
                            RGE_Task* task = this->list[i];
                            if (task != nullptr && task->action_type == 0x69) {
                                return task;
                            }
                        }
                    }
                }
            } else {
                for (short i = 0; i < this->list_num; ++i) {
                    RGE_Task* task = this->list[i];
                    if (task != nullptr && task->action_type == 0x68) {
                        return task;
                    }
                }
            }

            return nullptr;
        }
    }

    return this->RGE_Task_List::get_target_task(param_1, param_2, param_3, param_4, param_5);
}

int TRIBE_Task_List::is_attack_task(RGE_Task* param_1) {
    // RGE_Task.action_type offset is +0x6 (task.cpp.decomp / task_lst.cpp.asm).
    if (param_1 != nullptr) {
        const short action_type = *(const short*)((const unsigned char*)param_1 + 0x6);
        if (action_type == 0x68) {
            return 1;
        }
    }
    return this->RGE_Task_List::is_attack_task(param_1);
}

int TRIBE_Task_List::check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3) {
    return this->RGE_Task_List::check_task(param_1, param_2, param_3);
}
