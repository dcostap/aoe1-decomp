#pragma once
#include "common.h"

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;                      // 0x14
    int active_player_count;                 // 0x18

    virtual long get_size();                                // vt0[0]+0x0=0x52AA70
    virtual void save(int param_1);                         // vt0[1]+0x4=0x52AA80
    TRIBE_Scenario_Header(T_Scenario* param_1);
    TRIBE_Scenario_Header(int param_1);
};

static_assert(sizeof(TRIBE_Scenario_Header) == 0x1C, "TRIBE_Scenario_Header Size Mismatch");

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

    virtual RGE_Static_Object* get_object_pointer(int param_1); // vt0[0]+0x0=0x52C080
    virtual void rehook();                                  // vt0[2]+0x8=0x52C070
    virtual void save(int param_1);                         // vt0[3]+0xC=0x52AF20
    T_Scenario(RGE_Game_World* param_1);
    ~T_Scenario();
    T_Scenario(int param_1, RGE_Game_World* param_2);
    void InitializePlayerValues();
    void ClearDisabledTechnologies();
    void InitializeAIInformation();
    void Set_victory_all_flag(int param_1);
    int Get_victory_all_flag();
    void SetMPVictory(int param_1);
    int GetMPVictory();
    void SetVictoryScore(int param_1);
    int GetVictoryScore();
    void SetVictoryTime(int param_1);
    int GetVictoryTime();
    void SetSPWhich(int param_1);
    int GetSPWhich();
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
    void Set_Multi_Conquest(int param_1);
    void Set_Multi_Ruins(int param_1);
    void Set_Multi_Artifacts(int param_1);
    void Set_Multi_Discoveries(int param_1);
    void Set_Multi_Exploration(int param_1);
    void Set_Multi_Gold(int param_1);
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
    void SaveAttributesIntoPlayers();
    void Save_victory_conditions_into_players(int param_1);
    int get_object_ID(RGE_Static_Object* param_1);
    void WriteDisabledTechnologiesToMainSystem();
    int any_sp_victory();
    void set_player_tech(TRIBE_Player* param_1);
};

static_assert(sizeof(T_Scenario) == 0x514C, "T_Scenario Size Mismatch");

