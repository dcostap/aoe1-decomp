#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x4BF0];
    int field_4BF0;
    void SetSPWhich(int v);
};
#endif

void T_Scenario::SetSPWhich(int v) {
    if (v < 0) v = 0;
    if (v > 16) v = 15;
    this->which_player = v;
}
