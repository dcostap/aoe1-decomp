#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x4BA8];
    int arr_[1];
    void SetPlayerAlliedVictory(int i, int v);
};
#endif

void T_Scenario::SetPlayerAlliedVictory(int i, int v) {
    this->AlliedVictory[i] = v;
}
