#ifndef AOE1_WORLD_SCENARIO_CONTEXT_H
#define AOE1_WORLD_SCENARIO_CONTEXT_H

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Game_World;
class RGE_Player;
struct RGE_Player_Info;
class RGE_Static_Object;
class RGE_Object_Owner_Info;
class RGE_Sprite;
class RGE_Sound;
class TSound_Driver;
class RGE_Master_Player;
class RGE_Effects;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Scenario;
class RGE_Master_Static_Object;
class RGE_Object_Node;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class RGE_Doppleganger_Creator;
class Visible_Resource_Manager;
class RGE_Tile_List_Node;
class XYZBYTEPoint;
class AIPlayBook;
class RGE_Zone_Map_List;
class RGE_Unified_Visible_Map;
class Visible_Unit_Manager;
class RGE_RMM_Database_Controller;
class RGE_Tile;
class TMousePointer;
class RGE_Game_Info;
class RGE_Command_Give_Attribute;
class TDrawArea;
struct tagRECT;
typedef int PositionMode;
typedef int RedrawMode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, long, TPanel*, TPanel*,
                                 TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
};

class TCommunications_Handler {
public:
    unsigned long GetRandomSeed();
    int GetPlayerHumanity(int);
    int DoCycle(unsigned long);
    void LastWorldRandom(int);
};

class RGE_Sound {
public:
    short play_at_update_count;
    short sound_num;
    void* sound_items;
    unsigned long cache_time;
    short id;
    RGE_Sound(FILE*, short);
    RGE_Sound(int, TSound_Driver*);
    ~RGE_Sound();
    void stop();
    void update(unsigned long);
    void save(int);
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char color_table_name[30];
    short resource_id;
    unsigned char type;
    unsigned char map_color;
    short id;
    unsigned char table[256];
    RGE_Color_Table(int);
    RGE_Color_Table(FILE*, short);
    void save(int);
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void init(int, RGE_Sprite**, RGE_Sound**);
    virtual void master_player_slot_2();
    virtual void add_object(short);
    virtual void add_object_data(FILE*, short, RGE_Sprite**, RGE_Sound**, short);
    virtual void save(int);
    unsigned char gap_04[0x28];
    RGE_Master_Player(int);
    RGE_Master_Player(FILE*);
};

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save(int);
    char gap_04[0x08];
    RGE_Effects(int);
    RGE_Effects(char*);
};

class RGE_Sprite {
public:
    ~RGE_Sprite();
    unsigned char gap_00[0x78];
    RGE_Sprite(int, RGE_Sound**, RGE_Color_Table**);
    RGE_Sprite(FILE*, short, RGE_Sound**);
    RGE_Sprite(short);
    void rehook(RGE_Sprite**);
    void update(unsigned long);
    void save(int);
};

class RGE_Command {
public:
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute*);
    virtual ~RGE_Command();
    RGE_Command(RGE_Game_World*, TCommunications_Handler*);
    void do_commands();
    void reset_communications(TCommunications_Handler*);
    RGE_Game_World* world;
    unsigned char* last_order;
    long last_order_size;
    long last_order_time;
    TCommunications_Handler* com_hand;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    virtual void data_load_random_map(int);
    virtual void load_random_map(char*, char*, char*, char*);
    virtual unsigned char do_terrain_brush(long, long, long, unsigned char);
    virtual unsigned char do_terrain_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush(long, long, long, unsigned char);
    virtual unsigned char do_elevation_brush_stroke(long, long, long, long, long, unsigned char);
    virtual unsigned char do_cliff_brush(long, long, unsigned char, unsigned char);
    virtual unsigned char do_cliff_brush_stroke(long, long, long, long, unsigned char, unsigned char);
    virtual void map_generate(RGE_Player*, RGE_Game_World*, RGE_Player_Info*, unsigned char*);
    virtual void map_generate2(RGE_Game_World*, long, long, unsigned char, long);
    virtual void save(int);
    char gap_04[4];
    int map_width;
    int map_height;
    char gap_10[0x8D7C];
    char** row_data;
    char gap_8D90[0x38];
    RGE_Unified_Visible_Map* unified_vis_map;
    unsigned char gap_8DCC[4];
    RGE_Map(int, RGE_Sound**, int);
    RGE_Map(char*, char*, char*, short, short, short, RGE_Sound**);
    void load_terrain_obj_types(char*);
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
    void new_map(long, long);
    void load_map(int);
    void clear_map(unsigned char, unsigned char);
    void scenario_load(int, unsigned char*);
    void save_map(int);
    void scenario_save(int);
};

