#include "../include/game_globals.h"
#include "../include/airesmod.h"
#include <stdlib.h>

extern char s_setResource_n_v[];
extern char s_setResource_r_v[];
void* operator new(size_t size);
void operator delete(void* ptr);

ResourceAIModule::ResourceAIModule(void* owner, int player, int resourceCount,
                                   int initialValue, int minimumValue,
                                   int maximumValue)
    : AIModule("Resource AI", 0x3EF, player, owner), md(0),
      numberResourcesValue(resourceCount)
{
    int bytes = resourceCount * 4;
    this->resourceValue = (int*)operator new(bytes);
    this->minValue = (int*)operator new(this->numberResourcesValue * 4);
    this->maxValue = (int*)operator new(this->numberResourcesValue * 4);
    this->resourceTypesValue =
        (int**)operator new(this->numberResourcesValue * 4);
    this->numberResourceTypesValue =
        (int*)operator new(this->numberResourcesValue * 4);

    for (int i = 0; i < this->numberResourcesValue; i++) {
        this->resourceValue[i] = initialValue;
        this->minValue[i] = minimumValue;
        this->maxValue[i] = maximumValue;
        this->numberResourceTypesValue[i] = 0;
        this->resourceTypesValue[i] = 0;
    }
}

ResourceAIModule::~ResourceAIModule()
{
    operator delete(this->resourceValue);
    operator delete(this->minValue);
    operator delete(this->maxValue);

    if (this->numberResourcesValue > 0) {
        for (int i = 0; i < this->numberResourcesValue; i++) {
            operator delete(this->resourceTypesValue[i]);
        }
    }

    operator delete(this->resourceTypesValue);
    operator delete(this->numberResourceTypesValue);
}

int ResourceAIModule::processMessage(AIModuleMessage* message)
{
    return 0;
}

int ResourceAIModule::update(int frame)
{
    return 0;
}

void ResourceAIModule::setCallbackMessage(AIModuleMessage* message)
{
}

void ResourceAIModule::setMainDecisionAI(MainDecisionAIModule* decisionAI)
{
    this->md = decisionAI;
}

int ResourceAIModule::numberResources() const
{
    return this->numberResourcesValue;
}

int ResourceAIModule::resource(int index) const
{
    if (index >= 0 && index < numberResourcesValue) {
        return resourceValue[index];
    }
    return -1;
}

int ResourceAIModule::resourcesAvailable(ResourceItem* item)
{
    int index;
    int count;

    if (item == 0) {
        return 0;
    }

    if (this->numberResourcesValue != item->number()) {
        return 0;
    }

    index = 0;
    count = item->number();
    while (index < count) {
        if (this->resourceValue[index] < item->value(index)) {
            return 0;
        }
        ++index;
        count = item->number();
    }

    return 1;
}

int ResourceAIModule::unavailableResource(ResourceItem* item)
{
    int index;

    if (item == 0) {
        return 0;
    }

    if (this->numberResourcesValue != item->number()) {
        return -1;
    }

    for (index = 0; index < item->number(); ++index) {
        if (this->resourceValue[index] < item->value(index)) {
            return index;
        }
    }

    return -1;
}

int ResourceAIModule::minValueOfResource(int index) const
{
    if (index >= 0 && index < numberResourcesValue) {
        return minValue[index];
    }
    return -1;
}

int ResourceAIModule::maxValueOfResource(int index) const
{
    if (index >= 0 && index < numberResourcesValue) {
        return maxValue[index];
    }
    return -1;
}

void ResourceAIModule::setResource(int index, int value)
{
    this->logCommonHistory(s_setResource_n_v, index, value);
    if (index >= 0 && index < numberResourcesValue) {
        resourceValue[index] = value;
        this->logCommonHistory(s_setResource_r_v, index, resourceValue[index]);
    }
}

void ResourceAIModule::setResources(ResourceItem* item)
{
    if (item && this->numberResourcesValue == item->number()) {
        int i = 0;
        if (item->number() > 0) {
            do {
                this->setResource(i, item->value(i));
                i++;
            } while (i < item->number());
        }
    }
}

