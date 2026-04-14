class TribeSoldierUnitAIModule {
public:
    int convertToLOSResourceType(int);
};

int TribeSoldierUnitAIModule::convertToLOSResourceType(int value) {
    if (value == 0x1F || value == 0x5 || value == 0x21)
        return 2;
    return -1;
}
