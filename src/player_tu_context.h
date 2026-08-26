#ifndef AOE1_PLAYER_TU_CONTEXT_H
#define AOE1_PLAYER_TU_CONTEXT_H

// PDB-supported player.cpp module context.  This is local to the candidate
// translation unit.  It keeps the reviewed offsets and call surfaces without
// placeholder virtual names or raw vtable fields.

class RGE_Player;
class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Player;
class RGE_Master_Static_Object;
class RGE_Static_Object;
struct RGE_Object_Node;
struct RGE_Tile_List_Node;
struct RGE_Player_Info;
class RGE_Scenario;
class TSound_Driver;
struct _iobuf;
typedef struct _iobuf FILE;

#include "../include/rge_player_context.h"

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char gap_04[0x22];
    short id;
};
class RGE_Sound {
public:
    void play(int);
};
class TMousePointer {
public:
    void Poll();
};
extern TMousePointer* MouseSystem;

class TCommunications_Handler {
public:
    void SendChatMsg(unsigned int player, unsigned int to, char* text);
    int GetPlayerHumanity(int player);
};
extern TCommunications_Handler* comm;

class AIPlay;
class AIPlayBook {
public:
    AIPlay* play(int id);
};

struct XYZBYTEPoint {
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x10];
    TCommunications_Handler* com_hand;
    void command_order(RGE_Static_Object**, int, RGE_Static_Object*, float, float);
    void command_add_waypoint(int, int, int, int);
    void command_create(short, short, float, float, float);
    void command_formation(RGE_Static_Object**, int, int);
    void command_group_waypoint(RGE_Static_Object**, short, int, int);
    void command_group_ai_order(int, int, RGE_Static_Object**, short, int, int, int,
                                float, float, float, float, unsigned char,
                                unsigned char, unsigned char);
    void command_add_attribute(int, int, float);
    void command_give_attribute(int, int, int, int);
    void command_add_to_group(int, int, int, float);
    void command_remove_from_group(int, int, int);
    void command_create_group(int, int, int*, int, float);
    void command_destroy_group(int, int);
    void command_resign(int, int, int);
    void command_work(RGE_Static_Object**, short, RGE_Static_Object*, float, float);
    void command_ai_order(int, int, int, int, int, int, int, int, int,
                          int, int, int, int);
};

class UnitAIModule {
public:
    // These names are present in the PDB class surface.  The player caller
    // uses the fifth slot at +0x10 for its module-specific dispatch.
    virtual void save();
    virtual void load();
    virtual void owner();
    virtual void object();
    virtual void processAIOrder(int, int, int, int, float, float, float,
                                float, int, int, int);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void run(int);
    virtual void wnd_proc(int);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int);
    virtual void set_player(int);
    virtual void get_error_code(int);
    virtual void get_string(int);
    virtual void get_string2(int);
    virtual void new_scenario_header(int);
    virtual void new_scenario_info(int);
    virtual void reset_comm(int);
    virtual void send_game_options(int);
    virtual void receive_game_options(int);
    virtual void gameSummary(int);
    virtual void processCheatCode(int, int);
    virtual void notification(int, int, int, int, int);
    int numberPlayers();
    int playerID(int player);
    int playerTeam(int player);
    char gap_04[0x1AC];
    int prog_mode;
};
extern RGE_Base_Game* rge_base_game;

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;
    int map_width;
    int map_height;
    void setVisible(int);
};

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save(int file);
    virtual void do_effect(short effect, RGE_Player* player);
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
protected:
    virtual void data_load_map(char*, char*, char*, char*, short, short, short,
                               RGE_Sound**, char*);
