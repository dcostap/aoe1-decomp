// target: VA 004125C0 ResourceAIModule::resourcesAvailable(ResourceItem *)
// Exact-match note: keep a `count` local initialized from item->number(), then
// refresh it at the bottom of the loop. This gives VC5 the original single
// initial count test plus bottom `index < item->number()` back-edge, without an
// extra top-of-loop number() call or first-iteration peel.

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
