class TribeTacticalAIModule {
public:
    char gap_0[0xD68];
    int arr_D68[4];

    int actualGathererCountByRealResourceID(int index);
};

int TribeTacticalAIModule::actualGathererCountByRealResourceID(int index) {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->arr_D68[index];
}
