#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x4BF4];
    int arr_[320];
    void ClearDisabledTechnologies();
};
#endif

void T_Scenario::ClearDisabledTechnologies() {
    for (int i = 0; i < 320; i++) this->DisabledTechnology[0][i] = 1;
}
