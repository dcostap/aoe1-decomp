#pragma once
#include "common.h"

class RGE_Player : public RGE_Tile_List {
public:
    long checksum;                           // 0x14
    long position_checksum;                  // 0x18
    long action_checksum;                    // 0x1C
    uchar checksum_created_this_update;      // 0x20
    short master_object_num;                 // 0x22
    RGE_Master_Static_Object** master_objects; // 0x24
    RGE_Object_List* objects;                // 0x28
    RGE_Object_List* sleeping_objects;       // 0x2C
    RGE_Object_List* doppleganger_objects;   // 0x30
    RGE_Victory_Conditions* victory_conditions; // 0x34
    RGE_Visible_Map* visible;                // 0x38
    RGE_Game_World* world;                   // 0x3C
    RGE_Doppleganger_Creator* doppleganger_creator; // 0x40
    char* name;                              // 0x44
    uchar type;                              // 0x48
    short id;                                // 0x4A
    short attribute_num;                     // 0x4C
    float* attributes;                       // 0x50
    uchar culture;                           // 0x54
    RGE_Tile_List tile_list;                 // 0x58
    RGE_Tile_List diam_tile_list;            // 0x6C
    uchar game_status;                       // 0x80
    uchar resigned;                          // 0x81
    uchar* relations;                        // 0x84
    int unitDiplomacy[9];                    // 0x88
    int mutualAlly[9];                       // 0xAC
    ulong mutualExploredMask;                // 0xD0
    ulong mutualVisibleMask;                 // 0xD4
    ulong nonMutualVisibleMask;              // 0xD8
    ulong RemoveVisibleBits[9];              // 0xDC
    int allied_LOS_Enable;                   // 0x100
    uchar allied_victory;                    // 0x104
    uchar master_player_id;                  // 0x105
    RGE_Color_Table* color_table;            // 0x108
    long tribe_effect;                       // 0x10C
    Visible_Resource_Manager* VR_List;       // 0x110
    float view_x;                            // 0x114
    float view_y;                            // 0x118
    short map_x;                             // 0x11C
    short map_y;                             // 0x11E
    short selected_start_col;                // 0x120
    short selected_start_row;                // 0x122
    short selected_end_col;                  // 0x124
    short selected_end_row;                  // 0x126
    short replacement_terrain;               // 0x128
    short replacement_overlay;               // 0x12A
    short replacement_overlay_shape;         // 0x12C
    RGE_Static_Object* selected_obj;         // 0x130
    RGE_Static_Object* sel_list[25];         // 0x134
    ulong sel_object_properties;             // 0x198
    short sel_count;                         // 0x19C
    uchar groups_used[127];                  // 0x19E

