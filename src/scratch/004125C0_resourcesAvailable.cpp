// target: VA 004125C0 ResourceAIModule::resourcesAvailable(ResourceItem *)
// sibling of unavailableResource; keep the memory-vs-register compare order and the early count<=0 success path
// probe 1: used a local count and then a for-loop; compare basin stayed close but branch layout drifted
// probe 2: moved to direct item->number() checks; exact compare order matched, but the loop-start basin still drifted
// probe 3: tried do/while to mirror the PDB shape; codegen got worse, so leaving the function in scratch

class ResourceItem {
public:
    int typeID_;
    char gap_04[0x68];
    ResourceItem* next; // +0x6C

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
    MainDecisionAIModule* md; // +0xF0
    int numberResourcesValue; // +0xF4
    int* resourceValue; // +0xF8
    int* minValue; // +0xFC
    int* maxValue; // +0x100
    int** resourceTypesValue; // +0x104
    int* numberResourceTypesValue; // +0x108

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
