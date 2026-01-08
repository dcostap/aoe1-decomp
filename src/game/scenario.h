#pragma once
#include "../common.h"

class RGE_Scenario : public RGE_Timeline       {
public:
    RGE_Timeline* time_line;                 // 0x4
    RGE_Game_World* world;                   // 0x8
    uchar victory_conquest;                  // 0xC
    PlayerName player_name[16];              // 0xD
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

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual RGE_Static_Object* get_object_pointer(int param_1); // Ghidra: get_object_pointer

    // [Slot 01] Offset 0x04 (Override)
    virtual  ~RGE_Scenario() noexcept(false); // Ghidra: `scalar_deleting_destructor'

    // [Slot 02] Offset 0x08 (Override)
    virtual void rehook(); // Ghidra: rehook

    // [Slot 03] Offset 0x0C (Override)
    virtual void save(int param_1); // Ghidra: save

    // --- Non-Virtual Members ---
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
static_assert(offsetof(RGE_Scenario, mission_picture) == 0x198C, "RGE_Scenario Offset Mismatch");

class RGE_Scenario_Header       {
public:
    int error_code;                          // 0x4
    long version;                            // 0x8
    ulong checksum;                          // 0xC
    char* description;                       // 0x10

    RGE_Scenario_Header(RGE_Scenario* param_1);
    RGE_Scenario_Header(int param_1);

    // --- VTABLE DUMP (Source: Ghidra) ---

    // [Slot 00] Offset 0x00 (Override)
    virtual long get_size(); // Ghidra: get_size

    // [Slot 01] Offset 0x04 (Override)
    virtual void save(int param_1); // Ghidra: save

    // [Slot 02] Offset 0x08 WARNING: Function body missing in analysis
    // virtual void get_object_pointer();

    // [Slot 03] Offset 0x0C WARNING: Function body missing in analysis
    // virtual void `scalar_deleting_destructor'();

    // [Slot 04] Offset 0x10 WARNING: Function body missing in analysis
    // virtual void rehook();

    // [Slot 05] Offset 0x14 WARNING: Function body missing in analysis
    // virtual void save();

    // --- Non-Virtual Destructor ---
    ~RGE_Scenario_Header() noexcept(false);
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

