// 004E0470 TribeInformationAIModule::removeLot
// Source: taiinfmd.cpp lines 5847-5868. 154 bytes. __thiscall, ret 10h.
//
// ATTEMPT LOG:
// 1. First pass (indexed loop, no walking pointer): 98.7% diff, wrong loop structure
// 2. Walking pointer with base saved: 91% diff, redundant bounds check
// 3. Walking pointer, byte offset: 62% diff, char* local broke reg alloc
// 4. Walking pointer, unscaled idx: 5.8% diff, lea+sub scheduling diff
// 5. Byte offset (x_start*24), char* cast: 0% diff for 00486210 (DO NOT REUSE)
// 6. For loop (no explicit if check): 14.3% diff — 3 instr reordered (scheduling)
// 7. Nested if+for: regressed to redundant check
// 8. Parked: remaining diff is VC5 prologue scheduling (buildingLots load moved
//    before test/jle check). Cannot force from C++.

struct BuildingLot {
    int typeID;              // +0
    unsigned char status;    // +4
    unsigned char x;         // +5
    unsigned char y;         // +6
};

class TribeInformationAIModule {
public:
    char gap_00[0x1F4];
    int maxBuildingLots;       // +0x1F4
    BuildingLot* buildingLots; // +0x1F8

    void removeLot(int typeID, unsigned char x, unsigned char y, unsigned char status);
};

void TribeInformationAIModule::removeLot(int typeID, unsigned char x, unsigned char y, unsigned char status) {
    int i = 0;
    int count = this->maxBuildingLots;

    BuildingLot* lots = this->buildingLots;
    BuildingLot* base = lots;
    for (; i < count; i++, lots++) {
        if (lots->typeID == typeID && lots->x == x && lots->y == y) {
            if (status != 3) {
                base[i].status = status;
            } else {
                base[i].typeID = -1;
                this->buildingLots[i].x = 0;
                this->buildingLots[i].y = 0;
                this->buildingLots[i].status = 3;
            }
            return;
        }
    }
}