struct RGE_Map_Gen_Info {
    short base_terrain;
};

struct RGE_Player_Info {
    char name[9][65];
    char type[9];
    char tribe[9];
    unsigned char gap_25B;
    short color[9];
    unsigned char gap_26E[2];
    union {
        long player_id_hash[9];
        long player_id[9];
    };
    union {
        short player_num;
        short player_num_minus1;
    };
    unsigned char gap_296[2];
    char* scenario;
    RGE_Map_Gen_Info* map_info;
    union {
        short map_type;
        short victory;
    };
    short map_width;
    short map_height;
    short ai_info;
    unsigned char campaign;
    unsigned char gap_end[3];
};

class RGE_Master_Static_Object {
public:
    char gap_00[4];
    unsigned char master_type;
    char gap_05[0x0B];
    short id;
    char gap_12[2];
    short object_group;
};

class RGE_Object_Owner_Info {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Object_Owner_Info* owner_info;
    char gap_10[0x25];
    unsigned char facet;
    char gap_36[2];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[0x53];
    float angle;
    void change_unique_id();
};

class RGE_Object_Node {
public:
    union {
        RGE_Static_Object* object;
        RGE_Static_Object* node;
    };
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
};

class RGE_Object_List {
public:
    virtual void load(unsigned char, int, void*);
    union {
        int count;
        RGE_Object_Node* list;
    };
    union {
        void* nodes;
        struct {
            short number_of_objects;
            short number_of_objects_pad;
        };
    };
    RGE_Object_List();
    ~RGE_Object_List();
    void removeAllObjects();
    void update();
    void add_node(void*);
    void remove_node(RGE_Static_Object*, RGE_Object_Node*);
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
    void del_list();
};

class RGE_Doppleganger_Creator {
public:
    void perform_doppleganger_checks();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    RGE_Player(RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char);
    RGE_Player(int, RGE_Game_World*, unsigned char);
    virtual void set_game_status(unsigned char);
    virtual void do_resign(int);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int);
    virtual int isEnemy(int);
    virtual int isAlly(int);
    virtual int isNeutral(int);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int, int);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float, float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short, unsigned char, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_work(RGE_Static_Object*, float, float);
    virtual unsigned char command_make_do(RGE_Static_Object*, float, float);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short, float, float, float);
    virtual unsigned char command_add_attribute(int, float);
    virtual unsigned char command_give_attribute(int, int, float);
    virtual unsigned char command_formation(int);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int, int*, int, float);
    virtual unsigned char command_add_to_group(int, int, float);
    virtual unsigned char command_remove_from_group(int, int);
    virtual unsigned char command_destroy_group(int);
    virtual unsigned char command_resign(int, int);
    virtual unsigned char command_add_waypoint(float, float, float);
    virtual RGE_Object_Node* addObject(RGE_Static_Object*, int, int);
    virtual void removeObject(RGE_Static_Object*, int, int, RGE_Object_Node*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();
    unsigned char check_victory();
    unsigned char relation(long);
    void destroy_objects();
    void victory_if_game_on();
    void loss_if_game_on();
    void set_map_visible();
    void remake_visible_map();
    void load_info(int);
    void set_color_table(unsigned char);
    void set_relation(long, unsigned char);
    void set_allied_victory(unsigned char);
    char gap_04[0x24];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    char gap_34[0x0C];
    RGE_Doppleganger_Creator* doppleganger_creator;
    char gap_44[4];
    unsigned char type;
    char gap_49[0x0F];
    RGE_Tile_List tile_list;
    char gap_6C[0x14];
    unsigned char game_status;
    unsigned char gap_81[3];
    unsigned char* relations;
    int unit_diplomacy[9];
    int mutualAlly[9];
    int mutualExploredMask;
    int mutualVisibleMask;
    int nonMutualVisibleMask;
    int removeVisibleBits[9];
    int allied_LOS_Enable;
    union {
        unsigned char allied_victory;
        unsigned char civ;
    };
    char gap_105[0x11B];
};

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int);
    unsigned char gap_04[0x198C];
    RGE_Scenario(RGE_Game_World*);
    RGE_Scenario(int, RGE_Game_World*);
    void update();
    unsigned char Get_conquest_victory();
    int GetPlayerPosture(int);
    char* Get_player_AI(int, int);
    char* Get_CityPlan(int, int);
    char* Get_BuildList(int, int);
};

