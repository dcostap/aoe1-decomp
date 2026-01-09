#pragma once
#include "common.h"

class RGE_Scenario : public RGE_Timeline {
public:
    char* scenario_name;                     // 0x1010
    char* description;                       // 0x1014
    char* hints;                             // 0x1018
    char* win_message;                       // 0x101C
    char* loss_message;                      // 0x1020
    char* historicle_notes;                  // 0x1024
    char TempText1[224];                     // 0x1028
    char TempText2[224];                     // 0x1108
    char TempText3[224];                     // 0x11E8
    char* BuildList[16];                     // 0x12C8
    char* CityPlan[16];                      // 0x1308
    char* AiRules[16];                       // 0x1348
    uchar* BuildListFile[16];                // 0x1388
    uchar* CityPlanFile[16];                 // 0x13C8
    uchar* AiRulesFile[16];                  // 0x1408
    int BuildListFileSize[16];               // 0x1448
    int CityPlanFileSize[16];                // 0x1488
    int AiRulesFileSize[16];                 // 0x14C8
    char Cine_PreGame[224];                  // 0x1508
    char Cine_Victory[224];                  // 0x15E8
    char Cine_Loss[224];                     // 0x16C8
    char Mission_Bmp[224];                   // 0x17A8
    float Version;                           // 0x1888
    int PlayerPosture[16];                   // 0x188C
    int PlType[16];                          // 0x18CC
    int PlCivilization[16];                  // 0x190C
    int PlActive[16];                        // 0x194C
    TPicture* mission_picture;               // 0x198C

    virtual RGE_Static_Object* get_object_pointer(int param_1); // vt0[0]+0x0=0x48B580
    virtual void rehook();                                  // vt0[2]+0x8=0x48B590
    virtual void save(int param_1);                         // vt0[3]+0xC=0x48C3E0
    RGE_Scenario(RGE_Game_World* param_1);
    RGE_Scenario(int param_1, RGE_Game_World* param_2);
    ~RGE_Scenario();
    void InitializeTextValues();
    void Set_scenario_name(char* param_1);
    void Set_description(char* param_1);
    void Set_Cine_PreGame(char* param_1);
    void Set_Cine_Victory(char* param_1);
    void Set_Cine_Loss(char* param_1);
    void Set_Mission_Bmp(char* param_1);
    void Set_BuildList(int param_1, char* param_2, int param_3);
    void Set_CityPlan(int param_1, char* param_2, int param_3);
    void Set_player_AI(int param_1, char* param_2, int param_3);
    void Set_Version(float param_1);
    void Set_player_Type(int param_1, int param_2);
    void Set_player_Civ(int param_1, int param_2);
    void Set_player_Active(int param_1, int param_2);
    void SetPlayerName(int param_1, char* param_2);
    char* Get_scenario_name();
    char* Get_description();
    char* Get_Cine_PreGame();
    char* Get_Cine_Victory();
    char* Get_Cine_Loss();
    char* Get_Mission_Bmp();
    char* Get_BuildList(int param_1, int param_2);
    char* Get_CityPlan(int param_1, int param_2);
    float Get_Version();
    char* Get_player_AI(int param_1, int param_2);
    int GetPlayerPosture(int param_1);
    char* GetPlayerName(int param_1);
    int Get_player_Type(int param_1);
    int Get_player_Civ(int param_1);
    int Get_player_Active(int param_1);
    void update();
    int active_player_count();
    int any_player_count();
    int computer_player_count();
    void Set_conquest_victory(uchar param_1);
    uchar Get_conquest_victory();
    void add_description(char* param_1);
    void Set_message(char* param_1, long param_2);
    char* Get_message(long param_1);
};

static_assert(sizeof(RGE_Scenario) == 0x1990, "RGE_Scenario Size Mismatch");

class RGE_Scenario_Header {
public:
    // [omitted] vfptr @ 0x0 ('_padding_')
    int error_code;                          // 0x4
    long version;                            // 0x8
    ulong checksum;                          // 0xC
    char* description;                       // 0x10

    virtual long get_size();                                // vt0[0]+0x0=0x48ACA0
    virtual void save(int param_1);                         // vt0[1]+0x4=0x48ACC0
    RGE_Scenario_Header(RGE_Scenario* param_1);
    RGE_Scenario_Header(int param_1);
    ~RGE_Scenario_Header();
};

static_assert(sizeof(RGE_Scenario_Header) == 0x14, "RGE_Scenario_Header Size Mismatch");