void ResourceAIModule::incrementResource(int resourceID, int value)
{
    this->logCommonHistory("incrementResource: n=%d, v=%d.", resourceID, value);

    if (resourceID < 0 || resourceID >= numberResourcesValue) {
        return;
    }

    resourceValue[resourceID] += value;

    if (value == 0) {
        return;
    }

    this->logCommonHistory("  incrementResource: r[%d]=%d.", resourceID,
                           resourceValue[resourceID]);
}

void ResourceAIModule::incrementResources(ResourceItem* item)
{
    int count;
    int i;
    int value;

    if (item != 0) {
        count = item->number();
        if (this->numberResourcesValue == count) {
            i = 0;
            count = item->number();
            if (count > 0) {
                do {
                    value = item->value(i);
                    this->incrementResource(i, value);
                    i++;
                    count = item->number();
                } while (i < count);
            }
        }
    }
}

void ResourceAIModule::decrementResource(int resourceID, int value)
{
    this->logCommonHistory("decrementResource: n=%d, v=%d.", resourceID, value);

    if (resourceID < 0 || resourceID >= numberResourcesValue) {
        return;
    }

    resourceValue[resourceID] -= value;

    if (value == 0) {
        return;
    }

    this->logCommonHistory("  decrementResource: r[%d]=%d.", resourceID,
                           resourceValue[resourceID]);
}

void ResourceAIModule::decrementResources(ResourceItem* item)
{
    int count;
    int index;

    if (item != 0) {
        count = item->number();
        if (this->numberResourcesValue == count) {
            index = 0;
            count = item->number();
            if (count > 0) {
                do {
                    count = item->value(index);
                    this->decrementResource(index, count);
                    index = index + 1;
                    count = item->number();
                } while (index < count);
            }
        }
    }
}

void ResourceAIModule::setResourceMin(int index, int value)
{
    if (index >= 0 && index < numberResourcesValue) {
        minValue[index] = value;
    }
}

void ResourceAIModule::setResourceMax(int index, int value)
{
    if (index >= 0 && index < numberResourcesValue) {
        maxValue[index] = value;
    }
}

int ResourceAIModule::filterOutMessage(AIModuleMessage* message)
{
    return AIModule::filterOutMessage(message);
}

void ResourceAIModule::addResourceType(int resourceIndex, int type)
{
    int* newTypes = (int*)operator new(
        this->numberResourceTypesValue[resourceIndex] * 4 + 4);

    int count = 0;
    if (this->numberResourceTypesValue[resourceIndex] > 0) {
        do {
            newTypes[count] = this->resourceTypesValue[resourceIndex][count];
            count++;
        } while (count < this->numberResourceTypesValue[resourceIndex]);
    }

    newTypes[count] = type;

    if (this->resourceTypesValue[resourceIndex]) {
        operator delete(this->resourceTypesValue[resourceIndex]);
    }

    this->resourceTypesValue[resourceIndex] = newTypes;
    this->numberResourceTypesValue[resourceIndex]++;
}

int ResourceAIModule::isResourceType(int resourceIndex, int type)
{
    this->logCommonHistory("Entering isResourceType: r=%d, t=%d.",
                           resourceIndex, type);
    this->logCommonHistory("  There are %d resource types for resource %d.",
                           this->numberResourceTypesValue[resourceIndex],
                           resourceIndex);

    for (int i = 0; i < this->numberResourceTypesValue[resourceIndex]; i++) {
        this->logCommonHistory("    Checking against type %d.",
                               this->resourceTypesValue[resourceIndex][i]);
        if (this->resourceTypesValue[resourceIndex][i] == type) {
            this->logCommonHistory("      Match!  Returning TRUE.");
            return 1;
        }
    }

    this->logCommonHistory("  No match!  Returning FALSE.");
    return 0;
}

int ResourceAIModule::numberResourceTypes(int index)
{
    return this->numberResourceTypesValue[index];
}

int ResourceAIModule::lowestResourceType() const
{
    return 1;
}
