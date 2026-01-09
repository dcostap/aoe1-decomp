#pragma once
#include "common.h"

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

    virtual uchar data_load_world(_iobuf* param_1);         // vt0[0]+0x0=0x52E350
    virtual void data_load_players_type(short param_1, short param_2, _iobuf* param_3); // vt0[7]+0x1C=0x52E220
    virtual void data_load_map(char* param_1, char* param_2, char* param_3, char* param_4, short param_5, short param_6, short param_7, RGE_Sound** param_8, char* param_9); // vt0[9]+0x24=0x52E2B0
    virtual uchar init_player_type(int param_1, short param_2, uchar param_3); // vt0[11]+0x2C=0x52E400
    virtual void load_player(int param_1, uchar param_2, short param_3); // vt0[13]+0x34=0x52E830
    virtual void map_init(int param_1, TSound_Driver* param_2); // vt0[18]+0x48=0x52E4C0
    virtual void effects_init(int param_1);                 // vt0[19]+0x4C=0x52E650
    virtual void command_init(int param_1, TCommunications_Handler* param_2); // vt0[21]+0x54=0x52E530
    virtual void world_init(int param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // vt0[22]+0x58=0x52E6B0
    virtual void setup_gaia();                              // vt0[23]+0x5C=0x52E920
    virtual void setup_players(RGE_Player_Info* param_1);   // vt0[24]+0x60=0x52E990
    virtual void save(int param_1);                         // vt0[26]+0x68=0x52E790
    virtual void scenario_make_player(short param_1, uchar param_2, uchar param_3, uchar param_4, char* param_5); // vt0[27]+0x6C=0x52ECF0
    virtual void logStatus(_iobuf* param_1, int param_2);   // vt0[39]+0x9C=0x52E0B0
    virtual uchar init(char* param_1, TSound_Driver* param_2, TCommunications_Handler* param_3); // vt0[44]+0xB0=0x52E750
    virtual uchar check_game_state();                       // vt0[49]+0xC4=0x5303F0
    virtual uchar load_world(int param_1);                  // vt0[50]+0xC8=0x52EDF0
    virtual uchar new_game(RGE_Player_Info* param_1, int param_2); // vt0[52]+0xD0=0x52EF30
    virtual uchar new_scenario(RGE_Player_Info* param_1, int param_2); // vt0[53]+0xD4=0x530370
    virtual void base_save(int param_1);                    // vt0[56]+0xE0=0x52E770
    virtual void scenario_init(RGE_Game_World* param_1);    // vt0[60]+0xF0=0x52E5F0
    virtual void scenario_init(int param_1, RGE_Game_World* param_2); // vt0[61]+0xF4=0x52E590
    TRIBE_World();
    ~TRIBE_World();
    void check_destructables(short param_1, short param_2, float param_3, float param_4, uchar param_5);
    long get_achievement(uchar param_1, char** param_2);
    void send_cheat(short param_1);
    void cheat(short param_1, short param_2);
    void fill_in_score(TRIBE_Zone_High_Score_Info* param_1, long param_2);
    void send_zone_score_info();
};

static_assert(sizeof(TRIBE_World) == 0x124, "TRIBE_World Size Mismatch");

