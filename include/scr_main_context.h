#ifndef AOE1_SCR_MAIN_CONTEXT_H
#define AOE1_SCR_MAIN_CONTEXT_H

#include <windows.h>

class TDrawArea;
class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TPanel {
public:
    virtual ~TPanel();

    char gap_04[0x8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    char gap_24[0x1C];
    void* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x14];
    void* clip_rgn;
    RECT render_rect;
    char gap_9C[0x3C];
    int setup_error;
    char gap_DC[0x4];
    int display_changed_count;
    char gap_E4[0x10];

    virtual long setup(TDrawArea* area, TPanel* parent, long x, long y,
                       long w, long h, unsigned char mode);
    virtual void set_rect(RECT rect);
    virtual void set_rect(long left, long top, long right, long bottom);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active_value);
    virtual void set_positioning(int mode, long p2, long p3, long p4,
                                 long p5, long p6, long p7, long p8,
                                 long p9, TPanel* p10, TPanel* p11,
                                 TPanel* p12, TPanel* p13);
    virtual void set_fixed_position(long x, long y, long right, long bottom);
    virtual void set_redraw(int mode);
    virtual void set_overlapped_redraw(TPanel* first, TPanel* second,
                                       int mode);
    virtual void draw_setup(int mode);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(RECT* rect);
    virtual void draw_offset(long x, long y, RECT* rect);
    virtual void draw_rect2(RECT* rect);
    virtual void draw_offset2(long x, long y, RECT* rect);
    virtual void paint();
    virtual long wnd_proc(void* window, unsigned int message,
                          unsigned int wparam, long lparam);
    virtual long handle_idle();
    virtual long handle_size(long width, long height);
    virtual long handle_paint();
    virtual long handle_key_down(long key, short state, int p3, int p4,
                                 int p5);
    virtual long handle_char(long key, short state);
    virtual long handle_command(unsigned int command, long value);
    virtual long handle_user_command(unsigned int command, long value);
    virtual long handle_timer_command(unsigned int command, long value);
    virtual long handle_scroll(long value, long state);
    virtual long handle_mouse_down(unsigned char button, long x, long y,
                                   int p4, int p5);
    virtual long handle_mouse_move(long x, long y, int p3, int p4);
    virtual long handle_mouse_up(unsigned char button, long x, long y,
                                 int p4, int p5);
    virtual long handle_mouse_dbl_click(unsigned char button, long x, long y,
                                        int p4, int p5);
    virtual long mouse_move_action(long x, long y, int p3, int p4);
    virtual long mouse_left_down_action(long x, long y, int p3, int p4);
    virtual long mouse_left_hold_action(long x, long y, int p3, int p4);
    virtual long mouse_left_move_action(long x, long y, int p3, int p4);
    virtual long mouse_left_up_action(long x, long y, int p3, int p4);
    virtual long mouse_left_dbl_click_action(long x, long y, int p3, int p4);
    virtual long mouse_right_down_action(long x, long y, int p3, int p4);
    virtual long mouse_right_hold_action(long x, long y, int p3, int p4);
    virtual long mouse_right_move_action(long x, long y, int p3, int p4);
    virtual long mouse_right_up_action(long x, long y, int p3, int p4);
    virtual long mouse_right_dbl_click_action(long x, long y, int p3, int p4);
    virtual long key_down_action(long key, short state, int p3, int p4,
                                 int p5);
    virtual long char_action(long key, short state);
    virtual long action(TPanel* panel, long event, unsigned long p3,
                        unsigned long p4);
    virtual void get_true_render_rect(RECT* rect);
    virtual int is_inside(long x, long y);
    virtual void set_focus(int focus);
    virtual void set_tab_order(TPanel* previous, TPanel* next);
    virtual void set_tab_order(TPanel** panels, short count);
    virtual unsigned char get_help_info(char** text, long* id, long p3,
                                        long p4);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    void delete_panel(TPanel** panel_ptr);
    char* panelName();
    int get_string(int id, char* buffer, int length);
    char* get_string(int id);
    long xPosition();
    long yPosition();
    long width();
    long height();
    void set_curr_child(TPanel* child);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
    // BINARY NOTE: The message vtable uses the slots at +0xE0, +0xE4,
    // and +0xE8 for three text forms.  Recovery names keep VC5 from
    // regrouping the overloads while preserving those observed slots.
    virtual void set_text_list(char** text, short id);
    virtual void set_text_long(long id);
    virtual void set_text(char* text);
    int get_text_rect(RECT* rect);
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
    void set_text(short state, long string_id);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];

    virtual ~TEasy_Panel();
    void set_ideal_size(long width, long height);
    int create_button(TPanel* parent, TButtonPanel** output,
                      char* text, long x, long y, long width, long height,
                      long font, long sound, long user, long flags);
    int create_button(TPanel* parent, TButtonPanel** output,
                      long string_id, long x, long y, long width, long height,
                      long font, long sound, long user, long flags);
    int create_text(TPanel* parent, TTextPanel** output, long string_id,
                    long x, long y, long width, long height, long font,
                    long align, long center, long wrap);
    int create_text(TPanel* parent, TTextPanel** output, char* text,
                    long x, long y, long width, long height, long font,
                    long align, long center, long wrap);
    void popupOKDialog(long string_id, char* text, int value1, int value2);
    long action(TPanel* panel, long event, unsigned long p3,
                unsigned long p4);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(void* draw_area, char* info, long id, long value);
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    void* pic;
    void* shape;

    virtual ~TPicturePanel();
    TPicturePanel();
    long setup(TDrawArea* draw_area, TPanel* parent, long x, long y,
               long width, long height, char* name, long id,
               int size_from_pic_value, int keep_loaded_value);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x0C];
    void* prog_window;
    char gap_14[0x38];
    TDrawArea* draw_area;
    char gap_50[0x170];
    int field_1C0;
    char gap_1C4[0x14];
    int input_enabled;
    char gap_1DC[0x7D0];
    int save_check_for_cd;

    int check_for_cd(int players);
    void disable_input();
    void close();
    void enable_input();
    int gameDeveloperMode();
    int load_db_files();
};

