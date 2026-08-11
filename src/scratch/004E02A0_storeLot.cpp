// VA: 004E02A0 TribeInformationAIModule::storeLot
// PDB: taiinfmd.cpp:5774-5841
// Default flags: /nologo /c /O2 /Oy
//
// Baseline reconstruction: BuildingLot is the proven 8-byte record at +0x1F8;
// the routine scans for an existing lot or a typeID == -1 slot, then doubles
// the lot array and initializes the new slots when no free slot exists.
//
// Attempt log (sa-f4a574e2-r1, 10 meaningful hypotheses):
// - Baseline: canonical typed BuildingLot fields (+0, +4, +5, +6), max/count
//   at +0x1F4, array at +0x1F8, field-wise growth copy, and real VC5 new/delete
//   declarations. 448 emitted bytes, 391 positional diff; calls and frame align.
// - Reversed coordinate equality operands improved the emitted diff to 381 and
//   preserved parameter-byte reloads, but VC5 still chose the opposite cmp
//   encoding and kept the existing-lot return immediately after the scan.
// - Late-label/goto, explicit alternate-arm, explicit returns, saved-base
//   pointer, and donor <windows.h> context probes were codegen duplicates.
// - Negative-disjunction spelling regressed to the baseline group. A natural
//   break plus post-loop existing-lot arm reached exact size and 347 diff, but
//   emitted an extra i/max test absent from the oracle; retained only as
//   diagnostic evidence and restored this simpler source.
// - Raw cursor/decompiler-shaped field plumbing was worse (444 bytes, 391
//   diff), so it is not retained. Remaining blocker is structural: the oracle
//   sends the existing-lot branch to a late handler at 004E044E while default
//   VC5 lowering places that handler immediately after the scan.

#include <stddef.h>

void* operator new(size_t size);
void operator delete(void* ptr);

struct BuildingLot {
    int typeID;                 // +0x00
    unsigned char status;       // +0x04
    unsigned char x;             // +0x05
    unsigned char y;             // +0x06
    unsigned char pad_end;       // +0x07
};

class TribeInformationAIModule {
public:
    char gap_000[0x1F4];
    int maxBuildingLots;         // +0x1F4
    BuildingLot* buildingLots;   // +0x1F8

    void storeLot(int typeID, unsigned char x, unsigned char y,
                 unsigned char built);
};

void TribeInformationAIModule::storeLot(int typeID, unsigned char x,
                                        unsigned char y, unsigned char built)
{
    int freeIndex = -1;
    int i = 0;

    if (this->maxBuildingLots > 0) {
        BuildingLot* lot = this->buildingLots;
        do {
            if (lot->typeID == typeID && lot->x == x && lot->y == y) {
                this->buildingLots[i].status = built;
                return;
            }

            if (freeIndex == -1 && lot->typeID == -1) {
                freeIndex = i;
            }

            ++i;
            ++lot;
        } while (i < this->maxBuildingLots);
    }

    if (freeIndex == -1) {
        BuildingLot* newLots = (BuildingLot*)::operator new(
            this->maxBuildingLots << 4);
        if (newLots != 0) {
            i = 0;
            if (this->maxBuildingLots > 0) {
                do {
                    newLots[i].typeID = this->buildingLots[i].typeID;
                    newLots[i].x = this->buildingLots[i].x;
                    newLots[i].y = this->buildingLots[i].y;
                    newLots[i].status = this->buildingLots[i].status;
                    ++i;
                } while (i < this->maxBuildingLots);
            }

            if (i < this->maxBuildingLots * 2) {
                do {
                    newLots[i].typeID = -1;
                    newLots[i].x = 0;
                    newLots[i].y = 0;
                    newLots[i].status = built;
                    ++i;
                } while (i < this->maxBuildingLots * 2);
            }

            ::operator delete(this->buildingLots);
            this->buildingLots = newLots;

            newLots[this->maxBuildingLots].typeID = typeID;
            this->buildingLots[this->maxBuildingLots].x = x;
            this->buildingLots[this->maxBuildingLots].y = y;
            this->buildingLots[this->maxBuildingLots].status = built;
            this->maxBuildingLots <<= 1;
        }
    } else {
        this->buildingLots[freeIndex].typeID = typeID;
        this->buildingLots[freeIndex].x = x;
        this->buildingLots[freeIndex].y = y;
        this->buildingLots[freeIndex].status = built;
    }
}
