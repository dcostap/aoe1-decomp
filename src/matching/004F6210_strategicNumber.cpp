struct TribeTacticalAIModule {
    char gap_00[0x194];
    int strategicNumbers[226];
    int strategicNumber(int index);
};

int TribeTacticalAIModule::strategicNumber(int index) {
    if (index < 0 || index >= 226)
        return -1;
    return strategicNumbers[index];
}
