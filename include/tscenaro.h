#ifndef AOE1_TSCENARO_H
#define AOE1_TSCENARO_H

// Declarations for the tscenaro.cpp source module.

#include "scenario.h"

typedef unsigned char uchar;

extern double DAT_00577330;

class TRIBE_Player;

struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

struct Victory_Info {
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};

struct Friendliness {
    int Attitude[16];
};

struct SP_Victory_Info {
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    void* obj;
    void* dest_obj;
};

class T_Scenario : public RGE_Scenario {
private:
    virtual RGE_Static_Object* get_object_pointer(int);

public:
    virtual ~T_Scenario();
    virtual void rehook();
    virtual void save(int);

    Player_Start_Info player_info[16];
    Victory_Info victory;
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

    T_Scenario(RGE_Game_World*);
    T_Scenario(int, RGE_Game_World*);

    void ClearSPVictoryCondition(int);
    int GetDisabledTechnology(int, int);
    int GetMPVictory();
    int GetPlayerAge(int);
    int GetPlayerAlliedVictory(int);
    int GetSPAllFlag(int);
    int GetSPAmount(int);
    int GetSPAttribType(int);
    RGE_Static_Object* GetSPDestObjectID(int);
    RGE_Static_Object* GetSPObject(int);
    int GetSPObjectType(int);
    int GetSPPlayerID(int);
    void GetSPRectangle(int, float*, float*, float*, float*);
    int GetSPVictoryType(int);
    int GetSPWhich();
    int GetScenarioOption(int);
    int GetVictoryScore();
    int GetVictoryTime();
    int Get_Multi_Artifacts();
    int Get_Multi_Conquest();
    int Get_Multi_Discoveries();
    int Get_Multi_Exploration();
    int Get_Multi_Gold();
    int Get_Multi_Ruins();
    int Get_player_Food(int);
    int Get_player_Gold(int);
    Player_Start_Info* Get_player_Info(int);
    int Get_player_Stone(int);
    int Get_player_Wood(int);
    int Get_player_attitude(int, int);
    int Get_victory_all_flag();
    void InitializeAIInformation();
    void InitializeFriendlinessValues();
    void InitializePlayerValues();
    void InitializeVictoryValues();
    void Save_victory_conditions_into_players(int);
    void SetDisabledTechnology(int, int, int);
    void SetMPVictory(int);
    void SetPlayerAge(int, int);
    void SetPlayerAlliedVictory(int, int);
    void SetSPAllFlag(int, int);
    void SetSPAmount(int, int);
    void SetSPAttribType(int, int);
    void SetSPDestObjectID(int, RGE_Static_Object*);
    void SetSPObject(int, RGE_Static_Object*);
    void SetSPObjectType(int, int);
    void SetSPPlayerID(int, int);
    void SetSPRectangle(int, float, float, float, float);
    void SetSPVictoryType(int, int);
    void SetSPWhich(int);
    void SetScenarioOption(int, int);
    void SetVictoryScore(int);
    void SetVictoryTime(int);
    void Set_Multi_Artifacts(int);
    void Set_Multi_Conquest(int);
    void Set_Multi_Discoveries(int);
    void Set_Multi_Exploration(int);
    void Set_Multi_Gold(int);
    void Set_Multi_Ruins(int);
    void Set_player_Food(int, int);
    void Set_player_Gold(int, int);
    void Set_player_Info(int, Player_Start_Info*);
    void Set_player_Stone(int, int);
    void Set_player_Wood(int, int);
    void Set_player_attitude(int, int, int);
    void Set_victory_all_flag(int);
    int any_sp_victory();
    void set_player_tech(TRIBE_Player*);
    void update();

private:
    void ClearDisabledTechnologies();
    void SaveAttributesIntoPlayers();
    int get_object_ID(RGE_Static_Object*);
    void WriteDisabledTechnologiesToMainSystem();
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(T_Scenario*);
    TRIBE_Scenario_Header(int);
    virtual long get_size();
    virtual void save(int);
};

typedef char t_scenario_size_check[
    (sizeof(T_Scenario) == 0x514C) ? 1 : -1];

#endif
