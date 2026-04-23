// straightforward lot scan first
// tried the direct while-loop form; mismatch was mainly in the prolog/register basin
// tried caching maxBuildingLots first and then caching the target type; VC5 still did not pick the saved-EDI basin
// remaining mismatch is the early register save / loop-counter basin, not the scan logic

class BuildingLot {
public:
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
};

class TribeInformationAIModule {
public:
    char gap_0000[0x1F4];
    int maxBuildingLots;
    BuildingLot* buildingLots;

    BuildingLot* availableLot(int lotType);
};

BuildingLot* TribeInformationAIModule::availableLot(int lotType) {
    int maxLots = this->maxBuildingLots;
    int type = lotType;
    if (maxLots <= 0) {
        return 0;
    }

    BuildingLot* lot = this->buildingLots;
    int i = 0;
    while (i < maxLots) {
        if (lot->typeID == type) {
            if (lot->status == 0) {
                return lot;
            }
        }
        ++i;
        ++lot;
    }

    return 0;
}
