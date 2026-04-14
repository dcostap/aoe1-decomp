class TribeInformationAIModule {
public:
    char gap_0[0x550];
    int arr_550[4];

    int closestDropsiteResID(int index);
};

int TribeInformationAIModule::closestDropsiteResID(int index) {
    if (index < 0 || index > 3) {
        return -1;
    }
    return this->arr_550[index];
}
