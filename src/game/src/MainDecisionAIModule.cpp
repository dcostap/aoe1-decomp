#include "../include/MainDecisionAIModule.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/UnitAIModule.h"
#include "../include/globals.h"

#include <new>

namespace {
static void aimdmod_ensure_capacity(MainDecisionAIModule* self, int index) {
    if (self->objects.maximumSizeValue - 1 >= index) {
        return;
    }

    int* new_values = (int*)::operator new((size_t)index * 4 + 4, std::nothrow);
    if (new_values == nullptr) {
        return;
    }

    int copy_index = 0;
    if (self->objects.maximumSizeValue > 0) {
        do {
            if (index + 1 <= copy_index) {
                break;
            }
            int next_index = copy_index + 1;
            new_values[copy_index] = self->objects.value[copy_index];
            copy_index = next_index;
        } while (copy_index < self->objects.maximumSizeValue);
    }

    ::operator delete(self->objects.value);
    self->objects.value = new_values;
    self->objects.maximumSizeValue = index + 1;
}
}

MainDecisionAIModule::MainDecisionAIModule() {
    // TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040CDF0
    // TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040CE90
    this->player = nullptr;
    this->objects.value = nullptr;
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}

MainDecisionAIModule::MainDecisionAIModule(void* param_1, int param_2, RGE_Player* param_3) : MainDecisionAIModule() {
    // TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040CDF0
    (void)param_1;
    (void)param_2;
    this->player = param_3;
}

MainDecisionAIModule::MainDecisionAIModule(int param_1, RGE_Player* param_2, int param_3) : MainDecisionAIModule() {
    // TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040CE90
    this->player = param_2;

    int number_units = 0;
    rge_read(param_3, &number_units, 4);
    for (int i = 0; i < number_units; ++i) {
        int read_id = 0;
        rge_read(param_3, &read_id, 4);
        int current_count = this->objects.numberValue;
        int dup = 0;
        for (int j = 0; j < current_count; ++j) {
            if (this->objects.maximumSizeValue <= j) {
                break;
            }
            if (this->objects.value[j] == read_id) {
                dup = 1;
                break;
            }
        }
        if (dup == 0) {
            aimdmod_ensure_capacity(this, current_count);
            if (this->objects.value != nullptr && this->objects.numberValue < this->objects.maximumSizeValue) {
                this->objects.value[this->objects.numberValue] = read_id;
                this->objects.numberValue = this->objects.numberValue + 1;
            }
        }
    }
    (void)param_1;
}

MainDecisionAIModule::~MainDecisionAIModule() {
    // TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040D020
    if (this->objects.value != nullptr) {
        ::operator delete(this->objects.value);
        this->objects.value = nullptr;
    }
    this->objects.numberValue = 0;
    this->objects.desiredNumberValue = 0;
    this->objects.maximumSizeValue = 0;
}
int MainDecisionAIModule::loggingHistory() { return 0; }
void MainDecisionAIModule::setLogHistory(int param_1) {
    // Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D090
    (void)param_1;
}
void MainDecisionAIModule::toggleLogHistory() {}
void MainDecisionAIModule::setHistoryFilename(char* param_1) { (void)param_1; }
int MainDecisionAIModule::loggingCommonHistory() { return 0; }
void MainDecisionAIModule::setLogCommonHistory(int param_1) { (void)param_1; }
void MainDecisionAIModule::toggleLogCommonHistory() {}
int MainDecisionAIModule::loadState(char* param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::saveState(char* param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::gleanState(int param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::processMessage(AIModuleMessage* param_1) { (void)param_1; return 1; }
int MainDecisionAIModule::update(int param_1) { (void)param_1; return 1; }
void MainDecisionAIModule::setCallbackMessage(AIModuleMessage* param_1) { (void)param_1; }
int MainDecisionAIModule::filterOutMessage(AIModuleMessage* param_1) { (void)param_1; return 0; }
int MainDecisionAIModule::save(int param_1) {
    // Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D0A0
    int temp_int = this->objects.numberValue;
    rge_write(param_1, &temp_int, 4);

    int i = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, i);
            temp_int = this->objects.value[i];
            rge_write(param_1, &temp_int, 4);
            i = i + 1;
        } while (i < this->objects.numberValue);
    }
    return 1;
}
int MainDecisionAIModule::addObject(RGE_Static_Object* param_1) {
    // Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D180
    if (param_1 == nullptr) {
        return 0;
    }

    int current_count = this->objects.numberValue;
    int object_id = param_1->id;
    for (int index = 0; index < current_count; ++index) {
        if (this->objects.maximumSizeValue <= index) {
            break;
        }
        if (this->objects.value[index] == object_id) {
            return 1;
        }
    }

    aimdmod_ensure_capacity(this, current_count);

    if (this->objects.value != nullptr && this->objects.numberValue < this->objects.maximumSizeValue) {
        this->objects.value[this->objects.numberValue] = object_id;
        this->objects.numberValue = this->objects.numberValue + 1;
    }

    return 1;
}

