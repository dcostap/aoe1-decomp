#ifndef AOE1_PLAYER_CONTEXT_H
#define AOE1_PLAYER_CONTEXT_H

// Canonical declarations for the reviewed player.cpp owner span.
//
// This surface comes from the constructor/load audit in
// build/audit_player_full_context.cpp.  Keep the member offsets and virtual
// order stable.  The owner files supply the function bodies.

class RGE_Player;
class RGE_Sprite;
class RGE_Sound;
class RGE_Master_Player;
class RGE_Static_Object;

class RGE_Map {
public:
    virtual ~RGE_Map();
    void* map;
    int map_width;
    int map_height;
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
    char gap_04[0x24];
    RGE_Map* map;
    char gap_2C[0x04];
    RGE_Sound** sounds;
    char gap_34[0x04];
    RGE_Sprite** sprites;
    short player_num;
    char gap_3E[0x0E];
    RGE_Effects* effects;
};

class RGE_Static_Object {
public:
    virtual void vf00_0();
    virtual void vf00_1();
    virtual void vf00_2();
    virtual void vf00_3();
    virtual void vf00_4();
    virtual void vf00_5();
    virtual void vf00_6();
    virtual void vf00_7();
    virtual void vf00_8();
    virtual void vf00_9();
    virtual void vf00_A();
    virtual void vf00_B();
    virtual void vf00_C();
    virtual void vf00_D();
    virtual void vf00_E();
    virtual void vf00_F();
    virtual void vf00_10();
    virtual void vf00_11();
    virtual void vf00_12();
    virtual void vf00_13();
    virtual void vf00_14();
    virtual void vf00_15();
    virtual void vf00_16();
    virtual void vf00_17();
    virtual void vf00_18();
    virtual void vf00_19();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf00_28();
    virtual void vf00_29();
    virtual void vf00_2A();
    virtual void vf00_2B();
    virtual void vf00_2C();
    virtual void vf00_2D();
    virtual void vf00_2E();
    virtual void vf00_2F();
    virtual void vf00_30();
    virtual void vf00_31();
    virtual void vf00_32();
    virtual void vf00_33();
    virtual void vf00_34();
    virtual void vf00_35();
    virtual void vf00_36();
    virtual void vf00_37();
    virtual void vf00_38();
    virtual void vfB4(float value);
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(void*, float, float, float);
    virtual RGE_Master_Static_Object* copy_obj();
    RGE_Master_Static_Object(int file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int mode);
    char gap_04[0xB4];
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
};

class RGE_Object_List {
public:
    virtual void destroy();
    void load_list(int file, RGE_Game_World* world);
    int list;
    short number_of_objects;

    RGE_Object_List();
    ~RGE_Object_List();
};

class RGE_Victory_Conditions {
public:
    ~RGE_Victory_Conditions();
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void save(int file);
};

class Visible_Resource_Manager {
public:
    ~Visible_Resource_Manager();
    char pad[0x14];
    Visible_Resource_Manager(int file, RGE_Player* player);
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
    virtual void sendGameOrder(void*, void*, float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int value);
    virtual void trackUnitGather(int, int, int);
    virtual void vf60();
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
    virtual void* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual unsigned char command_make_move(void*, float, float);
    virtual unsigned char command_make_work(void*, float, float);
    virtual unsigned char command_make_do(void*, float, float);
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
    virtual void* addObject(void*, int, int);
    virtual void removeObject(void*, int, int, void*);
    virtual void logMessage(char*);
    virtual void notify(int, int, int, long, long, long);
    virtual void logStatus(void*, int);
    virtual void load_victory(int file, long* data, unsigned char flag);
    virtual void vfF4();

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
    void* color_table;
    int tribe_effect;
    Visible_Resource_Manager* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    char gap_120[0x100];

    RGE_Player(int file, RGE_Game_World* world_arg, unsigned char player_id);
    RGE_Player(RGE_Game_World* world, RGE_Master_Player* master,
               unsigned char player_id, char* player_name,
               unsigned char master_id, unsigned char is_computer);
    void reset_selected();
    void set_color_table(unsigned char table);
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
    void new_victory();
    void load_master_object(int file, short index, unsigned char type,
                            RGE_Sprite** sprites, RGE_Sound** sounds);
    RGE_Static_Object* make_scenario_obj(float x, float y, float z,
                                         short typeID, unsigned char objType,
                                         float param6);
};

#endif
