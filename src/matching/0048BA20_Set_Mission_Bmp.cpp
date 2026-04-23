// VC5 emitted the same inline strcpy/strlen-style expansion here as for Set_Cine_Victory, but targeting Mission_Bmp.
// Keep the null path explicit so the short-circuit and copy expansion stay aligned with the original bytes.

#include <string.h>

class RGE_Scenario {
public:
    char gap_000[0x17A8];
    char Mission_Bmp[224];

    void Set_Mission_Bmp(char* param_1);
};

void RGE_Scenario::Set_Mission_Bmp(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->Mission_Bmp, param_1);
        return;
    }

    this->Mission_Bmp[0] = 0;
}
