#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x50F4];
    int arr_[1];
    void SetScenarioOption(int i, int v);
};
#endif

void T_Scenario::SetScenarioOption(int i, int v) {
    this->ScenarioOptions[i] = v;
}
