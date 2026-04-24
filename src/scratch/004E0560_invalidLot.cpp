// Function: TribeInformationAIModule::invalidLot
// VA: 004E0560
// Source: taiinfmd.cpp
//
// STATUS: Cannot match exactly due to compiler register allocation differences
//
// ISSUE: The original compiler (older MSVC) made different register choices:
// - Original: ESI = maxBuildingLots, EDI = typeID, BL = x, CL = y
// - Modern MSVC: EDX = maxBuildingLots, EBP = typeID, BL = x, CL = y
//
// The logic is identical, but MSVC uses EBP as a general purpose register
// while the original didn't use EBP at all.
//
// This is a fundamental compiler version difference that can't be easily
// worked around without inline assembly (which is forbidden).
//
// Leaving in scratch due to this toolchain limitation.
// 
// This is a simple array search function that checks if a building lot
// with specific properties exists in the buildingLots array.

class BuildingLot {
public:
    int typeID;      // offset 0
    char status;     // offset 4
    char x;          // offset 5
    char y;          // offset 6
    char pad;        // offset 7 (padding to 8 bytes)
};

class TribeInformationAIModule {
public:
    char pad_000[0x1F4];
    int maxBuildingLots;    // offset 0x1F4
    BuildingLot* buildingLots; // offset 0x1F8
    
    int invalidLot(int typeID, unsigned char x, unsigned char y);
};

int TribeInformationAIModule::invalidLot(int typeID, unsigned char x, unsigned char y) {
    // Original uses EDI for typeID, but MSVC is using EBP
    // Let me try to force EDI usage by accessing it early
    
    int maxLots = this->maxBuildingLots;
    if (maxLots <= 0) {
        return 0;
    }
    
    BuildingLot* lot = this->buildingLots;
    int counter = 0;
    
    // Force EDI to be used for typeID by assigning it first
    register int typeID_copy = typeID;
    
    while (counter < maxLots) {
        if (lot->typeID == typeID_copy &&
            lot->status == 2 &&
            lot->x == x &&
            lot->y == y) {
            return 1;
        }
        counter++;
        lot++;
    }
    
    return 0;
}
