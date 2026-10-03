#include "../include/aimdmod.h"

#include "../include/m_s_obj.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/stat_obj.h"
#include "../include/unit_ai_module.h"
#include "../include/world.h"

MainDecisionAIModule::MainDecisionAIModule(void* pW, int playerID, RGE_Player* plyr)
    : AIModule("Main Decision AI", 1000, playerID, pW),
      player(plyr),
      objects() {
}

MainDecisionAIModule::MainDecisionAIModule(int playerID, RGE_Player* plyr, int infile)
    : AIModule("Main Decision AI", 1000, playerID, 0),
      player(plyr),
      objects() {
    int numberUnits;

    rge_read(infile, &numberUnits, sizeof(numberUnits));
    for (int i = 0; i < numberUnits; ++i) {
        int tempInt;
        rge_read(infile, &tempInt, sizeof(tempInt));
        this->objects.add(tempInt);
    }
}

MainDecisionAIModule::~MainDecisionAIModule() {
}

void MainDecisionAIModule::setLogHistory(int v) {
}

int MainDecisionAIModule::save(int outfile) {
    {
        int tempInt = this->objects.number();
        rge_write(outfile, &tempInt, sizeof(tempInt));
    }

    for (int i = 0; i < this->objects.number(); ++i) {
        int tempInt = this->objects[i];
        rge_write(outfile, &tempInt, sizeof(tempInt));
    }
    return 1;
}

int MainDecisionAIModule::addObject(RGE_Static_Object* obj) {
    if (obj == 0) {
        return 0;
    }

    this->objects.add(obj->id);
    return 1;
}

int MainDecisionAIModule::removeObject(int id) {
    return this->objects.remove(id);
}

int MainDecisionAIModule::numberObjects() {
    return this->objects.number();
}

int MainDecisionAIModule::numberObjectsWithAction(int aid) {
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 && object->unitAI()->currentAction() == aid) {
            ++count;
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithGroup(int gid) {
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->master_obj->object_group == gid) {
            ++count;
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithActionAndTarget(int action, int target) {
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0) {
            if (object->unitAI() != 0) {
                UnitAIModule* unit_ai = object->unitAI();
                if (unit_ai->currentAction() == action) {
                    unit_ai = object->unitAI();
                    if (unit_ai->currentTarget() == target) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithTargetType(int tt) {
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0 && object->unitAI()->currentTargetType() == tt) {
            ++count;
        }
    }

    return count;
}

int MainDecisionAIModule::numberObjectsWithActionAndTargetType(int action, int tt) {
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0) {
            if (object->unitAI() != 0) {
                UnitAIModule* unit_ai = object->unitAI();
                if (unit_ai->currentAction() == action) {
                    unit_ai = object->unitAI();
                    if (unit_ai->currentTargetType() == tt) {
                        ++count;
                    }
                }
            }
        }
    }

    return count;
}

RGE_Static_Object* MainDecisionAIModule::object(int id) {
    return this->player->world->object(id);
}

RGE_Static_Object* MainDecisionAIModule::object(
    int gameID, int typeID, int groupID, int currentAction,
    int canPerformActionID, int targetID, int targetType,
    int secondaryTargetType, int objectState, int maxAttributeAmount) {
    int i = 0;
    for (; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0 && object->unitAI() != 0) {

            if (gameID != -1 && object->id != gameID) {
                goto next_object;
            }
            if (typeID != -1 && object->master_obj->id != typeID) {
                goto next_object;
            }
            if (groupID != -1 && object->master_obj->object_group != groupID) {
                goto next_object;
            }
            if (currentAction != -1 && object->unitAI()->currentAction() != currentAction) {
                goto next_object;
            }
            if (canPerformActionID != -1 && !this->canPerformAction(this->objects[i], canPerformActionID)) {
                goto next_object;
            }
            if (targetID != -1 && object->unitAI()->currentTarget() != targetID) {
                goto next_object;
            }
            if (targetType != -1 && object->unitAI()->currentTargetType() != targetType) {
                goto next_object;
            }
            if ((objectState == RGE_OBJECT_STATE_ANY || (int)object->object_state == objectState) && (maxAttributeAmount == -1 ||
                 object->attribute_amount_held <= (float)maxAttributeAmount)) {
                return object;
            }
        }

    next_object:
        ;
    }

    return 0;
}

RGE_Static_Object* MainDecisionAIModule::object(int gameID, int typeID, int groupID,
                                                int action1, int action2,
                                                int objectState) {
    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object == 0) {
            continue;
        }

        UnitAIModule* ai = object->unitAI();
        if (ai == 0) {
            continue;
        }
        if (gameID != -1 && object->id != gameID) {
            continue;
        }
        if (typeID != -1 && object->master_obj->id != typeID) {
            continue;
        }
        if (groupID != -1 && object->master_obj->object_group != groupID) {
            continue;
        }
        ai = object->unitAI();
        if (ai->currentAction() == action1) {
            continue;
        }
        ai = object->unitAI();
        if (ai->currentAction() == action2) {
            continue;
        }
        if (objectState != RGE_OBJECT_STATE_ANY && (int)object->object_state != objectState) {
            continue;
        }
        return object;
    }

    return 0;
}

int MainDecisionAIModule::objectGroupThatCanPerformAction(int a) {
    this->logCommonHistory("ERROR!  %d is an unrecognized action id.", a);
    return -1;
}

int MainDecisionAIModule::canPerformAction(int id, int t) {
    return 0;
}

int MainDecisionAIModule::numberBusyObjects() {
    int count = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object != 0) {
            UnitAIModule* unit_ai = object->unitAI();
            if (unit_ai != 0) {
                unit_ai = object->unitAI();
                if (unit_ai->currentAction() == -1) {
                    ++count;
                }
            }
        }
    }

    return count;
}

RGE_Static_Object* MainDecisionAIModule::mostDamaged(int oGroup, int oType) {
    RGE_Static_Object* mDB = 0;
    int damagePercentage = 0;

    for (int i = 0; i < this->objects.number(); ++i) {
        RGE_Static_Object* object =
            this->player->world->object(this->objects[i]);
        if (object == 0 || object->unitAI() == 0 || object->object_state == RGE_OBJECT_STATE_UNBUILT) {
            continue;
        }
        if ((int)object->master_obj->object_group != oGroup) {
            continue;
        }

        int maxhp = object->master_obj->hp;
        if ((float)maxhp <= object->hp || object->canRepair() != 1) {
            continue;
        }
        if (oType != -1 && oType != (int)object->master_obj->id) {
            continue;
        }

        int hp = object->master_obj->hp;
        int damage = (long)((float)hp - object->hp) * 100 / hp;
        if (damage > damagePercentage) {
            mDB = object;
            damagePercentage = damage;
        }
    }

    return mDB;
}
