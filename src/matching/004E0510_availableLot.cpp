#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct BuildingLot {
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
    unsigned char pad_end;
};

class TribeInformationAIModule {
public:
    char gap_00[0x1F4];
    int maxBuildingLots;
    BuildingLot* buildingLots;

    BuildingLot* availableLot(int typeID);
};
#endif

#endif
BuildingLot* TribeInformationAIModule::availableLot(int typeID) {
    int i = 0;
    int max = this->maxBuildingLots;
    BuildingLot* base;
    BuildingLot* cur;

    if (max > 0) {
        base = this->buildingLots;
        cur = base;
        while (1) {
            if (cur->typeID == typeID) {
                if (cur->status == 0) {
                    break;
                }
            }
            i++;
            cur++;
            if (i < max) {
                continue;
            }
            return 0;
        }
        return base + i;
    }
    return 0;
}
