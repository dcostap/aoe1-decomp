#pragma once
#include "../common.h"

class RGE_Tile_List {
public:
    int num_active;                          // 0x4
    int new_count;                           // 0x8
    int collapse_list;                       // 0xC
    RGE_Tile_List_Node* list;                // 0x10

    virtual void add_node(int param_1, int param_2);
    virtual void del_list();
    RGE_Tile_List(int param_1);
    virtual ~RGE_Tile_List();
    virtual void get_list_info(RGE_Tile_List_Node** param_1, int* param_2);
    virtual int get_new_count();
};

static_assert(sizeof(RGE_Tile_List) == 0x14, "RGE_Tile_List Size Mismatch");
static_assert(offsetof(RGE_Tile_List, list) == 0x10, "RGE_Tile_List Offset Mismatch");

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

    RGE_Player(int param_1, RGE_Game_World* param_2, uchar param_3);
    RGE_Player(RGE_Game_World* param_1, RGE_Master_Player* param_2, uchar param_3, char* param_4, uchar param_5, uchar param_6);
    virtual ~RGE_Player();
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual void kickAI(int param_1);
    virtual int strategicNumber(int param_1);
    virtual int sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5);
    virtual int objectCostByType(int param_1);
    virtual void set_game_status(uchar param_1);
    virtual void trackUnitGather(int param_1, int param_2, int param_3);
    virtual void logStatus(_iobuf* param_1, int param_2);
    virtual void do_resign(int param_1);
    virtual uchar get_resigned();
    virtual char* aiStatus(int param_1);
    virtual int computerPlayer();
    virtual int isEnemy(int param_1);
    virtual int isAlly(int param_1);
    virtual int isNeutral(int param_1);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int param_1, int param_2);
    virtual void loadAIInformation(char* param_1, char* param_2, char* param_3, int param_4, int param_5);
    virtual void sendUnitAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12);
    virtual void processAIOrder(int param_1, int param_2, int param_3, int param_4, int param_5, float param_6, float param_7, float param_8, float param_9, int param_10, int param_11, int param_12);
    virtual void sendGameOrder(RGE_Static_Object* param_1, RGE_Static_Object* param_2, float param_3, float param_4);
    virtual void sendAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3);
    virtual void processAddWaypointCommand(int param_1, XYZBYTEPoint* param_2, int param_3);
    virtual void sendPlayCommand(int param_1, int param_2, int param_3);
    virtual void sendPlayCommand(int param_1, int* param_2, int param_3, int param_4, int param_5);
    virtual int pathingAttemptCap();
    virtual void setPathingAttemptCap(int param_1);
    virtual int pathingDelayCap();
    virtual void setPathingDelayCap(int param_1);
    virtual int currentUpdatePathingAttempts();
    virtual int availablePathingAttempts(int param_1);
    virtual void incrementPathingAttempts();
    virtual void sendChatMessage(int param_1, int param_2, char* param_3);
    virtual RGE_Static_Object* make_scenario_obj(float param_1, float param_2, float param_3, short param_4, uchar param_5, float param_6);
    virtual void scenario_save(int param_1);
    virtual void scenario_load(int param_1, long* param_2, float param_3);
    virtual void scenario_postsave(int param_1);
    virtual void scenario_postload(int param_1, long* param_2, float param_3);
    virtual void load(int param_1);
    virtual void load_master_object(int param_1, short param_2, uchar param_3, RGE_Sprite** param_4, RGE_Sound** param_5);
    virtual void load_info(int param_1);
    virtual long get_checksum();
    virtual uchar get_checksums(long* param_1, long* param_2, long* param_3);
    virtual long create_checksum();
    virtual void new_attribute_num(short param_1, float param_2);
    virtual void add_attribute_num(short param_1, float param_2, uchar param_3);
    virtual void make_available(short param_1, uchar param_2);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int param_1);
    virtual void save2(int param_1);
    virtual void save_info(int param_1);
    virtual void set_map_loc(short param_1, short param_2);
    virtual void set_view_loc(float param_1, float param_2);
    virtual void random_start();
    virtual void destroy_objects();
    virtual void set_color_table(uchar param_1);
    virtual void victory_if_game_on();
    virtual void loss_if_game_on();
    virtual void win_game_now();
    virtual uchar check_victory_conditions();
    virtual uchar check_ally_group(long* param_1);
    virtual uchar check_victory();
    virtual void modify_tobj(short param_1, short param_2, float param_3, uchar param_4);
    virtual void modify_tobj_delta(short param_1, short param_2, float param_3, uchar param_4);
    virtual void modify_tobj_percent(short param_1, short param_2, float param_3, uchar param_4);
    virtual void copy_obj(short param_1, short param_2);
    virtual void set_allied_victory(uchar param_1);
    virtual uchar get_allied_victory();
    virtual uchar relation(long param_1);
    virtual void set_relation(long param_1, uchar param_2);
    virtual RGE_Static_Object* make_new_object(long param_1, float param_2, float param_3, float param_4, int param_5);
    virtual void reset_selected();
    virtual int select_object(RGE_Static_Object* param_1);
    virtual int select_one_object(RGE_Static_Object* param_1, int param_2);
    virtual void unselect_object();
    virtual void unselect_one_object(RGE_Static_Object* param_1);
    virtual void unselect_one_object(short param_1);
    virtual int group_objects(int param_1);
    virtual int select_group(int param_1);
    virtual int own_selected();
    virtual int is_category_selected(short param_1);
    virtual int is_group_selected(short param_1);
    virtual uchar unit_level_selected();
    virtual uchar get_select_level();
    virtual uchar get_selected_objects_to_command(RGE_Static_Object*** param_1, short* param_2, short param_3, short param_4, short param_5, short param_6);
    virtual void update_selected();
    virtual void select_area(short param_1, short param_2, short param_3, short param_4);
    virtual void unselect_area();
    virtual void ungroup_objects();
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int param_1, int* param_2, int* param_3);
    virtual uchar command_make_move(RGE_Static_Object* param_1, float param_2, float param_3);
    virtual uchar command_make_work(RGE_Static_Object* param_1, float param_2, float param_3);
    virtual uchar command_make_do(RGE_Static_Object* param_1, float param_2, float param_3);
    virtual uchar command_stop();
    virtual uchar command_place_object(short param_1, float param_2, float param_3, float param_4);
    virtual uchar command_add_attribute(int param_1, float param_2);
    virtual uchar command_give_attribute(int param_1, int param_2, float param_3);
    virtual uchar command_formation(int param_1);
    virtual uchar command_stand_ground();
    virtual uchar command_create_group(int param_1, int* param_2, int param_3, float param_4);
    virtual uchar command_add_to_group(int param_1, int param_2, float param_3);
    virtual uchar command_remove_from_group(int param_1, int param_2);
    virtual uchar command_destroy_group(int param_1);
    virtual uchar command_resign(int param_1, int param_2);
    virtual uchar command_add_waypoint(float param_1, float param_2, float param_3);
    virtual RGE_Object_Node* addObject(RGE_Static_Object* param_1, int param_2, int param_3);
    virtual void removeObject(RGE_Static_Object* param_1, int param_2, int param_3, RGE_Object_Node* param_4);
    virtual void logMessage(char* param_1);
    virtual void notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    virtual void set_map_visible();
    virtual void remake_visible_map();
    virtual void load_victory(int param_1, long* param_2, uchar param_3);
    virtual void new_victory();
};

