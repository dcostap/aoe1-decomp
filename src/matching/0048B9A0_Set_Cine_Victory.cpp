// VC5 emitted an inline strcpy/strlen-style expansion here, so the natural source spelling is the direct copy.
// Keep the null path explicit so the short-circuit and copy expansion stay aligned with the original bytes.

#include <string.h>

#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_000[0x15E8];
    char Cine_Victory[224];

    void Set_Cine_Victory(char* param_1);
};
#endif

void RGE_Scenario::Set_Cine_Victory(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->Cine_Victory, param_1);
        return;
    }

    this->Cine_Victory[0] = 0;
}
