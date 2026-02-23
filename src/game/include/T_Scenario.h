#pragma once
#include "common.h"
#include "RGE_Scenario.h"
#include "Player_Start_Info.h"
#include "Victory_StartInfo.h"
#include "SP_Victory_Info.h"
#include "Friendliness.h"

class TRIBE_Player;

class T_Scenario : public RGE_Scenario {
public:
    T_Scenario(int param_1, RGE_Game_World* param_2);
    T_Scenario(RGE_Game_World* param_1);

    // Virtuals (best-effort)
    virtual RGE_Static_Object* get_object_pointer(int param_1); // vt[0] (0x0)
    virtual ~T_Scenario(); // vt[1] (0x4)
    virtual void rehook(); // vt[2] (0x8)
    virtual void save(int param_1); // vt[3] (0xC)

    void InitializePlayerValues();
    void ClearDisabledTechnologies();
    void InitializeAIInformation();
    void InitializeVictoryValues();
    void ClearSPVictoryCondition(int param_1);
    void InitializeFriendlinessValues();
    void Set_player_attitude(int param_1, int param_2, int param_3);
    int Get_player_attitude(int param_1, int param_2);
    void Set_player_Gold(int param_1, int param_2);
    void Set_player_Wood(int param_1, int param_2);
    void Set_player_Food(int param_1, int param_2);
    void Set_player_Stone(int param_1, int param_2);
    void Set_player_Info(int param_1, Player_Start_Info* param_2);
    void Set_victory_all_flag(int param_1);
    int Get_victory_all_flag();
    void SetMPVictory(int param_1);
    int GetMPVictory();
    void SetVictoryScore(int param_1);
    int GetVictoryScore();
    void SetVictoryTime(int param_1);
    int GetVictoryTime();
    void Set_Multi_Conquest(int param_1);
    void Set_Multi_Ruins(int param_1);
    void Set_Multi_Artifacts(int param_1);
    void Set_Multi_Discoveries(int param_1);
    void Set_Multi_Exploration(int param_1);
    void Set_Multi_Gold(int param_1);
    void SetSPWhich(int param_1);
    int GetSPWhich();
    void SetSPRectangle(int param_1, float param_2, float param_3, float param_4, float param_5);
    void SetSPObjectType(int param_1, int param_2);
    void SetSPPlayerID(int param_1, int param_2);
    void SetSPAllFlag(int param_1, int param_2);
    void SetSPAttribType(int param_1, int param_2);
    void SetSPVictoryType(int param_1, int param_2);
    void SetSPObject(int param_1, RGE_Static_Object* param_2);
    void SetSPDestObjectID(int param_1, RGE_Static_Object* param_2);
    void SetSPAmount(int param_1, int param_2);
    void SetPlayerAlliedVictory(int param_1, int param_2);
    void SetDisabledTechnology(int param_1, int param_2, int param_3);
    void SetScenarioOption(int param_1, int param_2);
    void SetPlayerAge(int param_1, int param_2);
    int Get_player_Gold(int param_1);
    int Get_player_Wood(int param_1);
    int Get_player_Food(int param_1);
    int Get_player_Stone(int param_1);
    Player_Start_Info* Get_player_Info(int param_1);
    int Get_Multi_Conquest();
    int Get_Multi_Ruins();
    int Get_Multi_Artifacts();
    int Get_Multi_Discoveries();
    int Get_Multi_Exploration();
    int Get_Multi_Gold();
    void GetSPRectangle(int param_1, float* param_2, float* param_3, float* param_4, float* param_5);
    int GetSPObjectType(int param_1);
    int GetSPPlayerID(int param_1);
    int GetSPAllFlag(int param_1);
    int GetSPAttribType(int param_1);
    int GetSPAmount(int param_1);
    int GetSPVictoryType(int param_1);
    RGE_Static_Object* GetSPDestObjectID(int param_1);
    RGE_Static_Object* GetSPObject(int param_1);
    int GetPlayerAlliedVictory(int param_1);
    int GetDisabledTechnology(int param_1, int param_2);
    int GetScenarioOption(int param_1);
    int GetPlayerAge(int param_1);
    void update();
    void Save_victory_conditions_into_players(int param_1);
    void WriteDisabledTechnologiesToMainSystem();
    int any_sp_victory();
    void set_player_tech(TRIBE_Player* param_1);

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

private:
    int get_object_ID(RGE_Static_Object* param_1);
};
static_assert(sizeof(T_Scenario) == 0x514C, "Size mismatch");
