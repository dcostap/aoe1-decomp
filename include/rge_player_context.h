#ifndef AOE1_RGE_PLAYER_CONTEXT_H
#define AOE1_RGE_PLAYER_CONTEXT_H

// Canonical RGE_Player declaration shared by focused and grouped builds.
// The beta vtable places the three-argument play command before the
// five-argument play command.

class RGE_Static_Object;
class RGE_Game_World;
class RGE_Visible_Map;
class RGE_Master_Player;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Victory_Conditions;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class Visible_Resource_Manager;
class RGE_Sprite;
class RGE_Sound;
struct RGE_Object_Node;
struct RGE_Tile_List_Node;
struct XYZBYTEPoint;
struct _iobuf;
typedef struct _iobuf FILE;

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
    RGE_Tile_List(int max_tiles);
    ~RGE_Tile_List();
    void add_node(int, int);
    void del_list();
    void get_list_info(RGE_Tile_List_Node*&, int&);
    int get_new_count();
};

class RGE_Object_List {
public:
    virtual void load(unsigned char, int, RGE_Game_World*);
    void update();
    void load_list(int, RGE_Game_World*);
    RGE_Object_Node* list;
    RGE_Object_Node* add_node(RGE_Static_Object*);
    void remove_node(RGE_Static_Object*, RGE_Object_Node*);
    void rehook_list();
    void save(int);
    short number_of_objects;
    RGE_Object_List();
    ~RGE_Object_List();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  unsigned char, float);
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
    virtual int get_mouse_pointer_action_vars(int, int&, int&);
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
    virtual void __cdecl logMessage(char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(FILE*, int);
    virtual void load_victory(int, long*, unsigned char);
    virtual void new_victory();

    unsigned char get_resigned();
    int computerPlayer() const;

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
    RGE_Visible_Map* visible; // PDB RGE_Player +0x38
    RGE_Game_World* world; // PDB RGE_Player +0x3C
    RGE_Doppleganger_Creator* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id; // PDB RGE_Player +0x4A
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
    void load_info(int);
    unsigned char get_checksums(long&, long&, long&);
    void new_attribute_num(short, float);
    void set_relation(long, unsigned char);
    void unselect_area();
    void ungroup_objects();
    void set_map_visible();
    void victory_if_game_on();
    void loss_if_game_on();
    void win_game_now();
    unsigned char check_victory_conditions();
    unsigned char check_ally_group(long&);
    unsigned char check_victory();
    unsigned char relation(long);
    void load_master_object(int file, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);
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