static_assert(sizeof(RGE_Player) == 0x220, "RGE_Player Size Mismatch");
static_assert(offsetof(RGE_Player, groups_used) == 0x19E, "RGE_Player Offset Mismatch");

void RGE_Player::changeToHumanPlayer() {
    /* TODO: Stub */
//                              void __thiscall changeToHumanPlayer(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?changeToHumanPlayer@RGE_Player@@UAEXXZ                      XREF[1]:     00570edc(*)
//                               RGE_Player::changeToHumanPlayer
//                              player.h:173 (1)
//         0046ec80     RET
//         0046ec81     ??         90h
//         0046ec82     NOP
//         0046ec83     NOP
//         0046ec84     NOP
//         0046ec85     NOP
//         0046ec86     NOP
//         0046ec87     NOP
//         0046ec88     NOP
//         0046ec89     NOP
//         0046ec8a     NOP
//         0046ec8b     NOP
//         0046ec8c     NOP
//         0046ec8d     NOP
//         0046ec8e     NOP
//         0046ec8f     NOP
    return;
}

void RGE_Player::changeToComputerPlayer() {
    /* TODO: Stub */
//                              void __thiscall changeToComputerPlayer(RGE_Player * this)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//                               ?changeToComputerPlayer@RGE_Player@@UAEXXZ                   XREF[1]:     00570ee0(*)
//                               RGE_Player::changeToComputerPlayer
//                              player.h:174 (1)
//         0046ec90     RET
//         0046ec91     ??         90h
//         0046ec92     NOP
//         0046ec93     NOP
//         0046ec94     NOP
//         0046ec95     NOP
//         0046ec96     NOP
//         0046ec97     NOP
//         0046ec98     NOP
//         0046ec99     NOP
//         0046ec9a     NOP
//         0046ec9b     NOP
//         0046ec9c     NOP
//         0046ec9d     NOP
//         0046ec9e     NOP
//         0046ec9f     NOP
    return;
}

void RGE_Player::kickAI(int param_1) {
    /* TODO: Stub */
//                              void __thiscall kickAI(RGE_Player * this, int param_1)
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?kickAI@RGE_Player@@UAEXH@Z                                  XREF[1]:     00570f08(*)
//                               RGE_Player::kickAI
//                              player.h:186 (3)
//         0046eca0     RET        0x4
//         0046eca3     ??         90h
//         0046eca4     NOP
//         0046eca5     NOP
//         0046eca6     NOP
//         0046eca7     NOP
//         0046eca8     NOP
//         0046eca9     NOP
//         0046ecaa     NOP
//         0046ecab     NOP
//         0046ecac     NOP
//         0046ecad     NOP
//         0046ecae     NOP
//         0046ecaf     NOP
    return;
}

