//
// Owners:
//
// one direct RGE_Task_List::get_target_task call.

#include "../include/ttsk_lst.h"
#include "../include/task_lst.h"
#include "../include/act_obj.h"
#include "../include/stat_obj.h"
#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/game_globals.h"

RGE_Task* TRIBE_Task_List::get_target_task(RGE_Action_Object* obj, RGE_Static_Object* target_obj,
                                           float target_x, float target_y, float target_z) {
    short attribute_type = obj->attribute_type_held;

    if (attribute_type != -1 && obj->attribute_amount_held > 0.0f &&
        target_obj != 0 && target_obj->object_state == 2 &&
        (obj->master_obj->object_group == 4 ||
         obj->master_obj->object_group == 0x15)) {
        short target_id = -1;
        short alternate_target_id = -1;
        short source_group = obj->master_obj->object_group;

        if (source_group == 4) {
            switch (attribute_type) {
            case 1:
            case 2:
            case 3:
            case 0x0F:
            case 0x11:
                target_id = 0x6D;
                alternate_target_id = 0x67;
                break;

            case 0x10:
                target_id = 0x6D;
                alternate_target_id = 0x44;
                break;
            }
        } else if (source_group == 0x15 &&
                   (attribute_type == 9 || attribute_type == 0x11)) {
            target_id = 0x2D;
        }

        if ((target_obj->master_obj->id == target_id ||
             target_obj->master_obj->id == alternate_target_id) &&
            target_obj->owner->id == obj->owner->id) {
            for (int index = 0; index < list_num; index++) {
                RGE_Task* task = list[index];
                if (task->attribute_type == attribute_type &&
                    (task->action_type == 5 || task->action_type == 0x6E ||
                     task->action_type == 0x6F))
                    return task;
            }
        }
    }

    if (target_obj != 0) {
        if (obj != 0 && target_obj->owner == obj->owner &&
            target_obj->master_obj->master_type == 0x50 &&
            target_obj->object_state == 0) {
            for (int index = 0; index < list_num; index++) {
                RGE_Task* task = list[index];
                if (task->action_type == 0x65)
                    return task;
            }
            return 0;
        }

        if ((target_obj->owner == obj->owner ||
             (obj->owner->isAlly(target_obj->owner->id) &&
              target_obj->owner->isAlly(obj->owner->id))) &&
            target_obj->object_state < 3 &&
            target_obj->master_obj->unit_level == 7) {
            for (int index = 0; index < list_num; index++) {
                RGE_Task* task = list[index];
                if (task->action_type == 3)
                    return task;
            }
            return 0;
        }

        if (obj != 0 &&
            (target_obj->owner == obj->owner ||
             obj->owner->isAlly(target_obj->owner->id))) {
            RGE_Master_Static_Object* master_obj = target_obj->master_obj;
            if (master_obj->master_type == 0x50 &&
                target_obj->hp < (float)master_obj->hp &&
                target_obj->object_state < 3 && master_obj->id != 0x32) {
                for (int index = 0; index < list_num; index++) {
                    RGE_Task* task = list[index];
                    if (task->action_type == 0x6A &&
                        (task->object_group == -1 ||
                         task->object_group == 0))
                        return task;
                }
                return 0;
            }
        }

        if (obj != 0 &&
            (target_obj->owner == obj->owner ||
             (obj->owner->isAlly(target_obj->owner->id) &&
              target_obj->owner->isAlly(obj->owner->id)))) {
            short target_group = target_obj->master_obj->object_group;
            if ((target_group == 2 || target_group == 0x14 ||
                 target_group == 0x15 || target_group == 0x16) &&
                target_obj->hp < (float)target_obj->master_obj->hp &&
                target_obj->object_state < 3) {
                for (int index = 0; index < list_num; index++) {
                    RGE_Task* task = list[index];
                    if (task->action_type == 0x6A &&
                        task->object_group == target_group)
                        return task;
                }
                return 0;
            }
        }
    }

    if (obj != 0 && obj->master_obj->object_group == 0x12) {
        if (target_obj != 0) {
            if (target_obj->owner != obj->owner &&
                target_obj->object_state < 3 && target_obj->owner->id > 0 &&
                !obj->owner->isAlly(target_obj->owner->id) &&
                target_obj->master_obj->object_group != 1) {
                for (int index = 0; index < list_num; index++) {
                    RGE_Task* task = list[index];
                    if (task->action_type == 0x68)
                        return task;
                }
                return 0;
            }

            if (target_obj->owner == obj->owner ||
                obj->owner->isAlly(target_obj->owner->id)) {
                RGE_Master_Static_Object* master_obj = target_obj->master_obj;
                if (target_obj->hp < (float)master_obj->hp &&
                    target_obj->object_state < 3) {
                    short target_group = master_obj->object_group;
                    if (target_group != 0x15 && target_group != 2 &&
                        target_group != 0x14 && target_group != 0x16 &&
                        target_group != 1 && target_group != 0x1B &&
                        target_group != 3) {
                        for (int index = 0; index < list_num; index++) {
                            RGE_Task* task = list[index];
                            if (task->action_type == 0x69)
                                return task;
                        }
                        return 0;
                    }
                }
            }
        }
        return 0;
    }

    return RGE_Task_List::get_target_task(obj, target_obj, target_x,
                                          target_y, target_z);
}

int TRIBE_Task_List::is_attack_task(RGE_Task* task) {
    if (task->action_type == 0x68) {
        return 1;
    }
    return RGE_Task_List::is_attack_task(task);
}
