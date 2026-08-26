#ifndef AOE1_TPNL_OBJ_CONTEXT_H
#define AOE1_TPNL_OBJ_CONTEXT_H

// Authentic compiler-facing declaration context for tpnl_obj.cpp.
//
// Evidence: the PDB module is C:\\msdev\\work\\age1_x1\\tpnl_obj.cpp;
// owner order is the address/line order recorded in
// build/tu_plans/tpnl_obj_cpp/packet.json.  The panel base uses the observed
// slot +0x20 set_redraw and slot +0xB4 notify surfaces.  The object classes
// retain only named period fields needed by this module, with their proven
// offsets and inherited virtual order.

#include <windows.h>
#include <stdio.h>

class TDrawArea;
class TShape;
class RGE_Player;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Sprite;
class RGE_Object_Node;
class RGE_Action_Object;
class RGE_Combat_Object;
class TRIBE_Building_Object;
class RGE_Object_List;
class RGE_Action_List;
class RGE_Action;
class RGE_Victory_Conditions;
class RGE_Game_World;
class RGE_Scenario;
class RGE_Task;
class RGE_Master_Animated_Object;
class RGE_Master_Moving_Object;
class RGE_Master_Action_Object;
class RGE_Master_Combat_Object;
class Production_Queue_Record;
class RGE_Color_Table;
class TCommunications_Handler;
class LOSTBL;
class RGE_Armor_Weapon_Info;
class RGE_Active_Sprite_List;
class Path;
template<class T> class ManagedArray;
struct XYZPoint;
struct XYPoint;
struct XYZBYTEPoint;
struct PanelNode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long notify(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    tagRECT clip_rect;
    long position_mode;
    long need_redraw;
    TPanel* curr_child;
    union { TPanel* parent_panel; TPanel* child; };
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    long mouse_captured;
    long active;
    long visible;
    long tab_stop;
    long have_focus;
    long overlapping_children;
    long handle_mouse_input;
    long just_drawn;
    void* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    long mouse_down_ctrl;
    long mouse_down_shift;
    unsigned long mouse_down_time;
    long error_code;
    long z_order;
    long display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

typedef char tpnl_obj_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;
    void* DrawSurface;
    char gap_40[0x78];

    void Clear(tagRECT*, int);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void* GetDc(char*);
    void ReleaseDc(char*);
};

class TShape {
public:
    // BINARY NOTE: the object allocated by this module is 0x20 bytes.
    char shape_data[0x20];
    TShape(char*, int);
    ~TShape();
    int is_loaded();
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
    long shape_count();
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
    unsigned char table[0x100];
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[0x10];
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2d[0x21];
    short button_pict;
    unsigned char gap_50[0x3f];
    unsigned char unit_level;
    unsigned char gap_90[0xde];
    short building_facet;
};

