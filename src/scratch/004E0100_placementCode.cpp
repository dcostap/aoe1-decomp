// attempt 4: explicit slot table + switch so the compiler has the same dense range information as the asm
// blocked: VC5 keeps picking a different table-layout basin than the original two-level switch dispatch; leaving this in scratch rather than forcing it

class TribeInformationAIModule {
public:
    int placementCode(int param_1);
};

static const unsigned char kPlacementCodeSlots[0xE8] = { 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 5, 0, 6, 0, 0, 0, 0, 0, 0, 4, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 8, 5, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5 };

int TribeInformationAIModule::placementCode(int param_1) {
    unsigned char slot;

    if (param_1 < 0x2D || param_1 > 0x114) {
        return 5;
    }
    slot = kPlacementCodeSlots[param_1 - 0x2D];
    switch (slot) {
    case 1:
        return 7;
    case 2:
        return 8;
    case 3:
        return 2;
    case 4:
        return 3;
    case 5:
        return 6;
    case 6:
        return 4;
    case 7:
        return 1;
    case 8:
        return 9;
    default:
        return 5;
    }
}
