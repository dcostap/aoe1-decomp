#ifndef AOE1_TWORLD_H
#define AOE1_TWORLD_H

#include "world.h"

class TRIBE_Tech;

// These records are serialized by send_zone_score_info. Their source owner is
// tworld.cpp, and their wire sizes are part of the TWorld ABI.
struct TRIBE_Zone_High_Score_Info {
  public:
    long score;
    unsigned char civ;
    char player_name[16];
    unsigned char num_allies;
};

typedef char tribe_zone_high_score_info_size_check[(sizeof(TRIBE_Zone_High_Score_Info) == 0x18) ? 1 : -1];

class TRIBE_Zone_Player_Info {
  public:
    char name[16];
    long score;
    unsigned char winner;
    unsigned char civ_played;
    unsigned char civ_random;
    unsigned char player_no;
    unsigned char team_no;
    unsigned char game_outcome;
    long tool_time;
    long bronze_time;
    long iron_time;
};

typedef char tribe_zone_player_info_size_check[(sizeof(TRIBE_Zone_Player_Info) == 0x28) ? 1 : -1];

class TRIBE_Zone_Map_Info {
  public:
    unsigned char Map_Size;
    unsigned char Map_Type;
    short Pop_Limit;
    unsigned char Victory_Condition;
    unsigned char Start_Age;
    unsigned char Resources;
    unsigned char Full_Tech;
    unsigned char Fixed_Pos;
    unsigned char Reveal_Map;
    unsigned char Death_Match;
};

typedef char tribe_zone_map_info_size_check[(sizeof(TRIBE_Zone_Map_Info) == 0x0C) ? 1 : -1];

class TRIBE_Zone_Info {
  public:
    unsigned char number_of_players;
    unsigned char number_of_computer_players;
    char scenario_name[32];
    unsigned long game_time;
    TRIBE_Zone_High_Score_Info total_score;
    TRIBE_Zone_High_Score_Info religion_score;
    TRIBE_Zone_High_Score_Info economy_score;
    TRIBE_Zone_High_Score_Info combat_score;
    TRIBE_Zone_High_Score_Info research_score;
    TRIBE_Zone_Player_Info player_info[8];
    TRIBE_Zone_Map_Info map_info;
    unsigned char cheats_enabled;
    unsigned char game_end_condition_code;
    unsigned long database_checksum;
    unsigned long code_checksum;
    unsigned long program_version;
};

typedef char tribe_zone_info_size_check[(sizeof(TRIBE_Zone_Info) == 0x1FC) ? 1 : -1];

class TRIBE_World : public RGE_Game_World {
  public:
    TRIBE_Tech* tech;                        // +0x104
    int victory_type;                        // +0x108
    int artifact_count;                      // +0x10C
    int ruin_count;                          // +0x110
    unsigned char countdown_victory;         // +0x114
    float countdown_clock;                   // +0x118
    unsigned char score_displayed;           // +0x11C
    unsigned char controllingComputerPlayer; // +0x11D
    int sent_zone_score;                     // +0x120

    TRIBE_World();
    virtual ~TRIBE_World();

  protected:
    virtual void logStatus(FILE* out, int firstTime);

  public:
    // Override declarations follow inherited vtable slot order. Only
    virtual unsigned char data_load_world(FILE* infile);
    virtual void data_load_players_type(short id, short type, FILE* infile);
    virtual void data_load_map(
        char* border_file, char* overlay_file, char* terrain_file, char* map_file, short tile_width, short tile_height,
        short elev_height, RGE_Sound** sounds, char* terr_obj_file
    );
    virtual unsigned char init_player_type(int infile, short index, unsigned char type);
    virtual void load_player(int infile, unsigned char type, short index);
    virtual void map_init(int infile, TSound_Driver* sound_dvr);
    virtual void effects_init(int infile);
    virtual void command_init(int infile, TCommunications_Handler* com_hand);
    virtual void world_init(int infile, TSound_Driver* sound_dvr, TCommunications_Handler* com_hand);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    virtual void save(int outfile);
    virtual void scenario_make_player(
        short index, unsigned char player_type, unsigned char info_type, unsigned char master_player_id, char* name
    );
    virtual unsigned char init(char* base_name, TSound_Driver* sound_dvr, TCommunications_Handler* com_hand);
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int infile1);
    virtual unsigned char new_game(RGE_Player_Info& info, int myPlayerNum);
    virtual unsigned char new_scenario(RGE_Player_Info& info, int random_seed_in);
    virtual void base_save(int outfile);
    virtual void scenario_init(int infile, RGE_Game_World* world);
    virtual void scenario_init(RGE_Game_World* world);

    void check_destructables(short player_id, short obj_id, float col, float row, unsigned char delete_flag);
    long get_achievement(unsigned char achievement, char** info);
    void send_cheat(short cheat_code);
    void cheat(short player, short cheat_code);
    void fill_in_score(TRIBE_Zone_High_Score_Info& info, long score_group);
    void send_zone_score_info();
};

typedef char tribe_world_size_check[(sizeof(TRIBE_World) == 0x124) ? 1 : -1];

#endif
