#ifndef AOE1_VW_MAIN_TU_CONTEXT_H
#define AOE1_VW_MAIN_TU_CONTEXT_H

// Keep direct Win32 ABI declarations used by this module. The Windows header
// changes VC5 grouped scheduling in 0053E340 and breaks exact bytes.
typedef unsigned char uchar;
typedef unsigned char byte;
typedef void* HWND;

struct tagPOINT {
    long x;
    long y;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

typedef tagRECT RECT;

extern "C" __declspec(dllimport) HWND __stdcall GetForegroundWindow(void);
extern "C" __declspec(dllimport) int __stdcall GetWindowRect(HWND, tagRECT*);
extern "C" __declspec(dllimport) int __stdcall GetCursorPos(tagPOINT*);
extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int);
extern "C" __declspec(dllimport) int __stdcall GetKeyboardState(uchar*);
extern "C" __declspec(dllimport) int __stdcall ClientToScreen(HWND, tagPOINT*);
extern "C" __declspec(dllimport) int __stdcall ScreenToClient(HWND, tagPOINT*);

class RGE_Main_View;
class RGE_Game_World;
class RGE_Map;
class RGE_Visible_Map;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Static_Object;
class RGE_Tile;
class TPanel;
class TShape;
class RGE_Task_List;
class XYZBYTEPoint;

struct RGE_Pick_Info {
    float x;
    float y;
    union { short scr_x; short sx; };
    union { short scr_y; short sy; };
    union { RGE_Static_Object* object; RGE_Static_Object* obj; };
    RGE_Tile* tile;
};

struct PickedInfo {
    union { int id; int object_id; };
    short confidence;
    short draw_level;
    short sx;
    short sy;
};

extern PickedInfo Picked_Objects[];
typedef PickedInfo RGE_Pick_Obj_Info;

struct MapInfo {
    unsigned char gap_00[8];
    int width;
    int height;
};

class DisplaySelectedObjRec {
public:
    int active;
    int id;
    unsigned long start_time;
    unsigned long duration;
    int select_type;
};

class TDrawSystem {
public:
    unsigned char gap_00[0x479];
    unsigned char screen_mode;
};

class TDrawArea {
public:
    TDrawSystem* draw_system;
    union {
        HWND Wnd;
        HWND wnd;
    };
    void Clear(RECT*, int);
};
typedef TDrawArea TDrawArea_Local;

extern void __cdecl write_draw_log2(char*);

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*);
    virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*);
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
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char*&, long&, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    unsigned char gap_04[0x1C];
    TDrawArea* render_area;
    union { RECT clip_rect; RECT render_rect; };
    unsigned char gap_34[0x0C];
    TPanel* parent_panel;
    unsigned char gap_44[0x28];
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    unsigned char gap_7C[0x44];
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
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

    void capture_mouse();
    void release_mouse();
    char* get_string(int);
};

class RGE_Prog_Info {
public:
    unsigned char gap_00[0x8C0];
    int auto_scroll;
    long mouse_scroll_edge;
    unsigned long mouse_scroll_interval;
    float mouse_scroll_max_dist;
    union {
        unsigned long key_scroll_interval;
        unsigned long key_scroll_time_divisor;
    };
    float key_scroll_max_dist;
    float key_scroll_object_move;
    short interface_style;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    unsigned char gap_04[0x08];
    RGE_Prog_Info* prog_info;
    unsigned char gap_10[0x4C];
    TShape** shapes;
    unsigned char gap_60[0x150];
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    unsigned char gap_1BC[0x240];
    short master_obj_id;

    int get_paused();
    RGE_Player* get_player();
    void add_to_timing(int index, unsigned long value);
    unsigned long get_accum_time(int index);
    void increment_view_update_count();
    void update(unsigned long, unsigned long);
};

class TPanelSystem {
public:
    TPanel* modalPanel();
    TPanel* mouseOwner();
};

