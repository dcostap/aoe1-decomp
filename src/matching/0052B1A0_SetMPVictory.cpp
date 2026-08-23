#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0xC];
    unsigned char field_C;
    char gap_D[0x5133];
    int field_5140;
    void SetMPVictory(int v);
};
#endif

void T_Scenario::SetMPVictory(int v) {
    this->mp_victory_type = v;
    if (v != 4) this->victory_conquest = 1;
}
