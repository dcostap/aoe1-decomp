#ifndef DIAM_MAP_CONTEXT_H
#define DIAM_MAP_CONTEXT_H

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
typedef struct tagRECT RECT;

typedef unsigned char uchar;

class TDrawArea {
public:
    void* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    RECT ClipRect;
    void* DrawDc;
    void* DrawSurface;
    unsigned char SurfaceDesc[0x6C];
    void* Node;
    char* Name;
    unsigned char* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    void* shadow_color_table;
    void* SpanList;
    void* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    unsigned char TransColor;
    unsigned char pad_end[3];

    TDrawArea(char*, int);
    ~TDrawArea();
    int Init(void*, int, int, int, int);
    void SetSize(int, int, int);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void Copy(TDrawArea*, int, int, RECT*, int);
    void Clear(RECT*, int);
    void SetPixel(long, long, unsigned char);
    void FillRect(long, long, long, long, unsigned char);
    void DrawHorzLine(long, long, long, unsigned char);
};
class RGE_Game_World;
class RGE_Player;
class RGE_Map;
class RGE_Diamond_Map_View;
class RGE_Static_Object;
class RGE_Tile;
class RGE_Master_Static_Object;
class RGE_Color_Table;
class RGE_Object_List;
class RGE_Object_Node;
class RGE_Tile_List;

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
    RGE_Object_Node* prev;
    unsigned char centered;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
    unsigned char pad_0A[2];
};

class RGE_Tile_List {
public:
    RGE_Object_Node* list;
    int count;
    char pad_08[0x0C];
    void get_list_info(void**, int*);
    void del_list();
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char gap_04[0x21];
    unsigned char map_color;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x65];
    unsigned char fog_flag;
    char gap_66[0x28];
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
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
    virtual unsigned char update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int);
    virtual float teleport(float, float, float);
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership(RGE_Player*);
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state(unsigned char);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual float calculateDamage();
    virtual void rotate(long);
    virtual unsigned char can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual int heal(int, int);
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
    virtual RGE_Static_Object* spawn_death_obj();
    virtual void* get_command_master();
    virtual void set_being_worked_on();
    virtual void release_being_worked_on();
    virtual unsigned char is_moving();
    virtual RGE_Static_Object* get_target_obj();
    virtual void enter_obj();
    virtual void exit_obj();
    virtual int explore_terrain();
    virtual void unexplore_terrain();
    virtual void* get_los_table();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual unsigned char underAttack();

    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    RGE_Tile* tile;
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
    char tail[0x38];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    unsigned long LastMapValue;
    unsigned long CantSeeBits;
    unsigned char map_draw_level;
    unsigned char map_color;
    unsigned char gap_AA[2];
    int doppledObjectID;
};

class RGE_Tile {
public:
    char gap_00[4];
    unsigned char tile_type;
    unsigned char terrain_type;
    char gap_06[6];
    RGE_Object_List objects;
};

struct RGE_Tile_Size {
    short width;
    short height;
    short y_delta;
};

class RGE_Terrain_Set {
public:
    char gap_00[0x28];
    unsigned char map_hi_color;
    unsigned char map_med_color;
    unsigned char map_low_color;
    char gap_2B[0x16D];
};

class RGE_Map {
public:
    char gap_00[8];
    long map_width;
    long map_height;
    char gap_10[0x7C];
    RGE_Terrain_Set terrain_types[32];
    char gap_338C[0x5A00];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x28];
    unsigned char map_visible_flag;
    unsigned char fog_flag;
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x0C];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    char gap_80[0x2C];
    int mutualAlly[9];
    unsigned long mutualExploredMask;
    unsigned long mutualVisibleMask;
    char gap_D8[0x30];
    RGE_Color_Table* color_table;
    char gap_10C[8];
    float view_x;
    float view_y;
    char gap_11C[0x14];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;
    void set_view_loc(float, float);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x10];
    short player_num;
    unsigned char pad_3E[2];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_View {
public:
    virtual ~RGE_View();
    virtual void setup();
    virtual void set_rect();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_focus();
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw();
    void get_max_size(short*, short*);
};

