#ifndef AOE1_WORLD_H
#define AOE1_WORLD_H

#include <stdio.h>

class RGE_Game_World;
class RGE_Map;
class RGE_Player;
struct RGE_Player_Info;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Sound;
class TSound_Driver;
class TCommunications_Handler;
class RGE_Master_Player;
class RGE_Effects;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Command;
class RGE_Scenario;
class AIPlayBook;

class RGE_Game_World {
public:
    RGE_Game_World();

    // ABI NOTE: Keep these virtual declarations in PDB and vtable order.
    // The load_scenario, setup_player_colors, base_save, and scenario_init
    // overloads below use the original declaration order. addObject and
    // removeObject occupy world vslots 62 and 63.
protected:
    virtual unsigned char data_load_world(FILE*);
    virtual unsigned char data_load_terrain_tables(char*);
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
protected:
    virtual void data_load_players_type(short, short, FILE*);
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
    virtual unsigned char init_player_type(int, short, unsigned char);
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
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
    virtual void setup_players(RGE_Player_Info&);
    virtual unsigned char new_random_game(RGE_Player_Info&);
    virtual void save(int);
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(char*, RGE_Player_Info&);
    virtual unsigned char load_scenario(RGE_Player_Info&);
    virtual void load_scenario1(int, RGE_Player_Info&);
    virtual void load_scenario2(int, RGE_Player_Info&);
    virtual void load_scenario3(int, RGE_Player_Info&);
    virtual void load_scenario4(int, RGE_Player_Info&);
    virtual void load_scenario5(int, RGE_Player_Info&);
    virtual void load_scenario6(int, RGE_Player_Info&);
    virtual void load_scenario7(int, RGE_Player_Info&);
    virtual void load_scenario8(int, RGE_Player_Info&);
    virtual void logStatus(FILE*, int);

public:
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info&);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char*, char*);
    virtual unsigned char init(char*, TSound_Driver*, TCommunications_Handler*);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int);
    virtual unsigned char load_game(char*);
    virtual unsigned char new_game(RGE_Player_Info&, int);
    virtual unsigned char new_scenario(RGE_Player_Info&, int);
    virtual unsigned char save_game(char*);
    virtual void base_save(int);
    virtual void base_save(char*);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual void scenario_init(RGE_Game_World*);

    int initializePathingSystem();
    void update_sounds(unsigned long);
    void selectNextComputerPlayer(int);
    void useComputerPlayerUpdateTime(unsigned long);
    int computerPlayerUpdateTimeAvailable();
    int objectGroupOnTile(int, int, int, int, int&);
    int difficultyLevel();
    int maxNumberObjects();
    int maxNumberNegativeObjects();
    int numberObjects();
    int numberNegativeObjects();
    RGE_Static_Object* object(int);
    RGE_Static_Object* object_ptr(int);
    long get_next_object_id();
    long get_next_reusable_object_id();
    virtual int addObject(RGE_Static_Object*); // vslot 62
    virtual int removeObject(int);             // vslot 63
    unsigned char recycle_object_out_of_game(unsigned char, RGE_Static_Object*);
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);
    void update_mutual_allies();
    void update_sprites(unsigned long);
    int is_player_turn(int);
    unsigned long get_accum_time_delta(int);
    void reset_object_count();
    void reset_communications(TCommunications_Handler*);
    void reset_player_visible_maps();
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
    void set_game_speed(float);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    float game_speed;
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    RGE_Sound** sounds;
    short sprite_num;
    RGE_Sprite** sprites;
    short player_num;
    RGE_Player** players;
    short master_player_num;
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    RGE_Command* commands;
    RGE_Scenario* scenario;
    short color_table_num;
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;
    unsigned int random_seed;
    short curr_player;
    TSound_Driver* sound_driver;
    float world_time_delta_seconds;
    RGE_Static_Object** objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    RGE_Static_Object** negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;
    AIPlayBook* playbook;
    long campaign;
    long campaign_player;
    long campaign_scenario;
    int player_turn;
    unsigned long player_time_delta[9];
    RGE_Object_List* reusable_static_objects;
    RGE_Object_List* reusable_animated_objects;
    RGE_Object_List* reusable_moving_objects;
    RGE_Object_List* reusable_action_objects;
    RGE_Object_List* reusable_combat_objects;
    RGE_Object_List* reusable_missile_objects;
    RGE_Object_List* reusable_doppleganger_objects;
    unsigned long maximumComputerPlayerUpdateTime;
    unsigned long availableComputerPlayerUpdateTime;
    int currentUpdateComputerPlayer;
    int difficultyLevelValue;
};

typedef char rge_game_world_size_check[
    (sizeof(RGE_Game_World) == 0x104) ? 1 : -1];

#endif