struct RGE_Prog_Info {
    char gap[0xB12];
    char save_dir[261];
    char scenario_dir[261];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    RGE_Game_Info* player_game_info;
    char gap_08[0x04];
    RGE_Prog_Info* save_prog_info;
    RGE_Prog_Info* prog_info;
    void add_to_timing(int, int);
    unsigned char set_campaign_info(long, long, long);
    void set_campaign_win();
    int difficulty();
    unsigned char check_prog_argument(char*);
    void write_scenario_header(int);
    int multiplayerGame();
    int randomGame();
    int campaignGame();
    int singlePlayerGame();
    float get_game_speed();
    int playerTeam(int);
    int playerID(int);
    int campaign_open_scenario();
    void get_campaign_info(long*, long*, long*);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE*);
protected:
    virtual unsigned char data_load_terrain_tables(char*);
public:
    virtual unsigned char data_load_players(char*);
    virtual unsigned char data_load_objects(char*);
    virtual unsigned char data_load_sounds(char*);
    virtual unsigned char data_load_color_tables(char*);
    virtual unsigned char data_load_sprites(char*);
protected:
    virtual void data_load_players_type(short, short, FILE*);
public:
    virtual void data_load_effects(char*);
    virtual void data_load_map(char*, char*, char*, char*, short, short, short, RGE_Sound**, char*);
    virtual void data_load_random_map(char*, char*, char*, char*);
protected:
    virtual unsigned char init_player_type(int, short, unsigned char);
public:
    virtual unsigned char init_player(int);
    virtual void load_player(int, unsigned char, short);
    virtual void color_table_init(int);
    virtual void terrain_tables_init(int);
    virtual void init_sounds(int, TSound_Driver*);
    virtual void init_sprites(int);
    virtual void map_init(int, TSound_Driver*);
    virtual void effects_init(int);
protected:
    virtual void master_player_init(int);
public:
    virtual void command_init(int, TCommunications_Handler*);
    virtual void world_init(int, TSound_Driver*, TCommunications_Handler*);
    virtual void setup_gaia();
    virtual void setup_players(RGE_Player_Info&);
protected:
    virtual unsigned char new_random_game(RGE_Player_Info&);
public:
    virtual void save(int);
