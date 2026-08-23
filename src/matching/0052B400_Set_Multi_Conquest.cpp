#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x1A90];
    int MP_Conquest;

    void Set_conquest_victory(int flag);
    void Set_Multi_Conquest(int param);
};
#endif

void T_Scenario::Set_Multi_Conquest(int param) {
    if (param) {
        this->victory.MP_Conquest = 1;
        this->Set_conquest_victory(1);
    } else {
        this->victory.MP_Conquest = 0;
        this->Set_conquest_victory(0);
    }
}
