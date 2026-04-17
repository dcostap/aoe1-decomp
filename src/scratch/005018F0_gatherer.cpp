struct UnitData {
    int id;
    char data[0x14];
};

class TribeTacticalAIModule {
public:
    UnitData* gatherer(int unitId);
    char gap_00[0x51C];
    UnitData gatherers[50];
};

UnitData* TribeTacticalAIModule::gatherer(int unitId) {
    int i = 0;
    int* p = (int*)((char*)this + 0x51C);
    do {
        if (*p == unitId) {
            return (UnitData*)((char*)this + 0x51C + i * 0x18);
        }
        ++i;
        p = (int*)((char*)p + 0x18);
    } while (i < 0x32);
    return 0;
}
