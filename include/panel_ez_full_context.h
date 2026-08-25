#ifndef PANEL_EZ_FULL_CONTEXT_H
#define PANEL_EZ_FULL_CONTEXT_H

// This is the complete Panel_ez.cpp context.  It keeps the button/text
// surface local to this module so the constructor and early lifecycle owners
// can share one compiler-facing TEasy_Panel declaration.
#define AOE1_PANEL_EZ_CONTEXT_H
#define PANEL_BUTTON_TEXT_CONTEXT_H

static char s_space[] = " ";
static char s_X[] = "X";

#include <windows.h>

typedef PALETTEENTRY tagPALETTEENTRY;

typedef unsigned char uchar;

class TDrawSystem;
class TDrawArea;
class RGE_Color_Table;
struct tagRECT;
class TDigital;
class TShape;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TListPanel;
class TDropDownPanel;

class TDrawSystem {
public:
    char gap_00[8];
    void* Pal;
    char gap_0C[0x1C];
    unsigned long Flags;
    void Paint(void* rect);
    void SetPalette(void* palette);
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x14];
    union { long width; long Width; };
    union { long height; long Height; };
    TDrawArea(char*, int);
    int Init(TDrawSystem*, long, long, int, int);
    void Clear(tagRECT*, int);
    unsigned char* Lock(char*, int);
    void Unlock(char*);
    void Copy(TDrawArea*, long, long, tagRECT*, int);
    void SetShadowTable(class RGE_Color_Table*);
    void DrawShadowBox(long, long, long, long);
    void DrawBevel3(long, long, long, long, unsigned char, unsigned char,
                    unsigned char, unsigned char, unsigned char, unsigned char);
};

enum FormatType {
    FormatSingleLine = 0,
    FormatMultiLine = 7
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};
typedef RGE_Font FontInfo;

class TMousePointer {
public:
    int LoadCursors(char*, long, int);
    int get_game_enable();
    void set_game_enable(int);
    void set_game_enable(long);
};

class TPanel {
public:
    virtual ~TPanel();
    TPanel(char* name);
    TPanel();
    char gap_04[8];
    long pnl_x;
    long pnl_y;
    union { long width; long base_width; long screen_width; long field_14; long pnl_wid; };
    union { long height; long base_height; long screen_height; long field_18; long pnl_hgt; };
    union { char* panelNameValue; char* help_title; };
    union { TDrawArea* draw_area; TDrawArea* render_area; };
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
    union { int have_focus; int focused; void* field_78; void* panel_window; };
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
    union { long failed; long error_code; long error_flag; long error; long field_D8; };
    long z_order;
    long display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    union { unsigned char color; unsigned char color_index; };
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;
    long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    void set_positioning(int, long, long, long, long, long, long, long, long,
                         TPanel*, TPanel*, TPanel*, TPanel*);
    void set_rect(long, long, long, long);
    char* panelName();
    void draw_rect2(unsigned char);
    void draw_setup(int);
    void draw_finish();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    void set_focus(int);
};

class RGE_Base_Game {
public:
    char gap_000[0x1C];
    void* prog_palette;
    char gap_020[0x1A0];
    TDigital* get_sound(int id);
    RGE_Font* get_font(int id);
    TMousePointer* mouse_pointer;
    void set_mouse_cursor(void*);
    void set_mouse_cursor(int);
    void set_mouse_facet(long);
};

extern RGE_Base_Game* rge_base_game;

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char data[0x124];
    RGE_Color_Table(TDrawArea*, long, void*, tagPALETTEENTRY*);
    RGE_Color_Table(void*, long, PALETTEENTRY*, PALETTEENTRY*);
};

class TPanelSystem {
public:
    void release_palette(void* palette);
    int destroyPanel(char* name);
    void* get_palette(char* name, long id);
    TPanel* panel(char* name);
    void EnableIME(void);
    void DisableIME(void);
};

extern TPanelSystem panel_system;

class TEasy_Panel;

class THelpDialog {
public:
    char data[0x5A4];
    THelpDialog(void*, char*, long, long, long, long);
    THelpDialog(void*, char*, char*, long, long, long);
};

