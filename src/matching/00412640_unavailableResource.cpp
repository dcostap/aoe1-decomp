// target: VA 00412640 ResourceAIModule::unavailableResource(ResourceItem *)
// first pass: keep the null guard, resource-count guard, and indexed availability scan

class ResourceItem {
public:
    int typeID_;
    char gap_04[0x68];
    ResourceItem* next; // +0x6C

    int number();
    int value(int index);
};

class ResourceAIModule {
public:
    void* vtable_ptr;
    char gap_04[0xF0];
    int numberResourcesValue; // +0xF4
    int* resourceValue; // +0xF8

    int unavailableResource(ResourceItem* item);
};

int ResourceAIModule::unavailableResource(ResourceItem* item) {
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