public:
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
    virtual void scenario_make_player(short, unsigned char, unsigned char,
                                      unsigned char, char*);
    virtual void scenario_make_map(int);
    virtual unsigned char load_scenario(RGE_Player_Info&);
    virtual unsigned char load_scenario(char*, RGE_Player_Info&);
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
    virtual void setup_player_colors();
    virtual void setup_player_colors(RGE_Player_Info&);
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
    virtual void base_save(char*);
    virtual void base_save(int);
    virtual unsigned char save_scenario(char*);
    virtual RGE_Scenario* get_scenario_info(char*);
    virtual void pause(unsigned char);
    virtual void scenario_init(RGE_Game_World*);
    virtual void scenario_init(int, RGE_Game_World*);
    virtual int addObject(RGE_Static_Object*);
    virtual int removeObject(int);

    char gap_04[0x1A];
    unsigned char game_end_condition;
    char gap_1F[0x09];
    RGE_Map* map;
    char gap_2C[0x04];
    RGE_Sound** sounds;
    char gap_34[0x04];
    RGE_Sprite** sprites;
    short player_num;
    char gap_3E[0x02];
    RGE_Player** players;
    char gap_44[0x08];
    RGE_Effects* effects;
    char gap_50[0x08];
    RGE_Command* command;
    char gap_5C[0x08];
    RGE_Color_Table** color_tables;
    char gap_68[0x38];
    AIPlayBook* playbook;
    RGE_Static_Object* object(int id);
    void updateObject(RGE_Static_Object*);
    void reset_object_count();
    void set_map_visible();
    void set_map_fog(unsigned char);
    void reset_communications(TCommunications_Handler*);
    void update_sounds(unsigned long);
    void update_sprites(unsigned long);
    void reset_player_visible_maps();
    void update_mutual_allies();
    int numberObjects();
    int numberNegativeObjects();
    int maxNumberObjects();
    int maxNumberNegativeObjects();
    RGE_Static_Object* object_ptr(int);
    long get_next_object_id();
    long get_next_reusable_object_id();
    int initializePathingSystem();
    int is_player_turn(int);
    int get_accum_time_delta(int);
    int difficultyLevel();
    void selectNextComputerPlayer(int);
    void useComputerPlayerUpdateTime(unsigned long);
    int computerPlayerUpdateTimeAvailable();
    int objectGroupOnTile(int, int, int, int, int&);
    unsigned char recycle_object_out_of_game(unsigned char, void*);
    RGE_Static_Object* recycle_object_in_to_game(unsigned char);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate();
    virtual unsigned char can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual int heal();
    virtual unsigned char heal(float);
    virtual int canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*, float, float, float);
    void destroy();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Static_Object* inside_obj;
    char gap_14[0x22];
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    char gap_49[0x2B];
    UnitAIModule* field_74;
    UnitAIModule* unitAI();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual RGE_Master_Static_Object* copy_obj();
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(void*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void play_command_sound();
    void make_available(unsigned char);
    RGE_Master_Static_Object(int file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int mode);
    unsigned char master_type;
    char gap_05[0x0B];
    short id;
    char gap_12[2];
    short object_group;
    char gap_16[0x77];
    unsigned char select_level;
    unsigned char gap_8E;
    unsigned char unit_level;
    char gap_90[0x28];
    float los;
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    char gap_04[0x14];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    float* attributes;
    unsigned char culture;
    unsigned char gap_29;
    short tribe_effect;
};

struct RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
    unsigned char gap_0D[3];
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Conditions(RGE_Player*, int, long*, unsigned char);
    RGE_Victory_Conditions(RGE_Player*);
    ~RGE_Victory_Conditions();
    virtual void handle_point_condition();
    virtual void handle_condition();
    virtual char* condition_description();
    virtual void save(int file);
    unsigned char update();
    unsigned char victory_achieved();
};

class Visible_Resource_Manager {
public:
    ~Visible_Resource_Manager();
    char pad[0x14];
    Visible_Resource_Manager(int file, RGE_Player* player);
    void Process_New_Tiles(RGE_Tile_List* tile_list);
    void save(int);
};

class RGE_Visible_Map {
public:
    ~RGE_Visible_Map();
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    unsigned long PlayerVisibleMaskValue;
    unsigned long PlayerVisibleMaskInvertValue;
    unsigned long PlayerExploredMaskValue;
    unsigned long PlayerExploredMaskInvertValue;
    unsigned long input_csum;
    RGE_Visible_Map(RGE_Map* map, RGE_Player* player);
    RGE_Visible_Map(int file, RGE_Game_World* world);
    void save(int);
};

class RGE_Doppleganger_Creator {
public:
    ~RGE_Doppleganger_Creator();
    RGE_Player* owner;
    int allocated_size;
    int active_size;
    void* Objects;
    void* Map_Addresses;
    void* Last_Map_Value;
    void* Object_ids;
    RGE_Doppleganger_Creator(RGE_Player* player, int max_count);
    void perform_doppleganger_checks();
};

#endif
