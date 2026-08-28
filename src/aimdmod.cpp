// Authentic PDB-ordered source module for C:\\msdev\\work\\age1_x1\\aimdmod.cpp.
// The 20 normal owners below follow the original source-line and address order.
// The nearby 0040CE70 vector-deleting destructor is compiler-generated.

#include "../include/aimdmod.h"

// 0040CDF0 MainDecisionAIModule::MainDecisionAIModule(void*, int, RGE_Player*)
// PDB: aimdmod.cpp lines 34-35. Status: verified_logic.
// BINARY NOTE: The shipped constructor uses an FS-first exception frame. The
// pinned VC5 build selects a different frame family. See the module note.
MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2,
                                           RGE_Player* param_3)
    : AIModule("Main Decision AI", 1000, param_2, param_1),
      player(param_3),
      objects()
{
}

// 0040CE90 MainDecisionAIModule::MainDecisionAIModule(int, RGE_Player*, int)
// PDB: aimdmod.cpp lines 43-52. Status: matching.
MainDecisionAIModule::MainDecisionAIModule(int param_1, RGE_Player* param_2,
                                           int param_3)
    : AIModule("Main Decision AI", 1000, param_1, 0),
      player(param_2),
      objects()
{
    RGE_Player* saved_p;
    int count;

    rge_read(param_3, &count, 4);

    param_1 = 0;
    if (count > 0) {
        do {
            rge_read(param_3, &param_2, 4);
            saved_p = param_2;

            int number = this->objects.numberValue;
            for (int j = 0; j < number; j++) {
                if (j >= this->objects.maximumSizeValue) break;
                if (this->objects.value[j] == (int)saved_p) goto next;
            }

            if (number > this->objects.maximumSizeValue - 1) {
                int new_size = number + 1;
                int* new_arr = (int*)operator new(new_size * 4);
                if (new_arr != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < new_size) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = new_size;
                }
            }
            this->objects.value[this->objects.numberValue] = (int)saved_p;
            this->objects.numberValue++;
next:
            param_1++;
        } while (param_1 < count);
    }
}

// 0040D020 MainDecisionAIModule::~MainDecisionAIModule()
// PDB: aimdmod.cpp lines 57-58. Status: matching.
MainDecisionAIModule::~MainDecisionAIModule() {}

// 0040D090 MainDecisionAIModule::setLogHistory(int)
// PDB: aimdmod.cpp line 63. Status: matching.
void MainDecisionAIModule::setLogHistory(int p0) {}

// 0040D0A0 MainDecisionAIModule::save(int)
// PDB: aimdmod.cpp lines 69-77. Status: matching.
int MainDecisionAIModule::save(int hFile) {
    int temp = this->objects.numberValue;
    rge_write(hFile, &temp, 4);

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
            rge_write(hFile, &temp, 4);
            ++i;
        } while (i < this->objects.numberValue);
    }
    return 1;
}

// 0040D180 MainDecisionAIModule::addObject(RGE_Static_Object*)
// PDB: aimdmod.cpp lines 82-87. Status: matching.
int MainDecisionAIModule::addObject(RGE_Static_Object* obj) {
    if (obj == NULL) return 0;

    int count = this->objects.numberValue;
    int id = obj->id;

    for (int i = 0; i < count; i++) {
        if (i >= this->objects.maximumSizeValue) break;
        if (this->objects.value[i] == id) goto done;
    }

    if (count > this->objects.maximumSizeValue - 1) {
        int newSize = count + 1;
        int* new_arr = (int*)operator_new(newSize * 4);
        if (new_arr != NULL) {
            int j = 0;
            while (j < this->objects.maximumSizeValue && j < newSize) {
                new_arr[j] = this->objects.value[j];
                j++;
            }
            operator_delete(this->objects.value);
            this->objects.value = new_arr;
            this->objects.maximumSizeValue = newSize;
        }
    }

    this->objects.value[this->objects.numberValue] = id;
    this->objects.numberValue++;

done:
    return 1;
}

// 0040D250 MainDecisionAIModule::removeObject(int)
// PDB: aimdmod.cpp lines 92-94. Status: matching.
int MainDecisionAIModule::removeObject(int objectId) {
    int i = 0;
    while (i < this->objects.maximumSizeValue) {
        if (this->objects.value[i] == objectId) {
            break;
        }
        i++;
    }
    if (i >= this->objects.maximumSizeValue) {
        return 0;
    }
    while (i < this->objects.maximumSizeValue - 1) {
        this->objects.value[i] = this->objects.value[i + 1];
        i++;
    }
    int count = this->objects.numberValue - 1;
    this->objects.numberValue = count;
    if (count < 0) {
        this->objects.numberValue = 0;
    }
    return 1;
}

