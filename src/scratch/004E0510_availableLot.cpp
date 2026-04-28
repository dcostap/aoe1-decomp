// TribeInformationAIModule::availableLot
// VA: 004E0510
// taiinfmd.cpp:5873-5879
// 71 bytes, 26 diff bytes (36.6%).
// Loop-bottom condition inversion: original uses `jl loop` (fall-through
// on exit), rebuilt uses `jge exit; jmp loop` (branch on exit).
// 7+ source forms tried (for, while, do-while, goto, pointer arithmetic).
// Cleanest readable version kept below.

#include "../../include/game_globals.h"

struct BuildingLot {
    int typeID;      // +0x00
    unsigned char status; // +0x04
};

class TribeInformationAIModule {
public:
    char gap_00[0x1F4];
    int maxBuildingLots;      // +0x1F4
    BuildingLot* buildingLots; // +0x1F8

    BuildingLot* availableLot(int typeID);
};

BuildingLot* TribeInformationAIModule::availableLot(int typeID) {
    int i = 0;
    int max = this->maxBuildingLots;
    if (max <= 0) {
        return 0;
    }
    BuildingLot* cur = this->buildingLots;
    do {
        if (cur->typeID == typeID && cur->status == 0) {
            return this->buildingLots + i;
        }
        i++;
        cur++;
    } while (i < max);
    return 0;
}
