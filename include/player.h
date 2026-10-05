#ifndef AOE1_PLAYER_H
#define AOE1_PLAYER_H

// These resource IDs also select the first four player attributes.
#define RGE_RESOURCE_FOOD   0
#define RGE_RESOURCE_WOOD   1
#define RGE_RESOURCE_STONE  2
#define RGE_RESOURCE_GOLD   3

// Visual cultures select building and interface art, not civilization IDs.
// These cleanup names describe shared styles; several civilizations can use one culture.
#define RGE_CULTURE_EGYPTIAN   0
#define RGE_CULTURE_GREEK      1
#define RGE_CULTURE_BABYLONIAN 2
#define RGE_CULTURE_EAST_ASIAN 3
#define RGE_CULTURE_ROMAN     4
#define RGE_CULTURE_COUNT     5

#include <stdio.h>

class RGE_Color_Table;
class RGE_Doppleganger_Creator;
class RGE_Game_World;
class RGE_Master_Player;
class RGE_Master_Static_Object;
class RGE_Object_List;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Tile_List;
class RGE_Victory_Conditions;
class RGE_Visible_Map;
class Visible_Resource_Manager;
struct RGE_Object_Node;
struct RGE_Tile_List_Node;
struct XYZBYTEPoint;

struct RGE_Tile_List_Node {
    int col;
    int row;
};

typedef char rge_tile_list_node_size_check[(sizeof(RGE_Tile_List_Node) == 0x08) ? 1 : -1];

class RGE_Tile_List {
  public:
    RGE_Tile_List(int Initial_Size);
    ~RGE_Tile_List();
    void add_node(int col, int row);
    void del_list();
    void get_list_info(RGE_Tile_List_Node*& theList, int& list_size);
    int get_new_count();

    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};

typedef char rge_tile_list_size_check[(sizeof(RGE_Tile_List) == 0x14) ? 1 : -1];

