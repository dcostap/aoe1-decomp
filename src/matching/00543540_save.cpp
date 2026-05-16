// 00543540 RGE_Game_World::save
// Attempt log:
// initial source from packet/decompiler.

extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" void __cdecl rge_write(int, void*, int);
extern "C" int save_game_version;
extern "C" void* rge_base_game;

class RGE_Base_Game { public: int difficulty(); };
class RGE_Map { public: void save_map(int file); };
class RGE_Scenario { public: virtual void v0(); virtual void v4(); virtual void v8(); virtual void save(int file); };
class RGE_Player {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3c();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4c();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5c();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6c();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7c();
    virtual void v80();
    virtual void save1(int file);
    virtual void save2(int file);
    virtual void save3(int file);
};

class RGE_Game_World {
public:
    int world_time;             // +04
    int old_world_time;         // +08
    int world_time_delta;       // +0c
    int timer;                  // +10
    char gap_14[4];
    int game_speed;             // +18
    unsigned char temp_pause;   // +1c
    unsigned char game_state;   // +1d
    char gap_1e[0x28-0x1e];
    RGE_Map* map;               // +28
    char gap_2c[0x3c-0x2c];
    short player_num;           // +3c
    char gap_3e[2];
    RGE_Player** players;       // +40
    char gap_44[0x5c-0x44];
    RGE_Scenario* scenario;     // +5c
    char gap_60[8];
    int next_object_id;         // +68
    int next_reusable_object_id;// +6c
    char gap_70[8];
    int random_seed;            // +78
    short curr_player;          // +7c
    char gap_7e[6];
    int world_time_delta_seconds; // +84
    char gap_88[0xA4-0x88];
    int campaign;               // +a4
    int campaign_player;        // +a8
    int campaign_scenario;      // +ac
    int player_turn;            // +b0
    int player_time_delta[9];   // +b4
    char gap_d8[0x100-0xd8];
    int difficultyLevelValue;   // +100

    virtual void save(int file);
};

void RGE_Game_World::save(int file)
{
    color_log('$', '$', 1);
    save_game_version = 0x40E75C29;
    rge_write(file, &this->world_time, 4);
    rge_write(file, &this->old_world_time, 4);
    rge_write(file, &this->world_time_delta, 4);
    rge_write(file, &this->world_time_delta_seconds, 4);
    rge_write(file, &this->timer, 4);
    rge_write(file, &this->game_speed, 4);
    rge_write(file, &this->temp_pause, 1);
    rge_write(file, &this->next_object_id, 4);
    rge_write(file, &this->next_reusable_object_id, 4);
    rge_write(file, &this->random_seed, 4);
    rge_write(file, &this->curr_player, 2);
    rge_write(file, &this->player_num, 2);
    rge_write(file, &this->game_state, 1);
    rge_write(file, &this->campaign, 4);
    rge_write(file, &this->campaign_player, 4);
    rge_write(file, &this->campaign_scenario, 4);
    rge_write(file, &this->player_turn, 4);
    for (int i = 0; i < 9; i++) rge_write(file, &this->player_time_delta[i], 4);
    this->map->save_map(file);
    for (int j = 0; j < this->player_num; j++) {
        color_log('$', 'L', 1);
        this->players[j]->save1(file);
        color_log('$', 0x16, 1);
        this->players[j]->save2(file);
    }
    color_log('$', '2', 1);
    for (int k = 0; k < this->player_num; k++) {
        this->players[k]->save3(file);
    }
    color_log('$', 'E', 1);
    this->scenario->save(file);
    color_log('$', '_', 1);
    if (this->difficultyLevelValue == -1) {
        this->difficultyLevelValue = ((RGE_Base_Game*)rge_base_game)->difficulty();
    }
    rge_write(file, &this->difficultyLevelValue, 4);
}
