#include "../include/BaseItem.h"
#include "../include/BuildingLot.h"
#include "../include/BuildItem.h"
#include "../include/ConstructionAIModule.h"
#include "../include/ConstructionItem.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/ResourceItem.h"
#include "../include/TribeInformationAIModule.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/TribeResourceAIModule.h"
#include "../include/TribeTacticalAIModule.h"
#include "../include/UnitAIModule.h"

#include <stddef.h>
#include <string.h>

class TribeBuildAIModule {
public:
    void setMainDecisionAI(TribeMainDecisionAIModule* param_1);
    int addBuiltItem(RGE_Static_Object* param_1, int param_2);
    int cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7);
    int addTrainedUnit(int param_1, int param_2, int param_3, int param_4);
    int cancelTrainUnit(int param_1, int param_2, int param_3, int param_4);
    int addResearch(int param_1, int param_2, int param_3);
    int cancelResearch(int param_1, int param_2, int param_3, int param_4);
};

namespace {
constexpr ptrdiff_t kBuildListOffset = 0xF0;
constexpr ptrdiff_t kCurrentBuildItemRequestedOffset = 0x2A5;
constexpr ptrdiff_t kNumberItemsIntoBuildListOffset = 0x5A8;
constexpr ptrdiff_t kMdOffset = 0x5BC;
constexpr ptrdiff_t kWonderInProgressOffset = 0x122B0;
constexpr ptrdiff_t kWonderBuiltOffset = 0x122B4;

unsigned char* tribe_build_ai_raw(TribeBuildAIModule* build_ai) {
    return (unsigned char*)build_ai;
}

BuildItem* tribe_build_ai_build_list(TribeBuildAIModule* build_ai) {
    return (BuildItem*)(tribe_build_ai_raw(build_ai) + kBuildListOffset);
}

char* tribe_build_ai_current_build_item_requested(TribeBuildAIModule* build_ai) {
    return (char*)(tribe_build_ai_raw(build_ai) + kCurrentBuildItemRequestedOffset);
}

int* tribe_build_ai_number_items_into_build_list(TribeBuildAIModule* build_ai) {
    return (int*)(tribe_build_ai_raw(build_ai) + kNumberItemsIntoBuildListOffset);
}

TribeMainDecisionAIModule** tribe_build_ai_md_slot(TribeBuildAIModule* build_ai) {
    return (TribeMainDecisionAIModule**)(tribe_build_ai_raw(build_ai) + kMdOffset);
}

TribeMainDecisionAIModule* tribe_build_ai_md(TribeBuildAIModule* build_ai) {
    return *tribe_build_ai_md_slot(build_ai);
}

void tribe_build_ai_set_wonder_value(TribeBuildAIModule* build_ai, ptrdiff_t offset, int value) {
    TribeMainDecisionAIModule* md = tribe_build_ai_md(build_ai);
    if (md != nullptr) {
        *(int*)((unsigned char*)md + offset) = value;
    }
}

BuildItem* tribe_build_ai_specific_build_item(TribeBuildAIModule* build_ai, int unique_id) {
    BuildItem* head = tribe_build_ai_build_list(build_ai);
    BuildItem* item = head->next;
    while ((item != head) && (item != nullptr)) {
        if (((BaseItem*)item)->uniqueID() == unique_id) {
            return item;
        }
        item = item->next;
    }
    return nullptr;
}

RGE_Static_Object* tribe_build_ai_object(TribeBuildAIModule* build_ai, int object_id) {
    TribeMainDecisionAIModule* md = tribe_build_ai_md(build_ai);
    if (md == nullptr || md->player == nullptr || md->player->world == nullptr) {
        return nullptr;
    }
    return md->player->world->object(object_id);
}

ConstructionAIModule* tribe_build_ai_construction_ai(TribeBuildAIModule* build_ai) {
    TribeMainDecisionAIModule* md = tribe_build_ai_md(build_ai);
    if (md == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<ConstructionAIModule*>(md->constructionAI);
}

TribeInformationAIModule* tribe_build_ai_information_ai(TribeBuildAIModule* build_ai) {
    TribeMainDecisionAIModule* md = tribe_build_ai_md(build_ai);
    if (md == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<TribeInformationAIModule*>(md->informationAI);
}

TribeTacticalAIModule* tribe_build_ai_tactical_ai(TribeBuildAIModule* build_ai) {
    TribeMainDecisionAIModule* md = tribe_build_ai_md(build_ai);
    if (md == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<TribeTacticalAIModule*>(md->tacticalAI);
}

TribeResourceAIModule* tribe_build_ai_resource_ai(TribeBuildAIModule* build_ai) {
    TribeMainDecisionAIModule* md = tribe_build_ai_md(build_ai);
    if (md == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<TribeResourceAIModule*>(md->resourceAI);
}

void tribe_build_ai_send_unit_ai_order(TribeMainDecisionAIModule* md,
                                       int object_id,
                                       int order_type,
                                       int target_id,
                                       int target_owner,
                                       float target_x,
                                       float target_y,
                                       float target_z,
                                       float range,
                                       int command_order) {
    if ((md == nullptr) || (md->player == nullptr)) {
        return;
    }

    md->player->sendUnitAIOrder((int)md->player->id,
                                object_id,
                                order_type,
                                target_id,
                                target_owner,
                                target_x,
                                target_y,
                                target_z,
                                range,
                                1,
                                0,
                                command_order);
}

int tribe_build_ai_busy_with_action(TribeBuildAIModule* build_ai, int object_id, int action_id) {
    RGE_Static_Object* object = tribe_build_ai_object(build_ai, object_id);
    if ((object == nullptr) || (object->unitAIValue == nullptr)) {
        return 0;
    }
    return (object->unitAIValue->currentActionValue == action_id) ? 1 : 0;
}

void tribe_build_ai_remove_from_task_array(ManagedArray<int>& array, int object_id) {
    if ((array.value == nullptr) || (array.numberValue < 1)) {
        return;
    }

    int write_index = 0;
    for (int read_index = 0; read_index < array.numberValue; ++read_index) {
        if ((read_index < array.maximumSizeValue) && (array.value[read_index] != object_id)) {
            array.value[write_index] = array.value[read_index];
            write_index = write_index + 1;
        }
    }
    array.numberValue = write_index;
}

void tribe_build_ai_display_build_list(TribeBuildAIModule* build_ai) {
    void** vtable = *(void***)build_ai;
    if ((vtable != nullptr) && (vtable[16] != nullptr)) {
        typedef void(__thiscall* DisplayBuildListFn)(TribeBuildAIModule*);
        DisplayBuildListFn display_build_list = (DisplayBuildListFn)vtable[16];
        display_build_list(build_ai);
    }
}

void tribe_build_ai_detask(TribeBuildAIModule* build_ai, int task_id) {
    if (task_id == -1) {
        return;
    }

    TribeTacticalAIModule* tactical_ai = tribe_build_ai_tactical_ai(build_ai);
    if (tactical_ai != nullptr) {
        tribe_build_ai_remove_from_task_array(tactical_ai->civilianExplorers, task_id);
        tribe_build_ai_remove_from_task_array(tactical_ai->unitsTaskedThisUpdate, task_id);
        tactical_ai->removeFromGroup(task_id);

        RGE_Static_Object* object = tribe_build_ai_object(build_ai, task_id);
        int action_id = -1;
        if ((object != nullptr) && (object->unitAIValue != nullptr)) {
            action_id = object->unitAIValue->currentActionValue;
        }

        for (int i = 0; i < 50; ++i) {
            if (tactical_ai->gatherers[i].id == task_id) {
                if ((action_id == 0x261) || (action_id == 0x265)) {
                    int resource_id = tactical_ai->gatherers[i].data1;
                    if ((0 <= resource_id) && (resource_id < 4)) {
                        tactical_ai->actualGathererDistribution[resource_id] =
                            tactical_ai->actualGathererDistribution[resource_id] - 1;
                    }
                }
                tactical_ai->gatherers[i].id = -1;
                tactical_ai->gatherers[i].data1 = -1;
                tactical_ai->gatherers[i].data2 = -1;
                tactical_ai->gatherers[i].data3 = -1;
                tactical_ai->gatherers[i].target = -1;
            }
        }
    }

    tribe_build_ai_send_unit_ai_order(tribe_build_ai_md(build_ai),
                                      task_id,
                                      0x2C2,
                                      -1,
                                      -1,
                                      -1.0f,
                                      -1.0f,
                                      -1.0f,
                                      -1.0f,
                                      100);
}

int tribe_build_ai_is_moveable(TribeBuildAIModule* build_ai, int object_id) {
    RGE_Static_Object* object = tribe_build_ai_object(build_ai, object_id);
    if ((object != nullptr) && (object->master_obj != nullptr)) {
        short object_group = object->master_obj->object_group;
        if ((object_group != 3) &&
            (object_group != 0x1B) &&
            (object_group != 0x1E) &&
            (object_group != 0x1F) &&
            (object_group != 5) &&
            (object_group != 0x21) &&
            (object_group != 7) &&
            (object_group != 8) &&
            (object_group != 0x20) &&
            (object_group != 0x10) &&
            (object_group != 0xE) &&
            (object_group != 0xF)) {
            return 1;
        }
    }
    return 0;
}

void tribe_build_ai_clear_area(TribeBuildAIModule* build_ai, int object_id, float min_x, float min_y, float max_x, float max_y) {
    if (tribe_build_ai_busy_with_action(build_ai, object_id, -1) != 1) {
        return;
    }

    RGE_Static_Object* object = tribe_build_ai_object(build_ai, object_id);
    if (object == nullptr) {
        return;
    }

    float best_x = -1.0f;
    float best_y = -1.0f;
    float best_distance = -1.0f;
    float test_x = -1.0f;
    float test_y = -1.0f;

    for (int i = 0; i < 8; ++i) {
        switch (i) {
        case 0:
            test_x = min_x - 2.0f;
            test_y = min_y - 2.0f;
            break;
        case 1:
        case 5:
            test_x = (max_x + min_x) * 0.5f;
            break;
        case 2:
            test_x = max_x + 2.0f;
            break;
        case 3:
        case 7:
            test_y = (max_y + min_y) * 0.5f;
            break;
        case 4:
            test_y = max_y + 2.0f;
            break;
        case 6:
            test_x = min_x - 2.0f;
            break;
        }

        int can_move = object->passableTile(test_x, test_y, 1);
        if (can_move != 0) {
            float distance = object->distance_to_position(test_x, test_y, object->world_z);
            if ((best_distance == -1.0f) || (distance < best_distance)) {
                best_x = test_x;
                best_y = test_y;
                best_distance = distance;
            }
        }
    }

    if (best_distance != -1.0f) {
        tribe_build_ai_send_unit_ai_order(tribe_build_ai_md(build_ai),
                                          object_id,
                                          0x2C6,
                                          -1,
                                          -1,
                                          best_x,
                                          best_y,
                                          1.0f,
                                          1.0f,
                                          100);
    }
}

void tribe_build_ai_remove_lot(TribeBuildAIModule* build_ai, int type_id, int x, int y, int lot_status) {
    TribeInformationAIModule* information_ai = tribe_build_ai_information_ai(build_ai);
    if ((information_ai == nullptr) || (information_ai->buildingLots == nullptr)) {
        return;
    }

    for (int i = 0; i < information_ai->maxBuildingLots; ++i) {
        BuildingLot* lot = &information_ai->buildingLots[i];
        if ((lot->typeID == type_id) && (lot->x == (uchar)x) && (lot->y == (uchar)y)) {
            if ((uchar)lot_status != '\x03') {
                lot->status = (uchar)lot_status;
            } else {
                lot->typeID = -1;
                lot->x = '\0';
                lot->y = '\0';
                lot->status = '\x03';
            }
            return;
        }
    }
}

void tribe_build_ai_update_needed_resources(TribeBuildAIModule* build_ai) {
    TribeTacticalAIModule* tactical_ai = tribe_build_ai_tactical_ai(build_ai);
    TribeResourceAIModule* resource_ai = tribe_build_ai_resource_ai(build_ai);
    if ((tactical_ai == nullptr) || (resource_ai == nullptr)) {
        return;
    }

    int assigned_resource[4] = {0, 0, 0, 0};
    int temp_needed_resource[4] = {0, -1, -1, -1};
    int temp_resource_difference[4] = {-1, -1, -1, -1};

    for (int i = 0; i < 4; ++i) {
        int available = resource_ai->resource(i);
        int needed = tactical_ai->neededResources.value(i);
        tactical_ai->resourceDifferenceValue[i] = available - needed;
    }

    for (int slot = 0; slot < 4; ++slot) {
        int best_resource = -1;
        int best_difference = 0x7FFFFFFF;
        for (int resource_id = 0; resource_id < 4; ++resource_id) {
            if (resource_id == 0) {
                if (resource_ai->resource(0) >= tactical_ai->sn[0xBE]) {
                    continue;
                }
            } else if (resource_id == 1) {
                if (tactical_ai->sn[0xBF] <= resource_ai->resource(1)) {
                    continue;
                }
            } else if (resource_id == 3) {
                if (tactical_ai->sn[0xC1] <= resource_ai->resource(3)) {
                    continue;
                }
            } else if (resource_id == 2) {
                if (tactical_ai->sn[0xC0] <= resource_ai->resource(2)) {
                    continue;
                }
            }

            int needed = tactical_ai->neededResources.value(resource_id);
            if ((0 < needed) &&
                ((best_resource == -1) || (tactical_ai->resourceDifferenceValue[resource_id] < best_difference)) &&
                (assigned_resource[resource_id] == 0)) {
                best_difference = tactical_ai->resourceDifferenceValue[resource_id];
                best_resource = resource_id;
            }
        }

        if (best_resource == -1) {
            for (int resource_id = 0; resource_id < 4; ++resource_id) {
                if (((best_resource == -1) || (tactical_ai->resourceDifferenceValue[resource_id] < best_difference)) &&
                    (assigned_resource[resource_id] == 0)) {
                    best_difference = tactical_ai->resourceDifferenceValue[resource_id];
                    best_resource = resource_id;
                }
            }
        }

        if (best_resource < 0) {
            continue;
        }

        assigned_resource[best_resource] = 1;
        temp_needed_resource[slot] = best_resource;
        temp_resource_difference[slot] = best_difference;
    }

    for (int i = 0; i < 4; ++i) {
        int resource_id = temp_needed_resource[i];
        int resource_diff = temp_resource_difference[i];
        tactical_ai->neededResourceValue[i] = resource_id;
        if ((0 <= resource_id) && (resource_id < 4)) {
            tactical_ai->resourceDifferenceValue[resource_id] = resource_diff;
        }
    }
}
}

// Offset: 0x004D3B10
// Fully verified. Source of truth: taibldmd.cpp.decomp @ 0x004D3B10
void TribeBuildAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    *tribe_build_ai_md_slot(this) = param_1;
}

// Offset: 0x004D5170
int TribeBuildAIModule::addBuiltItem(RGE_Static_Object* param_1, int param_2) {
    int found = 0;
    BuildItem* head = tribe_build_ai_build_list(this);
    BuildItem* item = head->next;

    if (item != head) {
        while ((item != nullptr) && (found == 0)) {
            if ((((BaseItem*)item)->typeID() == param_1->master_obj->id) &&
                (item->builtValue == 0) &&
                (param_2 != -1) &&
                (((BaseItem*)item)->uniqueID() == param_2)) {
                item->progressValue = 0;
                found = 1;
                item->builtValue = 1;
                ((BaseItem*)item)->setGameID((int)param_1->id);
                item->numberBuildsValue = item->numberBuildsValue + 1;
                if (((BaseItem*)item)->typeID() == 0x114) {
                    tribe_build_ai_set_wonder_value(this, kWonderBuiltOffset, 1);
                }
                strncpy(tribe_build_ai_current_build_item_requested(this), ((BaseItem*)item)->name(), 0x3F);
                *tribe_build_ai_number_items_into_build_list(this) = ((BaseItem*)item)->uniqueID();
            } else {
                item = item->next;
                if (item == head) {
                    break;
                }
            }
        }
    }

    tribe_build_ai_update_needed_resources(this);
    return 1;
}

// Offset: 0x004D5310
int TribeBuildAIModule::cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {
    (void)param_6;
    if (param_7 != -1) {
        tribe_build_ai_detask(this, param_7);
    }

    int clear_placement = 0;
    int is_building = 0;
    int new_lot_status = 2;
    switch (param_1) {
    default:
        clear_placement = 1;
        is_building = 0;
        new_lot_status = 0;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    case 8:
        is_building = 1;
        clear_placement = 1;
        break;
    case -1:
        clear_placement = 1;
        is_building = 0;
        new_lot_status = 0;
        break;
    }

    ConstructionAIModule* construction_ai = tribe_build_ai_construction_ai(this);
    RGE_Static_Object* object = tribe_build_ai_object(this, param_2);
    if ((object != nullptr) && (is_building != 0) && (construction_ai != nullptr)) {
        if (tribe_build_ai_is_moveable(this, param_2) == 1) {
            ConstructionItem* lot = construction_ai->lot(param_4, param_5);
            if (lot == nullptr) {
                tribe_build_ai_clear_area(this, param_2, param_4 - 2.0f, param_5 - 2.0f, param_4 + 2.0f, param_5 + 2.0f);
            } else {
                float max_y = ((BaseItem*)lot)->y() - (((BaseItem*)lot)->ySize() * -0.5f);
                float max_x = ((BaseItem*)lot)->x() - (((BaseItem*)lot)->xSize() * -0.5f);
                float min_y = ((BaseItem*)lot)->y() - (((BaseItem*)lot)->ySize() * 0.5f);
                float min_x = ((BaseItem*)lot)->x() - (((BaseItem*)lot)->xSize() * 0.5f);
                tribe_build_ai_clear_area(this, param_2, min_x, min_y, max_x, max_y);
            }
        } else {
            construction_ai->incrementBuildAttempts(param_4, param_5, 10);
        }
    }

    if (construction_ai != nullptr) {
        construction_ai->unplaceStructure(param_4, param_5, clear_placement);
    }

    BuildItem* item = tribe_build_ai_specific_build_item(this, param_3);
    if (item != nullptr) {
        item->progressValue = 0;
        int lot_x = (int)param_4;
        int lot_y = (int)param_5;
        tribe_build_ai_remove_lot(this, ((BaseItem*)item)->typeID(), lot_x, lot_y, new_lot_status);
        if (((BaseItem*)item)->typeID() == 0x114) {
            tribe_build_ai_set_wonder_value(this, kWonderInProgressOffset, 0);
        }
    }

    return 1;
}

// Offset: 0x004D5590
int TribeBuildAIModule::addTrainedUnit(int param_1, int param_2, int param_3, int param_4) {
    (void)param_1;
    BuildItem* item = tribe_build_ai_specific_build_item(this, param_3);
    if (item != nullptr) {
        item->progressValue = 0;
        item->builtValue = 1;
        ((BaseItem*)item)->setGameID(param_4);
        item->numberBuildsValue = item->numberBuildsValue + 1;
    }
    tribe_build_ai_detask(this, param_2);
    tribe_build_ai_update_needed_resources(this);
    return 1;
}

// Offset: 0x004D5600
int TribeBuildAIModule::cancelTrainUnit(int param_1, int param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    BuildItem* item = tribe_build_ai_specific_build_item(this, param_4);
    if (item != nullptr) {
        item->progressValue = 0;
        tribe_build_ai_display_build_list(this);
        return 1;
    }
    tribe_build_ai_display_build_list(this);
    return 1;
}

// Offset: 0x004D5690
int TribeBuildAIModule::addResearch(int param_1, int param_2, int param_3) {
    (void)param_1;
    BuildItem* item = tribe_build_ai_specific_build_item(this, param_3);
    if (item != nullptr) {
        item->progressValue = 0;
        item->builtValue = 1;
        item->numberBuildsValue = item->numberBuildsValue + 1;
    }
    tribe_build_ai_detask(this, param_2);
    tribe_build_ai_update_needed_resources(this);
    return 1;
}

// Offset: 0x004D56F0
int TribeBuildAIModule::cancelResearch(int param_1, int param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    BuildItem* item = tribe_build_ai_specific_build_item(this, param_4);
    if (item != nullptr) {
        item->progressValue = 0;
        tribe_build_ai_display_build_list(this);
        return 1;
    }
    tribe_build_ai_display_build_list(this);
    return 1;
}
