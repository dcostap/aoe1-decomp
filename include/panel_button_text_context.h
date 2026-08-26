#ifndef PANEL_BUTTON_TEXT_CONTEXT_H
#define PANEL_BUTTON_TEXT_CONTEXT_H

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
    char gap_00[0x28];
    unsigned long Flags;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x14];
    long width;
    long height;
    TDrawArea(char*, int);
    int Init(TDrawSystem*, long, long, int, int);
    void Clear(tagRECT*, int);
    unsigned char* Lock(char*, int);
    void SetShadowTable(class RGE_Color_Table*);
    void DrawShadowBox(long, long, long, long);
    void Unlock(char*);
};

struct RGE_Font {
    void* font;
    long font_wid;
    long font_hgt;
};
typedef RGE_Font FontInfo;

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x14 - 0x04];
    union { long width; long base_width; long screen_width; long field_14; long pnl_wid; };
    union { long height; long base_height; long screen_height; long field_18; long pnl_hgt; };
    char* panelNameValue;
    union { TDrawArea* draw_area; TDrawArea* render_area; };
    char gap_24[0xD8 - 0x24];
    union { long failed; long error_code; long error_flag; long error; long field_D8; };
    char gap_DC[0xF4 - 0xDC];
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
};

class RGE_Base_Game {
public:
    TDigital* get_sound(int id);
    RGE_Font* get_font(int id);
};

extern RGE_Base_Game* rge_base_game;

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
    virtual ~TTextPanelBase();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    // The executable puts the char** overload at +0xE0 and char* at +0xE8.
    // A distinct recovery name prevents VC5 from regrouping both overloads.
    virtual void set_text_list(char** text, short id);
};

class TTextPanel : public TTextPanelBase {
public:
    virtual void set_text(char* text);
    virtual void set_text(long text);
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
};

class TShape {
public:
    char data[0x20];
    TShape(char* filename, long id);
    ~TShape();
    int is_loaded();
    unsigned char shape_minmax(long&, long&, long&, long&, long);
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
    enum FormatType {
        FormatSingleLine = 0,
        FormatMultiLine = 7
    };
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
    virtual void mouse_right_up_action_panel();
    virtual void mouse_right_dbl_click_panel(); virtual void key_down_action_panel();
    virtual void char_action_panel(); virtual void action_panel();
    virtual void get_true_render_rect_panel(); virtual void is_inside_panel();
    virtual void set_focus_panel(); virtual void set_tab_order_panel();
    virtual void set_tab_order_index(); virtual void get_help_info_panel();
    virtual void stop_sound_system_panel(); virtual void restart_sound_system_panel();
    virtual void take_snapshot_panel(); virtual void handle_reactivate_panel();
    virtual void set_text_list(char**, short);
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
    enum FormatType {
        FormatSingleLine = 0,
        FormatMultiLine = 7
    };
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
    long ideal_width;
    long ideal_height;
    char gap_FC[0x31C - 0xFC];
    long use_bevels;
    uchar bevel_color1;
    uchar bevel_color2;
    uchar bevel_color3;
    uchar bevel_color4;
    uchar bevel_color5;
    uchar bevel_color6;
    char gap_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char gap_340[0x448 - 0x340];
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    char gap_450[4];
    unsigned char background_color1;
    char gap_455[0x0F];
    void* brush;
    int brush_color;
    long allow_shadow_area;

    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);
    void setup_shadow_area(int);
    void draw_setup(int);
    void draw();
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
    void set_text_colors(unsigned long, unsigned long);
    void set_focus_colors(unsigned long, unsigned long);
    void set_state_colors(unsigned long, unsigned long);
    void set_button_pics(char*, long);
    void set_popup_info_file(char*, long);
    virtual void draw_background(int);

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
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long, long,
                            long, long, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, TInputPanel::FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, TEditPanel::FormatType, long, long,
                            long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long, long,
                                 long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                   long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);
};

#endif
