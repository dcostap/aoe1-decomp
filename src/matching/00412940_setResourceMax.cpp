class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;

    void setResourceMax(int index, int value);
};

void ResourceAIModule::setResourceMax(int index, int value) {
    if (index >= 0 && index < numberResourcesValue) {
        maxValue[index] = value;
    }
}