    virtual void set_game_status(uchar param_1);            // vt0[1]+0x4=0x46ECE0
    virtual void do_resign(int param_1);                    // vt0[2]+0x8=0x46ED50
    virtual void changeToHumanPlayer();                     // vt0[3]+0xC=0x46EC80
    virtual void changeToComputerPlayer();                  // vt0[4]+0x10=0x46EC90
    virtual char* aiStatus(int param_1);                    // vt0[5]+0x14=0x46EDA0
    virtual int isEnemy(int param_1);                       // vt0[6]+0x18=0x46EDC0
    virtual int isAlly(int param_1);                        // vt0[7]+0x1C=0x46EE00
    virtual int isNeutral(int param_1);                     // vt0[8]+0x20=0x46EE40
    virtual int isAllNeutral();                             // vt0[9]+0x24=0x46EE80
    virtual void setDiplomaticStance(int param_1, int param_2); // vt0[10]+0x28=0x46EED0
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5); // vt0[11]+0x2C=0x46EEE0
    virtual void sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12); // vt0[12]+0x30=0x46EEF0
    virtual void processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12); // vt0[13]+0x34=0x46EF40
    virtual void kickAI(int param_1);                       // vt0[14]+0x38=0x46ECA0
    virtual int strategicNumber(int param_1);               // vt0[15]+0x3C=0x46ECB0
    virtual void sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4); // vt0[16]+0x40=0x46EFB0
    virtual void sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3); // vt0[17]+0x44=0x46EFE0
    virtual void processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3); // vt0[18]+0x48=0x46F010
    virtual void sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5); // vt0[19]+0x4C=0x46F140
    virtual void sendPlayCommand(int param_1, int param_2, int param_3); // vt0[20]+0x50=0x46F050
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5); // vt0[21]+0x54=0x46ECC0
    virtual int objectCostByType(int param_1);              // vt0[22]+0x58=0x46ECD0
    virtual void trackUnitGather(int param_1, int param_2, int param_3); // vt0[23]+0x5C=0x46ED30
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6); // vt0[24]+0x60=0x46F3A0
    virtual void scenario_save(int param_1);                // vt0[25]+0x64=0x46F410
    virtual void scenario_load(int param_1, long* param_2, float param_3); // vt0[26]+0x68=0x46F420
    virtual void scenario_postsave(int param_1);            // vt0[27]+0x6C=0x46F6B0
    virtual void scenario_postload(int param_1, long* param_2, float param_3); // vt0[28]+0x70=0x46F7A0
    virtual void load(int param_1);                         // vt0[29]+0x74=0x46FA60
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3); // vt0[30]+0x78=0x4700D0
    virtual void update();                                  // vt0[31]+0x7C=0x470120
    virtual void update_dopplegangers();                    // vt0[32]+0x80=0x470180
    virtual void save(int param_1);                         // vt0[33]+0x84=0x4701B0
    virtual void save2(int param_1);                        // vt0[34]+0x88=0x470380
    virtual void save_info(int param_1);                    // vt0[35]+0x8C=0x470490
    virtual void random_start();                            // vt0[36]+0x90=0x470570
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5); // vt0[37]+0x94=0x470C70
    virtual void analyize_selected_objects();               // vt0[38]+0x98=0x471520
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3); // vt0[39]+0x9C=0x471530
    virtual uchar command_make_move(RGE_Static_Object* param_1, float param_2, float param_3); // vt0[40]+0xA0=0x471550
    virtual uchar command_make_work(RGE_Static_Object* param_1, float param_2, float param_3); // vt0[41]+0xA4=0x4715D0
    virtual uchar command_make_do(RGE_Static_Object* param_1, float param_2, float param_3); // vt0[42]+0xA8=0x4716D0
    virtual uchar command_stop();                           // vt0[43]+0xAC=0x471760
    virtual uchar command_place_object(short param_1, float param_2, float param_3, float param_4); // vt0[44]+0xB0=0x4717D0
    virtual uchar command_add_attribute(int param_1, float param_2); // vt0[45]+0xB4=0x471820
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3); // vt0[46]+0xB8=0x471860
    virtual uchar command_formation(int param_1);           // vt0[47]+0xBC=0x4718C0
    virtual uchar command_stand_ground();                   // vt0[48]+0xC0=0x471940
    virtual uchar command_create_group(int param_1, int* param_2, int param_3, float param_4); // vt0[49]+0xC4=0x4719D0
    virtual uchar command_add_to_group(int param_1, int param_2, float param_3); // vt0[50]+0xC8=0x471A00
    virtual uchar command_remove_from_group(int param_1, int param_2); // vt0[51]+0xCC=0x471A30
    virtual uchar command_destroy_group(int param_1);       // vt0[52]+0xD0=0x471A50
    virtual uchar command_resign(int param_1, int param_2); // vt0[53]+0xD4=0x471A70
    virtual uchar command_add_waypoint(float param_1, float param_2, float param_3); // vt0[54]+0xD8=0x471AA0
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3); // vt0[55]+0xDC=0x471B20
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4); // vt0[56]+0xE0=0x471B70
    virtual void logMessage(char* param_1);                 // vt0[57]+0xE4=0x471BD0
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt0[58]+0xE8=0x471BE0
    virtual void logStatus(_iobuf* param_1, int param_2);   // vt0[59]+0xEC=0x46ED40
    virtual void load_victory(int param_1, long* param_2, uchar param_3); // vt0[60]+0xF0=0x471C90
    virtual void new_victory();                             // vt0[61]+0xF4=0x471D00
    RGE_Player(int param_1, RGE_Game_World* param_2, uchar param_3);
    RGE_Player(RGE_Game_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6);
    ~RGE_Player();
    uchar get_resigned();
    int computerPlayer();
    int pathingAttemptCap();
    void setPathingAttemptCap(int param_1);
    int pathingDelayCap();
    void setPathingDelayCap(int param_1);
    int currentUpdatePathingAttempts();
    int availablePathingAttempts(int param_1);
    void incrementPathingAttempts();
    void sendChatMessage(int param_1, int param_2, char* param_3);
    void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
    void load_info(int param_1);
    long get_checksum();
    uchar get_checksums(long* param_1, long* param_2, long* param_3);
    long create_checksum();
    void new_attribute_num(short param_1, float param_2);
    void make_available(short param_1, uchar param_2);
    void set_map_loc(short param_1, short param_2);
    void set_view_loc(float param_1, float param_2);
    void destroy_objects();
    void set_color_table(uchar param_1);
    void victory_if_game_on();
    void loss_if_game_on();
    void win_game_now();
    uchar check_victory_conditions();
    uchar check_ally_group(long* param_1);
    uchar check_victory();
    void modify_tobj(short param_1, short param_2, float param_3, uchar param_4);
    void modify_tobj_delta(short param_1, short param_2, float param_3, uchar param_4);
    void modify_tobj_percent(short param_1, short param_2, float param_3, uchar param_4);
    void copy_obj(short param_1, short param_2);
    void set_allied_victory(uchar param_1);
    uchar get_allied_victory();
    uchar relation(long param_1);
    void set_relation(long param_1, uchar param_2);
    void reset_selected();
    int select_object(RGE_Static_Object* param_1);
    int select_one_object(RGE_Static_Object* param_1, int param_2);
    void unselect_object();
    void unselect_one_object(RGE_Static_Object* param_1);
    void unselect_one_object(short param_1);
    int group_objects(int param_1);
    int select_group(int param_1);
    int own_selected();
    int is_category_selected(short param_1);
    int is_group_selected(short param_1);
    uchar unit_level_selected();
    uchar get_select_level();
    uchar get_selected_objects_to_command(RGE_Static_Object*** param_1, short* param_2, short param_3, short param_4, short param_5, short param_6);
    void update_selected();
    void select_area(short param_1, short param_2, short param_3, short param_4);
    void unselect_area();
    void ungroup_objects();
    void set_map_visible();
    void remake_visible_map();
    void update_dopplegangers();
};

static_assert(sizeof(RGE_Player) == 0x220, "RGE_Player Size Mismatch");

class RGE_Tile_List {
public:
    int list_size;                           // 0x0
    int num_active;                          // 0x4
    int new_count;                           // 0x8
    int collapse_list;                       // 0xC
    RGE_Tile_List_Node* list;                // 0x10

    void add_node(int param_1, int param_2);
    void del_list();
    RGE_Tile_List(int param_1);
    ~RGE_Tile_List();
    void get_list_info(RGE_Tile_List_Node** param_1, int* param_2);
    int get_new_count();
};

static_assert(sizeof(RGE_Tile_List) == 0x14, "RGE_Tile_List Size Mismatch");