class RGE_Active_Sprite_List {
public:
    uchar get_lowest_draw_level();
};

class RGE_Sprite {
public:
    unsigned char gap_00[0x29];
    unsigned char draw_level;
    uchar get_lowest_draw_level();
};

class RGE_Action_Object;
class RGE_Task;
class RGE_Task_List {
public:
    RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float,
                               float, float);
    int is_attack_task(RGE_Task*);
};

struct RGE_Task {
    short task_type;
    short id;
    unsigned char gap_04[2];
    short action_type;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(RGE_Player*, float, float, int*, uchar,
                                  uchar, uchar, uchar, uchar, uchar);
    virtual uchar alignment(float*, float*, RGE_Game_World*, uchar);
    int get_help_message();
    int get_help_page();

    unsigned char kind;
    unsigned char gap_05;
    short action_id;
    unsigned char gap_08[0x08];
    short id;
    short copy_id;
    union { short object_group; short object_type; };
    unsigned char gap_18[0x4C];
    unsigned char elevation_flag;
    unsigned char gap_65[0x28];
    unsigned char select_level;
    RGE_Task_List* tasks;
    unsigned char gap_0DC[0x10];
    unsigned char flag_ec;
};

class RGE_Static_Object {
public:
    RGE_Static_Object();
    RGE_Static_Object(RGE_Master_Static_Object*, RGE_Player*, float, float,
                      float, int);
    RGE_Static_Object(int, RGE_Game_World*, int);
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(void*, short, short, void*);
    virtual void shadow_draw(void*, short, short, uchar);
    virtual void normal_draw(void*, short, short);
    virtual void draw_front_frame(void*, short, short);
    virtual void draw_back_frame(void*, short, short);
    virtual void draw_frame(void*, short, short);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite*);
    virtual void add_overlay_sprite(RGE_Sprite*, uchar);
    virtual void remove_overlay_sprite(RGE_Sprite*);
    virtual void change_ownership(RGE_Player*);
    virtual void modify(float, uchar);
    virtual void modify_delta(float, uchar);
    virtual void modify_percent(float, uchar);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void set_object_state(uchar);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual float calculateDamage(int, void*, float, RGE_Player*, RGE_Static_Object* = 0);
    virtual void rotate(long);
    virtual void do_right_action(int);

    int get_frame(short*, short*, short*, short*);

    long id;
    RGE_Master_Static_Object* master_obj;
    union { RGE_Player* owner; uchar owner_id; };
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    uchar curr_damage_percent;
    uchar facet;
    uchar selected;
    uchar selected_group;
    union { float x; float world_x; };
    union { float y; float world_y; };
    float world_z;
    float attribute_amount_held;
    union { uchar object_state; uchar owner_type; };
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(uchar);
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float, float,
                                 float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float, float,
                                float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*, float,
                               float);
    virtual void sendAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void processAddWaypointCommand(int, XYZBYTEPoint*, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual void sendPlayCommand(int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, short,
                                                  uchar, float);
    virtual void scenario_save(int);
    virtual void scenario_load(int, long*, float);
    virtual void scenario_postsave(int);
    virtual void scenario_postload(int, long*, float);
    virtual void load(int);
    virtual void add_attribute_num(short, float, uchar);
    virtual void update();
    virtual void update_dopplegangers();
    virtual void save(int);
    virtual void save2(int);
    virtual void save_info(int);
    virtual void random_start();
    virtual RGE_Static_Object* make_new_object(long, float, float, float, int);
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int, int*, int*);
    virtual uchar command_make_move(RGE_Static_Object*, float, float);
    virtual uchar command_make_work(RGE_Static_Object*, float, float);
    virtual uchar command_make_do(RGE_Static_Object*, float, float);
    virtual uchar command_stop();
    virtual uchar command_place_object(short, float, float, float);
    virtual void command_add_waypoint(float, float, float);

    unsigned char gap_04[0x1E];
    short object_count;
    RGE_Master_Static_Object** master_objects;
    unsigned char gap_28[0x10];
    RGE_Visible_Map* visible;
    unsigned char gap_3C[0x0E];
    short id;
    unsigned char gap_4C[0xC8];
    float view_x;
    float view_y;
    unsigned char gap_11C[0x14];
    RGE_Static_Object* selected_obj;
    unsigned char gap_134[0x68];
    short sel_count;

    void set_view_loc(float x, float y);
    void set_view_loc(float x, float y, float z);
    void unselect_object();
    void select_one_object(RGE_Static_Object*);
    int select_one_object(RGE_Static_Object*, int);
    void unselect_one_object(RGE_Static_Object*);
    int select_object(RGE_Static_Object*);
    uchar get_select_level();
    uchar get_selected_objects_to_command(RGE_Static_Object***, short*,
                                           short, short, short, short);
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    unsigned char gap_04[0x3C];
    RGE_Player** players;
    unsigned char gap_40[0x44];
    RGE_Static_Object** objects;
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    unsigned char gap_04[0x8DB4];
    union { uchar map_visible_flag; uchar flag; };
};

