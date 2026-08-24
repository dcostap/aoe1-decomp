// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\tvw_main.cpp.
//
// The packet has one unambiguous PDB source module and eleven normal owners.
// These includes follow PDB line order.  The linked address order is also
// monotonic, so no source-order/address-order conflict is present.
//
// PDB boundary audit:
//   0052CAF0  39-210  draw_multi_object_outline
//   0052D060 216-275  draw_wall_outline
//   0052D1F0 281-313  command_place_object
//   0052D320 319-376  command_place_multi_object
//   0052D4F0 382-418  place_line_of_walls
//   0052D600 424-534  mouse_left_up_action
//   0052D970 540-650  mouse_right_up_action
//   0052DCE0 656-661  pick_through_fog
//   0052DD10 667-723  pick_weight
//   0052DE20 731-769  command_make_do
//   0052DE40 776-817  mouse_left_dbl_click_action
// No nearby compiler-generated owner is registered in the packet.

#define TVW_MAIN_SHARED_CONTEXT 1

typedef unsigned char uchar;

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

class TDrawArea {
public:
    void SetClipRect(RECT* rect);
};

class TShape;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Tile;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Main_View;
class TRIBE_Player;
class TRIBE_Master_Building_Object;

struct RGE_Pick_Info {
    float x;
    float y;
    short scr_x;
    short scr_y;
    RGE_Static_Object* object;
    RGE_Tile* tile;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, uchar);
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
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
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
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    unsigned char gap_04[0x1C];
    union {
        TDrawArea* render_area;
        TDrawArea* draw_area;
    };
    RECT clip_rect;
    unsigned char gap_34[0x58];
    long left;
    long top;
    long right;
    long bottom;
    unsigned char gap_9C[0x50];
    uchar mouse_action;
    unsigned char gap_ED[7];

    void release_mouse();
};

class RGE_Game_World {
public:
    // BINARY NOTE: The PDB type is polymorphic and world_time is at +4.
    virtual ~RGE_Game_World();
    int world_time;
};

class RGE_Prog_Info {
public:
    unsigned char gap_00[0x8C0];
    int auto_scroll;
    long mouse_scroll_edge;
    unsigned long mouse_scroll_interval;
    float mouse_scroll_max_dist;
    unsigned long key_scroll_interval;
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
    unsigned char gap_1BC[0x238];
    RGE_Game_World* world;
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;

    int get_paused();
    RGE_Player* get_player();
    void get_mouse_pos(tagPOINT& point);
    int play_sound(int value);
};

extern int allow_user_commands;
extern int fog_next_shape;
extern int SDI_Draw_Line;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, uchar attribute);
    virtual void modify_delta(float amount, uchar attribute);
    virtual void modify_percent(float amount, uchar attribute);
    virtual void save(int file_handle);
    virtual RGE_Static_Object* make_new_obj(
        RGE_Player* player, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual uchar check_placement(
        RGE_Player* player, float x, float y, int* placement,
        uchar check_terrain, uchar elevation, uchar check_objects,
        uchar check_units, uchar check_buildings, uchar check_fog);
    virtual uchar alignment(float* x, float* y, RGE_Game_World* world,
                            uchar value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, uchar flags);

    unsigned char gap_04[0x0C];
    short id;
    unsigned char gap_12[0x06];
    RGE_Sprite* sprite;
    unsigned char gap_1C[0x48];
    uchar elevation_flag;
    unsigned char gap_65[0x28];
    uchar select_level;
    uchar gap_8E;
    uchar unit_level;
    unsigned char gap_90[0x18];
    uchar draw_flag;
    uchar draw_color;
    unsigned char gap_AA[0x0E];

    uchar alignment_box(RGE_Game_World* world, float x, float y,
                        short& x1, short& y1, short& x2, short& y2,
                        short& x3, short& y3, short& x4, short& y4);
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    unsigned char gap_00[4];
    RGE_Object_Node* list;
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
    virtual void sendUnitAIOrder(int, int, int, int, int, float, float,
                                 float, float, int, int, int);
    virtual void processAIOrder(int, int, int, int, int, float, float,
                                float, float, int, int, int);
    virtual void kickAI(int);
    virtual int strategicNumber(int);
    virtual void sendGameOrder(RGE_Static_Object*, RGE_Static_Object*,
                               float, float);
    virtual void sendAddWaypointCommand(int, void*, int);
    virtual void processAddWaypointCommand(int, void*, int);
    virtual void sendPlayCommand(int, int, int);
    virtual void sendPlayCommand(int, int*, int, int, int);
    virtual int sendAICommand(int, int, int, int, int);
    virtual int objectCostByType(int);
    virtual void trackUnitGather(int, int, int);
    virtual RGE_Static_Object* make_scenario_obj(float, float, float, int);
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
    virtual RGE_Static_Object* make_new_object(long, float, float, float,
                                                int);

    unsigned char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    unsigned char gap_2C[0xDC];
    RGE_Color_Table* color_table;

    unsigned char command_make_building(short, float, float);
    unsigned char command_make_wall(short, long, long, long, long);
    void unselect_object();
    int select_one_object(RGE_Static_Object*, int);
};

