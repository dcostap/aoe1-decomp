class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;

    void setResourceMin(int index, int value);
};

void ResourceAIModule::setResourceMin(int index, int value) {
    if (index >= 0 && index < numberResourcesValue) {
        minValue[index] = value;
    }
}
