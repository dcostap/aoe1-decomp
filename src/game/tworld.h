#pragma once
#include "../common.h"

class TRIBE_World : public RGE_Game_World {
public:
    TRIBE_Tech* tech;                        // 0x104
    int victory_type;                        // 0x108
    int artifact_count;                      // 0x10C
    int ruin_count;                          // 0x110
    uchar countdown_victory;                 // 0x114
    float countdown_clock;                   // 0x118
    uchar score_displayed;                   // 0x11C
    uchar controllingComputerPlayer;         // 0x11D
    int sent_zone_score;                     // 0x120

    TRIBE_World();
    virtual ~TRIBE_World();
    virtual void logStatus(_iobuf* param_1, int param_2);
    virtual void data_load_players_type(short param_1, short param_2, _iobuf* param_3);
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9);
    virtual uchar data_load_world(_iobuf* param_1);
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3);
    virtual void map_init(int param_1, TSound_Driver* param_2);
    virtual void command_init(int param_1, TCommunications_Handler* param_2);
    virtual void scenario_init(int param_1, RGE_Game_World* param_2);
    virtual void scenario_init(RGE_Game_World* param_1);
    virtual void effects_init(int param_1);
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3);
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3);
    virtual void base_save(int param_1);
    virtual void save(int param_1);
    virtual void load_player(int param_1, uchar param_2, short param_3);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info* param_1);
    virtual void check_destructables(short param_1, short param_2, float param_3, float param_4, uchar param_5);
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5);
    virtual uchar load_world(int param_1);
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2);
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2);
    virtual uchar check_game_state();
    virtual long get_achievement(uchar param_1, char** param_2);
    virtual void send_cheat(short param_1);
    virtual void cheat(short param_1, short param_2);
    virtual void fill_in_score(TRIBE_Zone_High_Score_Info* param_1, long param_2);
    virtual void send_zone_score_info();
};

static_assert(sizeof(TRIBE_World) == 0x124, "TRIBE_World Size Mismatch");
static_assert(offsetof(TRIBE_World, sent_zone_score) == 0x120, "TRIBE_World Offset Mismatch");

