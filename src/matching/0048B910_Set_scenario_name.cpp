// RGE_Scenario::scenario_name is a pointer field, so this is a direct copy into the pointed-to buffer.
// Keep the null path explicit so the short-circuit and copy expansion stay aligned with the original bytes.

#include <string.h>

class RGE_Scenario {
public:
    char gap_000[0x1010];
    char* scenario_name;

    void Set_scenario_name(char* param_1);
};

void RGE_Scenario::Set_scenario_name(char* param_1) {
    if (param_1 != 0) {
        strcpy(this->scenario_name, param_1);
        return;
    }

    this->scenario_name[0] = 0;
}
