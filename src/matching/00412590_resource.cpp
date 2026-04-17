class ResourceAIModule {
public:
    char gap_00[0xF4];
    int numberResourcesValue;
    int* resourceValue;

    int resource(int index) const;
};

int ResourceAIModule::resource(int index) const {
    if (index >= 0 && index < numberResourcesValue) {
        return resourceValue[index];
    }
    return -1;
}
