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

    // The load_scenario, setup_player_colors, base_save, and scenario_init
    // overloads below use the original declaration order. addObject and
    // removeObject occupy world vslots 62 and 63.
  protected:
    virtual unsigned char data_load_world(FILE* infile);
    virtual unsigned char data_load_terrain_tables(char* file_name);
    virtual unsigned char data_load_players(char* file_name);
    virtual unsigned char data_load_objects(char* file_name);
    virtual unsigned char data_load_sounds(char* file_name);
    virtual unsigned char data_load_color_tables(char* file_name);
    virtual unsigned char data_load_sprites(char* file_name);

  protected:
    virtual void data_load_players_type(short id, short type, FILE* infile);
    virtual void data_load_effects(char* effects_file);
    virtual void data_load_map(
        char* border_file, char* overlay_file, char* terrain_file, char* map_file, short tile_width, short tile_height,
        short elev_height, RGE_Sound** sounds, char* terr_obj_file
    );
    virtual void data_load_random_map(char* rmm_map_file, char* rmm_land_file, char* rmm_terr_file, char* rmm_obj_file);
    virtual unsigned char init_player_type(int infile, short index, unsigned char type);
    virtual unsigned char init_player(int infile);
    virtual void load_player(int infile, unsigned char type, short index);
    virtual void color_table_init(int infile);
    virtual void terrain_tables_init(int infile);
    virtual void init_sounds(int infile, TSound_Driver* sound_dvr);
    virtual void init_sprites(int infile);
    virtual void map_init(int infile, TSound_Driver* sound_dvr);
    virtual void effects_init(int infile);
    virtual void master_player_init(int infile);
    virtual void command_init(int infile, TCommunications_Handler* com_hand);
    virtual void world_init(int infile, TSound_Driver* sound_dvr, TCommunications_Handler* com_hand);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info& info);
    virtual unsigned char new_random_game(RGE_Player_Info& info);
    virtual void save(int outfile);
    virtual void scenario_make_player(
        short index, unsigned char player_type, unsigned char info_type, unsigned char master_player_id, char* name
    );
    virtual void scenario_make_map(int infile);
    virtual unsigned char load_scenario(char* scenario, RGE_Player_Info& info);
    virtual unsigned char load_scenario(RGE_Player_Info& info);
    virtual void load_scenario1(int infile, RGE_Player_Info& info);
    virtual void load_scenario2(int infile, RGE_Player_Info& info);
    virtual void load_scenario3(int infile, RGE_Player_Info& info);
    virtual void load_scenario4(int infile, RGE_Player_Info& info);
    virtual void load_scenario5(int infile, RGE_Player_Info& info);
    virtual void load_scenario6(int infile, RGE_Player_Info& info);
    virtual void load_scenario7(int infile, RGE_Player_Info& info);
    virtual void load_scenario8(int infile, RGE_Player_Info& info);
    virtual void logStatus(FILE*, int) {
    }

  public:
    virtual ~RGE_Game_World();
    virtual void setup_player_colors(RGE_Player_Info& info);
    virtual void setup_player_colors();
    virtual unsigned char data_load(char* base_name, char* world_info);
    virtual unsigned char init(char* base_name, TSound_Driver* sound_dvr, TCommunications_Handler* com_hand);
    virtual void turn_sound_off();
    virtual void del_game_info();
    virtual unsigned char update();
    virtual unsigned char get_game_state();
    virtual unsigned char check_game_state();
    virtual unsigned char load_world(int infile1);
    virtual unsigned char load_game(char* name);
    virtual unsigned char new_game(RGE_Player_Info& info, int myPlayerNum);
    virtual unsigned char new_scenario(RGE_Player_Info& info, int random_seed_in);
    virtual unsigned char save_game(char* name);
    virtual void base_save(int outfile);
    virtual void base_save(char* name);
    virtual unsigned char save_scenario(char* filename);
    virtual RGE_Scenario* get_scenario_info(char* filename);
    virtual void pause(unsigned char flag);
    virtual void scenario_init(int infile, RGE_Game_World* world);
    virtual void scenario_init(RGE_Game_World* world);

    int initializePathingSystem();
    void update_sounds(unsigned long time);
    void selectNextComputerPlayer(int cPType);
    void useComputerPlayerUpdateTime(unsigned long usedTime);
    int computerPlayerUpdateTimeAvailable();
    int objectGroupOnTile(int ownerID, int groupID, int x, int y, int& objectCount);
    int difficultyLevel();
    int maxNumberObjects();
    int maxNumberNegativeObjects();
    int numberObjects();
    int numberNegativeObjects();
    RGE_Static_Object* object(int oID);
    RGE_Static_Object* object_ptr(int oID);
    long get_next_object_id();
    long get_next_reusable_object_id();
    virtual int addObject(RGE_Static_Object* newObject); // vslot 62
    virtual int removeObject(int oID);                   // vslot 63
    unsigned char recycle_object_out_of_game(unsigned char object_type, RGE_Static_Object* obj);
    RGE_Static_Object* recycle_object_in_to_game(unsigned char object_type);
    void update_mutual_allies();
    void update_sprites(unsigned long time);
    int is_player_turn(int player_id);
    unsigned long get_accum_time_delta(int player_id);
    void reset_object_count();
    void reset_communications(TCommunications_Handler* com_hand);
    void reset_player_visible_maps();
    void set_map_visible(unsigned char flag);
    void set_map_fog(unsigned char flag);
    void set_game_speed(float new_speed);

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

typedef char rge_game_world_size_check[(sizeof(RGE_Game_World) == 0x104) ? 1 : -1];

#endif
