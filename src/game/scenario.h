#pragma once
#include "../common.h"

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

    RGE_Scenario(RGE_Game_World* param_1);
    RGE_Scenario(int param_1, RGE_Game_World* param_2);
    virtual RGE_Static_Object* get_object_pointer(int param_1);
    virtual void rehook();
    virtual ~RGE_Scenario();
    virtual void InitializeTextValues();
    virtual void Set_scenario_name(char* param_1);
    virtual void Set_description(char* param_1);
    virtual void Set_Cine_PreGame(char* param_1);
    virtual void Set_Cine_Victory(char* param_1);
    virtual void Set_Cine_Loss(char* param_1);
    virtual void Set_Mission_Bmp(char* param_1);
    virtual void Set_BuildList(int param_1, char* param_2, int param_3);
    virtual void Set_CityPlan(int param_1, char* param_2, int param_3);
    virtual void Set_player_AI(int param_1, char* param_2, int param_3);
    virtual void Set_Version(float param_1);
    virtual void Set_player_Type(int param_1, int param_2);
    virtual void Set_player_Civ(int param_1, int param_2);
    virtual void Set_player_Active(int param_1, int param_2);
    virtual void SetPlayerName(int param_1, char* param_2);
    virtual char* Get_scenario_name();
    virtual char* Get_description();
    virtual char* Get_Cine_PreGame();
    virtual char* Get_Cine_Victory();
    virtual char* Get_Cine_Loss();
    virtual char* Get_Mission_Bmp();
    virtual char* Get_BuildList(int param_1, int param_2);
    virtual char* Get_CityPlan(int param_1, int param_2);
    virtual float Get_Version();
    virtual char* Get_player_AI(int param_1, int param_2);
    virtual int GetPlayerPosture(int param_1);
    virtual char* GetPlayerName(int param_1);
    virtual int Get_player_Type(int param_1);
    virtual int Get_player_Civ(int param_1);
    virtual int Get_player_Active(int param_1);
    virtual void update();
    virtual void save(int param_1);
    virtual int active_player_count();
    virtual int any_player_count();
    virtual int computer_player_count();
    virtual void Set_conquest_victory(uchar param_1);
    virtual uchar Get_conquest_victory();
    virtual void add_description(char* param_1);
    virtual void Set_message(char* param_1, long param_2);
    virtual char* Get_message(long param_1);
};

static_assert(sizeof(RGE_Scenario) == 0x1990, "RGE_Scenario Size Mismatch");
static_assert(offsetof(RGE_Scenario, mission_picture) == 0x198C, "RGE_Scenario Offset Mismatch");

class RGE_Scenario_Header {
public:
    int error_code;                          // 0x4
    long version;                            // 0x8
    ulong checksum;                          // 0xC
    char* description;                       // 0x10

    RGE_Scenario_Header(RGE_Scenario* param_1);
    RGE_Scenario_Header(int param_1);
    virtual ~RGE_Scenario_Header();
    virtual long get_size();
    virtual void save(int param_1);
};

static_assert(sizeof(RGE_Scenario_Header) == 0x14, "RGE_Scenario_Header Size Mismatch");
static_assert(offsetof(RGE_Scenario_Header, description) == 0x10, "RGE_Scenario_Header Offset Mismatch");

RGE_Static_Object* RGE_Scenario::get_object_pointer(int param_1) {
    /* TODO: Stub */
//                              RGE_Static_Object * __thiscall get_object_pointer(RGE_Scenario * thi
//              RGE_Static_Obj    EAX:4          <RETURN>
//              RGE_Scenario *    ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?get_object_pointer@RGE_Scenario@@MAEPAVRGE_Static_Object@@  XREF[1]:     00572128(*)
//                               RGE_Scenario::get_object_pointer
//                              scenario.h:59 (5)
//         0048b580     XOR        EAX,EAX
//         0048b582     RET        0x4
//         0048b585     ??         90h
//         0048b586     NOP
//         0048b587     NOP
//         0048b588     NOP
//         0048b589     NOP
//         0048b58a     NOP
//         0048b58b     NOP
//         0048b58c     NOP
//         0048b58d     NOP
//         0048b58e     NOP
//         0048b58f     NOP
    return 0;
}

void RGE_Scenario::rehook() {
    /* TODO: Stub */
//                              void __thiscall rehook(RGE_Scenario * this)
//              void              <VOID>         <RETURN>
//              RGE_Scenario *    ECX:4 (auto)   this
//                               ?rehook@RGE_Scenario@@UAEXXZ                                 XREF[1]:     00572130(*)
//                               RGE_Scenario::rehook
//                              scenario.h:148 (1)
//         0048b590     RET
//         0048b591     ??         90h
//         0048b592     NOP
//         0048b593     NOP
//         0048b594     NOP
//         0048b595     NOP
//         0048b596     NOP
//         0048b597     NOP
//         0048b598     NOP
//         0048b599     NOP
//         0048b59a     NOP
//         0048b59b     NOP
//         0048b59c     NOP
//         0048b59d     NOP
//         0048b59e     NOP
//         0048b59f     NOP
    return;
}

