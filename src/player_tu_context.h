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
class RGE_Object_Node;
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
    void command_add_to_group(int, int, int, int);
    void command_remove_from_group(int, int, int);
    void command_create_group(int, int, int, int, int);
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
    virtual ~RGE_Game_World();
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
    int removeObject(int id);
    void updateObject(RGE_Static_Object*);
    void set_map_visible();
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
    virtual void notify_of_relation();
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
    virtual void* make_new_obj(void*, float, float, float);
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

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;
    RGE_Tile_List(int max_tiles);
    ~RGE_Tile_List();
    void add_node(int, int);
    void del_list();
    void get_list_info(int*, int*);
    int get_new_count();
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual void destroy();
    void update();
    void load_list(int file, RGE_Game_World* world);
    RGE_Object_Node* list;
    RGE_Object_Node* add_node(RGE_Static_Object*);
    void remove_node(RGE_Static_Object*, RGE_Object_Node*);
    void save(int);
    short number_of_objects;
    RGE_Object_List();
    ~RGE_Object_List();
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
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char value);
    virtual void do_resign(int value);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int value);
    virtual int isAlly(int value);
    virtual int isNeutral(int value);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int value, int stance);
    virtual void loadAIInformation(char*, char*, char*, int, int);
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int value);
    virtual int strategicNumber(int value);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int, int, int);
    // The executable has a vtable entry here, while make_scenario_obj is a
    // nonvirtual PDB owner.  Keep the ABI slot with the PDB method name.
    virtual RGE_Static_Object* make_scenario_obj();
    virtual void scenario_save(int file);
    virtual void scenario_load(int file, long* data, float version);
    virtual void scenario_postsave(int file);
    virtual void scenario_postload(int file, long* data, float version);
    virtual void load(int file);
    virtual void add_attribute_num(short, float, unsigned char);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int file);
    virtual void save2(int file);
    virtual void save_info(int file);
    virtual void random_start();
    virtual void* make_new_object();
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
    virtual void logMessage();
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int file, long* data, unsigned char flag);

    unsigned char get_resigned();
    int computerPlayer();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap_21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    RGE_Victory_Conditions* victory_conditions;
    RGE_Visible_Map* visible;
    RGE_Game_World* world;
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
    short attribute_num;
    unsigned char gap_4E[2];
    float* attributes;
    unsigned char culture;
    unsigned char gap_55[3];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
    unsigned char gap_82[2];
    unsigned char* relations;
    int unitDiplomacy[9];
    char gap_AC[0x24];
    int mutualExploredMask;
    int mutualVisibleMask;
    int nonMutualVisibleMask;
    char gap_DC[0x24];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    unsigned char gap_106[2];
    RGE_Color_Table* color_table;
    int tribe_effect;
    Visible_Resource_Manager* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;
    short replacement_terrain;
    short replacement_overlay;
    short replacement_overlay_shape;
    char gap_12E[2];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    unsigned char groups_used[127];
    unsigned char gap_21D[3];

    RGE_Player(int file, RGE_Game_World* world_arg, unsigned char player_id);
    RGE_Player(RGE_Game_World* world, RGE_Master_Player* master,
               unsigned char player_id, char* player_name,
               unsigned char master_id, unsigned char is_computer);
    void reset_selected();
    void remake_visible_map();
    void update_selected();
    void set_color_table(unsigned char table);
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
    void new_victory();
    void victory_if_game_on();
    void loss_if_game_on();
    void win_game_now();
    unsigned char check_victory_conditions();
    unsigned char check_ally_group(long&);
    unsigned char check_victory();
    unsigned char relation(long);
    void load_master_object(int file, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);
    RGE_Static_Object* make_scenario_obj(float x, float y, float z,
                                         short typeID, unsigned char objType,
                                         float param6);
    int pathingAttemptCap();
    void setPathingAttemptCap(int value);
    int pathingDelayCap();
    void setPathingDelayCap(int value);
    int currentUpdatePathingAttempts();
    int availablePathingAttempts(int value);
    void incrementPathingAttempts();
    long get_checksum();
    long create_checksum();
    void make_available(short, unsigned char);
    void* make_new_object(long, float, float, float, int);
    void copy_obj(short, short);
    int is_category_selected(short);
    int is_group_selected(short);
    void set_allied_victory(unsigned char);
    unsigned char get_allied_victory();
    void destroy_objects();
    void modify_tobj(short, short, float, unsigned char);
    void modify_tobj_delta(short, short, float, unsigned char);
    void modify_tobj_percent(short, short, float, unsigned char);
    int select_one_object(RGE_Static_Object*, int);
    void select_one_object(RGE_Static_Object*);
    int select_object(RGE_Static_Object*);
    void unselect_object();
    void unselect_one_object(short);
    void unselect_one_object(RGE_Static_Object*);
    int group_objects(int);
    int select_group(int);
    int own_selected();
    unsigned char unit_level_selected();
    unsigned char get_select_level();
    unsigned char get_selected_objects_to_command(RGE_Static_Object***,
        short*, short, short, short, short);
    unsigned char get_selected_objects_to_command(RGE_Static_Object***,
        int*, short, short, short, short);
    void select_area(short, short, short, short);
    void __cdecl sendChatMessage(int player, int mode, char* message, ...);
};

#endif
