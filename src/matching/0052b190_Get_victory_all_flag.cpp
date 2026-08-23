#include "../../include/tscenaro_context.h"

#if 0
class T_Scenario {
public:
    virtual ~T_Scenario();
    char gap_04[0x1A8C];
    int MP_Conquest_;
    int MP_Ruins_;
    int MP_Artifacts_;
    int MP_Discoveries_;
    int MP_Exploration_;
    int MP_Gold_;
    char gap_1AA8[0x3100];
    int AlliedVictory_[16];
    int victory_all_flag_;
    char gap_4BEC[4];
    int which_player_;
    char gap_4BF4[0x500];
    int ScenarioOptions_[3];
    int PlayerAge_[16];
    int mp_victory_type_;
    int victory_score_;
    int victory_time_;

    int Get_victory_all_flag();
};
#endif

int T_Scenario::Get_victory_all_flag() {
    return this->victory_all_flag;
}
