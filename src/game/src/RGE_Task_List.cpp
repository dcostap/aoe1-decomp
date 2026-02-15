#include "../include/RGE_Task_List.h"

#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <stdio.h>
#include <stdlib.h>

RGE_Task_List::RGE_Task_List() {
    this->list = nullptr;
    this->list_num = 0;
}

RGE_Task_List::~RGE_Task_List() {
    this->delete_list();
}

void RGE_Task_List::copy(RGE_Task_List* param_1) {
    if (this->list != nullptr) {
        this->delete_list();
    }

    if (param_1 == nullptr || param_1->list_num <= 0) {
        this->list_num = 0;
        this->list = nullptr;
        return;
    }

    this->list_num = param_1->list_num;
    this->list = (RGE_Task**)calloc((int)this->list_num, sizeof(RGE_Task*));
    if (this->list == nullptr) {
        this->list_num = 0;
        return;
    }

    for (short i = 0; i < this->list_num; ++i) {
        const short task_type = (param_1->list != nullptr && param_1->list[i] != nullptr) ? param_1->list[i]->task_type : (short)1;
        RGE_Task* task = this->create_task(task_type, i);
        if (task == nullptr) {
            task = new RGE_Task(i);
        }
        this->list[i] = task;

        if (task != nullptr && param_1->list != nullptr && param_1->list[i] != nullptr) {
            task->copy(param_1->list[i]);
        }
    }
}

void RGE_Task_List::load(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    if (this->list != nullptr) {
        this->delete_list();
    }

    rge_read(param_1, &this->list_num, 2);
    if (this->list_num <= 0) {
        this->list = nullptr;
        return;
    }

    this->list = (RGE_Task**)calloc((int)this->list_num, sizeof(RGE_Task*));
    if (this->list == nullptr) {
        this->list_num = 0;
        return;
    }

    for (short i = 0; i < this->list_num; ++i) {
        short task_type = 0;
        rge_read(param_1, &task_type, 2);

        RGE_Task* task = this->create_task(task_type, i);
        if (task == nullptr) {
            task = new RGE_Task(i);
        }
        this->list[i] = task;

        if (this->list[i] != nullptr) {
            this->list[i]->load(param_1, param_2, param_3);
        }
    }
}

void RGE_Task_List::load(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3) {
    if (this->list != nullptr) {
        this->delete_list();
    }

    fscanf(param_1, " %hd", &this->list_num);
    if (this->list_num <= 0) {
        this->list = nullptr;
        return;
    }

    this->list = (RGE_Task**)calloc((int)this->list_num, sizeof(RGE_Task*));
    if (this->list == nullptr) {
        this->list_num = 0;
        return;
    }

    for (short i = 0; i < this->list_num; ++i) {
        short task_type = 0;
        fscanf(param_1, " %hd", &task_type);

        RGE_Task* task = this->create_task(task_type, i);
        if (task == nullptr) {
            task = new RGE_Task(i);
        }
        this->list[i] = task;

        if (this->list[i] != nullptr) {
            this->list[i]->load(param_1, param_2, param_3);
        }
    }
}

void RGE_Task_List::save(int param_1) {
    rge_write(param_1, &this->list_num, 2);

    for (short i = 0; i < this->list_num; ++i) {
        if (this->list != nullptr && this->list[i] != nullptr) {
            this->list[i]->save(param_1);
        }
    }
}

void RGE_Task_List::delete_list() {
    if (this->list != nullptr) {
        for (short i = 0; i < this->list_num; ++i) {
            if (this->list[i] != nullptr) {
                delete this->list[i];
                this->list[i] = nullptr;
            }
        }

        free(this->list);
        this->list = nullptr;
    }

    this->list_num = 0;
}

RGE_Task* RGE_Task_List::create_task(short param_1, short param_2) {
    if (param_1 == 1) {
        return new RGE_Task(param_2);
    }
    return nullptr;
}

