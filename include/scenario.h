#ifndef AOE1_SCENARIO_H
#define AOE1_SCENARIO_H

#include "Timeline.h"

typedef unsigned char uchar;
typedef unsigned int uint;

class TPanel;
class RGE_Static_Object;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Scenario_Header;
class RGE_Scenario_File_Info;
class TPicture;

class RGE_Scenario_Header {
public:
    virtual long get_size();
    virtual void save(int outfile);

    int error_code;
    int version;
    int checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario* scenario_info);
    RGE_Scenario_Header(int infile);
    ~RGE_Scenario_Header();
};

class RGE_Scenario {
protected:
    virtual RGE_Static_Object* get_object_pointer(int obj_ID) {
        return 0;
    }

public:
    virtual ~RGE_Scenario();
    virtual void rehook() {}
    virtual void save(int outfile);

    RGE_Timeline* time_line;
    RGE_Game_World* world;
    unsigned char victory_conquest;
    char player_name[16][0x100];
    char pad_100D[3];
    char* scenario_name;
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;
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
    TPicture* mission_picture;

    RGE_Scenario(RGE_Game_World* w);
    RGE_Scenario(int infile, RGE_Game_World* w);
    void InitializeTextValues();
    void Set_scenario_name(char* str);
    void Set_description(char* str);
    void Set_Cine_PreGame(char* str);
    void Set_Cine_Victory(char* str);
    void Set_Cine_Loss(char* str);
    void Set_Mission_Bmp(char* str);
    void Set_BuildList(int which_player, char* str, int WithExtension);
    void Set_CityPlan(int which_player, char* str, int WithExtension);
    void Set_player_AI(int which_player, char* str, int WithExtension);
    void Set_Version(float ver);
    void Set_player_Type(int which, int t);
    void Set_player_Civ(int which, int c);
    void Set_player_Active(int which, int val);
    void SetPlayerName(int which, char* Name);
    char* Get_scenario_name();
    char* Get_description();
    char* Get_Cine_PreGame();
    char* Get_Cine_Victory();
    char* Get_Cine_Loss();
    char* Get_Mission_Bmp();
    char* Get_BuildList(int which_player, int WithExtension);
    char* Get_CityPlan(int which_player, int WithExtension);
    float Get_Version();
    char* Get_player_AI(int which_player, int WithExtension);
    int GetPlayerPosture(int which);
    char* GetPlayerName(int which);
    int Get_player_Type(int which);
    int Get_player_Civ(int which);
    int Get_player_Active(int which);
    void update();
    int active_player_count();
    int any_player_count();
    int computer_player_count();
    void Set_conquest_victory(unsigned char flag);
    unsigned char Get_conquest_victory();
    void add_description(char* new_text);
    void Set_message(char* str, long message);
    char* Get_message(long message);
};

#endif
