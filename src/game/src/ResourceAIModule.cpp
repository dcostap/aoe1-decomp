#include "../include/ResourceAIModule.h"

#include "../include/AIModule.h"
#include "../include/MainDecisionAIModule.h"
#include "../include/ResourceItem.h"

#include <new>

namespace {
char kResourceAIName[] = "Resource AI";

int resource_item_number(ResourceItem* item) {
    return item->numberValue;
}

int resource_item_value(ResourceItem* item, int index) {
    return item->valueValue[index];
}
}

// Offset: 0x00412310
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412310
ResourceAIModule::ResourceAIModule(void* param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    new ((AIModule*)this) AIModule(kResourceAIName, 0x3EF, param_2, param_1);
    this->md = nullptr;
    this->numberResourcesValue = param_3;
    this->resourceValue = (int*)::operator new((size_t)param_3 * sizeof(int));
    this->minValue = (int*)::operator new((size_t)this->numberResourcesValue * sizeof(int));
    this->maxValue = (int*)::operator new((size_t)this->numberResourcesValue * sizeof(int));
    this->resourceTypesValue = (int**)::operator new((size_t)this->numberResourcesValue * sizeof(int*));
    this->numberResourceTypesValue = (int*)::operator new((size_t)this->numberResourcesValue * sizeof(int));

    if (0 < this->numberResourcesValue) {
        for (int i = 0; i < this->numberResourcesValue; ++i) {
            this->resourceValue[i] = param_4;
            this->minValue[i] = param_5;
            this->maxValue[i] = param_6;
            this->numberResourceTypesValue[i] = 0;
            this->resourceTypesValue[i] = nullptr;
        }
    }
}

// Offset: 0x00412480
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412480
ResourceAIModule::~ResourceAIModule() {
    ::operator delete(this->resourceValue);
    ::operator delete(this->minValue);
    ::operator delete(this->maxValue);
    if (0 < this->numberResourcesValue && this->resourceTypesValue != nullptr) {
        for (int i = 0; i < this->numberResourcesValue; ++i) {
            ::operator delete(this->resourceTypesValue[i]);
        }
    }
    ::operator delete(this->resourceTypesValue);
    ::operator delete(this->numberResourceTypesValue);
    ((AIModule*)this)->~AIModule();
}

// TODO: Header model declares explicit overrides; forward to AIModule base behavior.
int ResourceAIModule::loggingHistory() {
    return ((AIModule*)this)->loggingHistory();
}

void ResourceAIModule::setLogHistory(int param_1) {
    ((AIModule*)this)->setLogHistory(param_1);
}

void ResourceAIModule::toggleLogHistory() {
    ((AIModule*)this)->toggleLogHistory();
}

void ResourceAIModule::setHistoryFilename(char* param_1) {
    ((AIModule*)this)->setHistoryFilename(param_1);
}

int ResourceAIModule::loggingCommonHistory() {
    return ((AIModule*)this)->loggingCommonHistory();
}

void ResourceAIModule::setLogCommonHistory(int param_1) {
    ((AIModule*)this)->setLogCommonHistory(param_1);
}

void ResourceAIModule::toggleLogCommonHistory() {
    ((AIModule*)this)->toggleLogCommonHistory();
}

int ResourceAIModule::loadState(char* param_1) {
    return ((AIModule*)this)->loadState(param_1);
}

int ResourceAIModule::saveState(char* param_1) {
    return ((AIModule*)this)->saveState(param_1);
}

int ResourceAIModule::gleanState(int param_1) {
    return ((AIModule*)this)->gleanState(param_1);
}

// Offset: 0x00412540
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412540
int ResourceAIModule::processMessage(AIModuleMessage* param_1) {
    (void)param_1;
    return 0;
}

// Offset: 0x00412550
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412550
int ResourceAIModule::update(int param_1) {
    (void)param_1;
    return 0;
}

// Offset: 0x00412560
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412560
void ResourceAIModule::setCallbackMessage(AIModuleMessage* param_1) {
    (void)param_1;
}

// Offset: 0x00412570
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412570
void ResourceAIModule::setMainDecisionAI(MainDecisionAIModule* param_1) {
    this->md = param_1;
}

// Offset: 0x00412580
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412580
int ResourceAIModule::numberResources() const {
    return this->numberResourcesValue;
}

// Offset: 0x00412590
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412590
int ResourceAIModule::resource(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        return this->resourceValue[param_1];
    }
    return -1;
}

// Offset: 0x004125C0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x004125C0
int ResourceAIModule::resourcesAvailable(ResourceItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->numberResourcesValue != resource_item_number(param_1)) {
        return 0;
    }
    for (int i = 0; i < resource_item_number(param_1); ++i) {
        if (this->resourceValue[i] < resource_item_value(param_1, i)) {
            return 0;
        }
    }
    return 1;
}

// Offset: 0x00412640
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412640
int ResourceAIModule::unavailableResource(ResourceItem* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (this->numberResourcesValue != resource_item_number(param_1)) {
        return -1;
    }
    for (int i = 0; i < resource_item_number(param_1); ++i) {
        if (this->resourceValue[i] < resource_item_value(param_1, i)) {
            return i;
        }
    }
    return -1;
}

// Offset: 0x004126B0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x004126B0
int ResourceAIModule::minValueOfResource(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        return this->minValue[param_1];
    }
    return -1;
}

