#pragma once
#include "common.h"
#include "RGE_Scenario.h"
#include "Player_Start_Info.h"
#include "Victory_StartInfo.h"
#include "SP_Victory_Info.h"
#include "Friendliness.h"

class T_Scenario : public RGE_Scenario {
public:
    T_Scenario(int param_1, RGE_Game_World* param_2);
    T_Scenario(RGE_Game_World* param_1);

    // Virtuals (best-effort)
    virtual RGE_Static_Object* get_object_pointer(int param_1); // vt[0] (0x0)
    virtual ~T_Scenario(); // vt[1] (0x4)
    virtual void rehook(); // vt[2] (0x8)
    virtual void save(int param_1); // vt[3] (0xC)

    Player_Start_Info player_info[16];
    Victory_StartInfo victory;
    SP_Victory_Info sp_victory[16][12];
    Friendliness Opponent[16];
    int AlliedVictory[16];
    int victory_all_flag;
    int is_multi_player_flag;
    int which_player;
    int DisabledTechnology[16][20];
    int ScenarioOptions[3];
    int PlayerAge[16];
    int mp_victory_type;
    int victory_score;
    int victory_time;
};
static_assert(sizeof(T_Scenario) == 0x514C, "Size mismatch");
