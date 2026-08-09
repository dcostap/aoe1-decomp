// 004372C0 RGE_Diamond_Map::draw (diam_map.cpp:426-510)
// Baseline reconstruction: typed TPanel/RGE_Diamond_Map fields and the two natural
// full/partial draw paths are kept local while call order and layout are validated.

typedef struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT;

class TDrawArea {
public:
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void Copy(TDrawArea*, int, int, RECT*, int);
    void Clear(RECT*, int);
};

class RGE_Tile_List {
public:
    void del_list();
};

class RGE_Player {
public:
    char gap_00[0x6C];
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    char gap_00[0x7C];
    short curr_player;
};

class RGE_Base_Game {
public:
    char gap_00[0x1B4];
    int game_mode;
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(RECT); virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char); virtual void set_active(int);
    virtual void set_positioning(); virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int); virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT*);
    virtual void draw_offset(long, long, RECT*); virtual void draw_rect2(RECT*);
    virtual void draw_offset2(long, long, RECT*); virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle(); virtual long handle_size(long, long); virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int); virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long); virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long); virtual long handle_scroll(long, long);
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
    virtual long char_action(long, short); virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(RECT*); virtual int is_inside(long, long);
    virtual void set_focus(int); virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short); virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system(); virtual int restart_sound_system();
    virtual void take_snapshot(); virtual void handle_reactivate();

    char gap_04[0x08];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
    RECT clip_rect;
    int position_mode;
    int need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x18];
    RECT render_rect;
    char gap_9C[0x53];
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
};

class RGE_Diamond_Map : public TPanel {
public:
    virtual void draw();
    virtual void draw_selected_area();
    virtual void draw_objects();
    virtual void draw_visible_object(void*, unsigned char, unsigned char);
    virtual void draw_object(short, short, unsigned char, short, void*);
    virtual void draw_view_rect();

    RGE_Game_World* world;
    RGE_Player* player;
    void* map;
    int all_visible;
    int render_all;
    char gap_108[0x1C];
    void* last_player;
    void* map_image_lines;
    void* map_tile_rows;
    char gap_130[0x20];
    void* main_view;
    char gap_154[0x0C];
    unsigned long cur_player_bit;
    int own_save_area;
    TDrawArea* save_area;

    void clear_image();
    void copy_image();
    void draw_all_tiles();
    void draw_explored_tiles();
};

void RGE_Diamond_Map::draw()
{
    if (this->render_area == 0 || this->save_area == 0 ||
        this->visible == 0 || this->active == 0) {
        this->need_redraw = 0;
        return;
    }

    if (this->map != 0 && this->player != 0 &&
        this->map_image_lines != 0 && this->map_tile_rows != 0) {
        this->draw_setup(0);
        this->cur_player_bit = 1 << this->world->curr_player;

        if (this->render_all != 0) {
            if (this->parent_panel != 0) {
                this->parent_panel->draw_rect(&this->clip_rect);
                this->render_area->Copy(this->save_area, 0, 0,
                                        &this->render_rect, 0);
                this->clear_image();
            } else {
                this->save_area->Clear(0, this->color);
            }
            this->draw_all_tiles();
            this->render_all = 0;
        } else {
            this->draw_explored_tiles();
        }

        this->copy_image();
        if (rge_base_game->game_mode != 0x15)
            this->draw_selected_area();
        this->draw_objects();

        if (this->render_area->Lock("diam_map::draw", 1) != 0) {
            this->draw_view_rect();
            this->render_area->Unlock("diam_map::draw");
        }

        this->draw_finish();
        this->player->diam_tile_list.del_list();
        return;
    }

    this->draw_setup(0);
    if (this->map_image_lines != 0) {
        this->clear_image();
        this->copy_image();
        this->draw_finish();
        return;
    }

    if (this->parent_panel != 0) {
        this->parent_panel->draw_rect(&this->clip_rect);
        this->draw_finish();
        return;
    }

    this->render_area->Clear(&this->clip_rect, this->color);
    this->draw_finish();
}
