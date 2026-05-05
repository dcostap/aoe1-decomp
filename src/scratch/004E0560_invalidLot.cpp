// VA: 004E0560 TribeInformationAIModule::invalidLot
// left in scratch: natural loop matches call-free behavior and register allocation but VC5 either emits
// an extra redundant pre-loop `test esi,esi` for `while(i<count)` or, with do/while, collapses the
// original false/true return tails and uses a jge+jmp loop shape. No exact branch-layout basin found yet.

class BuildingLot {
public:
    int typeID;
    unsigned char status;
    unsigned char x;
    unsigned char y;
    unsigned char pad;
};

class TribeInformationAIModule {
public:
    char gap_000[0x1F4];
    int maxBuildingLots;
    BuildingLot* buildingLots;

    int invalidLot(int typeID, unsigned char x, unsigned char y);
};

int TribeInformationAIModule::invalidLot(int typeID, unsigned char x, unsigned char y) {
    int count = this->maxBuildingLots;
    int i = 0;
    if (count <= 0) {
        return 0;
    }
    BuildingLot* lot = this->buildingLots;
    while (i < count) {
        if (lot->typeID == typeID && lot->status == 2 && lot->x == x && lot->y == y) {
            return 1;
        }
        i++;
        lot++;
    }
    return 0;
}