int MainDecisionAIModule::removeObject(int param_1) {
    // Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D250
    int capacity = this->objects.maximumSizeValue;
    int index = 0;
    if (capacity > 0 && this->objects.value != nullptr) {
        int* values = this->objects.value;
        while (index < capacity) {
            if (*values == param_1) {
                break;
            }
            index = index + 1;
            values = values + 1;
        }
    }

    if (capacity <= index) {
        return 0;
    }

    if (index < capacity - 1 && this->objects.value != nullptr) {
        while (index < this->objects.maximumSizeValue - 1) {
            int next_index = index + 1;
            this->objects.value[index] = this->objects.value[next_index];
            index = next_index;
        }
    }

    int new_count = this->objects.numberValue - 1;
    this->objects.numberValue = new_count;
    if (new_count < 0) {
        this->objects.numberValue = 0;
    }

    return 1;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D2C0
int MainDecisionAIModule::numberObjects() { return this->objects.numberValue; }

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D2D0
int MainDecisionAIModule::numberObjectsWithAction(int param_1) {
    int count = 0;
    int index = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr) {
                UnitAIModule* ai = obj->unitAI();
                if (ai != nullptr && ai->currentAction() == param_1) {
                    count = count + 1;
                }
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return count;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D3B0
int MainDecisionAIModule::numberObjectsWithGroup(int param_1) {
    int count = 0;
    int index = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr && obj->master_obj->object_group == param_1) {
                count = count + 1;
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return count;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D480
int MainDecisionAIModule::numberObjectsWithActionAndTarget(int param_1, int param_2) {
    int count = 0;
    int index = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr) {
                UnitAIModule* ai = obj->unitAI();
                if (ai != nullptr && ai->currentAction() == param_1 && ai->currentTarget() == param_2) {
                    count = count + 1;
                }
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return count;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D580
int MainDecisionAIModule::numberObjectsWithTargetType(int param_1) {
    int count = 0;
    int index = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr) {
                UnitAIModule* ai = obj->unitAI();
                if (ai != nullptr && ai->currentTargetType() == param_1) {
                    count = count + 1;
                }
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return count;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D660
int MainDecisionAIModule::numberObjectsWithActionAndTargetType(int param_1, int param_2) {
    int count = 0;
    int index = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr) {
                UnitAIModule* ai = obj->unitAI();
                if (ai != nullptr && ai->currentAction() == param_1 && ai->currentTargetType() == param_2) {
                    count = count + 1;
                }
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return count;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040D760
RGE_Static_Object* MainDecisionAIModule::object(int param_1) { return this->player->world->object(param_1); }

// TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040D780
RGE_Static_Object* MainDecisionAIModule::object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9, int param_10) {
    (void)param_8;
    int i = 0;
    if (this->objects.numberValue < 1) {
        return nullptr;
    }

    do {
        aimdmod_ensure_capacity(this, i);
        RGE_Static_Object* obj = this->player->world->object(this->objects.value[i]);
        if (obj != nullptr) {
            UnitAIModule* ai = obj->unitAI();
            if (ai != nullptr &&
                (param_1 == -1 || obj->id == param_1) &&
                (param_2 == -1 || obj->master_obj->id == param_2) &&
                (param_3 == -1 || obj->master_obj->object_group == param_3)) {
                if (param_4 != -1 && ai->currentAction() != param_4) {
                    goto next_obj;
                }
                if (param_5 != -1 && this->canPerformAction(this->objects.value[i], param_5) == 0) {
                    goto next_obj;
                }
                if (param_6 != -1 && ai->currentTarget() != param_6) {
                    goto next_obj;
                }
                if (param_7 != -1 && ai->currentTargetType() != param_7) {
                    goto next_obj;
                }
                if ((param_9 == -1 || (unsigned int)obj->object_state == (unsigned int)param_9) &&
                    (param_10 == -1 || obj->attribute_amount_held <= (float)param_10)) {
                    return obj;
                }
            }
        }
    next_obj:
        i = i + 1;
        if (this->objects.numberValue <= i) {
            return nullptr;
        }
    } while (true);
}

// TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040D9D0
RGE_Static_Object* MainDecisionAIModule::object(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    int i = 0;
    if (this->objects.numberValue < 1) {
        return nullptr;
    }

    do {
        aimdmod_ensure_capacity(this, i);
        RGE_Static_Object* obj = this->player->world->object(this->objects.value[i]);
        if (obj != nullptr) {
            UnitAIModule* ai = obj->unitAI();
            if (ai != nullptr &&
                (param_1 == -1 || obj->id == param_1) &&
                (param_2 == -1 || obj->master_obj->id == param_2) &&
                (param_3 == -1 || obj->master_obj->object_group == param_3)) {
                int action = ai->currentAction();
                if (action != param_4) {
                    action = ai->currentAction();
                    if (action != param_5 && (param_6 == -1 || (unsigned int)obj->object_state == (unsigned int)param_6)) {
                        return obj;
                    }
                }
            }
        }
        i = i + 1;
        if (this->objects.numberValue <= i) {
            return nullptr;
        }
    } while (true);
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040DB20
int MainDecisionAIModule::objectGroupThatCanPerformAction(int param_1) {
    (void)param_1;
    return -1;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040DB40
int MainDecisionAIModule::canPerformAction(int param_1, int param_2) {
    (void)param_1;
    (void)param_2;
    return 0;
}

// Fully verified. Source of truth: aimdmod.cpp.decomp @ 0x0040DB50
int MainDecisionAIModule::numberBusyObjects() {
    int count = 0;
    int index = 0;
    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr) {
                UnitAIModule* ai = obj->unitAI();
                if (ai != nullptr && ai->currentAction() == -1) {
                    count = count + 1;
                }
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return count;
}

// TODO: Partial transliteration. Source of truth: aimdmod.cpp.decomp @ 0x0040DC30
RGE_Static_Object* MainDecisionAIModule::mostDamaged(int param_1, int param_2) {
    int index = 0;
    int max_damage_percent = 0;
    RGE_Static_Object* best = nullptr;

    if (0 < this->objects.numberValue) {
        do {
            aimdmod_ensure_capacity(this, index);
            RGE_Static_Object* obj = this->player->world->object(this->objects.value[index]);
            if (obj != nullptr &&
                obj->unitAI() != nullptr &&
                obj->object_state != 0 &&
                obj->master_obj->object_group == param_1 &&
                obj->hp < (float)(int)obj->master_obj->hp &&
                obj->canRepair() == 1 &&
                (param_2 == -1 || param_2 == obj->master_obj->id)) {
                int damage_percent = (int)((obj->hp * 100.0f) / (float)(int)obj->master_obj->hp);
                if (max_damage_percent < damage_percent) {
                    max_damage_percent = damage_percent;
                    best = obj;
                }
            }
            index = index + 1;
        } while (index < this->objects.numberValue);
    }
    return best;
}
