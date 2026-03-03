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

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
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
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C20 (audited vs tairesmd.cpp.asm).
TribeResourceAIModule::~TribeResourceAIModule() {
    // TODO: EMPTY_STUB - function body not transliterated [decomp: bucket_0560.decomp @ 0x005606fe]
}

// Fully verified. Not in decomp, inherited/forwarding overrides from AIModule.
int TribeResourceAIModule::loggingHistory() {
    return AIModule::loggingHistory();
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
void TribeResourceAIModule::setLogHistory(int param_1) {
    AIModule::setLogHistory(param_1);
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
void TribeResourceAIModule::toggleLogHistory() {
    AIModule::toggleLogHistory();
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
void TribeResourceAIModule::setHistoryFilename(char* param_1) {
    AIModule::setHistoryFilename(param_1);
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
int TribeResourceAIModule::loggingCommonHistory() {
    return AIModule::loggingCommonHistory();
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
void TribeResourceAIModule::setLogCommonHistory(int param_1) {
    AIModule::setLogCommonHistory(param_1);
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
void TribeResourceAIModule::toggleLogCommonHistory() {
    AIModule::toggleLogCommonHistory();
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
int TribeResourceAIModule::loadState(char* param_1) {
    return AIModule::loadState(param_1);
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
int TribeResourceAIModule::saveState(char* param_1) {
    return AIModule::saveState(param_1);
}

// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (virtual forwarding/helper coverage).
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
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C30 (audited vs tairesmd.cpp.asm).
void TribeResourceAIModule::setMainDecisionAI(TribeMainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x004E6C40
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C40 (audited vs tairesmd.cpp.asm).
int TribeResourceAIModule::save(int param_1) {
    rge_write(param_1, &this->numberResourcesValue, 4);
    return 1;
}

// Offset: 0x004E6C60
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C60 (audited vs tairesmd.cpp.asm).
int TribeResourceAIModule::numberResources() const {
    return this->numberResourcesValue;
}

// Offset: 0x004E6C70
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6C70 (audited vs tairesmd.cpp.asm).
int TribeResourceAIModule::resource(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        return (int)tribe_resource_values(this->md)[param_1];
    }
    return -1;
}

// Offset: 0x004E6CA0
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6CA0 (audited vs tairesmd.cpp.asm).
int TribeResourceAIModule::resourcesAvailable(ResourceItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->numberResourcesValue != param_1->number()) {
        return 0;
    }
    float* resources = tribe_resource_values(this->md);
    for (int i = 0; i < param_1->number(); ++i) {
        if (resources[i] < (float)param_1->value(i)) {
            return 0;
        }
    }
    return 1;
}

// Offset: 0x004E6D40
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6D40 (audited vs tairesmd.cpp.asm).
int TribeResourceAIModule::unavailableResource(ResourceItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->numberResourcesValue != param_1->number()) {
        return -1;
    }
    float* resources = tribe_resource_values(this->md);
    for (int i = 0; i < param_1->number(); ++i) {
        if (resources[i] < (float)param_1->value(i)) {
            return i;
        }
    }
    return -1;
}

// Offset: 0x004E6DD0
// Fully verified. Source of truth: tairesmd.cpp.decomp @ 0x004E6DD0 (audited vs tairesmd.cpp.asm).
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
