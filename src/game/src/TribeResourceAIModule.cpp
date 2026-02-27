#include "../include/TribeResourceAIModule.h"

#include "../include/ResourceItem.h"
#include "../include/TribeMainDecisionAIModule.h"
#include "../include/globals.h"

namespace {
char kResourceAIName[] = "Resource AI";
char kResAIName[] = "ResAI";
char kFoodName[] = "Food";
char kWoodName[] = "Wood";
char kStoneName[] = "Stone";
char kGoldName[] = "Gold";
char kUnknownName[] = "Unknown";

int resource_item_number(ResourceItem* item) {
    return item->numberValue;
}

int resource_item_value(ResourceItem* item, int index) {
    return item->valueValue[index];
}

float* tribe_resource_values(TribeMainDecisionAIModule* md) {
    return *(float**)((unsigned char*)md + 0x50);
}
}

// Offset: 0x004E6B40
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6B40
TribeResourceAIModule::TribeResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6)
    : AIModule(kResourceAIName, 0x3EF, param_2, param_1) {
    (void)param_4;
    (void)param_5;
    (void)param_6;
    this->md = nullptr;
    this->numberResourcesValue = param_3;
}

// Offset: 0x004E6BA0
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6BA0
TribeResourceAIModule::TribeResourceAIModule(int param_1, int param_2)
    : AIModule(kResAIName, 0x3EF, param_1, nullptr) {
    this->md = nullptr;
    rge_read(param_2, &this->numberResourcesValue, 4);
}

// Offset: 0x004E6C20
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C20
TribeResourceAIModule::~TribeResourceAIModule() {
    AIModule::~AIModule();
}

// TODO: Header model declares explicit overrides; forward to AIModule base behavior.
int TribeResourceAIModule::loggingHistory() {
    return AIModule::loggingHistory();
}

void TribeResourceAIModule::setLogHistory(int param_1) {
    AIModule::setLogHistory(param_1);
}

void TribeResourceAIModule::toggleLogHistory() {
    AIModule::toggleLogHistory();
}

void TribeResourceAIModule::setHistoryFilename(char* param_1) {
    AIModule::setHistoryFilename(param_1);
}

int TribeResourceAIModule::loggingCommonHistory() {
    return AIModule::loggingCommonHistory();
}

void TribeResourceAIModule::setLogCommonHistory(int param_1) {
    AIModule::setLogCommonHistory(param_1);
}

void TribeResourceAIModule::toggleLogCommonHistory() {
    AIModule::toggleLogCommonHistory();
}

int TribeResourceAIModule::loadState(char* param_1) {
    return AIModule::loadState(param_1);
}

int TribeResourceAIModule::saveState(char* param_1) {
    return AIModule::saveState(param_1);
}

int TribeResourceAIModule::gleanState(int param_1) {
    return AIModule::gleanState(param_1);
}

int TribeResourceAIModule::processMessage(AIModuleMessage* param_1) {
    return AIModule::processMessage(param_1);
}

int TribeResourceAIModule::update(int param_1) {
    return AIModule::update(param_1);
}

void TribeResourceAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    AIModule::setCallbackMessage(param_1);
}

int TribeResourceAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return AIModule::filterOutMessage(param_1);
}

// Offset: 0x004E6C30
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30
void TribeResourceAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x004E6C40
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C40
int TribeResourceAIModule::save(int param_1) {
    rge_write(param_1, &this->numberResourcesValue, 4);
    return 1;
}

// Offset: 0x004E6C60
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C60
int TribeResourceAIModule::numberResources() const {
    return this->numberResourcesValue;
}

// Offset: 0x004E6C70
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C70
int TribeResourceAIModule::resource(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        return (int)tribe_resource_values(this->md)[param_1];
    }
    return -1;
}

// Offset: 0x004E6CA0
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6CA0
int TribeResourceAIModule::resourcesAvailable(ResourceItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->numberResourcesValue != resource_item_number(param_1)) {
        return 0;
    }
    float* resources = tribe_resource_values(this->md);
    for (int i = 0; i < resource_item_number(param_1); ++i) {
        if (resources[i] < (float)resource_item_value(param_1, i)) {
            return 0;
        }
    }
    return 1;
}

// Offset: 0x004E6D40
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6D40
int TribeResourceAIModule::unavailableResource(ResourceItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->numberResourcesValue != resource_item_number(param_1)) {
        return -1;
    }
    float* resources = tribe_resource_values(this->md);
    for (int i = 0; i < resource_item_number(param_1); ++i) {
        if (resources[i] < (float)resource_item_value(param_1, i)) {
            return i;
        }
    }
    return -1;
}

// Offset: 0x004E6DD0
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6DD0
char* TribeResourceAIModule::resourceName(int param_1) {
    if (param_1 == 0) {
        return kFoodName;
    }
    if (param_1 == 1) {
        return kWoodName;
    }
    if (param_1 == 2) {
        return kStoneName;
    }
    if (param_1 == 3) {
        return kGoldName;
    }
    return kUnknownName;
}
