#ifndef SCR_TRB_CONTEXT_H
#define SCR_TRB_CONTEXT_H

// Authentic scr_trb.cpp context. The full TPanel surface is required to place
// the inherited TTextPanel virtual slots at their observed addresses.

class TDrawArea {
public:
    char gap_00[0x18];
    int width;
};

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDigital;
class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int active);
    virtual void set_positioning(long mode, long a2, long a3, long a4,
                                 long a5, long a6, long a7, long a8,
                                 long a9, TPanel* a10, TPanel* a11,
                                 TPanel* a12, TPanel* a13);
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

    char gap_04[0x8];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[4];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];

    void set_curr_child(TPanel* child);
};

class TPicturePanel : public TPanel {
public:
    char gap_F4[0x28];
    TPicturePanel();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, char* picture, long resource,
               int size_from_picture, int keep_loaded);
};

class RGE_Font {
public:
    void* font;
    int font_wid;
    int font_hgt;
};

class TTextPanel : public TPanel {
public:
    char gap_F4[0x94];

    TTextPanel();
    virtual ~TTextPanel();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, void* font, long font_wid,
               long font_hgt, char* back_picture, int fill,
               unsigned char back_color, int outline,
               unsigned char outline_color, short fixed_len, char* text);
    void set_alignment(int vertical, int horizontal);
    virtual void set_rect(long, long, long, long);
    virtual void set_active(int);
    virtual void draw();
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    // BINARY NOTE: The original vtable has char** at +0xE0, long at +0xE4,
    // and char* at +0xE8. VC5 emits that order from these declarations.
    virtual void set_text(char* text);
    virtual void set_text(long text);
    virtual void set_text(char** text, short count);
    virtual void set_bevel_info(int, int, int, int, int, int, int);
    void scroll(int scroll_type, short amount, int param_3);
};

class TButtonPanel : public TPanel {
public:
    TButtonPanel();
    char gap_F4[0x1A4];
    long hotkey;
    long hotkey_shift;
    char gap_2A0[0x18];

    long setup(TDrawArea* draw, TPanel* parent, long x, long y,
               long width, long height, long draw_type, TDigital* sound,
               long notify_type, long button_id);
    void set_text_info(char* text, void* font, long font_wid,
                       long font_hgt, long x, long y);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual long action(TPanel* sender, long actionType, unsigned long param3,
                        unsigned long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel(char* name);
    virtual ~TScreenPanel();
    long setup(TDrawArea* draw, char* text, long id, int value);
};

class RGE_Base_Game {
public:
    char gap_00[0x4C];
    TDrawArea* draw_area;
    RGE_Font* get_font(int index);
    TDigital* get_sound(int index);
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int a);
    int destroyPanel(char* name);
};

enum { NotifyAction = 1 };

class TribeSelectTribeScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* tribeText;
    TButtonPanel* tribeButton[9];
    TButtonPanel* okButton;
    TButtonPanel* cancelButton;
    char** screenText;
    int numLines;

    virtual ~TribeSelectTribeScreen();
    TribeSelectTribeScreen();

protected:
    virtual long action(TPanel* sender, long actionType, unsigned long param3,
                        unsigned long param4);
    void fillTribeText(int index);
    char* tribeName(int index);
};

extern RGE_Base_Game* rge_base_game;
extern TPanelSystem panel_system;

#endif
