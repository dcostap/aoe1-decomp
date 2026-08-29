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

typedef char tribe_zone_high_score_info_size_check[
    (sizeof(TRIBE_Zone_High_Score_Info) == 0x18) ? 1 : -1];

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

typedef char tribe_zone_player_info_size_check[
    (sizeof(TRIBE_Zone_Player_Info) == 0x28) ? 1 : -1];

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

typedef char tribe_zone_map_info_size_check[
    (sizeof(TRIBE_Zone_Map_Info) == 0x0C) ? 1 : -1];

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

typedef char tribe_zone_info_size_check[
    (sizeof(TRIBE_Zone_Info) == 0x1FC) ? 1 : -1];

// Owner-only TRIBE_World surface from tworld.cpp.
// RGE_Game_World owns the first 0x104 bytes.
class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;                         // +0x104
    int victory_type;                         // +0x108
    int artifact_count;                       // +0x10C
    int ruin_count;                           // +0x110
    unsigned char countdown_victory;          // +0x114
    float countdown_clock;                    // +0x118
    unsigned char score_displayed;            // +0x11C
    unsigned char controllingComputerPlayer;  // +0x11D
    int sent_zone_score;                      // +0x120

    TRIBE_World();
    virtual ~TRIBE_World();

protected:
    virtual void logStatus(FILE*, int);

public:
    // Override declarations follow inherited vtable slot order. Only
    virtual unsigned char data_load_world(FILE*);
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual void load_player(int, unsigned char, short);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char new_game(RGE_Player_Info&, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual void base_save(int);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);

    void check_destructables(short, short, float, float, unsigned char);
    long get_achievement(unsigned char, char**);
    void send_cheat(short);
    void cheat(short, short);
    void fill_in_score(TRIBE_Zone_High_Score_Info&, long);
    void send_zone_score_info();
};

typedef char tribe_world_size_check[
    (sizeof(TRIBE_World) == 0x124) ? 1 : -1];

#endif
