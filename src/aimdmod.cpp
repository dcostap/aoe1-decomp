#include "../include/aimdmod.h"

#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"

MainDecisionAIModule::MainDecisionAIModule(void* owner, int player_number,
                                           RGE_Player* player_value)
    : AIModule("Main Decision AI", 1000, player_number, owner),
      player(player_value),
      objects()
{
}

MainDecisionAIModule::MainDecisionAIModule(int player_number,
                                           RGE_Player* player_value,
                                           int file)
    : AIModule("Main Decision AI", 1000, player_number, 0),
      player(player_value),
      objects()
{
    RGE_Player* saved_player;
    int count;

    rge_read(file, &count, 4);

    player_number = 0;
    if (count > 0) {
        do {
            rge_read(file, &player_value, 4);
            saved_player = player_value;

            int number = this->objects.numberValue;
            for (int j = 0; j < number; j++) {
                if (j >= this->objects.maximumSizeValue) break;
                if (this->objects.value[j] == (int)saved_player) goto next;
            }

            if (number > this->objects.maximumSizeValue - 1) {
                int new_size = number + 1;
                int* new_arr = (int*)operator_new(new_size * 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < new_size) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = new_size;
                }
            }
            this->objects.value[this->objects.numberValue] = (int)saved_player;
            this->objects.numberValue++;
        next:
            player_number++;
        } while (player_number < count);
    }
}

MainDecisionAIModule::~MainDecisionAIModule()
{
}

void MainDecisionAIModule::setLogHistory(int)
{
}

int MainDecisionAIModule::save(int file)
{
    int temp = this->objects.numberValue;
    rge_write(file, &temp, 4);

    int i = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int newCapacity = i + 1;
                int* newIds = (int*)operator_new(newCapacity * 4);
                if (newIds != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < newCapacity) {
                        newIds[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = newIds;
                    this->objects.maximumSizeValue = newCapacity;
                }
            }
            temp = this->objects.value[i];
            rge_write(file, &temp, 4);
            ++i;
        } while (i < this->objects.numberValue);
    }
    return 1;
}

int MainDecisionAIModule::addObject(RGE_Static_Object* object)
{
    if (object == 0) {
        return 0;
    }

    this->objects.add(object->id);
    return 1;
}

int MainDecisionAIModule::removeObject(int object_id)
{
    return this->objects.remove(object_id);
}

int MainDecisionAIModule::numberObjects()
{
    return this->objects.number();
}

int MainDecisionAIModule::numberObjectsWithAction(int action)
{
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* object = world->object(this->objects.value[i]);
            if (object != 0) {
                if (object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == action) {
                        ++count;
                    }
                }
            }

            ++i;
        } while (i < this->objects.numberValue);
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithGroup(int group_id)
{
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->master_obj->object_group == group_id) {
            ++count;
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithActionAndTarget(int action,
                                                            int target)
{
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* object = world->object(this->objects.value[i]);
            if (object != 0) {
                if (object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == action) {
                        if (object->unitAI()->currentTarget() == target) {
                            ++count;
                        }
                    }
                }
            }

            ++i;
        } while (i < this->objects.numberValue);
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithTargetType(int target_type)
{
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            {
                int id = this->objects.value[i];
                RGE_Game_World* world = this->player->world;
                RGE_Static_Object* object = world->object(id);
                if (object != 0) {
                    if (object->unitAI()) {
                        if (object->unitAI()->currentTargetType() == target_type) {
                            ++count;
                        }
                    }
                }
            }

            ++i;
        } while (i < this->objects.numberValue);
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithActionAndTargetType(
    int action, int target_type)
{
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* object = world->object(this->objects.value[i]);
            if (object != 0) {
                if (object->unitAI() != 0) {
                    if (object->unitAI()->currentAction() == action) {
                        if (object->unitAI()->currentTargetType() == target_type) {
                            ++count;
                        }
                    }
                }
            }

            ++i;
        } while (i < this->objects.numberValue);
    }

    return count;
}

RGE_Static_Object* MainDecisionAIModule::object(int object_id)
{
    return this->player->world->object(object_id);
}

