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
    int count;

    rge_read(file, &count, sizeof(count));
    for (int i = 0; i < count; ++i) {
        rge_read(file, &player_value, sizeof(player_value));
        this->objects.add((int)player_value);
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
    int count = this->objects.number();
    rge_write(file, &count, sizeof(count));

    for (int i = 0; i < this->objects.number(); ++i) {
        count = this->objects[i];
        rge_write(file, &count, sizeof(count));
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

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 &&
            object->unitAI()->currentAction() == action) {
            ++count;
        }
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

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 &&
            object->unitAI()->currentAction() == action &&
            object->unitAI()->currentTarget() == target) {
            ++count;
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithTargetType(int target_type)
{
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 &&
            object->unitAI()->currentTargetType() == target_type) {
            ++count;
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithActionAndTargetType(
    int action, int target_type)
{
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 &&
            object->unitAI()->currentAction() == action &&
            object->unitAI()->currentTargetType() == target_type) {
            ++count;
        }
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
    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object == 0) {
            continue;
        }

        if (object->unitAI() == 0) {
            continue;
        }

        if (object_id != -1 && object->id != object_id) {
            continue;
        }
        if (type != -1 && object->master_obj->id != type) {
            continue;
        }
        if (class_id != -1 && object->master_obj->object_group != class_id) {
            continue;
        }
        if (action != -1 && object->unitAI()->currentAction() != action) {
            continue;
        }
        if (can_perform_action != -1 &&
            !this->canPerformAction(this->objects[i], can_perform_action)) {
            continue;
        }
        if (current_target != -1 &&
            object->unitAI()->currentTarget() != current_target) {
            continue;
        }
        if (current_target_type != -1 &&
            object->unitAI()->currentTargetType() != current_target_type) {
            continue;
        }
        if ((state == -1 || (int)object->object_state == state) &&
            (attribute_amount == -1 ||
             object->attribute_amount_held <= (float)attribute_amount)) {
            return object;
        }
    }

    return 0;
}

RGE_Static_Object* MainDecisionAIModule::object(int p1, int p2, int p3,
                                                int p4, int p5, int p6)
{
    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object == 0) {
            continue;
        }

        if (object->unitAI() == 0) {
            continue;
        }
        if (p1 != -1 && object->id != p1) {
            continue;
        }
        if (p2 != -1 && object->master_obj->id != p2) {
            continue;
        }
        if (p3 != -1 && object->master_obj->object_group != p3) {
            continue;
        }
        if (object->unitAI()->currentAction() == p4) {
            continue;
        }
        if (object->unitAI()->currentAction() == p5) {
            continue;
        }
        if (p6 != -1 && (int)object->object_state != p6) {
            continue;
        }
        return object;
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

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 &&
            object->unitAI()->currentAction() == -1) {
            ++count;
        }
    }

    return count;
}

RGE_Static_Object* MainDecisionAIModule::mostDamaged(int class_id, int type_id)
{
    RGE_Static_Object* result = 0;
    int damage_percentage = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object == 0 || object->unitAI() == 0 || !object->object_state) {
            continue;
        }
        if ((int)object->master_obj->object_group != class_id) {
            continue;
        }

        if ((float)object->master_obj->hp <= object->hp ||
            object->canRepair() != 1) {
            continue;
        }
        if (type_id != -1 && type_id != (int)object->master_obj->id) {
            continue;
        }

        int damage =
            (long)((float)object->master_obj->hp - object->hp) * 100 /
            object->master_obj->hp;
        if (damage > damage_percentage) {
            result = object;
            damage_percentage = damage;
        }
    }

    return result;
}