class TRIBE_Player : public RGE_Player {
public:
    virtual RGE_Static_Object* make_new_object(long, float, float, float,
                                                int);
    uchar command_attack_ground(float, float);
    uchar command_make_unload(float, float);
    uchar command_make_repair(RGE_Static_Object*);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    // BINARY NOTE: object_state is at +0x48 after the owner at +0x0C.
    unsigned char gap_10[0x38];
    uchar object_state;
};

class RGE_View : public TPanel {
public:
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual int start_scroll_view(uchar, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    virtual void draw_multi_object_outline();

    TDrawArea* cur_render_area;
    int calc_draw_count;
    RGE_Game_World* world;
    TRIBE_Player* player;
    unsigned char gap_104[0x2C];
    int map_scr_x_offset;
    int map_scr_y_offset;
    unsigned char gap_138[0x204];
    int UC_ObjectTouched;
    int UC_TouchedObj;

    int get_selection_area(long* col1, long* row1, long* col2, long* row2,
                           int normalize);
    void set_selection_area(long col1, long row1, long col2, long row2);
    void add_overlay_sprite(TShape*, int, int, int, int, int, uchar*, int,
                            unsigned long);
    void reset_overlay_sprites();
    void display_object_selection(int, int, int, int);
    int get_tile_screen_coords(short col, short row, short* out_x,
                               short* out_y, int adjust);
    bool Object_Was_Displayed(int id, bool allow_flagged);
};

class RGE_Main_View : public RGE_View {
public:
    virtual int command_place_object(long, long, int);
    virtual int command_make_do(long, long, int, short);
    virtual int command_make_move(long, long);
    virtual int command_make_work(long, long);
    virtual int command_place_multi_object(long, long, long, long, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);

    uchar pick1(uchar, uchar, long, long, RGE_Pick_Info*, RGE_Static_Object*,
                int);
    void fixup_pick_info(RGE_Pick_Info*);
    void reset_display_object_selection(int);
    RGE_Static_Object* pick_best_target(long, long, int*, short);
};

class TRIBE_Main_View : public RGE_Main_View {
public:
    virtual void draw_multi_object_outline();
    int draw_wall_outline(long, long, TRIBE_Master_Building_Object*, long);
    virtual int command_place_object(long, long, int);
    virtual int command_place_multi_object(long, long, long, long, int);
    void place_line_of_walls(TRIBE_Player*, TRIBE_Master_Building_Object*,
                             int, int, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual int pick_through_fog(RGE_Static_Object*);
    int pick_weight(RGE_Static_Object*, int);
    virtual int command_make_do(long, long, int, short);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
};

#include "scratch/0052CAF0_draw_multi_object_outline.cpp"
#include "matching/0052D060_draw_wall_outline.cpp"
#include "matching/0052D1F0_command_place_object.cpp"

#include "matching/0052D320_command_place_multi_object.cpp"

#include "matching/0052D4F0_place_line_of_walls.cpp"
#include "accepted_drift/0052D600_mouse_left_up_action.cpp"
#include "accepted_drift/0052D970_mouse_right_up_action.cpp"
#include "matching/0052DCE0_pick_through_fog.cpp"
#include "matching/0052DD10_pick_weight.cpp"
#include "matching/0052DE20_command_make_do.cpp"
#include "matching/0052DE40_mouse_left_dbl_click_action.cpp"