class RGE_Player {
  public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char new_status);
    virtual void do_resign(int dropped);
    virtual void changeToHumanPlayer() {
    }
    virtual void changeToComputerPlayer() {
    }
    virtual char* aiStatus(int sNum);
    virtual int isEnemy(int playerNum);
    virtual int isAlly(int playerNum);
    virtual int isNeutral(int playerNum);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int playerNum, int rType);
    virtual void loadAIInformation(char* bL, char* cP, char* rS, int mood, int mapType);
    virtual void sendUnitAIOrder(
        int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY,
        float targetZ, float range, int immediate, int inFront, int priority
    );
    virtual void processAIOrder(
        int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY,
        float targetZ, float range, int immediate, int inFront, int priority
    );
    virtual void kickAI(int) {
    }
    virtual int strategicNumber(int) {
        return -1;
    }
    virtual void sendGameOrder(RGE_Static_Object* unit, RGE_Static_Object* target, float targetX, float targetY);
    virtual void sendAddWaypointCommand(int recipient, XYZBYTEPoint* waypoint, int numWaypoints);
    virtual void processAddWaypointCommand(int recipient, XYZBYTEPoint* waypoint, int numWaypoints);
    virtual void sendPlayCommand(int recipient, int target, int playID);
    virtual void sendPlayCommand(int recipient, int* groupUnits, int groupCount, int target, int playID);
    virtual int sendAICommand(int, int, int, int, int) {
        return 0;
    }
    virtual int objectCostByType(int) {
        return -1;
    }
    virtual void trackUnitGather(int, int, int) {
    }
    virtual RGE_Static_Object* make_scenario_obj(
        float world_x, float world_y, float world_z, short master_id, unsigned char state, float new_angle
    );
    virtual void scenario_save(int outfile);
    virtual void scenario_load(int infile, long* player_id_hash, float version);
    virtual void scenario_postsave(int outfile);
    virtual void scenario_postload(int infile, long* player_id_hash, float version);
    virtual void load(int infile);
    virtual void add_attribute_num(short attribute, float amount, unsigned char earned);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int outfile);
    virtual void save2(int outfile);
    virtual void save_info(int outfile);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long obj_id, float x, float y, float z, int build_all_the_way);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int Obj_id, int& newFacet, int& text_id);
    virtual unsigned char command_make_move(RGE_Static_Object* obj, float x, float y);
    virtual unsigned char command_make_work(RGE_Static_Object* obj, float x, float y);
    virtual unsigned char command_make_do(RGE_Static_Object* obj, float x, float y);
    virtual unsigned char command_stop();
    virtual unsigned char command_place_object(short obj_id, float x, float y, float z);
    virtual unsigned char command_add_attribute(int attr_id, float attr_amount);
    virtual unsigned char command_give_attribute(int to_player_id, int attr_id, float attr_amount);
    virtual unsigned char command_formation(int formationID);
    virtual unsigned char command_stand_ground();
    virtual unsigned char command_create_group(int commander, int* groupList, int groupLength, float range);
    virtual unsigned char command_add_to_group(int commander, int unitID, float range);
    virtual unsigned char command_remove_from_group(int commander, int unitID);
    virtual unsigned char command_destroy_group(int unitID);
    virtual unsigned char command_resign(int comm_player_id, int dropped);
    virtual unsigned char command_add_waypoint(float x, float y, float z);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* obj, int sleep_flag, int dopple_flag);
    virtual void removeObject(RGE_Static_Object* obj, int sleep_flag, int dopple_flag, RGE_Object_Node* node);
    virtual void __cdecl logMessage(char* in, ...);
    virtual void notify(int caller, int recipient, int mType, long p1, long p2, long p3);
    virtual void logStatus(FILE*, int) {
    }
    virtual void load_victory(int infile, long* player_id_hash, unsigned char version_control);
    virtual void new_victory();

    RGE_Player(
        RGE_Game_World* gworld, RGE_Master_Player* prototype, unsigned char this_id, char* new_name,
        unsigned char m_player_id, unsigned char flag
    );
    RGE_Player(
        RGE_Game_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char, unsigned char, char*,
        char*, char*
    );
    RGE_Player(int infile, RGE_Game_World* gworld, unsigned char this_id);

    unsigned char get_resigned();
    int computerPlayer() const;
    int pathingAttemptCap();
    void setPathingAttemptCap(int);
    int pathingDelayCap();
    void setPathingDelayCap(int);
    int currentUpdatePathingAttempts();
    int availablePathingAttempts(int numWaitDelays);
    void incrementPathingAttempts();
    void __cdecl sendChatMessage(int playerID, int copySelf, char* textIn, ...);
    void reset_selected();
    void remake_visible_map();
    void update_selected();
    void set_color_table(unsigned char new_table);
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
    void load_info(int infile);
    unsigned char get_checksums(long& new_checksum, long& new_position_checksum, long& new_action_checksum);
    void new_attribute_num(short attribute, float amount);
    void set_relation(long player_id, unsigned char relation);
    void unselect_area();
    void ungroup_objects();
    void set_map_visible();
    void victory_if_game_on();
    void loss_if_game_on();
    void win_game_now();
    unsigned char check_victory_conditions();
    unsigned char check_ally_group(long& count);
    unsigned char check_victory();
    unsigned char relation(long player_id);
    void load_master_object(int infile, short index, unsigned char type, RGE_Sprite** sprites, RGE_Sound** sounds);
    long get_checksum();
    long create_checksum();
    void make_available(short obj_category, unsigned char on_off_flag);
    void copy_obj(short dest, short source);
    int is_category_selected(short object_category);
    int is_group_selected(short object_group);
    void set_allied_victory(unsigned char flag);
    unsigned char get_allied_victory();
    void destroy_objects();
    void modify_tobj(short obj_id, short group, float amount, unsigned char flag);
    void modify_tobj_delta(short obj_id, short group, float amount, unsigned char flag);
    void modify_tobj_percent(short obj_id, short group, float amount, unsigned char flag);
    int select_one_object(RGE_Static_Object* obj, int play_sound);
    void select_one_object(RGE_Static_Object*);
    int select_object(RGE_Static_Object* obj);
    void unselect_object();
    void unselect_one_object(short index);
    void unselect_one_object(RGE_Static_Object* obj);
    int group_objects(int id);
    int select_group(int id);
    int own_selected();
    unsigned char unit_level_selected();
    unsigned char get_select_level();
    unsigned char get_selected_objects_to_command(
        RGE_Static_Object*** list_in, short* list_num_in, short min_select_level, short object_group, short object_id,
        short unit_level
    );
    void select_area(short col1, short row1, short col2, short row2);

  protected:
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;

  public:
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
    short id;
    short attribute_num;
    float* attributes;
    unsigned char culture;
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
    unsigned char* relations;
    int unitDiplomacy[9];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    int allied_LOS_Enable;
    unsigned char allied_victory;
    unsigned char master_player_id;
    RGE_Color_Table* color_table;
    long tribe_effect;
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
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
    unsigned char groups_used[127];
};

typedef char rge_player_size_check[(sizeof(RGE_Player) == 0x220) ? 1 : -1];

#endif
