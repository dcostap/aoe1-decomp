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
    int i;

    for (i = 0; i < 0x32; i++) {
        if (this->gatherers[i].id == unitId)
            return this->gatherers + i;
    }
    return 0;
}