class TMessageDialog {
public:
    char data[0x4A4];
    TMessageDialog(char* name);
    long setup(TEasy_Panel*, char*, long, int, int, int, char*, int, int);
};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x2B8 - 0xF4];
    TButtonPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, int, TDigital*, int, long);
    void set_sound_number(long sound_id);
    void set_state_info(short state);
    void setDrawType(int type);
    void set_picture(short state, TShape*, short frame);
    void set_text_info(char*, void*, int, int, int, int);
    void set_text(short mode, char* text);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(int, int, int);
    void set_highlight_text_color(int, int, int);
};

class TTextPanelBase {
public:
    // These are the inherited TPanel operations before the text overloads.
    // The source module uses the real slot order, not an invented vtable.
    virtual ~TTextPanelBase();
    virtual void set_rect_by_bounds();
    virtual void set_color();
    virtual void set_active();
    virtual void set_positioning();
    virtual void set_fixed_position();
    virtual void set_redraw();
    virtual void set_overlapped_redraw();
    virtual void draw_setup_base();
    virtual void draw_finish_base();
    virtual void draw_base();
    virtual void draw_rect_base();
    virtual void draw_offset_base();
    virtual void draw_rect2_base();
    virtual void draw_offset2_base();
    virtual void paint();
    virtual void wnd_proc();
    virtual void handle_idle();
    virtual void handle_size();
    virtual void handle_paint();
    virtual void handle_key_down();
    virtual void handle_char();
    virtual void handle_command();
    virtual void handle_user_command();
    virtual void handle_timer_command();
    virtual void handle_scroll();
    virtual void handle_mouse_down();
    virtual void handle_mouse_move();
    virtual void handle_mouse_up();
    virtual void handle_mouse_dbl_click();
    virtual void mouse_move_action();
    virtual void mouse_left_down_action();
    virtual void mouse_left_hold_action();
    virtual void mouse_left_move_action();
    virtual void mouse_left_up_action();
    virtual void mouse_left_dbl_click_action();
    virtual void mouse_right_down_action();
    virtual void mouse_right_hold_action();
    virtual void mouse_right_move_action();
    virtual void mouse_right_up_action();
    virtual void mouse_right_dbl_click_action();
    virtual void key_down_action();
    virtual void char_action();
    virtual void action();
    virtual void get_true_render_rect();
    virtual void is_inside();
    virtual void set_focus();
    virtual void set_tab_order_panel();
    virtual void set_tab_order_index();
    virtual void get_help_info();
    virtual void stop_sound_system();
    virtual void restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    // The executable puts the char** overload at +0xE0 and char* at +0xE8.
    // A distinct recovery name prevents VC5 from regrouping both overloads.
    virtual void set_text_list(char** text, short id);
};

class TTextPanel : public TTextPanelBase {
public:
    virtual void set_text(long text_id);
    virtual void set_text(char* text);
    virtual void set_bevel_info(int, int, int, int, int, int, int); // +0xEC
    char gap_004[0xD4];
    union { long field_D8; long error_code; };
    char gap_0DC[0xAC];
    TTextPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, char, long, char, long, char*);
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, long);
    void scroll(int, int, int);
    void set_alignment(int, int);
    void set_word_wrap(int);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
    void set_scrollbar(TScrollBarPanel*, int);
    long field_40;
};

class TShape {
public:
    char data[0x20];
    TShape(char* filename, long id);
    ~TShape();
    int is_loaded();
    unsigned char shape_minmax(long&, long&, long&, long&, long);
    unsigned char shape_minmax(long*, long*, long*, long*, int);
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char, unsigned char*);
};

class TScrollBarPanel : public TPanel {
public:
    char data_F4[0x108 - 0xF4];
    TShape* button_pics;
    int back_frame;
    int up_frame;
    int down_frame;
    int tab_frame;
    char data_11C[0x1B8 - 0x11C];
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    char data_1C2[0x1C4 - 0x1C2];
    virtual ~TScrollBarPanel();
    TScrollBarPanel();
    long setup(void*, TPanel*, long, long, long, long, char*, char*, char*, char*,
               long, long, TPanel*, long, int);
    void set_buttons(TShape*, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
};

class TVerticalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0x1C4];
    virtual ~TVerticalSliderPanel();
    TVerticalSliderPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, char*, char*, long,
               long, long, long, int, int);
};

