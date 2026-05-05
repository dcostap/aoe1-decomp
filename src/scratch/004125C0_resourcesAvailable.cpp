// target: VA 004125C0 ResourceAIModule::resourcesAvailable(ResourceItem *)

class ResourceItem {
public:
    int typeID_;
    char gap_04[0x68];
    ResourceItem* next;

    int number();
    int value(int index);
};

class MainDecisionAIModule;

class AIModule {
public:
    void* vtable_ptr;
    char gap_04[0xEC];
};

class ResourceAIModule : public AIModule {
public:
    MainDecisionAIModule* md;
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;
    int** resourceTypesValue;
    int* numberResourceTypesValue;

    int resourcesAvailable(ResourceItem* item);
};

int ResourceAIModule::resourcesAvailable(ResourceItem* item) {
    int index;

    if (item == 0) {
        return 0;
    }

    if (this->numberResourcesValue != item->number()) {
        return 0;
    }

    index = 0;
    if (item->number() <= 0) {
        return 1;
    }

    for (; index < item->number(); ++index) {
        if (this->resourceValue[index] < item->value(index)) {
            return 0;
        }
    }

    return 1;
}
