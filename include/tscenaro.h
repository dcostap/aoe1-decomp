#ifndef AOE1_TSCENARO_H
#define AOE1_TSCENARO_H

#include "scenario.h"

typedef unsigned char uchar;

extern double g_scenario_victory_zero_coordinate;

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
    virtual RGE_Static_Object* get_object_pointer(int obj_ID);

  public:
    virtual void rehook();
    virtual void save(int outfile);

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

    T_Scenario(RGE_Game_World* w);
    T_Scenario(int infile, RGE_Game_World* w);

    void ClearSPVictoryCondition(int which);
    int GetDisabledTechnology(int PlayerId, int which);
    int GetMPVictory();
    int GetPlayerAge(int which);
    int GetPlayerAlliedVictory(int which);
    int GetSPAllFlag(int VicID);
    int GetSPAmount(int VicID);
    int GetSPAttribType(int VicID);
    RGE_Static_Object* GetSPDestObjectID(int VicID);
    RGE_Static_Object* GetSPObject(int VicID);
    int GetSPObjectType(int VicID);
    int GetSPPlayerID(int VicID);
    void GetSPRectangle(int VicID, float* x1, float* y1, float* x2, float* y2);
    int GetSPVictoryType(int VicID);
    int GetSPWhich();
    int GetScenarioOption(int option);
    int GetVictoryScore();
    int GetVictoryTime();
    int Get_Multi_Artifacts();
    int Get_Multi_Conquest();
    int Get_Multi_Discoveries();
    int Get_Multi_Exploration();
    int Get_Multi_Gold();
    int Get_Multi_Ruins();
    int Get_player_Food(int which);
    int Get_player_Gold(int which);
    Player_Start_Info* Get_player_Info(int which);
    int Get_player_Stone(int which);
    int Get_player_Wood(int which);
    int Get_player_attitude(int which, int opponent);
    int Get_victory_all_flag();
    void InitializeAIInformation();
    void InitializeFriendlinessValues();
    void InitializePlayerValues();
    void InitializeVictoryValues();
    void Save_victory_conditions_into_players(int SaveAttributes);
    void SetDisabledTechnology(int PlayerId, int which, int tf);
    void SetMPVictory(int i);
    void SetPlayerAge(int which, int val);
    void SetPlayerAlliedVictory(int which, int OnOff);
    void SetSPAllFlag(int VicID, int AllFlag);
    void SetSPAmount(int VicID, int Amount);
    void SetSPAttribType(int VicID, int AttribType);
    void SetSPDestObjectID(int VicID, RGE_Static_Object* dest_obj);
    void SetSPObject(int VicID, RGE_Static_Object* obj);
    void SetSPObjectType(int VicID, int ObjType);
    void SetSPPlayerID(int VicID, int PlayerID);
    void SetSPRectangle(int VicID, float x1, float y1, float x2, float y2);
    void SetSPVictoryType(int VicID, int VictoryType);
    void SetSPWhich(int i);
    void SetScenarioOption(int option, int value);
    void SetVictoryScore(int i);
    void SetVictoryTime(int i);
    void Set_Multi_Artifacts(int a);
    void Set_Multi_Conquest(int c);
    void Set_Multi_Discoveries(int d);
    void Set_Multi_Exploration(int e);
    void Set_Multi_Gold(int g);
    void Set_Multi_Ruins(int r);
    void Set_player_Food(int which, int f);
    void Set_player_Gold(int which, int g);
    void Set_player_Info(int which, Player_Start_Info* i);
    void Set_player_Stone(int which, int s);
    void Set_player_Wood(int which, int w);
    void Set_player_attitude(int which, int opponent, int attitude);
    void Set_victory_all_flag(int i);
    int any_sp_victory();
    void set_player_tech(TRIBE_Player* player);
    void update();

  private:
    void ClearDisabledTechnologies();
    void SaveAttributesIntoPlayers();
    int get_object_ID(RGE_Static_Object* obj);
    void WriteDisabledTechnologiesToMainSystem();
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header {
  public:
    int any_sp_victory;
    int active_player_count;

    TRIBE_Scenario_Header(T_Scenario* scenario_info);
    TRIBE_Scenario_Header(int infile);
    virtual long get_size();
    virtual void save(int outfile);
};

typedef char t_scenario_size_check[(sizeof(T_Scenario) == 0x514C) ? 1 : -1];

#endif