class THorizontalSliderPanel : public TScrollBarPanel {
public:
    char data[0x1CC - 0x1C4];
    virtual ~THorizontalSliderPanel();
    THorizontalSliderPanel();
    long setup(void*, TPanel*, long, long, long, long, char*, char*, long,
               long, long, long, int, int);
};

class TInputPanel {
public:
    virtual ~TInputPanel();
    virtual void setup_panel(); virtual void set_rect_by_rect_panel();
    virtual void set_rect_by_bounds_panel(); virtual void set_color_panel();
    virtual void set_active_panel(); virtual void set_positioning_panel();
    virtual void set_fixed_position_panel(); virtual void set_redraw_panel();
    virtual void set_overlapped_redraw_panel(); virtual void draw_setup_panel();
    virtual void draw_finish_panel(); virtual void draw_panel();
    virtual void draw_rect_panel(); virtual void draw_offset_panel();
    virtual void draw_rect2_panel(); virtual void draw_offset2_panel();
    virtual void paint_panel(); virtual void wnd_proc_panel();
    virtual void handle_idle_panel(); virtual void handle_size_panel();
    virtual void handle_paint_panel(); virtual void handle_key_down_panel();
    virtual void handle_char_panel(); virtual void handle_command_panel();
    virtual void handle_user_command_panel(); virtual void handle_timer_command_panel();
    virtual void handle_scroll_panel(); virtual void handle_mouse_down_panel();
    virtual void handle_mouse_move_panel(); virtual void handle_mouse_up_panel();
    virtual void handle_mouse_dbl_click_panel(); virtual void mouse_move_action_panel();
    virtual void mouse_left_down_action_panel(); virtual void mouse_left_hold_action_panel();
    virtual void mouse_left_move_action_panel(); virtual void mouse_left_up_action_panel();
    virtual void mouse_left_dbl_click_panel(); virtual void mouse_right_down_action_panel();
    virtual void mouse_right_hold_action_panel(); virtual void mouse_right_move_action_panel();
    virtual void mouse_right_up_action_panel(); virtual void mouse_right_dbl_click_panel();
    virtual void key_down_action_panel(); virtual void char_action_panel();
    virtual void action_panel(); virtual void get_true_render_rect_panel();
    virtual void is_inside_panel(); virtual void set_focus_panel();
    virtual void set_tab_order_panel(); virtual void set_tab_order_index();
    virtual void get_help_info_panel(); virtual void stop_sound_system_panel();
    virtual void restart_sound_system_panel(); virtual void take_snapshot_panel();
    virtual void handle_reactivate_panel(); virtual void set_text_list(char**, short);
    virtual void set_text(long);
    virtual void set_text(char*);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    char gap_004[0xD4];
    long field_D8;
    char gap_0DC[0xDC];
    TInputPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, long, char, char, int, int, short, TDigital*, char*, FormatType);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
};

class TEditPanel : public TPanel {
public:
    char whole[0x16C - 0xF4];
    TEditPanel();
    virtual ~TEditPanel();
    int setup(TDrawArea*, TPanel*, int, int, int, int, void*, short, char*, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(int, int);
    void set_highlight_text_color(int, int);
    void set_back_color(void*, int, unsigned char);
    void set_ime_info(int, int);
};

class TListPanel {
public:
    char gap_00[0xD8];
    long error;
    TListPanel();
    long setup(TDrawArea*, TPanel*, long, long, long, long, void*, long, long,
               char*, int, unsigned char, int, unsigned char, short, char**, int);
    void scroll_cur_line(unsigned char, int, unsigned char);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_text_color(unsigned long, unsigned long);
    void set_highlight_text_color(unsigned long, unsigned long);
};

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    char gap_100[0x144 - 0x100];
    TDropDownPanel();
    long setup(TDrawArea*, TPanel*, void*, int, int, int, char, int, int, int, int,
               int, int, int, int, int, int, char*, int, int, char**, int, int,
               char*, char*, char*, char*, int, int);
    void set_buttons(TShape*, int, int, int, int, int);
    void set_bevel_info(int, int, int, int, int, int, int);
    void set_val_text_color(unsigned long, unsigned long);
};

