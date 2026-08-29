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
    virtual void save(int file);

    int error_code;
    int version;
    int checksum;
    char* description;

    RGE_Scenario_Header(RGE_Scenario* scenario);
    RGE_Scenario_Header(int file);
    ~RGE_Scenario_Header();
};

class RGE_Scenario {
protected:
    virtual RGE_Static_Object* get_object_pointer(int object_id)
    {
        return 0;
    }

public:
    virtual ~RGE_Scenario();
    virtual void rehook() {}
    virtual void save(int file);

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

    RGE_Scenario(RGE_Game_World* world);
    RGE_Scenario(int file, RGE_Game_World* world);
    void InitializeTextValues();
    void Set_scenario_name(char* text);
    void Set_description(char* text);
    void Set_Cine_PreGame(char* text);
    void Set_Cine_Victory(char* text);
    void Set_Cine_Loss(char* text);
    void Set_Mission_Bmp(char* text);
    void Set_BuildList(int player, char* text, int flag);
    void Set_CityPlan(int player, char* text, int flag);
    void Set_player_AI(int player, char* text, int flag);
    void Set_Version(float version);
    void Set_player_Type(int player, int value);
    void Set_player_Civ(int player, int value);
    void Set_player_Active(int player, int value);
    void SetPlayerName(int player, char* name);
    char* Get_scenario_name();
    char* Get_description();
    char* Get_Cine_PreGame();
    char* Get_Cine_Victory();
    char* Get_Cine_Loss();
    char* Get_Mission_Bmp();
    char* Get_BuildList(int player, int use_file);
    char* Get_CityPlan(int player, int use_file);
    float Get_Version();
    char* Get_player_AI(int player, int use_temp_file);
    int GetPlayerPosture(int player);
    char* GetPlayerName(int player);
    int Get_player_Type(int player);
    int Get_player_Civ(int player);
    int Get_player_Active(int player);
    void update();
    int active_player_count();
    int any_player_count();
    int computer_player_count();
    void Set_conquest_victory(unsigned char value);
    unsigned char Get_conquest_victory();
    void add_description(char* text);
    void Set_message(char* text, long field_index);
    char* Get_message(long field_index);
};

#endif
