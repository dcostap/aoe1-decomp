// 0048BA60 RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3)
// Source: scenario.cpp lines 535-542
// Size: 107 bytes, 41 asm lines

// RGE_Scenario::Set_BuildList copies a string via strlen + memcpy
// (generating repne scasb + rep movsd/movsb), then conditionally sets
// byte at position strlen-4 to 0 if param_3 == 1.
//
// 4 attempts. The REP-string instructions ARE generated correctly.
// Remaining diff (85%): VC5 scheduling. The original computes
// &BuildList[param_1] (lea edx, [ecx+eax*4+12C8h]) BEFORE repne scasb,
// and doesn't need to save `this` (uses ecx directly for lea). Our VC5
// saves this in edx (mov edx,ecx) and computes the lea AFTER repne scasb.
// Also: extra `mov esi,ebx` before repne scasb, and an extra dec/inc nop.
// The binary is 128 bytes (vs original 107) due to these additions.
//
// Left in scratch — scheduling basin.

#include <string.h>

class RGE_Scenario {
public:
    char gap_000[0x12C8];
    char* BuildList[16];

    void Set_BuildList(int param_1, char* param_2, int param_3);
};

void RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3) {
    if (param_2 != 0) {
        int len = strlen(param_2);
        memcpy(this->BuildList[param_1], param_2, len + 1);
    } else {
        this->BuildList[param_1][0] = 0;
    }

    if (param_3 == 1) {
        this->BuildList[param_1][strlen(param_2) - 4] = 0;
    }
}
