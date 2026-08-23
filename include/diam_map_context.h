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

class TDrawArea;
class RGE_Game_World;
class RGE_Player;
class RGE_Map;
class RGE_Diamond_Map_View;
class RGE_Static_Object;

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
    float col_step;
    float col_extra;
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
    int pick_tile(long, long, short*, short*, void**);
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
    void draw_tile(short, short, unsigned char, short);
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
