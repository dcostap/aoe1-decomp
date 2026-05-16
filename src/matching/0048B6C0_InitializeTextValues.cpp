// VA: 0048B6C0 RGE_Scenario::InitializeTextValues
// Attempt log:
// try 1: natural reconstruction from asm/type layout: get localized None/Random strings, allocate text buffers, copy defaults, init per-player script/name arrays.
// try 2: local copystr helper compiled out-of-line, text too small; switch to CRT-recognized strcpy surface to encourage inline rep copy.

#include <string.h>
class RGE_Base_Game;
extern RGE_Base_Game* rge_base_game;
void* __cdecl operator new(unsigned int size);

class RGE_Base_Game {
public:
#define GPAD(n) virtual void g##n();
    GPAD(0) GPAD(1) GPAD(2) GPAD(3) GPAD(4) GPAD(5) GPAD(6) GPAD(7)
#undef GPAD
    virtual void get_string(int id, char* out, int len);
};

class RGE_Scenario {
public:
    char gap_0000[0x0D];
    char player_name[16][0x100];
    char gap_100D[3];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historical_notes;
    char TempText1[0xE0];
    char TempText2[0xE0];
    char TempText3[0xE0];
    char* BuildList[16];
    char* CityPlan[16];
    char* AiRules[16];
    unsigned char* BuildListFile[16];
    unsigned char* CityPlanFile[16];
    unsigned char* AiRulesFile[16];
    int BuildListFileSize[16];
    int CityPlanFileSize[16];
    int AiRulesFileSize[16];
    char Cine_PreGame[0xE0];
    char Cine_Victory[0xE0];
    char Cine_Loss[0xE0];
    char Mission_Bmp[0xE0];
    float Version;
    int PlayerPosture[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];

    void InitializeTextValues();
};

void RGE_Scenario::InitializeTextValues()
{
    char none_string[30];
    char pad1[2];
    char default_string[30];
    char pad2[2];

    rge_base_game->get_string(0x2775, none_string, 30);
    rge_base_game->get_string(0x277B, default_string, 30);

    this->description = 0;
    this->hints = 0;
    this->win_message = 0;
    this->loss_message = 0;
    this->historical_notes = 0;

    this->scenario_name = (char*)operator new(0xE0);
    memset(this->scenario_name, 0, 0xE0);

    strcpy(this->Cine_PreGame, none_string);
    strcpy(this->Cine_Victory, none_string);
    strcpy(this->Cine_Loss, none_string);
    strcpy(this->Mission_Bmp, none_string);

    int count = 16;
    for (int i = 0; i < 16; i++) {
        this->PlayerPosture[i] = 0;
        this->PlType[i] = 0;
        this->PlCivilization[i] = 0;
        this->PlActive[i] = 0;
        this->player_name[i][0] = 0;

        this->BuildList[i] = (char*)operator new(0xE0);
        memset(this->BuildList[i], 0, 0xE0);
        strcpy(this->BuildList[i], default_string);

        this->CityPlan[i] = (char*)operator new(0xE0);
        memset(this->CityPlan[i], 0, 0xE0);
        strcpy(this->CityPlan[i], none_string);

        this->AiRules[i] = (char*)operator new(0xE0);
        memset(this->AiRules[i], 0, 0xE0);
        strcpy(this->AiRules[i], default_string);

        this->BuildListFile[i] = 0;
        this->CityPlanFile[i] = 0;
        this->AiRulesFile[i] = 0;
        this->BuildListFileSize[i] = 0;
        this->CityPlanFileSize[i] = 0;
        this->AiRulesFileSize[i] = 0;
        count--;
    }
}