// 0040D2C0 MainDecisionAIModule::numberObjects()
// PDB: aimdmod.cpp lines 99-101. Status: matching.
int MainDecisionAIModule::numberObjects() { return this->objects.numberValue; }

// 0040D2D0 MainDecisionAIModule::numberObjectsWithAction(int)
// PDB: aimdmod.cpp lines 106-116. Status: matching.
int MainDecisionAIModule::numberObjectsWithAction(int action) {
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != NULL) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* obj = world->object(this->objects.value[i]);
            if (obj != NULL) {
                UnitAIModule* ai = obj->unitAI();
                if (ai != NULL) {
                    if (obj->unitAI()->currentAction() == action) {
                        count++;
                    }
                }
            }

            i++;
        } while (i < this->objects.numberValue);
    }

    return count;
}

// 0040D3B0 MainDecisionAIModule::numberObjectsWithGroup(int)
// PDB: aimdmod.cpp lines 121-131. Status: matching.
int MainDecisionAIModule::numberObjectsWithGroup(int groupId) {
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != NULL) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* obj = world->object(this->objects.value[i]);

            if (obj != NULL) {
                if (obj->master_obj->object_group == groupId) {
                    count++;
                }
            }

            i++;
        } while (i < this->objects.numberValue);
    }

    return count;
}

// 0040D480 MainDecisionAIModule::numberObjectsWithActionAndTarget(int, int)
// PDB: aimdmod.cpp lines 137-148. Status: matching.
int MainDecisionAIModule::numberObjectsWithActionAndTarget(int action, int target) {
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != NULL) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* obj = world->object(this->objects.value[i]);
            if (obj != NULL) {
                if (obj->unitAI() != NULL) {
                    if (obj->unitAI()->currentAction() == action) {
                        if (obj->unitAI()->currentTarget() == target) {
                            count++;
                        }
                    }
                }
            }

            i++;
        } while (i < this->objects.numberValue);
    }

    return count;
}

// 0040D580 MainDecisionAIModule::numberObjectsWithTargetType(int)
// PDB: aimdmod.cpp lines 153-163. Status: matching.
int MainDecisionAIModule::numberObjectsWithTargetType(int targetType) {
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != NULL) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            {
                int id = this->objects.value[i];
                RGE_Game_World* world = this->player->world;
                RGE_Static_Object* obj = world->object(id);
                if (obj != NULL) {
                    if (obj->unitAI()) {
                        if (obj->unitAI()->currentTargetType() == targetType) {
                            count++;
                        }
                    }
                }
            }

            i++;
        } while (i < this->objects.numberValue);
    }

    return count;
}

// 0040D660 MainDecisionAIModule::numberObjectsWithActionAndTargetType(int, int)
// PDB: aimdmod.cpp lines 169-180. Status: matching.
int MainDecisionAIModule::numberObjectsWithActionAndTargetType(int action,
                                                               int target_type) {
    int count = 0;
    int i = 0;

    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int limit = i + 1;
                int* new_arr = (int*)operator_new(i * 4 + 4);
                if (new_arr != NULL) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < limit) {
                        new_arr[j] = this->objects.value[j];
                        j++;
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = new_arr;
                    this->objects.maximumSizeValue = limit;
                }
            }

            RGE_Game_World* world = this->player->world;
            RGE_Static_Object* obj = world->object(this->objects.value[i]);
            if (obj != NULL) {
                if (obj->unitAI() != NULL) {
                    if (obj->unitAI()->currentAction() == action) {
                        if (obj->unitAI()->currentTargetType() == target_type) {
                            count++;
                        }
                    }
                }
            }

            i++;
        } while (i < this->objects.numberValue);
    }

    return count;
}

// 0040D760 MainDecisionAIModule::object(int)
// PDB: aimdmod.cpp lines 185-187. Status: matching.
RGE_Static_Object* MainDecisionAIModule::object(int param) {
    return this->player->world->object(param);
}

// 0040D780 MainDecisionAIModule::object(int, int, int, int, int, int, int, int, int, int)
// PDB: aimdmod.cpp lines 194-213. Status: matching.
RGE_Static_Object* MainDecisionAIModule::object(int object_id, int type, int class_id,
                                                int action, int can_perform_action,
                                                int current_target, int current_target_type,
                                                int unused, int state, int attribute_amount)
{
    int i = 0;
    for (; i < this->objects.numberValue; ++i) {
        RGE_Static_Object* obj = this->player->world->object(this->objects[i]);
        if (obj != 0 && obj->unitAI() != 0) {
            if (object_id != -1 && obj->id != object_id) {
                goto next_object;
            }
            if (type != -1 && obj->master_obj->id != type) {
                goto next_object;
            }
            if (class_id != -1 && obj->master_obj->object_group != class_id) {
                goto next_object;
            }
            if (action != -1 && obj->unitAI()->currentAction() != action) {
                goto next_object;
            }
            if (can_perform_action != -1) {
                if (!this->canPerformAction(this->objects[i], can_perform_action)) {
                    goto next_object;
                }
            }
            if (current_target != -1 && obj->unitAI()->currentTarget() != current_target) {
                goto next_object;
            }
            if (current_target_type != -1 &&
                obj->unitAI()->currentTargetType() != current_target_type) {
                goto next_object;
            }
            if ((state == -1 || (int)obj->object_state == state) &&
                (attribute_amount == -1 ||
                 obj->attribute_amount_held <= (float)attribute_amount)) {
                return obj;
            }
        }

    next_object:
        ;
    }

    return 0;
}

