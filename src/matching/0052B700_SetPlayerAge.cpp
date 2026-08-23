#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x5100];
    int arr_[1];
    void SetPlayerAge(int i, int v);
};
#endif

void T_Scenario::SetPlayerAge(int i, int v) {
    this->PlayerAge[i] = v;
}
