#pragma warning(disable:4234)
#ifndef TRIBEGAM_TU_CONTEXT
struct RGE_Player_Info;
class RGE_Sound;
class TSound_Driver;
class RGE_Player {
public:
    char gap_00[0x80];
    unsigned char game_status;
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(void* file);
    virtual unsigned char data_load_terrain_tables(char* name);
    virtual unsigned char data_load_players(char* name);
    virtual unsigned char data_load_objects(char* name);
    virtual unsigned char data_load_sounds(char* name);
    virtual unsigned char data_load_color_tables(char* name);
    virtual unsigned char data_load_sprites(char* name);
    virtual void data_load_players_type(short player, short type, void* file);
    virtual void data_load_effects(char* name);
    virtual void data_load_map(char* map, char* terrain, char* effect,
                               char* random, short width, short height,
                               short tile_set, RGE_Sound** sounds,
                               char* name);
    virtual void data_load_random_map(char* map, char* terrain,
                                      char* effect, char* random);
    virtual unsigned char init_player_type(int player, short type,
                                           unsigned char active);
    virtual unsigned char init_player(int player);
    virtual void load_player(int player, unsigned char type, short id);
    virtual void color_table_init(int table);
    virtual void terrain_tables_init(int table);
    virtual void init_sounds(int count, TSound_Driver* driver);
    virtual void init_sprites(int count);
    virtual void map_init(int count, TSound_Driver* driver);
    virtual void effects_init(int count);
    virtual void master_player_init(int count);
    virtual void command_init(int count, void* comm);
    virtual void world_init(int count, TSound_Driver* driver, void* comm);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    virtual unsigned char new_random_game(RGE_Player_Info& info);
    virtual void save(int file);
    virtual void scenario_make_player(short player, unsigned char active,
                                      unsigned char type, unsigned char civ,
                                      char* name);
    virtual void scenario_make_map(int map);
    virtual unsigned char load_scenario(char* name, RGE_Player_Info* info);
    virtual unsigned char load_scenario(RGE_Player_Info& info);
    virtual void load_scenario1(int player, RGE_Player_Info& info);
    virtual void load_scenario2(int player, RGE_Player_Info& info);
    virtual void load_scenario3(int player, RGE_Player_Info& info);
    virtual void load_scenario4(int player, RGE_Player_Info& info);
    virtual void load_scenario5(int player, RGE_Player_Info& info);
    virtual void load_scenario6(int player, RGE_Player_Info& info);
    virtual void load_scenario7(int player, RGE_Player_Info& info);
    virtual void load_scenario8(int player, RGE_Player_Info& info);
    virtual void logStatus(void* file, int verbose);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info* info);
    virtual unsigned char data_load(char* first, char* second);
    virtual unsigned char init(char* name, TSound_Driver* driver, void* comm);
    virtual void turn_sound_off();
    virtual void del_game_info();
    char gap_04[0x38];
    short player_num;
    char gap_3E[0x2];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
    char gap_7E[0x2];
};

extern char DAT_0086BCE0[];

class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    virtual int run();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int id, long param, char* buffer, int length);
    virtual void message(int text_id, char* text, int max_len);

    char gap_04[0x3F0];
    RGE_Game_World* world;

    char* game_over_msg();
};
#endif

char* TRIBE_Game::game_over_msg() {
    RGE_Game_World* world = this->world;
    RGE_Player* player = world->players[world->curr_player];
    if (player->game_status == 1) {
        this->message(0x47E, DAT_0086BCE0, 0x100);
        return DAT_0086BCE0;
    }
    this->message(0x47F, DAT_0086BCE0, 0x100);
    return DAT_0086BCE0;
}
