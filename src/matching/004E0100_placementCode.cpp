// VA: 004E0100 TribeInformationAIModule::placementCode(int)
// PDB source: taiinfmd.cpp lines 5740-5768 (101 bytes, 25 asm lines)
// Default flags
// Exact match.
// Attempts:
// - Existing scratch modeled the compiler's apparent two-level dispatch manually with an explicit slot table plus
//   switch. That preserved behavior but forced a different table-layout/check basin (`cmp param,2D`/`cmp param,114`,
//   then a second slot switch) and mismatched badly.
// - Winning shape: use the natural sparse `switch(param_1)` with grouped case labels. VC5 lowers this exact source
//   into the original range-normalized two-level dispatch: `add eax,-0x2D`, unsigned `cmp eax,0xE7`, byte class
//   table, and jump table, with one return block per grouped return value.

class TribeInformationAIModule {
public:
    int placementCode(int param_1);
};

int TribeInformationAIModule::placementCode(int param_1) {
    switch (param_1) {
    case 0x45:
    case 0x4f:
    case 0xc7:
        return 3;
    case 0x48:
    case 0x75:
    case 0x9b:
        return 4;
    case 0x44:
        return 2;
    case 0x67:
        return 1;
    case 0x46:
    case 0x52:
    case 0x54:
    case 0x6e:
    case 0x114:
        return 6;
    case 0x2d:
        return 7;
    case 0x32:
        return 8;
    case 0x6d:
        return 9;
    default:
        return 5;
    }
}