protected:
    virtual void scenario_make_player(short, unsigned char, unsigned char, unsigned char, char*);
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
public:
    virtual void logStatus(FILE*, int);
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
    void update_sprites(unsigned long);
    int is_player_turn(int);
    int get_accum_time_delta(int);
    void reset_object_count();
    void reset_communications(TCommunications_Handler*);
    void reset_player_visible_maps();
    void set_map_visible(unsigned char);
    void set_map_fog(unsigned char);
    void set_game_speed(int);
    void update_mutual_allies();
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
    int addObject(RGE_Static_Object*);
    int removeObject(int);
    unsigned char recycle_object_out_of_game(unsigned char, void*);
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);

    unsigned long world_time;
    unsigned long old_world_time;
    unsigned long world_time_delta;
    float timer;
    unsigned long old_time;
    union {
        float game_speed;
        int game_speed_bits;
    };
    unsigned char temp_pause;
    unsigned char game_state;
    unsigned char game_end_condition;
    unsigned char gap_1F;
    long sound_update_index;
    long sprite_update_index;
    RGE_Map* map;
    short sound_num;
    unsigned char gap_2E[2];
    RGE_Sound** sounds;
    short sprite_num;
    unsigned char gap_36[2];
    RGE_Sprite** sprites;
    short player_num;
    unsigned char gap_3E[2];
    RGE_Player** players;
    short master_player_num;
    unsigned char gap_46[2];
    RGE_Master_Player** master_players;
    RGE_Effects* effects;
    short terrain_num;
    short terrain_size;
    float** terrains;
    RGE_Command* commands;
    RGE_Scenario* scenario;
    short color_table_num;
    unsigned char gap_62[2];
    RGE_Color_Table** color_tables;
    long next_object_id;
    long next_reusable_object_id;
    long scenario_object_id;
    unsigned char scenario_object_flag;
    unsigned char gap_75[3];
    unsigned int random_seed;
    short curr_player;
    unsigned char gap_7E[2];
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

extern int world_update_counter;
extern int version_101;
extern int version_102;
extern int version_103;
extern int version_104;
extern int version_105;
extern int version_106;
extern int version_107;
extern int version_108;
extern int version_109;
extern int version_110;
extern int version_111;
extern RGE_Base_Game* rge_base_game;
extern float save_game_version;
extern int rge_write_error;

class TDebuggingLog {
public:
    void Log(const char*, ...);
};

class RGE_Unified_Visible_Map {
public:
    void suppress_updates(int);
};

class PathingSystem {
public:
    int initialize(int, int, RGE_Map*, RGE_Game_World*);
    void zeroObstructionMap();
};

class RGE_Game_Info {
public:
    virtual void unused_game_info_slot();
    virtual void deleting_destructor(int);
    char* get_current_player_name();
};

class AIPlayBook {
public:
    virtual ~AIPlayBook();
};

class TMousePointer {
public:
    void Poll();
};

extern TDebuggingLog* L;
extern PathingSystem pathSystem;
extern PathingSystem aiPathSystem;
extern int computerPlayerSetup[13];
extern int debug_timeGetTime_cnt;
extern int debug_timeGetTime_time;
extern int all_cp;
extern int debug_random_on;
extern int debug_timeGetTime_on;
extern int do_fixed_update;
extern int fixed_update_time;
extern short visible_combats;
extern TMousePointer* MouseSystem;
extern int logStatusOn;
extern unsigned long lastStatusLogTime;
extern FILE* logStatusFile;
extern FILE* DVlogf;
extern RGE_Static_Object** VIS_UNIT_objectsValue;
extern float DAT_00577a14;
extern float DAT_00577a10;

extern int __cdecl debug_rand(const char*, int);
extern void __cdecl debug_random_reset();
extern unsigned long __cdecl debug_timeGetTime(const char*, int);

extern "C" void __cdecl rge_read_uncompressed(int, void*, int);
extern "C" void __cdecl rge_read(int, void*, int);
extern "C" int __cdecl rge_close(int);
extern "C" void __cdecl rge_write(int, const void*, int);
extern "C" void __cdecl rge_write_uncompressed(int, const void*, int);
extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);
extern void __cdecl debug_srand(char*, int, unsigned int);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl rge_open(const char*, int, ...);
extern "C" int __cdecl _unlink(const char*);
extern "C" int __cdecl unlink(const char*);

#endif
