#pragma once
#include "common.h"

class RGE_Static_Object;
class RGE_Game_World;

typedef char PlayerName[256];

class RGE_Scenario {
public:
    // Virtuals (best-effort)
    virtual RGE_Static_Object* get_object_pointer(int param_1); // vt[0] (0x0)
    virtual ~RGE_Scenario(); // vt[1] (0x4)
    virtual void rehook(); // vt[2] (0x8)
    float Get_Version();
    void update();
    virtual void save(int param_1); // vt[3] (0xC)

    RGE_Timeline* time_line; // +0x4
    RGE_Game_World* world; // +0x8
    unsigned char victory_conquest; // +0xC
    PlayerName player_name[16]; // +0xD
    unsigned char _pad_0[3]; // +0x100D
    char* scenario_name; // +0x1010
    char* description; // +0x1014
    char* hints; // +0x1018
    char* win_message; // +0x101C
    char* loss_message; // +0x1020
    char* historicle_notes; // +0x1024
    char TempText1[224]; // +0x1028
    char TempText2[224]; // +0x1108
    char TempText3[224]; // +0x11E8
    char* BuildList[16]; // +0x12C8
    char* CityPlan[16]; // +0x1308
    char* AiRules[16]; // +0x1348
    unsigned char* BuildListFile[16]; // +0x1388
    unsigned char* CityPlanFile[16]; // +0x13C8
    unsigned char* AiRulesFile[16]; // +0x1408
    int BuildListFileSize[16]; // +0x1448
    int CityPlanFileSize[16]; // +0x1488
    int AiRulesFileSize[16]; // +0x14C8
    char Cine_PreGame[224]; // +0x1508
    char Cine_Victory[224]; // +0x15E8
    char Cine_Loss[224]; // +0x16C8
    char Mission_Bmp[224]; // +0x17A8
    float Version; // +0x1888
    int PlayerPosture[16]; // +0x188C
    int PlType[16]; // +0x18CC
    int PlCivilization[16]; // +0x190C
    int PlActive[16]; // +0x194C
    TPicture* mission_picture; // +0x198C
};
static_assert(sizeof(RGE_Scenario) == 0x1990, "Size mismatch");
