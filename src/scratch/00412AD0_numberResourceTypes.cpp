class ResourceAIModule {
public:
    char gap_0[0x108];
    int* arr_108;

    int numberResourceTypes(int index);
};

int ResourceAIModule::numberResourceTypes(int index) {
    return this->arr_108[index];
}