// 0040D9D0 MainDecisionAIModule::object(int, int, int, int, int, int)
// PDB: aimdmod.cpp lines 219-235. Status: matching.
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

        RGE_Static_Object* obj = this->player->world->object(this->objects.value[i]);
        if (!obj) goto next;
        if (!obj->unitAI()) goto next;
        if (p1 != -1 && obj->id != p1) goto next;
        if (p2 != -1 && obj->master_obj->id != p2) goto next;
        if (p3 != -1 && obj->master_obj->object_group != p3) goto next;
        if (((UnitAIModule*)obj->unitAI())->currentAction() == p4) goto next;
        if (((UnitAIModule*)obj->unitAI())->currentAction() == p5) goto next;
        if (p6 != -1 && (int)obj->object_state != p6) goto next;
        return obj;
next:;
    }
    return 0;
}

// 0040DB20 MainDecisionAIModule::objectGroupThatCanPerformAction(int)
// PDB: aimdmod.cpp lines 240-243. Status: matching.
int MainDecisionAIModule::objectGroupThatCanPerformAction(int action) {
    this->logCommonHistory("ERROR!  %d is an unrecognized action id.", action);
    return -1;
}

// 0040DB40 MainDecisionAIModule::canPerformAction(int, int)
// PDB: aimdmod.cpp lines 248-250. Status: matching.
int MainDecisionAIModule::canPerformAction(int p0, int p1) { return 0; }

// 0040DB50 MainDecisionAIModule::numberBusyObjects()
// PDB: aimdmod.cpp lines 255-265. Status: matching.
int MainDecisionAIModule::numberBusyObjects() {
    int count = 0;
    int i = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int newCapacity = i + 1;
                int* newIds = (int*)operator new(newCapacity * 4);
                if (newIds != 0) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < newCapacity) {
                        newIds[j] = this->objects.value[j];
                        ++j;
                    }
                    operator delete(this->objects.value);
                    this->objects.value = newIds;
                    this->objects.maximumSizeValue = newCapacity;
                }
            }
            RGE_Static_Object* obj = this->game->world->object(this->objects.value[i]);
            if (obj != 0 && obj->unitAI() != 0) {
                UnitAIModule* ai = obj->unitAI();
                if (ai->currentAction() == -1) {
                    count++;
                }
            }
            ++i;
        } while (i < this->objects.numberValue);
    }
    return count;
}

// 0040DC30 MainDecisionAIModule::mostDamaged(int, int)
// PDB: aimdmod.cpp lines 270-295. Status: matching.
RGE_Static_Object* MainDecisionAIModule::mostDamaged(int class_id, int type_id) {
    RGE_Static_Object* mDB = 0;
    int damagePercentage = 0;
    int i = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (i > this->objects.maximumSizeValue - 1) {
                int newCapacity = i + 1;
                int* newIds = (int*)operator new(newCapacity * 4);
                if (newIds) {
                    int j = 0;
                    while (j < this->objects.maximumSizeValue && j < newCapacity) {
                        newIds[j] = this->objects.value[j];
                        ++j;
                    }
                    operator delete(this->objects.value);
                    this->objects.value = newIds;
                    this->objects.maximumSizeValue = newCapacity;
                }
            }
            RGE_Static_Object* obj = this->game->world->object(this->objects.value[i]);
            if (obj && obj->unitAI() && obj->object_state) {
                if ((int)obj->master_obj->object_group == class_id) {
                    int maxhp = obj->master_obj->hp;
                    if ((float)maxhp > obj->hp && obj->canRepair() == 1) {
                        if (type_id == -1 || type_id == (int)obj->master_obj->id) {
                            int hp = obj->master_obj->hp;
                            int pct = ((long)((float)hp - obj->hp) * 100) / hp;
                            if (pct > damagePercentage) {
                                mDB = obj;
                                damagePercentage = pct;
                            }
                        }
                    }
                }
            }
            ++i;
        } while (i < this->objects.numberValue);
    }
    return mDB;
}
