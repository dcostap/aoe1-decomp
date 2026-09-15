#include "../include/game_globals.h"
#include "../include/airesmod.h"
#include <stdlib.h>

extern char s_setResource_n_v[];
extern char s_setResource_r_v[];
void* operator new(size_t size);
void operator delete(void* ptr);

ResourceAIModule::ResourceAIModule(void* pW, int playerID, int n, int iV,
                                   int minV, int maxV)
    : AIModule("Resource AI", 0x3EF, playerID, pW), md(0),
      numberResourcesValue(n) {
    int bytes = n * 4;
    this->resourceValue = (int*)operator new(bytes);
    this->minValue = (int*)operator new(this->numberResourcesValue * 4);
    this->maxValue = (int*)operator new(this->numberResourcesValue * 4);
    this->resourceTypesValue =
        (int**)operator new(this->numberResourcesValue * 4);
    this->numberResourceTypesValue =
        (int*)operator new(this->numberResourcesValue * 4);

    for (int i = 0; i < this->numberResourcesValue; i++) {
        this->resourceValue[i] = iV;
        this->minValue[i] = minV;
        this->maxValue[i] = maxV;
        this->numberResourceTypesValue[i] = 0;
        this->resourceTypesValue[i] = 0;
    }
}

ResourceAIModule::~ResourceAIModule() {
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

int ResourceAIModule::processMessage(AIModuleMessage* m) {
    return 0;
}

int ResourceAIModule::update(int timeLimit) {
    return 0;
}

void ResourceAIModule::setCallbackMessage(AIModuleMessage* m) {
}

void ResourceAIModule::setMainDecisionAI(MainDecisionAIModule* m) {
    this->md = m;
}

int ResourceAIModule::numberResources() const {
    return this->numberResourcesValue;
}

int ResourceAIModule::resource(int n) const {
    if (n >= 0 && n < numberResourcesValue) {
        return resourceValue[n];
    }
    return -1;
}

int ResourceAIModule::resourcesAvailable(ResourceItem* ri) {
    int index;
    int count;

    if (ri == 0) {
        return 0;
    }

    if (this->numberResourcesValue != ri->number()) {
        return 0;
    }

    index = 0;
    count = ri->number();
    while (index < count) {
        if (this->resourceValue[index] < ri->value(index)) {
            return 0;
        }
        ++index;
        count = ri->number();
    }

    return 1;
}

int ResourceAIModule::unavailableResource(ResourceItem* ri) {
    int index;

    if (ri == 0) {
        return 0;
    }

    if (this->numberResourcesValue != ri->number()) {
        return -1;
    }

    for (index = 0; index < ri->number(); ++index) {
        if (this->resourceValue[index] < ri->value(index)) {
            return index;
        }
    }

    return -1;
}

int ResourceAIModule::minValueOfResource(int n) const {
    if (n >= 0 && n < numberResourcesValue) {
        return minValue[n];
    }
    return -1;
}

int ResourceAIModule::maxValueOfResource(int n) const {
    if (n >= 0 && n < numberResourcesValue) {
        return maxValue[n];
    }
    return -1;
}

void ResourceAIModule::setResource(int n, int v) {
    this->logCommonHistory(s_setResource_n_v, n, v);
    if (n >= 0 && n < numberResourcesValue) {
        resourceValue[n] = v;
        this->logCommonHistory(s_setResource_r_v, n, resourceValue[n]);
    }
}

void ResourceAIModule::setResources(ResourceItem* ri) {
    if (ri && this->numberResourcesValue == ri->number()) {
        int i = 0;
        if (ri->number() > 0) {
            do {
                this->setResource(i, ri->value(i));
                i++;
            } while (i < ri->number());
        }
    }
}

void ResourceAIModule::incrementResource(int n, int v) {
    this->logCommonHistory("incrementResource: n=%d, v=%d.", n, v);

    if (n < 0 || n >= numberResourcesValue) {
        return;
    }

    resourceValue[n] += v;

    if (v == 0) {
        return;
    }

    this->logCommonHistory("  incrementResource: r[%d]=%d.", n,
                           resourceValue[n]);
}

void ResourceAIModule::incrementResources(ResourceItem* ri) {
    int count;
    int i;
    int value;

    if (ri != 0) {
        count = ri->number();
        if (this->numberResourcesValue == count) {
            i = 0;
            count = ri->number();
            if (count > 0) {
                do {
                    value = ri->value(i);
                    this->incrementResource(i, value);
                    i++;
                    count = ri->number();
                } while (i < count);
            }
        }
    }
}

void ResourceAIModule::decrementResource(int n, int v) {
    this->logCommonHistory("decrementResource: n=%d, v=%d.", n, v);

    if (n < 0 || n >= numberResourcesValue) {
        return;
    }

    resourceValue[n] -= v;

    if (v == 0) {
        return;
    }

    this->logCommonHistory("  decrementResource: r[%d]=%d.", n,
                           resourceValue[n]);
}

void ResourceAIModule::decrementResources(ResourceItem* ri) {
    int count;
    int index;

    if (ri != 0) {
        count = ri->number();
        if (this->numberResourcesValue == count) {
            index = 0;
            count = ri->number();
            if (count > 0) {
                do {
                    count = ri->value(index);
                    this->decrementResource(index, count);
                    index = index + 1;
                    count = ri->number();
                } while (index < count);
            }
        }
    }
}

void ResourceAIModule::setResourceMin(int n, int v) {
    if (n >= 0 && n < numberResourcesValue) {
        minValue[n] = v;
    }
}

void ResourceAIModule::setResourceMax(int n, int v) {
    if (n >= 0 && n < numberResourcesValue) {
        maxValue[n] = v;
    }
}

int ResourceAIModule::filterOutMessage(AIModuleMessage* m) {
    return AIModule::filterOutMessage(m);
}

void ResourceAIModule::addResourceType(int r, int t) {
    int* newTypes = (int*)operator new(
        this->numberResourceTypesValue[r] * 4 + 4);

    int count = 0;
    if (this->numberResourceTypesValue[r] > 0) {
        do {
            newTypes[count] = this->resourceTypesValue[r][count];
            count++;
        } while (count < this->numberResourceTypesValue[r]);
    }

    newTypes[count] = t;

    if (this->resourceTypesValue[r]) {
        operator delete(this->resourceTypesValue[r]);
    }

    this->resourceTypesValue[r] = newTypes;
    this->numberResourceTypesValue[r]++;
}

int ResourceAIModule::isResourceType(int r, int t) {
    this->logCommonHistory("Entering isResourceType: r=%d, t=%d.",
                           r, t);
    this->logCommonHistory("  There are %d resource types for resource %d.",
                           this->numberResourceTypesValue[r], r);

    for (int i = 0; i < this->numberResourceTypesValue[r]; i++) {
        this->logCommonHistory("    Checking against type %d.",
                               this->resourceTypesValue[r][i]);
        if (this->resourceTypesValue[r][i] == t) {
            this->logCommonHistory("      Match!  Returning TRUE.");
            return 1;
        }
    }

    this->logCommonHistory("  No match!  Returning FALSE.");
    return 0;
}

int ResourceAIModule::numberResourceTypes(int r) {
    return this->numberResourceTypesValue[r];
}

int ResourceAIModule::lowestResourceType() const {
    return 1;
}