class RGE_Visible_Map {
public:
    uchar get_visible(int x, int y);
};

class RGE_View : public TPanel {
public:
    union {
        TDrawArea* cur_render_area;
        TDrawArea* render_area;
    };
    int calc_draw_count;
    RGE_Game_World* world;
    RGE_Player* player;
    union { RGE_Map* map; MapInfo* mapInfo; };
    unsigned char gap_108[0x28];
    int map_scr_x_offset;
    int map_scr_y_offset;
    unsigned char gap_138[0x0C];
    long sel_col1;
    long sel_row1;
    long sel_col2;
    long sel_row2;
    unsigned char gap_154[0x14];
    uchar scroll_action;
    unsigned char gap_169[0x0B];
    RGE_Static_Object* movable_object;
    unsigned char gap_178[0x1DC];
    DisplaySelectedObjRec* DispSel_List;
    int DispSel_List_Size;
    int DispSel_List_Max;

    RGE_View();
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual int start_scroll_view(uchar, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    virtual void draw_multi_object_outline();
    void set_selection_area(long, long, long, long);
    void display_object_selection(int, int, int, int);
    void reset_overlay_sprites();
    void add_overlay_sprite(void*, int, int, int, int, int, uchar*, int,
                            unsigned long);
    int pick_objects(int, int, int, int, int, int, int);
    uchar pick(uchar, uchar, long, long, RGE_Pick_Info*, RGE_Static_Object*);
};

class RGE_Main_View : public RGE_View {
public:
    TPanel* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    RGE_Player* save_player;

    RGE_Main_View();
    virtual void draw();
    virtual long handle_idle();
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);
    virtual int start_scroll_view(uchar, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void draw_multi_object_outline();
    int do_auto_scroll();
    int handle_keys();
    uchar pick1(uchar, uchar, long, long, RGE_Pick_Info*,
                RGE_Static_Object*, int);
    int pick_objects1(long, long, RGE_Static_Object**, int);
    RGE_Static_Object* pick_best_target(long, long, int*, short);
    void fixup_pick_info(RGE_Pick_Info*);
    void display_object_selection(int, int, int, int);
    void reset_overlay_sprites();
    void reset_display_object_selection(int);
    virtual uchar get_help_info(char*&, long&, long, long);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

extern "C" void __cdecl color_log(unsigned char, unsigned char, int);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern const float DAT_00577900;
extern const float DAT_00577904;
extern const float DAT_00577908;

typedef char vw_main_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char vw_main_view_size_check[(sizeof(RGE_View) == 0x360) ? 1 : -1];
typedef char vw_main_main_view_size_check[(sizeof(RGE_Main_View) == 0x380) ? 1 : -1];

#endif
