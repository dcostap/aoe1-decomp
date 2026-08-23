#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_00[0x4BF4];
    int DisabledTechnology[64][20];

    int GetDisabledTechnology(int player, int index);
};
#endif

int T_Scenario::GetDisabledTechnology(int player, int index) {
    return this->DisabledTechnology[player][index];
}
