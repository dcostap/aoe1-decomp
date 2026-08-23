#ifndef RMM_OBJ_WORLD_CONTEXT_H
#define RMM_OBJ_WORLD_CONTEXT_H

// PDB-backed world surface used by rmm_obj.cpp.
// The virtual order and complete size come from type record 0x2882.

struct _iobuf;
class RGE_Player;
class RGE_Player_Info;
class RGE_Sound;
class RGE_Scenario;
class RGE_Static_Object;
class TSound_Driver;
class TCommunications_Handler;

class RGE_Game_World {
public:
    virtual uchar data_load_world(_iobuf*);
    virtual uchar data_load_terrain_tables(char*);
    virtual uchar data_load_players(char*);
    virtual uchar data_load_objects(char*);
    virtual uchar data_load_sounds(char*);
    virtual uchar data_load_color_tables(char*);
    virtual uchar data_load_sprites(char*);
    virtual void data_load_players_type(short, short, _iobuf*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short,
        short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual uchar init_player_type(int, short, uchar);
    virtual uchar init_player(int);
    virtual void load_player(int, uchar, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
    virtual void master_player_init(int);
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info*);
    virtual uchar new_random_game(RGE_Player_Info*);
    virtual void save(int);
    virtual void scenario_make_player(short, uchar, uchar, uchar, char*);
    virtual void scenario_make_map(int);
    virtual uchar load_scenario(RGE_Player_Info*);
    virtual uchar load_scenario(char*, RGE_Player_Info*);
    virtual void load_scenario1(int, RGE_Player_Info*);
    virtual void load_scenario2(int, RGE_Player_Info*);
    virtual void load_scenario3(int, RGE_Player_Info*);
    virtual void load_scenario4(int, RGE_Player_Info*);
    virtual void load_scenario5(int, RGE_Player_Info*);
    virtual void load_scenario6(int, RGE_Player_Info*);
    virtual void load_scenario7(int, RGE_Player_Info*);
    virtual void load_scenario8(int, RGE_Player_Info*);
    virtual void logStatus(_iobuf*, int);
    virtual ~RGE_Game_World();
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info*);
    virtual uchar data_load(char*, char*);
    virtual uchar init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual uchar update();
    virtual uchar get_game_state();
    virtual uchar check_game_state();
    virtual uchar load_world(int);
    virtual uchar load_game(char*);
    virtual uchar new_game(RGE_Player_Info*, int);
    virtual uchar new_scenario(RGE_Player_Info*, int);
    virtual uchar save_game(char*);
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual uchar save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(uchar);
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);

    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x0c];
    short terrain_num;
    short terrain_size;
    float** terrains;
    char gap_58[0xac];
};

#endif