RGE_Static_Object* MainDecisionAIModule::object(
    int object_id, int type, int class_id, int action, int can_perform_action,
    int current_target, int current_target_type, int, int state,
    int attribute_amount)
{
    int i = 0;
    for (; i < this->objects.numberValue; ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0) {
            if (object_id != -1 && object->id != object_id) {
                goto next_object;
            }
            if (type != -1 && object->master_obj->id != type) {
                goto next_object;
            }
            if (class_id != -1 && object->master_obj->object_group != class_id) {
                goto next_object;
            }
            if (action != -1 && object->unitAI()->currentAction() != action) {
                goto next_object;
            }
            if (can_perform_action != -1) {
                if (!this->canPerformAction(this->objects[i], can_perform_action)) {
                    goto next_object;
                }
            }
            if (current_target != -1 &&
                object->unitAI()->currentTarget() != current_target) {
                goto next_object;
            }
            if (current_target_type != -1 &&
                object->unitAI()->currentTargetType() != current_target_type) {
                goto next_object;
            }
            if ((state == -1 || (int)object->object_state == state) &&
                (attribute_amount == -1 ||
                 object->attribute_amount_held <= (float)attribute_amount)) {
                return object;
            }
        }

    next_object:
        ;
    }

    return 0;
}

RGE_Static_Object* MainDecisionAIModule::object(int p1, int p2, int p3,
                                                int p4, int p5, int p6)
{
    for (int i = 0; i < this->objects.numberValue; i++) {
        if (i > this->objects.maximumSizeValue - 1) {
            int newCount = i + 1;
            int* newArray = (int*)operator_new(i * 4 + 4);
            if (newArray) {
                int j = 0;
                if (this->objects.maximumSizeValue > 0) {
                    while (j < this->objects.maximumSizeValue && j < newCount) {
                        newArray[j] = this->objects.value[j];
                        j++;
                    }
                }
                operator_delete(this->objects.value);
                this->objects.value = newArray;
                this->objects.maximumSizeValue = newCount;
            }
        }

        RGE_Static_Object* object =
            this->player->world->object(this->objects.value[i]);
        if (!object) goto next;
        if (!object->unitAI()) goto next;
        if (p1 != -1 && object->id != p1) {
            goto next;
        }
        if (p2 != -1 && object->master_obj->id != p2) {
            goto next;
        }
        if (p3 != -1 && object->master_obj->object_group != p3) {
            goto next;
        }
        if (object->unitAI()->currentAction() == p4) {
            goto next;
        }
        if (object->unitAI()->currentAction() == p5) {
            goto next;
        }
        if (p6 != -1 && (int)object->object_state != p6) {
            goto next;
        }
        return object;

    next:
        ;
    }

    return 0;
}

int MainDecisionAIModule::objectGroupThatCanPerformAction(int action)
{
    this->logCommonHistory("ERROR!  %d is an unrecognized action id.", action);
    return -1;
}

int MainDecisionAIModule::canPerformAction(int, int)
{
    return 0;
}

int MainDecisionAIModule::numberBusyObjects()
{
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int newCapacity = i + 1;
                int* newIds = (int*)operator_new(newCapacity * 4);
                if (newIds != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < newCapacity) {
                        newIds[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = newIds;
                    this->objects.maximumSizeValue = newCapacity;
                }
            }
            RGE_Static_Object* object =
                this->player->world->object(this->objects.value[i]);
            if (object != 0 && object->unitAI() != 0) {
                UnitAIModule* unit_ai = object->unitAI();
                if (unit_ai->currentAction() == -1) {
                    ++count;
                }
            }

            ++i;
        } while (i < this->objects.numberValue);
    }

    return count;
}

RGE_Static_Object* MainDecisionAIModule::mostDamaged(int class_id, int type_id)
{
    RGE_Static_Object* result = 0;
    int damage_percentage = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int newCapacity = i + 1;
                int* newIds = (int*)operator_new(newCapacity * 4);
                if (newIds) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < newCapacity) {
                        newIds[j] = this->objects.value[j];
                        ++j;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = newIds;
                    this->objects.maximumSizeValue = newCapacity;
                }
            }
            RGE_Static_Object* object =
                this->player->world->object(this->objects.value[i]);
            if (object != 0 && object->unitAI() != 0 && object->object_state) {
                if ((int)object->master_obj->object_group == class_id) {
                    int maximum_hit_points = object->master_obj->hp;
                    if ((float)maximum_hit_points > object->hp &&
                        object->canRepair() == 1) {
                        if (type_id == -1 ||
                            type_id == (int)object->master_obj->id) {
                            int hit_points = object->master_obj->hp;
                            int damage =
                                ((long)((float)hit_points - object->hp) * 100) /
                                hit_points;
                            if (damage > damage_percentage) {
                                result = object;
                                damage_percentage = damage;
                            }
                        }
                    }
                }
            }
            ++i;
        } while (i < this->objects.numberValue);
    }

    return result;
}