typedef char tpnl_obj_master_size_check[(sizeof(RGE_Master_Static_Object) == 0x170) ? 1 : -1];

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, unsigned char);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);
    virtual void rotate(long);
    virtual void can_attack();
    virtual void set_attribute(short, float);
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    virtual int heal(int, int);
    virtual unsigned char heal(float);
    virtual void canRepair();
    virtual void notify_of_relation(long, unsigned char);
    virtual void do_command(RGE_Static_Object*, float, float, float);
    virtual void move_to(RGE_Static_Object*, float, float, float);
    virtual void work(RGE_Static_Object*, float, float, float);
    virtual void stop();
    virtual void set_attack(RGE_Static_Object*);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
    virtual RGE_Static_Object* spawn_death_obj();
    virtual RGE_Master_Static_Object* get_command_master(RGE_Static_Object*,
                                                          float, float, float);
    virtual void set_being_worked_on(RGE_Action_Object*, short, unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual void is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj(RGE_Static_Object*);
    virtual void exit_obj();
    virtual int explore_terrain(RGE_Player*, unsigned char, int);
    virtual void unexplore_terrain(RGE_Player*, unsigned char, int);
    virtual LOSTBL* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual void underAttack();
    virtual void setUnderAttack(unsigned char);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual float getSpeed();
    virtual float getAngle();
    virtual float maximumSpeed();
    virtual float rateOfFire();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float damageCapability();
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual int passableTile(float, float, int);
    virtual unsigned char facetToNextWaypoint();
    virtual int currentTargetID();
    virtual float currentTargetX();
    virtual float currentTargetY();
    virtual float currentTargetZ();
    virtual void setWaitingToMove(unsigned char);
    virtual unsigned char waitingToMove();
    virtual unsigned char actionState();
    virtual unsigned char keepGatheringWhenObjectIsOut(int);
    virtual unsigned char produceWhenKilledBy(int);
    virtual void useSameZoneDropsite();
    virtual void logDebug(const char*, ...);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(float, float, float, int);
    virtual int attack(int, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int hunt(int, int);
    virtual int gather(int, int);
    virtual int convert(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int unload(int, float, float, float);
    virtual int transport(float, float, float, int);
    virtual int stopAction();
    virtual int pause();
    virtual int canPath(int, float, float*, int, int, int);
    virtual int canPath(XYZPoint, float, int, float*, int, int, int);
    virtual int canBidirectionPath(int, int, float, float*, int, int, int);
    virtual int canPathWithObstructions(int, float, float*, int, int, int,
                                        ManagedArray<int>*);
    virtual int canPathWithAdditionalPassability(XYZPoint, float, int,
                                                  float*, int, int, int, int,
                                                  int);
    virtual int findFirstTerrainAlongExceptionPath(int, float*, float*);
    virtual int canLinePath(int, int, int, int, float, int);
    virtual int canLinePath(XYPoint*, XYPoint*, float, XYPoint*, int);
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);
    virtual XYZBYTEPoint* userDefinedWaypoint(int);
    virtual int addUserDefinedWaypoint(XYZBYTEPoint*, int);
    virtual void removeAllUserDefinedWaypoints(int);
    virtual void removeUserDefinedWaypoint(int);
    virtual int numberUserDefinedWaypoints();
    virtual Path* findAvoidancePath(XYZPoint*, float, int);
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();
    virtual int setup(int, RGE_Game_World*);
    virtual int setup(RGE_Master_Static_Object*, RGE_Player*, float, float, float);
    virtual RGE_Object_List* create_object_list();
    virtual RGE_Active_Sprite_List* create_sprite_list();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    RGE_Object_Node* player_object_node;
    char gap_54[0x30];
};

typedef char tpnl_obj_static_size_check[(sizeof(RGE_Static_Object) == 0x84) ? 1 : -1];

class RGE_Action_Object : public RGE_Static_Object {
public:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float, float);
    virtual void stop_moving();
    virtual unsigned char turn_towards(RGE_Static_Object*, float, float);
    virtual int setup(RGE_Master_Moving_Object*, RGE_Player*, float, float, float);
    virtual void work2(RGE_Static_Object*, float, float, float, unsigned char);
    virtual void set_task(short);
    virtual void setTaskByTaskID(int);
    virtual void set_action(RGE_Action*);
    virtual void set_only_action(RGE_Action*);
    virtual void set_end_action(RGE_Action*);
    virtual RGE_Task* getTask(RGE_Static_Object*, float, float, float);
    virtual int setup(RGE_Master_Action_Object*, RGE_Player*, float, float, float);

    char gap_84[4];
    char gap_88[0xf8];
    unsigned char waiting;
    unsigned char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char gap_189[3];
    int last_action;
    int last_action_state;

    unsigned char have_action();
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual RGE_Action_List* create_action_list();
    virtual unsigned char area_attack(float, float, float, RGE_Combat_Object*,
                                      RGE_Static_Object*);
    virtual unsigned char attack(float, float, float, RGE_Combat_Object*);
    virtual unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*,
                                    float, float, float);
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual int setup_combat(RGE_Master_Combat_Object*, RGE_Player*, float, float, float);
    virtual void get_pierce_armor(short&, short&);

    void* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    unsigned char capture_flag;
    unsigned char gap_1c1[3];
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    virtual void cancel_object();
    virtual void get_pierce_armor(short&, short&);
    virtual void higher_check_for_cliff();
    virtual void higher_than_target();
    virtual void initUnitAI();
    virtual int setup_tribe_combat();
    virtual void take_building_attribute_from_owner();
    virtual void give_building_attribute_to_owner();
    virtual int setup_building();

    char gap_1c4[4];
    Production_Queue_Record* production_queue;
    short production_queue_size;
    short production_queue_count;
    unsigned char production_queue_enabled;
    unsigned char gap_1d1[3];
    RGE_Action_List* production_queue_actions;
    unsigned char production_queue_change_flag;
    unsigned char production_queue_auto_paused;
    short production_queue_need_attr;
    float build_pts;
    int unique_build_id;
    unsigned char culture;
    unsigned char built;
    unsigned char gap_1e6[2];
    int DoppleInstalled;
    unsigned long PriorMap1;
    unsigned long PriorMap2;
    unsigned long PriorMap3;
    long PriorTurn1;
    long PriorTurn2;
    long PriorTurn3;

    short get_construction_progress();
    int work_status(short&, short&, short&, char*, short);
    int production_queue_status(short&, short&);
};

class RGE_Object_Node {
public:
    char gap_00[0x10];
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char gap_0A[2];
    RGE_Static_Object* find_by_master_id(long, float, float,
                                          unsigned char, unsigned char,
                                          RGE_Static_Object*);
};

class RGE_Action {
public:
    char gap_00[0x2c];
    union { float attribute_amount; float field_2c; };
};

class RGE_Action_List {
public:
    RGE_Action* get_action();
};

