#pragma once
#include "common.h"

class RGE_Scenario {
public:
    // Virtuals (best-effort)
    virtual RGE_Static_Object* get_object_pointer(int param_1); // vt[0] (0x0)
    virtual ~RGE_Scenario(); // vt[1] (0x4)
    virtual void rehook(); // vt[2] (0x8)
    virtual void save(int param_1); // vt[3] (0xC)

    RGE_Timeline* time_line;
    RGE_Game_World* world;
    unsigned char victory_conquest;
    PlayerName player_name[16];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;
    char TempText1[224];
    char TempText2[224];
    char TempText3[224];
    char* BuildList[16];
    char* CityPlan[16];
    char* AiRules[16];
    unsigned char* BuildListFile[16];
    unsigned char* CityPlanFile[16];
    unsigned char* AiRulesFile[16];
    int BuildListFileSize[16];
    int CityPlanFileSize[16];
    int AiRulesFileSize[16];
    char Cine_PreGame[224];
    char Cine_Victory[224];
    char Cine_Loss[224];
    char Mission_Bmp[224];
    float Version;
    int PlayerPosture[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];
    TPicture* mission_picture;
};
static_assert(sizeof(RGE_Scenario) == 0x1990, "Size mismatch");