class TEasy_Panel : public TPanel {
public:
    TEasy_Panel(char* name);
    TEasy_Panel();
    virtual ~TEasy_Panel();
    long ideal_width;
    long ideal_height;
    union { char info_file_name[260]; char field_FC[260]; };
    union { long info_id; int field_200; };
    union { TShape* background_pic; int field_204; };
    union { TShape* background_pic2; int field_208; };
    union { void* palette; int field_20C; };
    union { char cursor_file[260]; char field_210[260]; };
    union { long cursor_id; int field_314; };
    union { int background_pos; int field_318; };
    union { long use_bevels; long field_31C; };
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    char gap_326[2];
    union { unsigned long text_color1; int field_328; };
    union { unsigned long text_color2; int field_32C; };
    union { unsigned long focus_color1; int field_330; };
    union { unsigned long focus_color2; int field_334; };
    union { unsigned long state_color1; int field_338; };
    union { unsigned long state_color2; int field_33C; };
    union { char popup_info_file_name[260]; char field_340[260]; };
    union { long popup_info_id; int field_444; };
    union { TShape* button_pics; int field_448; };
    union { RGE_Color_Table* shadow_color_table; int field_44C; };
    union { long shadow_amount; int field_450; };
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char pad_456[2];
    union { int enable_ime; int field_458; };
    unsigned char help_mode;
    unsigned char pad_45D[3];
    union { int stock_brush; int fill_in_background; };
    union { void* brush; void* background_brush; };
    union { unsigned long brush_color; int field_468; };
    TDrawArea* shadow_area;
    long allow_shadow_area;
    long saved_mouse_mode;

    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
    void init_vars();
    void prepare_for_close();
    int get_string(long, char*, long);
    char* get_string(long);
    int action(TPanel*, long, long, long);
    int base_action(TPanel*, long, long, long);
    void set_system_colors();
    void popupOKDialog(int, char*, int, int);
    void popupOKDialog(char*, char*, int, int);
    void popupYesNoDialog(long, char*, int, int);
    void popupYesNoDialog(char*, char*, int, int);
    void popupYesNoCancelDialog(char*, char*, int, int);
    void popupYesNoCancelDialog(long, char*, int, int);
    void command_help(char*, long, long, long, long);
    void command_help(char*, char*, long, long, long);
    void setup_popup_help();
    void clear_popup_help();
    long command_do_popup_help(unsigned char, long, long);
    unsigned char get_popup_help(char**, long*, long, long);
    void setup_shadow_area(int);
    void draw_setup(int);
    void draw();
    void redraw(long);
    void set_focus(int);
    long handle_mouse_down(unsigned char, long, long, int, int);
    void set_info_file(char*, long);
    void set_use_bevels(int);
    int set_background(char*, long);
    int set_background2(char*, long);
    void set_shadow_amount(long);
    int set_palette(char*, long);
    int set_cursor(char*, long);
    void set_background_pos(int);
    void set_background_colors(unsigned char, unsigned char);
    void set_bevel_colors(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
    void set_text_colors(int, int);
    void set_focus_colors(int, int);
    void set_state_colors(int, int);
    void set_button_pics(char*, long);
    void set_popup_info_file(char*, long);
    void set_popup_info_file(const char*, long);
    void set_enable_ime(int);
    char* get_info_file();
    int get_info_id();
    int get_background();
    int get_background2();
    int get_palette();
    char* get_cursor();
    int get_use_bevels();
    int get_background_pos();
    void get_bevel_colors(unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned char*, unsigned char*);
    void get_text_colors(int*, int*);
    void get_focus_colors(int*, int*);
    int get_shadow_amount();
    void get_state_colors(int*, int*);
    char* get_popup_info_file();
    int get_popup_info_id();
    int get_button_pics();
    int get_shadow_color_table();
    int get_enable_ime();
    virtual void notify_background_color(unsigned char);
    void draw_background(int);

protected:
    virtual void set_ideal_size(long width, long height);

    // Panel_ez.cpp records these factory owners as protected virtual methods.
    // Keep MAE decoration and the PDB virtual-slot order in the shared TU.
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                              long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                              long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long,
                            long, long, long, long);
    int create_text(TPanel*, TTextPanel**, long, long, long, long, long, long, long, long);
    int create_text(TPanel*, TTextPanel**, long, long, long, long, long, long, long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long,
                            long, long, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, int, long, long,
                            long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long,
                                 long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    int create_auto_scrollbar_impl(long, TScrollBarPanel**, TTextPanel*, int, int, int, long, int);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

#endif
