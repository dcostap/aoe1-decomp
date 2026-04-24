class ResourceItem {
public:
    int number();
    int value(int index);
};

class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;

    void setResource(int index, int value);
    void setResources(ResourceItem* item);
};

void ResourceAIModule::setResources(ResourceItem* item) {
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
