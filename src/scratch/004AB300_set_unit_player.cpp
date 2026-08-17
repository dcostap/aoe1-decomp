// VA: 004AB300 TRIBE_Screen_Sed::set_unit_player
// Exact-finish log:
// - Baseline: 850 rebuilt bytes versus 879 original bytes, frame 0x10 versus 0x0C.
// - Decisive: short output and selected locals restored the original homes and frame.
// - Decisive: a guarded do/while scan restored test-before-offset initialization.
// - Decisive: direct indexed records restored the original 0x66 index arithmetic.
// - Decisive: long get_string ID restored the original virtual-call schedule.
// - ABI: RGE_Base_Game::master_obj_id is at +0x3FC after its vptr.
// - First exact checkpoint: 0.0000% positional difference, 2026-08-17.
// - Walkback: long get_string ID, short locals, guarded scan, and direct records are required.
// - Walkback: the expanded screen and base declaration surfaces were incidental.
// - Policy audit: canonical TScreenPanel inheritance remains exact.
// Policy repair:
// - Replaced RGE_Base_Game fake slots with the reviewed named prefix and fields.
// - Replaced TListPanel VPAD slots with the named TPanel/TTextPanel/TListPanel surface.
// - Replaced screen offset gaps with reviewed TRIBE_Screen_Sed fields and base types.
// - Replaced master-object byte cursors with typed indexed array access.
// - Canonical declarations retain exact size, frame, calls, and all but five bytes.
// - The remaining five bytes are VC5's zero/count initialization order in the first
//   natural indexed scan. The raw byte cursor is exact but is not policy-valid.
// FLAGS: default config/flags/default.rsp (/nologo /c /O2 /Oy).

#include <string.h>

extern "C" void* calloc(unsigned int, unsigned int);
extern "C" void free(void*);
extern "C" void qsort(void*, unsigned int, unsigned int, int (__cdecl*)(const void*, const void*));
int __cdecl TRIBE_Screen_Sed_unit_list_compare(const void*, const void*);

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    unsigned char master_type;
    unsigned char gap05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap16[2];
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap25;
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap2d[3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char disabled;
};
struct RGE_Tile_List { char values[0x14]; };
class RGE_Player {
public:
    virtual ~RGE_Player();
    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    unsigned char gap21;
    short master_object_num;
    RGE_Master_Static_Object** master_objects; // BINARY NOTE: this is a typed pointer array.
    void* objects;
    void* sleeping_objects;
    void* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    void* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    unsigned char gap49;
    short id;
    short attribute_num;
    unsigned char gap4e[2];
    float* attributes;
    unsigned char culture;
    unsigned char gap55[3];
    RGE_Tile_List tile_list;
    RGE_Tile_List diam_tile_list;
    unsigned char game_status;
    unsigned char resigned;
    unsigned char gap82[2];
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
    unsigned char gap106[2];
    void* color_table;
    long tribe_effect;
    void* VR_List;
    float view_x;
    float view_y;
    short map_x;
    short map_y;
    void set_view_loc(float x, float y);
    void set_map_loc(short x, short y);
};
struct List_Info { char text[100]; short id; };

// Keep the helper declarations on the owning classes used by the exact
// player/view methods.  These are separate game-state surfaces in the
// original TU, even though all four methods use the same player object.
class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short p); // +14
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long id, char* out, int len); // BINARY NOTE: the ID uses the long overload.
    virtual char* get_string(long);
    RGE_Player* get_player();
    void* player_game_info;
    void* scenario_info;
    void* prog_info;
    void* prog_window;
    int prog_ready;
    int prog_active;
    void* prog_palette;
    void* prog_mutex;
    long window_style;
    int random_game_seed;
    int random_map_seed;
    int save_random_game_seed;
    int save_random_map_seed;
    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;
    void* draw_system;
    void* draw_area;
    unsigned char outline_type;
    unsigned char gap51[3];
    int custom_mouse;
    short shape_num;
    unsigned char gap5a[2];
    void* shapes;
    void* sound_system;
    void* music_system;
    short sound_num;
    unsigned char gap6a[2];
    void* sounds;
    unsigned char save_music_type;
    unsigned char gap71[3];
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned long save_music_pos;
    void* comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;
    void* debugLog;
    int log_comm;
    void* registry;
    int prog_mode;
    int game_mode;
    int sub_game_mode;
    int paused;
    void* mouse_pointer;
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    void* mouse_cursor;
    int input_enabled;
    void* input_disabled_window;
    short font_num;
    unsigned char gap1e2[2];
    void* fonts;
    char work_dir[261];
    char string_dll_name[261];
    unsigned char gap3f2[2];
    void* world;
    int render_all;
    short master_obj_id;
};
extern RGE_Base_Game* rge_base_game;
class RGE_View { public: void set_player(RGE_Player*); };
class RGE_Diamond_Map { public: void set_player(RGE_Player*); };
struct tagRECT { long left; long top; long right; long bottom; };
class TPanel;
class TTextPanel;
class TListPanel;

