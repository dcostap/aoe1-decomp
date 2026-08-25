// VA: 004E0560 TribeInformationAIModule::invalidLot
// PDB source: taiinfmd.cpp lines 5884-5892 (88 bytes, 38 asm lines)
// Default flags
// Exact match: direct indexed `this->buildingLots[i]` with explicit positive guard.
// Attempts:
// - Initial scratch natural pointer-walk loop matched behavior/registers but VC5 emitted a redundant pre-loop
//   `test esi,esi` for `while(i<count)` or, in do/while/goto forms, collapsed false/true return tails and
//   used a `jge`+`jmp` loop shape.
// - Tried positive guard + while(1) bottom continue/return, explicit labels, do loop direct returns,
//   simple for with pointer, goto into while body, and explicit bottom positive goto: none matched branch layout.
// - Tried /O1 briefly; wrong function-size/codegen family; flag removed.
// - Winning try: direct indexed array access (`this->buildingLots[i].field`) instead of carried pointer local.
//   VC5 keeps the loaded array base in eax, counter in edx, emits the single top guard and original bottom `jl`.

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
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
#endif

#endif
int TribeInformationAIModule::invalidLot(int typeID, unsigned char x, unsigned char y) {
    int count = this->maxBuildingLots;
    int i = 0;
    if (count <= 0) return 0;
    for (; i < count; i++) {
        if (this->buildingLots[i].typeID == typeID && this->buildingLots[i].status == 2 && this->buildingLots[i].x == x && this->buildingLots[i].y == y) {
            return 1;
        }
    }
    return 0;
}
