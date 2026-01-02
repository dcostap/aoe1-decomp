#pragma once
#include "../common.h"

class T_Scenario : public RGE_Scenario {
public:
    Player_Start_Info player_info[16];       // 0x1990
    Victory_StartInfo victory;               // 0x1A90
    SP_Victory_Info* sp_victory[16];         // 0x1AA8
    Friendliness Opponent[16];               // 0x47A8
    int AlliedVictory[16];                   // 0x4BA8
    int victory_all_flag;                    // 0x4BE8
    int is_multi_player_flag;                // 0x4BEC
    int which_player;                        // 0x4BF0
    int* DisabledTechnology[16];             // 0x4BF4
    int ScenarioOptions[3];                  // 0x50F4
    int PlayerAge[16];                       // 0x5100
    int mp_victory_type;                     // 0x5140
    int victory_score;                       // 0x5144
    int victory_time;                        // 0x5148

    T_Scenario(RGE_Game_World* param_1);
    virtual ~T_Scenario();
    T_Scenario(int param_1, RGE_Game_World* param_2);
    virtual void save(int param_1);
    virtual void InitializePlayerValues();
    virtual void ClearDisabledTechnologies();
    virtual void InitializeAIInformation();
    virtual void Set_victory_all_flag(int param_1);
    virtual int Get_victory_all_flag();
    virtual void SetMPVictory(int param_1);
    virtual int GetMPVictory();
    virtual void SetVictoryScore(int param_1);
    virtual int GetVictoryScore();
    virtual void SetVictoryTime(int param_1);
    virtual int GetVictoryTime();
    virtual void SetSPWhich(int param_1);
    virtual int GetSPWhich();
    virtual void InitializeVictoryValues();
    virtual void ClearSPVictoryCondition(int param_1);
    virtual void InitializeFriendlinessValues();
    virtual void Set_player_attitude(int param_1, int param_2, int param_3);
    virtual int Get_player_attitude(int param_1, int param_2);
    virtual void Set_player_Gold(int param_1, int param_2);
    virtual void Set_player_Wood(int param_1, int param_2);
    virtual void Set_player_Food(int param_1, int param_2);
    virtual void Set_player_Stone(int param_1, int param_2);
    virtual void Set_player_Info(int param_1, Player_Start_Info* param_2);
    virtual void Set_Multi_Conquest(int param_1);
    virtual void Set_Multi_Ruins(int param_1);
    virtual void Set_Multi_Artifacts(int param_1);
    virtual void Set_Multi_Discoveries(int param_1);
    virtual void Set_Multi_Exploration(int param_1);
    virtual void Set_Multi_Gold(int param_1);
    virtual void SetSPRectangle(int param_1, float param_2, float param_3, float param_4, float param_5);
    virtual void SetSPObjectType(int param_1, int param_2);
    virtual void SetSPPlayerID(int param_1, int param_2);
    virtual void SetSPAllFlag(int param_1, int param_2);
    virtual void SetSPAttribType(int param_1, int param_2);
    virtual void SetSPVictoryType(int param_1, int param_2);
    virtual void SetSPObject(int param_1, RGE_Static_Object* param_2);
    virtual void SetSPDestObjectID(int param_1, RGE_Static_Object* param_2);
    virtual void SetSPAmount(int param_1, int param_2);
    virtual void SetPlayerAlliedVictory(int param_1, int param_2);
    virtual void SetDisabledTechnology(int param_1, int param_2, int param_3);
    virtual void SetScenarioOption(int param_1, int param_2);
    virtual void SetPlayerAge(int param_1, int param_2);
    virtual int Get_player_Gold(int param_1);
    virtual int Get_player_Wood(int param_1);
    virtual int Get_player_Food(int param_1);
    virtual int Get_player_Stone(int param_1);
    virtual Player_Start_Info* Get_player_Info(int param_1);
    virtual int Get_Multi_Conquest();
    virtual int Get_Multi_Ruins();
    virtual int Get_Multi_Artifacts();
    virtual int Get_Multi_Discoveries();
    virtual int Get_Multi_Exploration();
    virtual int Get_Multi_Gold();
    virtual void GetSPRectangle(int param_1, float* param_2, float* param_3, float* param_4, float* param_5);
    virtual int GetSPObjectType(int param_1);
    virtual int GetSPPlayerID(int param_1);
    virtual int GetSPAllFlag(int param_1);
    virtual int GetSPAttribType(int param_1);
    virtual int GetSPAmount(int param_1);
    virtual int GetSPVictoryType(int param_1);
    virtual RGE_Static_Object* GetSPDestObjectID(int param_1);
    virtual RGE_Static_Object* GetSPObject(int param_1);
    virtual int GetPlayerAlliedVictory(int param_1);
    virtual int GetDisabledTechnology(int param_1, int param_2);
    virtual int GetScenarioOption(int param_1);
    virtual int GetPlayerAge(int param_1);
    virtual void update();
    virtual void SaveAttributesIntoPlayers();
    virtual void Save_victory_conditions_into_players(int param_1);
    virtual void rehook();
    virtual RGE_Static_Object* get_object_pointer(int param_1);
    virtual int get_object_ID(RGE_Static_Object* param_1);
    virtual void WriteDisabledTechnologiesToMainSystem();
    virtual int any_sp_victory();
    virtual void set_player_tech(TRIBE_Player* param_1);
};

static_assert(sizeof(T_Scenario) == 0x514C, "T_Scenario Size Mismatch");
static_assert(offsetof(T_Scenario, victory_time) == 0x5148, "T_Scenario Offset Mismatch");

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;                      // 0x14
    int active_player_count;                 // 0x18

    TRIBE_Scenario_Header(T_Scenario* param_1);
    TRIBE_Scenario_Header(int param_1);
    virtual long get_size();
    virtual void save(int param_1);
};

static_assert(sizeof(TRIBE_Scenario_Header) == 0x1C, "TRIBE_Scenario_Header Size Mismatch");
static_assert(offsetof(TRIBE_Scenario_Header, active_player_count) == 0x18, "TRIBE_Scenario_Header Offset Mismatch");