int RGE_Player::strategicNumber(int param_1) {
    /* TODO: Stub */
//                              int __thiscall strategicNumber(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?strategicNumber@RGE_Player@@UAEHH@Z                         XREF[1]:     00570f0c(*)
//                               RGE_Player::strategicNumber
//                              player.h:187 (6)
//         0046ecb0     OR         EAX,0xffffffff
//         0046ecb3     RET        0x4
//         0046ecb6     ??         90h
//         0046ecb7     NOP
//         0046ecb8     NOP
//         0046ecb9     NOP
//         0046ecba     NOP
//         0046ecbb     NOP
//         0046ecbc     NOP
//         0046ecbd     NOP
//         0046ecbe     NOP
//         0046ecbf     NOP
    return 0;
}

int RGE_Player::sendAICommand(int param_1, int param_2, int param_3, int param_4, int param_5) {
    /* TODO: Stub */
//                              int __thiscall sendAICommand(RGE_Player * this, int param_1, int par
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//              int               Stack[0x10]:4  param_4
//              int               Stack[0x14]:4  param_5
//                               ?sendAICommand@RGE_Player@@UAEHHHHHH@Z                       XREF[1]:     00570f24(*)
//                               RGE_Player::sendAICommand
//                              player.h:193 (5)
//         0046ecc0     XOR        EAX,EAX
//         0046ecc2     RET        0x14
//         0046ecc5     ??         90h
//         0046ecc6     NOP
//         0046ecc7     NOP
//         0046ecc8     NOP
//         0046ecc9     NOP
//         0046ecca     NOP
//         0046eccb     NOP
//         0046eccc     NOP
//         0046eccd     NOP
//         0046ecce     NOP
//         0046eccf     NOP
    return 0;
}

int RGE_Player::objectCostByType(int param_1) {
    /* TODO: Stub */
//                              int __thiscall objectCostByType(RGE_Player * this, int param_1)
//              int               EAX:4          <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//                               ?objectCostByType@RGE_Player@@UAEHH@Z                        XREF[1]:     00570f28(*)
//                               RGE_Player::objectCostByType
//                              player.h:195 (6)
//         0046ecd0     OR         EAX,0xffffffff
//         0046ecd3     RET        0x4
//         0046ecd6     ??         90h
//         0046ecd7     NOP
//         0046ecd8     NOP
//         0046ecd9     NOP
//         0046ecda     NOP
//         0046ecdb     NOP
//         0046ecdc     NOP
//         0046ecdd     NOP
//         0046ecde     NOP
//         0046ecdf     NOP
    return 0;
}

void RGE_Player::trackUnitGather(int param_1, int param_2, int param_3) {
    /* TODO: Stub */
//                              void __thiscall trackUnitGather(RGE_Player * this, int param_1, int
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              int               Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//              int               Stack[0xc]:4   param_3
//                               ?trackUnitGather@RGE_Player@@UAEXHHH@Z                       XREF[1]:     00570f2c(*)
//                               RGE_Player::trackUnitGather
//                              player.h:206 (3)
//         0046ed30     RET        0xc
//         0046ed33     ??         90h
//         0046ed34     NOP
//         0046ed35     NOP
//         0046ed36     NOP
//         0046ed37     NOP
//         0046ed38     NOP
//         0046ed39     NOP
//         0046ed3a     NOP
//         0046ed3b     NOP
//         0046ed3c     NOP
//         0046ed3d     NOP
//         0046ed3e     NOP
//         0046ed3f     NOP
    return;
}

void RGE_Player::logStatus(_iobuf* param_1, int param_2) {
    /* TODO: Stub */
//                              void __thiscall logStatus(RGE_Player * this, _iobuf * param_1, int p
//              void              <VOID>         <RETURN>
//              RGE_Player *      ECX:4 (auto)   this
//              _iobuf *          Stack[0x4]:4   param_1
//              int               Stack[0x8]:4   param_2
//                               ?logStatus@RGE_Player@@UAEXPAU_iobuf@@H@Z                    XREF[1]:     00570fbc(*)
//                               RGE_Player::logStatus
//                              player.h:300 (3)
//         0046ed40     RET        0x8
//         0046ed43     ??         90h
//         0046ed44     NOP
//         0046ed45     NOP
//         0046ed46     NOP
//         0046ed47     NOP
//         0046ed48     NOP
//         0046ed49     NOP
//         0046ed4a     NOP
//         0046ed4b     NOP
//         0046ed4c     NOP
//         0046ed4d     NOP
//         0046ed4e     NOP
//         0046ed4f     NOP
    return;
}

