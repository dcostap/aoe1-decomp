#ifndef AOE1_TWORLD_H
#define AOE1_TWORLD_H

#include "world.h"

class TRIBE_Tech;
struct TRIBE_Zone_High_Score_Info;

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
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void load_player(int, unsigned char, short);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual unsigned char data_load_world(FILE*);
    virtual unsigned char init_player_type(int, short, unsigned char);

public:
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void base_save(int);
    virtual unsigned char load_world(int);
    virtual unsigned char new_game(RGE_Player_Info&, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char check_game_state();
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
