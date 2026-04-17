class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;

    int minValueOfResource(int index) const;
};

int ResourceAIModule::minValueOfResource(int index) const {
    if (index >= 0 && index < numberResourcesValue) {
        return minValue[index];
    }
    return -1;
}
