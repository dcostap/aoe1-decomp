// 004E0510 TribeInformationAIModule::availableLot
// PDB: taiinfmd.cpp:5873-5879, 71 bytes
// public BuildingLot* __thiscall availableLot(int)
// ret 4 (1 param)
//
// STATUS: 36.6% positional diff (26/71 bytes). Register allocation matches original
// (esi=max, ecx=base, edi=typeID, edx=i) but loop-bottom structure differs:
//   Original: jl loop      (backward on true, fall-through on false)
//   Rebuilt:  jge exit; jmp loop  (forward on false, backward jump)
//
// Attempts:
//   1 (original): do { } while (i < max) - right registers, wrong loop form (jge; jmp)
//   2: nested ifs (no &&) - registers changed (edx=max, ecx=i)
//   3: goto-based loop - same as 2
//   4: removed include - same as 2
//   5: while (i < max) - right loop form (jl!) but wrong registers + redundant entry check
//   6: while (i < max) with original decl order - wrong registers, redundant check
//   7: while (i < max) with game_globals.h - wrong registers from windows.h include
//
// The loop structure (jl vs jge;jmp) is a VC5 optimization choice that switches
// between do-while and while loop forms. do-while gives correct regs but jge;jmp;
// while gives jl but wrong regs. Likely TU context (taiinfmd.cpp) affects this.

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

BuildingLot* TribeInformationAIModule::availableLot(int typeID) {
    int max = this->maxBuildingLots;
    if (max <= 0) {
        return 0;
    }
    BuildingLot* cur = this->buildingLots;
    int i = 0;
    do {
        if (cur->typeID == typeID && cur->status == 0) {
            return this->buildingLots + i;
        }
        i++;
        cur++;
    } while (i < max);
    return 0;
}