// Canonical TPanel/TTextPanel/TListPanel surfaces from the reviewed UI donors.
// The target uses only TListPanel::set_text at virtual slot +0xE0.
class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long action(TPanel*, long, unsigned long, unsigned long);
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
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    void* render_area;
    tagRECT clip_rect;
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
};
class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    void* background_pic;
    void* background_pic2;
    void* palette;
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char gap326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    void* button_pics;
    void* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char gap456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char gap45d[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    void* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;
};
class TTextPanel : public TPanel {
public:
    void* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    int vert_align;
    int horz_align;
    int word_wrap;
    int text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    void* scbar_panel;
    int auto_scbar;
    short fixed_len;
    unsigned char gap13a[2];
    long text_wid;
    long text_hgt;
    void* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    unsigned char gap151[3];
    int outline;
    unsigned char outline_color;
    unsigned char gap159[3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;
    int scbar_active;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char gap17a[2];
    void* clip_rgn2;
    int border_size;
    int spacer_size;
    void empty_list();
};
class TDropDownPanel : public TTextPanel {
public:
    void setCurrentLineNumber(int);
};
class TMessagePanel : public TPanel {};
class TListPanel : public TTextPanel {
public:
    virtual ~TListPanel();
    virtual void set_text(char** data, short count);
    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;
    void scroll_cur_line(unsigned char, short, int);
};
class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(void*, void*, long, long, long, long, long, long, long, long, long);
    virtual int create_button(void*, void*, char*, char*, long, long, long, long, long, long, long);
    virtual int create_check_box(void*, void*, long, long, long, long, long, long);
    virtual int create_radio_button(void*, void*, long, long, long, long, long, long);
    virtual int create_text(void*, void*, int, long, long, long, long, long, int, int, int);
    virtual int create_text(void*, void*, char**, long, long, long, long, long, long, int, int);
    virtual int create_text(void*, void*, char*, long, long, long, long, long, int, int, int);
    virtual int create_input(void*, void*, char*, short, int, long, long, long, long, long);
    virtual int create_edit(void*, void*, char*, short, int, long, long, long, long, long, int, int);
    virtual int create_drop_down(void*, void*, long, long, long, long, long, long, long);
    virtual int create_list(void*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(void**, void*, void*, long, long, long, long, long);
    virtual int create_auto_scrollbar(void**, void*, long);
    virtual int create_vert_slider(void*, void*, long, long, long, long, long, long, long);
    virtual int create_horz_slider(void*, void*, long, long, long, long, long, long, long);
    virtual void position_panel(void*, long, long, long, long);
};
class TRIBE_Main_View : public RGE_View {};
class RGE_Diamond_Map_View : public RGE_Diamond_Map {};
class TRIBE_Screen_Sed : public TScreenPanel {
public:
    int is_multi_player;
    int set_player_first_flag;
    void* SelectedObject;
    void* DestinationObject;
    float px1;
    float py1;
    float px2;
    float py2;
    int CurrentVictory;
    int CurrentPlayer;
    int SelectRegionFlag;
    int scenario_mode;
    int map_type;
    int mp_victory_type;
    int brush_size;
    int paint_type;
    short player_num;
    unsigned char gap4ba[2];
    int message_type;
    unsigned char need_to_save_flag;
    unsigned char valid_save_spot_flag;
    unsigned char gap4c2[2];
    void* background_pic;
    TRIBE_Main_View* main_view;
    RGE_Diamond_Map_View* map_view;
    TMessagePanel* message_panel;
    TPanel* bottom_panel;
    void* scenario_mode_button[10];
    void* menu_button;
    void* help_button;
    void* map_type_button[3];
    void* map_type_text[3];
    void* map_type_label;
    void* default_terrain_label;
    void* default_terrain_drop;
    void* map_size_label;
    void* map_size_drop;
    void* map_style_label;
    void* map_style_drop;
    void* random_seed_label;
    void* random_seed_input;
    void* random_seed_used_label;
    void* random_seed_used_text;
    void* generate_map_button;
    void* map_generating_text;
    void* brush_size_label;
    void* brush_size_button[5];
    void* brush_size_button_label[5];
    void* paint_type_label;
    void* paint_type_button[3];
    void* paint_type_button_label[3];
    void* paint_terrain_label;
    void* paint_terrain_list;
    void* paint_terrain_scrollbar;
    void* paint_elevation_list;
    void* paint_elevation_scrollbar;
    void* player_label;
    void* player_list;
    void* player_number_list;
    void* player_advance_civilization_drop;
    void* player_advance_civilization_button;
    void* player_inven_label[5];
    void* player_inven_input[5];
    void* player_setting_label[2];
    void* player_starting_age_label;
    void* player_setting_drop[2];
    void* BuildList;
    void* CityLayout;
    void* AiRules;
    void* player_build_text;
    void* player_city_text;
    void* AiRules_text;
    TDropDownPanel* unit_player_list;
    void* unit_mode_select[4];
    void* unit_mode_select_label[4];
    TListPanel* unit_list;
    void* unit_scrollbar;
    List_Info* unit_list_info;
    void* button_unit_pics;
    void* button_bldg_pics[5];
    void* object_panel;
    short unit_list_size;
    void set_string(char* dst, int id, int len);
    void set_unit_player(short p);
};

void TRIBE_Screen_Sed::set_unit_player(short p)
{
    int is_error;
    float save_view_x;
    float save_view_y;
    short save_map_x;
    short save_map_y;

    RGE_Player* oldp = rge_base_game->get_player();
    save_view_x = oldp->view_x;
    save_view_y = oldp->view_y;
    save_map_x = oldp->map_x;
    save_map_y = oldp->map_y;
    rge_base_game->set_player(p);
    this->player_num = p;

    RGE_Player* player = rge_base_game->get_player();
    player->set_view_loc(save_view_x, save_view_y);
    player->set_map_loc(save_map_x, save_map_y);
    this->main_view->set_player(player);
    this->map_view->set_player(player);
    this->unit_player_list->setCurrentLineNumber((int)p);
    this->unit_list->empty_list();
    if (this->unit_list_info != 0) {
        free(this->unit_list_info);
        this->unit_list_info = 0;
    }
    if (player != 0) {
        this->unit_list_size = 1;
        short n = player->master_object_num;
        if (n > 0) {
            int count = n;
            int index = 0;
            do {
                // BINARY NOTE: direct indexing preserves the four-byte pointer stride.
                RGE_Master_Static_Object* m = player->master_objects[index];
                if (m != 0 && m->disabled == 0) this->unit_list_size++;
                ++index;
                count--;
            } while (count != 0);
        }
        if (this->unit_list_size == 0) return;
        this->unit_list_info = (List_Info*)calloc((int)this->unit_list_size, 0x66);
        if (this->unit_list_info == 0) return;
        this->unit_list_info[0].id = -1;
        this->set_string(this->unit_list_info[0].text, 0x2775, 0x14);

        short out = 1; // BINARY NOTE: the original loads this index as a word.
        short i = 0;
        // BINARY NOTE: the offset zero store follows the positive-count test.
        if (n > 0) {
            int master_index = 0;
            do {
                RGE_Master_Static_Object* m = player->master_objects[master_index];
                if (m != 0 && m->disabled == 0) {
                    this->unit_list_info[out].id = (short)i;
                    m = player->master_objects[master_index];
                    if (m->string_id > 0) {
                        rge_base_game->get_string(m->string_id, this->unit_list_info[out].text, 100);
                    } else {
                        strcpy(this->unit_list_info[out].text, m->name);
                    }
                    out++;
                }
                i++;
                master_index++;
            } while (i < n);
        }

        qsort(this->unit_list_info, (int)this->unit_list_size, 0x66, TRIBE_Screen_Sed_unit_list_compare);
        char** strings = (char**)calloc((int)this->unit_list_size, 4);
        if (strings == 0) return;
        is_error = 0;
        short selected = 0; // BINARY NOTE: the selected row uses a short home.
        for (i = 0; i < this->unit_list_size; i++) {
            char* s = (char*)calloc(100, 1);
            strings[i] = s;
            if (s == 0) { is_error = 1; break; }
            strcpy(s, this->unit_list_info[i].text);
            if (this->unit_list_info[i].id == rge_base_game->master_obj_id) selected = i;
        }
        if (!is_error) {
            this->unit_list->set_text(strings, this->unit_list_size);
            this->unit_list->scroll_cur_line(1, (short)selected, 1);
        }
        for (i = 0; i < this->unit_list_size; i++) {
            if (strings[i] != 0) free(strings[i]);
        }
        free(strings);
    }
}
