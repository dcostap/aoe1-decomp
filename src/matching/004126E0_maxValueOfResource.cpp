class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;
    int* minValue;
    int* maxValue;

    int maxValueOfResource(int index) const;
};

int ResourceAIModule::maxValueOfResource(int index) const {
    if (index >= 0 && index < numberResourcesValue) {
        return maxValue[index];
    }
    return -1;
}
