#ifndef SCR_SEDO_CONTEXT_H
#define SCR_SEDO_CONTEXT_H

class TDrawArea;
class TShape;
class RGE_Color_Table;
class TTextPanel;
class TButtonPanel;
class TListPanel;
class TScrollBarPanel;
class RGE_Prog_Info;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
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

    char gap_04[0xD4];
    int setup_error;
    char gap_DC[0x18];
    void set_curr_child(TPanel* child);
    char* panelName();
    int get_string(int id, char* buf, int maxlen);
};

class TEasy_Panel : public TPanel {
public:
    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
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
    unsigned char pad_326[2];
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    unsigned char pad_456[2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char pad_45D[3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    void set_ideal_size(long width, long height);
    long create_text(TPanel* panel, TTextPanel** text_field, long lang_id,
                     long x, long y, long width, long height,
                     long a8, long a9, long a10, long a11);
    long create_button(TPanel* panel, TButtonPanel** btn_field, long lang_id,
                       long x, long y, long width, long height,
                       long a8, long a9, long a10, long a11);
    long create_list(TPanel* panel, TListPanel** list_field,
                     long x, long y, long width, long height, long a7);
    long create_auto_scrollbar(TScrollBarPanel** scroll_field,
                               TTextPanel* list, long a4);
    void setup_shadow_area(int val);
    char* get_info_file();
    long get_info_id();
    virtual long action(TPanel* param_1, long param_2,
                        unsigned long param_3, unsigned long param_4);
    void popupYesNoDialog(char* msg, char* dialog_name, int h, int w);
    void popupOKDialog(int msg_id, char* unk, int h, int w);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(const char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, char* info, long param, int zero);
    void delete_panel(TPanel** panel_ptr);
};

class TPanelSystem {
public:
    TEasy_Panel* currentPanel();
    TPanel* panel(const char* name);
    int setCurrentPanel(const char* name, int val);
    int destroyPanel(const char* name);
};

extern TPanelSystem panel_system;

class TButtonPanel : public TPanel {
public:
    long id[9];
    long id2[9];
    int buttonTypeValue;
    int drawTypeValue;
    int notifyTypeValue;
    void* sound;
    void* pic[9];
    short pic_index[9];
    unsigned char pad_182[2];
    int auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;
    int draw_reverse;
    char* text1[9];
    char* text2[9];
    long text_x;
    long text_y;
    void* font;
    long font_wid;
    long font_hgt;
    short num_states;
    short cur_state;
    int is_down;
    TButtonPanel** radio_buttons;
    short num_radio_buttons;
    unsigned char pad_202[2];
    unsigned long button_down_time;
    unsigned long text_color1[9];
    unsigned long text_color2[9];
    unsigned long highlight_text_color1[9];
    unsigned long highlight_text_color2[9];
    long hotkey;
    long hotkey_shift;
    int bevel_type;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned char pad_2AA[2];
    long key_down;
    int disabled;
    int sound_number;
    void set_disabled(int val);
};

class TTextPanel : public TPanel {
public:
    char gap_00[0x15C - 0xF4];
    int sorted;
    char* currentLine();
    long get_line();
    int delete_line(long line);
    int numberLines();
    void empty_list();
    int append_line(char* text, int data);
};

class TListPanel : public TTextPanel {};
class TScrollBarPanel : public TPanel {};

class RGE_Prog_Info {
public:
    char gap_00[0xC17];
    char scenario_dir[261];
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;
    char gap_10[0x4C - 0x10];
    void* draw_area;
    int start_scenario_editor(char* path, int val);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed_Open : public TScreenPanel {
public:
    TTextPanel* title;
    TListPanel* list;
    TScrollBarPanel* scrollbar;
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    TButtonPanel* deleteButton;

    TRIBE_Screen_Sed_Open();
    virtual ~TRIBE_Screen_Sed_Open();
protected:
    void fillList();
    virtual long action(TPanel* param_1, long param_2,
                        unsigned long param_3, unsigned long param_4);
};

#endif
