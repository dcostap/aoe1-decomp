#include "../../include/tscenaro_context.h"

#if 0
struct SP_Victory_Info {
    int ObjectType;
    int AllFlag;
    int PlayerID;
    int gap_0C[5];
    int VictoryType;
    int Amount;
    int AttribType;
    int Object;
    int DestObjectID;
    int gap_34[2];
};

class T_Scenario {
public:
    char gap_0[0x1AA8];
    SP_Victory_Info sp_victory[16][12];
    char gap_mid[0x4BF0 - 0x1AA8 - sizeof(SP_Victory_Info) * 16 * 12];
    int which_player;

    int GetSPVictoryType(int sp_index);
};
#endif

int T_Scenario::GetSPVictoryType(int sp_index) {
    return this->sp_victory[this->which_player][sp_index].VictoryType;
}
