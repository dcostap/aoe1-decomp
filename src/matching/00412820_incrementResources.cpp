class ResourceItem {
public:
    int number();
    int value(int index);
};

class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;

    void incrementResource(int index, int value);
    void incrementResources(ResourceItem* item);
};

void ResourceAIModule::incrementResources(ResourceItem* item) {
    int count;
    int i;
    int v;

    if (item != 0) {
        count = item->number();
        if (this->numberResourcesValue == count) {
            i = 0;
            count = item->number();
            if (count > 0) {
                do {
                    v = item->value(i);
                    this->incrementResource(i, v);
                    i++;
                    count = item->number();
                } while (i < count);
            }
        }
    }
}
