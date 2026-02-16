#pragma once
#include "common.h"
#include "RGE_Tile_List.h"

class RGE_Player {
public:
    RGE_Player();
    RGE_Player(RGE_Game_World* world, RGE_Master_Player* master, uchar player_id, char* name, uchar civ, uchar is_computer, uchar is_active, char* ai1, char* ai2, char* ai3);
    RGE_Player(int param_1, RGE_Game_World* world, uchar player_id);

    // Virtuals (best-effort)
    virtual ~RGE_Player(); // vt[0] (0x0)
    virtual void set_game_status(uchar param_1); // vt[1] (0x4)
    virtual void do_resign(int param_1); // vt[2] (0x8)
    virtual void changeToHumanPlayer(); // vt[3] (0xC)
    virtual void changeToComputerPlayer(); // vt[4] (0x10)
    virtual char* aiStatus(int param_1); // vt[5] (0x14)
    virtual int isEnemy(int param_1); // vt[6] (0x18)
    virtual int isAlly(int param_1); // vt[7] (0x1C)
    virtual int isNeutral(int param_1); // vt[8] (0x20)
    virtual int isAllNeutral(); // vt[9] (0x24)
    virtual void setDiplomaticStance(int param_1, int param_2); // vt[10] (0x28)
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5); // vt[11] (0x2C)
    virtual void sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12); // vt[12] (0x30)
    virtual void processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12); // vt[13] (0x34)
    virtual void kickAI(int param_1); // vt[14] (0x38)
    virtual int strategicNumber(int param_1); // vt[15] (0x3C)
    virtual void sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4); // vt[16] (0x40)
    virtual void sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3); // vt[17] (0x44)
    virtual void processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3); // vt[18] (0x48)
    virtual void sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5); // vt[19] (0x4C)
    virtual void sendPlayCommand(int param_1, int param_2, int param_3); // vt[20] (0x50)
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5); // vt[21] (0x54)
    virtual int objectCostByType(int param_1); // vt[22] (0x58)
    virtual void trackUnitGather(int param_1, int param_2, int param_3); // vt[23] (0x5C)
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6); // vt[24] (0x60)
    virtual void scenario_save(int param_1); // vt[25] (0x64)
    virtual void scenario_load(int param_1, long* param_2, float param_3); // vt[26] (0x68)
    virtual void scenario_postsave(int param_1); // vt[27] (0x6C)
    virtual void scenario_postload(int param_1, long* param_2, float param_3); // vt[28] (0x70)
    virtual void load(int param_1); // vt[29] (0x74)
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3); // vt[30] (0x78)
    virtual void update(); // vt[31] (0x7C)
    virtual void update_dopplegangers(); // vt[32] (0x80)
    virtual void save(int param_1); // vt[33] (0x84)
    virtual void save2(int param_1); // vt[34] (0x88)
    virtual void save_info(int param_1); // vt[35] (0x8C)
    virtual void random_start(); // vt[36] (0x90)
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5); // vt[37] (0x94)
    virtual void analyize_selected_objects(); // vt[38] (0x98)
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3); // vt[39] (0x9C)
    virtual uchar command_make_move(RGE_Static_Object* param_1, float param_2, float param_3); // vt[40] (0xA0)
    virtual uchar command_make_work(RGE_Static_Object* param_1, float param_2, float param_3); // vt[41] (0xA4)
    virtual uchar command_make_do(RGE_Static_Object* param_1, float param_2, float param_3); // vt[42] (0xA8)
    virtual uchar command_stop(); // vt[43] (0xAC)
    virtual uchar command_place_object(short param_1, float param_2, float param_3, float param_4); // vt[44] (0xB0)
    virtual uchar command_add_attribute(int param_1, float param_2); // vt[45] (0xB4)
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3); // vt[46] (0xB8)
    virtual uchar command_formation(int param_1); // vt[47] (0xBC)
    virtual uchar command_stand_ground(); // vt[48] (0xC0)
    virtual uchar command_create_group(int param_1, int* param_2, int param_3, float param_4); // vt[49] (0xC4)
    virtual uchar command_add_to_group(int param_1, int param_2, float param_3); // vt[50] (0xC8)
    virtual uchar command_remove_from_group(int param_1, int param_2); // vt[51] (0xCC)
    virtual uchar command_destroy_group(int param_1); // vt[52] (0xD0)
    virtual uchar command_resign(int param_1, int param_2); // vt[53] (0xD4)
    virtual uchar command_add_waypoint(float param_1, float param_2, float param_3); // vt[54] (0xD8)
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3); // vt[55] (0xDC)
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4); // vt[56] (0xE0)
    virtual void logMessage(char* param_1); // vt[57] (0xE4)
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6); // vt[58] (0xE8)
    virtual void logStatus(FILE* param_1, int param_2); // vt[59] (0xEC)
    virtual void load_victory(int param_1, long* param_2, uchar param_3); // vt[60] (0xF0)
    virtual void new_victory(); // vt[61] (0xF4)

    // Non-virtual methods
    void new_attribute_num(short param_1, float param_2);
    void set_relation(long param_1, uchar param_2);
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
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
    void set_color_table(uchar param_1);
    void win_game_now();
    void victory_if_game_on();
    void loss_if_game_on();
    void set_allied_victory(uchar param_1);
    uchar get_allied_victory();
    uchar relation(long param_1);
    void reset_selected();
    void unselect_one_object(RGE_Static_Object* param_1);
    void unselect_one_object(short param_1);
    void select_one_object(RGE_Static_Object* param_1);
    void select_area(long param_1, long param_2, long param_3, long param_4);
    void unselect_area();
    void unselect_object();
    void update_selected();
    int select_object(RGE_Static_Object* param_1);

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
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
static_assert(sizeof(RGE_Player) == 0x220, "Size mismatch");