// Offset: 0x004126E0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x004126E0
int ResourceAIModule::maxValueOfResource(int param_1) const {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        return this->maxValue[param_1];
    }
    return -1;
}

// Offset: 0x00412710
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412710
void ResourceAIModule::setResource(int param_1, int param_2) {
    ((AIModule*)this)->logCommonHistory((char*)"setResource(n:%d,v:%d)", param_1, param_2);
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        this->resourceValue[param_1] = param_2;
        ((AIModule*)this)->logCommonHistory((char*)"  setResource(r:%d)=%d", param_1, this->resourceValue[param_1]);
    }
}

// Offset: 0x00412770
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412770
void ResourceAIModule::setResources(ResourceItem* param_1) {
    if ((param_1 != nullptr) && (this->numberResourcesValue == resource_item_number(param_1))) {
        for (int i = 0; i < resource_item_number(param_1); ++i) {
            setResource(i, resource_item_value(param_1, i));
        }
    }
}

// Offset: 0x004127C0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x004127C0
void ResourceAIModule::incrementResource(int param_1, int param_2) {
    ((AIModule*)this)->logCommonHistory((char*)"incrementResource(n:%d,v:%d)", param_1, param_2);
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        this->resourceValue[param_1] = this->resourceValue[param_1] + param_2;
        if (param_2 != 0) {
            ((AIModule*)this)->logCommonHistory((char*)"  incrementResource(r:%d)=%d", param_1, this->resourceValue[param_1]);
        }
    }
}

// Offset: 0x00412820
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412820
void ResourceAIModule::incrementResources(ResourceItem* param_1) {
    if ((param_1 != nullptr) && (this->numberResourcesValue == resource_item_number(param_1))) {
        for (int i = 0; i < resource_item_number(param_1); ++i) {
            incrementResource(i, resource_item_value(param_1, i));
        }
    }
}

// Offset: 0x00412870
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412870
void ResourceAIModule::decrementResource(int param_1, int param_2) {
    ((AIModule*)this)->logCommonHistory((char*)"decrementResource(n:%d,v:%d)", param_1, param_2);
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        this->resourceValue[param_1] = this->resourceValue[param_1] - param_2;
        if (param_2 != 0) {
            ((AIModule*)this)->logCommonHistory((char*)"  decrementResource(r:%d)=%d", param_1, this->resourceValue[param_1]);
        }
    }
}

// Offset: 0x004128D0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x004128D0
void ResourceAIModule::decrementResources(ResourceItem* param_1) {
    if ((param_1 != nullptr) && (this->numberResourcesValue == resource_item_number(param_1))) {
        for (int i = 0; i < resource_item_number(param_1); ++i) {
            decrementResource(i, resource_item_value(param_1, i));
        }
    }
}

// Offset: 0x00412920
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412920
void ResourceAIModule::setResourceMin(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        this->minValue[param_1] = param_2;
    }
}

// Offset: 0x00412940
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412940
void ResourceAIModule::setResourceMax(int param_1, int param_2) {
    if ((-1 < param_1) && (param_1 < this->numberResourcesValue)) {
        this->maxValue[param_1] = param_2;
    }
}

// Offset: 0x00412960
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412960
int ResourceAIModule::filterOutMessage(AIModuleMessage* param_1) {
    return ((AIModule*)this)->filterOutMessage(param_1);
}

// Offset: 0x00412970
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412970
void ResourceAIModule::addResourceType(int param_1, int param_2) {
    int old_count = this->numberResourceTypesValue[param_1];
    int* new_types = (int*)::operator new((size_t)(old_count + 1) * sizeof(int));
    for (int i = 0; i < old_count; ++i) {
        new_types[i] = this->resourceTypesValue[param_1][i];
    }
    new_types[old_count] = param_2;
    if (this->resourceTypesValue[param_1] != nullptr) {
        ::operator delete(this->resourceTypesValue[param_1]);
    }
    this->resourceTypesValue[param_1] = new_types;
    this->numberResourceTypesValue[param_1] = this->numberResourceTypesValue[param_1] + 1;
}

// Offset: 0x00412A10
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412A10
int ResourceAIModule::isResourceType(int param_1, int param_2) {
    ((AIModule*)this)->logCommonHistory((char*)"Entering isResourceType(r:%d,t:%d)", param_1, param_2);
    ((AIModule*)this)->logCommonHistory((char*)"  There are %d resource types for resource %d", this->numberResourceTypesValue[param_1], param_1);
    for (int i = 0; i < this->numberResourceTypesValue[param_1]; ++i) {
        ((AIModule*)this)->logCommonHistory((char*)"    Checking against type %d", this->resourceTypesValue[param_1][i]);
        if (this->resourceTypesValue[param_1][i] == param_2) {
            ((AIModule*)this)->logCommonHistory((char*)"      Match! Returning TRUE.");
            return 1;
        }
    }
    ((AIModule*)this)->logCommonHistory((char*)"  No match. Returning FALSE.");
    return 0;
}

// Offset: 0x00412AD0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412AD0
int ResourceAIModule::numberResourceTypes(int param_1) {
    return this->numberResourceTypesValue[param_1];
}

// Offset: 0x00412AE0
// Fully verified. Source of truth: airesmod.cpp.decomp @ 0x00412AE0
int ResourceAIModule::lowestResourceType() const {
    return 1;
}