class RGE_Victory_Conditions {
public:
    long get_victory_points();
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x38];
    short player_num;
    char gap_3e[2];
    RGE_Player** players;
    char gap_44[0x18];
    RGE_Scenario* scenario;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1e];
    short master_object_num;
    void* master_objects;
    RGE_Object_List* objects;
    char gap_2c[8];
    RGE_Victory_Conditions* victory_conditions;
    char gap_38[4];
    RGE_Game_World* world;
    char gap_40[4];
    char* name;
    unsigned char type;
    unsigned char gap_49;
    short id;
    short attribute_num;
    char gap_4e[2];
    float* attributes;
    char gap_54[0xb1];
    unsigned char master_player_id;
    char gap_106[2];
    RGE_Color_Table* color_table;
    char gap_10c[0x24];
    RGE_Static_Object* object_130;
};

class TRIBE_Player : public RGE_Player {
};

class RGE_Scenario {
public:
    char* GetPlayerName(int);
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
    virtual char* get_string2(int, long, long, char*, int);

    char gap_04[0x3f0];
    RGE_Game_World* world;
    char gap_3f8[0x59c];
    int campaignGame_;
    char gap_998[0x288];
    int object_name_mode;

    int playerID(int);
    int campaignGame();
    RGE_Player* get_player();
};

class TCommunications_Handler {
public:
    char* GetPlayerName(unsigned int);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern float DAT_00576d80;
extern float DAT_00576d84;
extern float DAT_00576d88;
extern float DAT_00576d8c;
extern float DAT_00576d98;
extern float DAT_00576da0;
extern float DAT_00576da4;
extern float DAT_00576da8;
extern float DAT_00576dac;
extern const char s_tpnl_obj_draw[];
extern char s_tpnl_obj_draw_score[];
extern const char s_tpnl_obj_draw_item[];
extern char s_fmt_d[];
extern const char s_fmt_d_plus_d[];
extern const char s_fmt_d_slash_d[];
extern const char s_fmt_d_percent[];
extern const char s_health_shp[];
extern const char s_itemicon_shp[];
extern "C" void __cdecl _ASMSet_Color_Xform(int);
extern unsigned long __cdecl debug_timeGetTime(char*, int);

#define S_FMT_ID_NAME ((const char*)0x0058B690)
#define S_FMT_NAME ((const char*)0x0057F324)
#define S_FMT_HP ((const char*)0x005870AC)

extern "C" {
__declspec(dllimport) int __stdcall SetBkMode(HDC, int);
__declspec(dllimport) COLORREF __stdcall SetTextColor(HDC, COLORREF);
__declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
__declspec(dllimport) BOOL __stdcall SelectClipRgn(HDC, HRGN);
__declspec(dllimport) BOOL __stdcall TextOutA(HDC, int, int, LPCSTR, int);
__declspec(dllimport) BOOL __stdcall SetRect(LPRECT, int, int, int, int);
__declspec(dllimport) int __stdcall DrawTextA(HDC, LPCSTR, int, LPRECT, UINT);
}

class TRIBE_Panel_Object : public TPanel {
public:
    enum ValueType {
        ValueTypeNumber,
        ValueTypeBonus,
        ValueTypeCompare,
        ValueTypePercent,
        ValueTypeNone
    };

    void* font;
    long font_wid;
    long font_hgt;
    TShape* health_pic;
    TShape* item_pic;
    TShape* unit_pics;
    TShape** bldg_pics;
    TRIBE_Player* player;
    TRIBE_Building_Object* game_obj;
    unsigned long idle_time;
    unsigned long idle_interval;
    unsigned char mode;
    unsigned char gap_121[3];
    RGE_Master_Static_Object* save_obj_type;
    RGE_Sprite* save_sprite;
    short save_attr_type;
    unsigned char gap_12E[2];
    float save_attr_amount;
    unsigned char save_object_state;
    unsigned char gap_135[3];
    float save_build_pts;
    RGE_Object_Node* save_list;
    short save_number_of_objects;
    unsigned char save_can_debark;
    unsigned char gap_143[1];
    float save_world_x;
    float save_world_y;
    float save_hp;
    short save_armor;
    short save_pierce_armor;
    short save_weapon;
    unsigned char gap_156[2];
    float save_weapon_range;
    float save_speed_of_attack;
    short save_work_type;
    short save_work_target;
    short save_progress;
    char save_name[100];
    unsigned char save_facet;
    unsigned char gap_1CB[1];
    float save_angle;
    float save_los;
    int save_pop;
    int save_max_pop;
    unsigned char save_selected_group;
    unsigned char gap_1DD[3];
    RGE_Player* save_owner;
    int save_age;
    unsigned char save_have_action;
    unsigned char gap_1E9[3];
    int save_score[9];
    int save_farm_amt;

    virtual ~TRIBE_Panel_Object();
    TRIBE_Panel_Object(TDrawArea*, TPanel*, void*, long, long, TShape*,
                       TShape**, TRIBE_Player*);
    virtual void draw();

protected:
    virtual void draw_item(int, int, ValueType, int, int);

public:
    virtual long handle_idle();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);

    void set_player(TRIBE_Player*);
    void set_object(RGE_Static_Object*);
    void set_mode(unsigned char);
    unsigned char get_mode();
    void draw_score();

protected:
    void save_object_info();
};

typedef char tpnl_obj_panel_size_check[(sizeof(TRIBE_Panel_Object) == 0x214) ? 1 : -1];

#endif