class TribeSPMenuScreen {
public:
    char data[0x49C];
    TribeSPMenuScreen();
};

class TribeMPStartupScreen {
public:
    char data[0x6A0];
    TribeMPStartupScreen();
};

class TRIBE_Screen_Sed_Menu {
public:
    char data[0x490];
    TRIBE_Screen_Sed_Menu();
};

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    char data[0x8B8 - sizeof(TScreenPanel)];
    TRIBE_Credits_Screen();
    virtual ~TRIBE_Credits_Screen();
};

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TTextPanel* title1;
    TTextPanel* title2;
    TButtonPanel* button[7];
    TTextPanel* ms_title_text;
    TTextPanel* ms_copy_text1;
    TTextPanel* ms_copy_text2;
    TTextPanel* warning_text;
    TPicturePanel* circle_p_pic;

    TRIBE_Screen_Main_Menu();
    virtual ~TRIBE_Screen_Main_Menu();
    virtual long handle_idle();
    virtual long key_down_action(long key, short param_2, int param_3,
                                 int param_4, int param_5);
    virtual long action(TPanel* panel, long event, unsigned long p3,
                        unsigned long p4);
};

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    TRIBE_Screen_Main_Error();
    virtual ~TRIBE_Screen_Main_Error();
    void set_text(char* param);
    void set_text(long param);
    virtual long action(TPanel* panel, long event, unsigned long p3,
                        unsigned long p4);
    virtual long handle_idle();
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;
extern char s_Main_Menu[];
extern char s_scr1[];
extern char s_empty[];
extern char s_circlep2[];
extern char s_space[];

#endif
