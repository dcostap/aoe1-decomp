#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    char gap_0[0x47A8];
    int arr_[256];
    void InitializeFriendlinessValues();
};
#endif

void T_Scenario::InitializeFriendlinessValues() {
    for (int i = 0; i < 256; i++) this->Opponent[0].Attitude[i] = 3;
}
