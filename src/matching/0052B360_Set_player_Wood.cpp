#include "../../include/tscenaro_context.h"

#if 0
struct Entry_0052B360 {
    char data[16];
};

class T_Scenario {
public:
    char gap_0[0x1994];
    Entry_0052B360 entries_[16];
    void Set_player_Wood(int index, int val);
};
#endif

void T_Scenario::Set_player_Wood(int index, int val) {
    if (index < 0 || index >= 16) return;
    this->player_info[index].Wood = val;
}