class RGE_Base_Game {
public:
    char gap_00[0x1B4];
    int game_mode;
};
extern RGE_Base_Game* rge_base_game;

struct RGE_Map_Image_Line {
    short tile_row;
    short start_x;
    short line_len;
};

struct RGE_Map_Tile_Row {
    short image_line;
    unsigned char draw;
    unsigned char _padding_03;
    short row_len;
    unsigned char _padding_06[2];
    union {
        float col_step;
        float scale;
    };
    union {
        float col_extra;
        float offset;
    };
    short map_col;
    short map_row;
    short draw_wid;
    unsigned char _padding_16[2];
    float draw_step;
    short num_tiles;
    unsigned char _padding_1E[2];
    float ratio;
};

class TPanel {
public:
    enum RedrawMode {
        redraw_none = 0,
        redraw_local = 1,
        redraw_all = 2
    };

    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning();
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(RECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    int capture_mouse();
    void release_mouse();

protected:
    char previousPanelValue[8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    RECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    void* node;
    void* first_child_node;
    void* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    void* clip_rgn;
    RECT render_rect;
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

    TPanel();
    TPanel(const TPanel&);
};

class RGE_Diamond_Map : public TPanel {
public:
    RGE_Diamond_Map();
    virtual ~RGE_Diamond_Map();

    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char,
               int, TDrawArea*);
    void set_world(RGE_Game_World*);
    int set_bitmap(char*, long);
    void set_player(RGE_Player*);
    void set_visibility(int);
    void set_main_view(RGE_Diamond_Map_View*);
    virtual void set_redraw(TPanel::RedrawMode);
    void set_fog_color(unsigned char);
    unsigned char get_fog_color();
    void delete_surfaces();
    int create_surfaces();
    virtual void draw();
    int pick_tile(long, long, short*, short*, RGE_Tile**);
    virtual long handle_size(long, long);
    void start_scroll_view(long, long);
    void handle_scroll_view(long, long);
    void end_scroll_view();
    virtual int is_inside(long, long);

protected:
    void clear_image();
    void copy_image();
    void draw_all_tiles();
    void draw_explored_tiles();
    void draw_tile(short, short, int, unsigned char);
    virtual void draw_selected_area();
    virtual void draw_objects();
    virtual void draw_visible_object(RGE_Static_Object*, unsigned char, unsigned char);
    virtual void draw_object(short, short, unsigned char, short, void*);
    void draw_clipped_horz_line(short, short, short, unsigned char, RGE_Map_Image_Line*);
    virtual void draw_view_rect();

protected:
    RGE_Game_World* world;
    RGE_Player* player;
    RGE_Map* map;
    int all_visible;
    int render_all;
    long mouse_last_x;
    long mouse_last_y;
    int repos_mouse;
    RECT view_rect;
    RGE_Player* last_player;
    RGE_Map_Image_Line* map_image_lines;
    RGE_Map_Tile_Row* map_tile_rows;
    short map_wid;
    short map_hgt;
    short map_image_start_y;
    short map_image_wid;
    short map_image_hgt;
    short map_tile_row_cnt;
    float map_row_step;
    float map_col_ratio;
    float map_row_ratio;
    short map_tile_draw_hgt;
    short map_tile_draw_wid;
    short view_col;
    short view_row;
    RGE_Diamond_Map_View* main_view;
    int scrolling;
    unsigned char fog_color;
    unsigned char _padding_159[3];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;
};

typedef char diam_map_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];
typedef char diam_map_size_check[(sizeof(RGE_Diamond_Map) == 0x16C) ? 1 : -1];
typedef char diam_map_image_line_size_check[(sizeof(RGE_Map_Image_Line) == 6) ? 1 : -1];
typedef char diam_map_tile_row_size_check[(sizeof(RGE_Map_Tile_Row) == 36) ? 1 : -1];

#endif
