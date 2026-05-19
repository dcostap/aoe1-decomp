// 004E0470 TribeInformationAIModule::removeLot (154B)
// STAUS: PAUSED — proposed accepted_drift
// Remaining drift: 94 bytes positional / 19 bytes edit (12.3%)
// VC5 loop reversal optimization: do { } while (idx < max) → jge exit; jmp loop
// instead of jl loop; fallthrough. 2-byte expansion shifts all subsequent code.
// All comparisons, stores, and control flow match logically.
// Attempts: 15+ across all documented axes
// - All loop forms: for, do-while, while(1), for(;;), goto-based
// - Various condition expressions: idx < max, idx >= max, ++idx, idx++
// - goto patterns (label-based, inverted checks)
// - Pointer iteration styles (indexed, pointer advance)
// - Different stack layouts (struct vs raw fields)
// - All register allocation matched except loop reversal can't be prevented

#include <windows.h>

struct BuildingLot {
    int typeID;         // +0
    unsigned char status;   // +4
    unsigned char x;        // +5
    unsigned char y;        // +6
};

class TribeInformationAIModule {
public:
    char pad_000[0x1F4];
    int maxBuildingLots;            // +0x1F4
    BuildingLot* buildingLots;       // +0x1F8

    void removeLot(int p1, unsigned char p2, unsigned char p3, unsigned char p4);
};

void TribeInformationAIModule::removeLot(int p1, unsigned char p2, unsigned char p3, unsigned char p4)
{
    int idx = 0;
    if (maxBuildingLots <= 0) return;

    BuildingLot* lot = buildingLots;
    goto enter;

loop:
    idx++;
    lot++;
    if (idx >= maxBuildingLots) return;

enter:
    if (lot->typeID == p1 && lot->x == p2 && lot->y == p3)
        goto found;
    goto loop;

found:
    if (p4 != 3) {
        buildingLots[idx].status = p4;
    } else {
        buildingLots[idx].typeID = -1;
        buildingLots[idx].x = 0;
        buildingLots[idx].y = 0;
        buildingLots[idx].status = 3;
    }
}
