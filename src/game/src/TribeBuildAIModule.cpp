#include "../include/BaseItem.h"
#include "../include/BuildItem.h"
#include "../include/RGE_Game_World.h"
#include "../include/RGE_Master_Static_Object.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Static_Object.h"
#include "../include/TribeMainDecisionAIModule.h"

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

void tribe_build_ai_detask(TribeBuildAIModule* build_ai, int task_id) {
    (void)build_ai;
    (void)task_id;
    // TODO: STUB - TribeMainDecisionAIModule::detask not transliterated yet.
}

int tribe_build_ai_is_moveable(TribeBuildAIModule* build_ai, int object_id) {
    (void)build_ai;
    (void)object_id;
    // TODO: STUB - TribeMainDecisionAIModule::isMoveable not transliterated yet.
    return 0;
}

void tribe_build_ai_clear_area(TribeBuildAIModule* build_ai, int object_id, float min_x, float min_y, float max_x, float max_y) {
    (void)build_ai;
    (void)object_id;
    (void)min_x;
    (void)min_y;
    (void)max_x;
    (void)max_y;
    // TODO: STUB - TribeTacticalAIModule::clearArea not transliterated yet.
}

void tribe_build_ai_remove_lot(TribeBuildAIModule* build_ai, int type_id, int x, int y) {
    (void)build_ai;
    (void)type_id;
    (void)x;
    (void)y;
    // TODO: STUB - TribeInformationAIModule::removeLot not transliterated yet.
}

void tribe_build_ai_update_needed_resources(TribeBuildAIModule* build_ai) {
    (void)build_ai;
    // TODO: STUB - TribeTacticalAIModule::updateNeededResources not transliterated yet.
}
}

// Offset: 0x004D3B10
// Fully verified. Source of truth: taibldmd.cpp.decomp @ 0x004D3B10
void TribeBuildAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    *tribe_build_ai_md_slot(this) = param_1;
}

// Offset: 0x004D5170
// TODO: Partial parity pending non-transliterated AI module dependencies.
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
// TODO: Partial parity pending non-transliterated AI module dependencies.
int TribeBuildAIModule::cancelBuildItem(int param_1, int param_2, int param_3, float param_4, float param_5, int param_6, int param_7) {
    (void)param_6;
    if (param_7 != -1) {
        tribe_build_ai_detask(this, param_7);
    }

    int clear_placement = 0;
    int is_building = 0;
    switch (param_1) {
    default:
        clear_placement = 1;
        is_building = 0;
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
        break;
    }

    RGE_Static_Object* object = tribe_build_ai_object(this, param_2);
    if ((object != nullptr) && (is_building != 0)) {
        if (tribe_build_ai_is_moveable(this, param_2) == 1) {
            tribe_build_ai_clear_area(this, param_2, param_4 - 2.0f, param_5 - 2.0f, param_4 + 2.0f, param_5 + 2.0f);
        } else {
            // TODO: STUB - ConstructionAIModule::incrementBuildAttempts not transliterated yet.
        }
    }

    if (clear_placement != 0) {
        // TODO: STUB - ConstructionAIModule::unplaceStructure(float,float,int) not transliterated yet.
    }

    BuildItem* item = tribe_build_ai_specific_build_item(this, param_3);
    if (item != nullptr) {
        item->progressValue = 0;
        int lot_x = (int)param_4;
        int lot_y = (int)param_5;
        tribe_build_ai_remove_lot(this, ((BaseItem*)item)->typeID(), lot_x, lot_y);
        if (((BaseItem*)item)->typeID() == 0x114) {
            tribe_build_ai_set_wonder_value(this, kWonderInProgressOffset, 0);
        }
    }

    return 1;
}

// Offset: 0x004D5590
// TODO: Partial parity pending non-transliterated AI module dependencies.
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
// TODO: Partial parity pending non-transliterated AI module dependencies.
int TribeBuildAIModule::cancelTrainUnit(int param_1, int param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    BuildItem* item = tribe_build_ai_specific_build_item(this, param_4);
    if (item != nullptr) {
        item->progressValue = 0;
        // TODO: STUB - BuildAIModule::displayBuildList not transliterated yet.
        return 1;
    }
    // TODO: STUB - BuildAIModule::displayBuildList not transliterated yet.
    return 1;
}

// Offset: 0x004D5690
// TODO: Partial parity pending non-transliterated AI module dependencies.
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
// TODO: Partial parity pending non-transliterated AI module dependencies.
int TribeBuildAIModule::cancelResearch(int param_1, int param_2, int param_3, int param_4) {
    (void)param_1;
    (void)param_2;
    (void)param_3;
    BuildItem* item = tribe_build_ai_specific_build_item(this, param_4);
    if (item != nullptr) {
        item->progressValue = 0;
        // TODO: STUB - BuildAIModule::displayBuildList not transliterated yet.
        return 1;
    }
    // TODO: STUB - BuildAIModule::displayBuildList not transliterated yet.
    return 1;
}