RGE_Task* RGE_Task_List::get_target_task(RGE_Action_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    (void)param_5;

    if (this->list_num <= 0 || this->list == nullptr) {
        return nullptr;
    }

    if (param_2 != nullptr) {
        if (param_2->object_state == 0) {
            for (short i = 0; i < this->list_num; ++i) {
                RGE_Task* task = this->list[i];
                if (task != nullptr && task->state_building == 1 && this->check_task(task, param_1, param_2) != 0) {
                    return task;
                }
            }
        }

        for (short i = 0; i < this->list_num; ++i) {
            RGE_Task* task = this->list[i];
            if (task != nullptr && param_2->master_obj != nullptr && task->object_id == param_2->master_obj->id && this->check_task(task, param_1, param_2) != 0) {
                return task;
            }
        }

        for (short i = 0; i < this->list_num; ++i) {
            RGE_Task* task = this->list[i];
            if (task != nullptr && param_2->master_obj != nullptr && task->object_group == param_2->master_obj->object_group && this->check_task(task, param_1, param_2) != 0) {
                return task;
            }
        }

        if (param_2->object_state < 3 && param_2->master_obj != nullptr && param_2->master_obj->combat_level != 0) {
            for (short i = 0; i < this->list_num; ++i) {
                RGE_Task* task = this->list[i];
                if (task != nullptr && task->combat_level != 0 && this->check_task(task, param_1, param_2) != 0) {
                    return task;
                }
            }
        }
    }

    if (param_3 != -1.0f && param_4 != -1.0f &&
        param_1 != nullptr && param_1->owner != nullptr && param_1->owner->world != nullptr && param_1->owner->world->map != nullptr) {
        const short tx = (short)param_3;
        const short ty = (short)param_4;
        RGE_Map* map = param_1->owner->world->map;

        if (tx >= 0 && ty >= 0 && tx < map->map_width && ty < map->map_height) {
            const uchar terrain = map->get_tile_type(tx, ty);
            for (short i = 0; i < this->list_num; ++i) {
                RGE_Task* task = this->list[i];
                if (task != nullptr && task->terrain_id == (short)(unsigned short)terrain) {
                    return task;
                }
            }
        }
    }

    return nullptr;
}

int RGE_Task_List::is_attack_task(RGE_Task* param_1) {
    return (param_1 != nullptr && param_1->action_type == 7) ? 1 : 0;
}

int RGE_Task_List::check_task(RGE_Task* param_1, RGE_Action_Object* param_2, RGE_Static_Object* param_3) {
    if (param_1 == nullptr || param_2 == nullptr || param_3 == nullptr || param_2->owner == nullptr || param_3->owner == nullptr) {
        return 0;
    }

    if (param_1->holding_attr == 1) {
        if (param_3->attribute_type_held == -1) {
            return 0;
        }
        if (param_3->attribute_amount_held <= 0.0f) {
            return 0;
        }
    }

    switch (param_1->owner_type) {
    case 1:
        if (param_3->owner != param_2->owner) {
            return 0;
        }
        break;

    case 2:
        if (param_3->owner == param_2->owner) {
            return 0;
        }
        if (param_3->owner->id == 0) {
            return 0;
        }
        if (param_2->owner->relation((long)param_3->owner->id) == 0) {
            return 0;
        }
        break;

    case 3:
        if (param_3->owner->id != 0) {
            return 0;
        }
        break;

    case 4:
        if (param_3->owner == param_2->owner) {
            return 1;
        }
        if (param_3->owner->id != 0 &&
            param_2->owner->isAlly((int)param_3->owner->id) != 0 &&
            param_3->owner->isAlly((int)param_2->owner->id) != 0) {
            return 1;
        }
        return 0;

    case 5:
        if (param_3->owner == param_2->owner) {
            return 0;
        }
        if (param_3->owner->id != 0 && param_2->owner->relation((long)param_3->owner->id) == 0) {
            return 0;
        }
        if (param_3->owner->id == 0 && param_2->command_flag == 0) {
            return 0;
        }
        break;

    default:
        break;
    }

    return (param_2 != (RGE_Action_Object*)param_3) ? 1 : 0;
}
