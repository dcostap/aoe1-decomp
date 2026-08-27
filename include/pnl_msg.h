#ifndef AOE1_PNL_MSG_H
#define AOE1_PNL_MSG_H

#include <windows.h>
#include "rge_base_game_global.h"

struct PnlMsgDrawSystem {
    char gap_00[8];
    void* Pal;
};

class TDrawSystem;
class TDrawArea;
class TPanel;
class TShape;
class RGE_Base_Game {
public:
    char gap_00[0x48];
    PnlMsgDrawSystem* draw_system;
};

extern RGE_Base_Game* rge_base_game;

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    void* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    long Width;
    long Height;
    long Pitch;
    long Orien;
    tagRECT ClipRect;
    HDC DrawDc;
    void* DrawSurface;
    char size_tail[0xC0];

    TDrawArea(char*, int);
    ~TDrawArea();
    int Init(void*, long, long, int, int);
    void PtrClear(tagRECT*, int);
    void SetClipRect(tagRECT*);
    void* GetDc(char*);
    void ReleaseDc(char*);
    void SetTrans(int, int);
    void Copy(TDrawArea*, long, long, tagRECT*, int);
};

struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

class TShape {
public:
    char gap_00[0x1C];
    Shape_Info* shape_info;
    unsigned char shape_draw(TDrawArea*, long, long, long,
                             unsigned char, unsigned char*);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual void get_true_render_rect(tagRECT&);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel();

    TPanel* previous_panel;
    TPanel* previous_modal_panel;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panel_name;
    TDrawArea* render_area;
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

typedef char pnl_msg_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TMessagePanel : public TPanel {
public:
    enum MessageType {
        InfoMessage = 0,
        BadMessage = 1,
        DebugMessage = 2,
        ChatMessage = 3,
        ColoredChatMessage = 4,
        RightInfoMessage = 5
    };
    enum JustType {
        TopJust = 0,
        BottomJust = 1,
        LeftJust = 2,
        RightJust = 3,
        CenterJust = 4
    };

    MessageType message_type;
    char text[0x200];
    int showing_message;
    int start_time;
    int show_message_interval;
    void* font;
    long font_wid;
    long font_hgt;
    unsigned char font_color;
    unsigned char back_color;
    unsigned char gap_312[2];
    int index_color;
    unsigned long font_color1;
    unsigned long font_color2;
    JustType horz_just;
    JustType vert_just;
    int word_wrap;
    void* image_clip_region;
    TDrawArea* ImageBuffer;
    tagRECT ImageRect;
    tagRECT UsedImageRect;
    tagRECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    TShape* Icon1;
    TShape* Icon2;
    int IconFrame1;
    int IconFrame2;

    TMessagePanel(void*, long, long);
    virtual ~TMessagePanel();
    virtual void set_rect(long, long, long, long);
    virtual void draw();
    virtual void get_true_render_rect(tagRECT&);
    virtual long handle_idle();
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    void set_justification(JustType, JustType, int);
    void show_message(MessageType, char*, unsigned char, unsigned char,
                      void*, long, long);
    void show_message2(MessageType, char*, unsigned long, unsigned long,
                       void*, long, long, TShape*, int, TShape*, int);
    void remove_message();
protected:
    int render_to_image_buffer();
public:
    virtual void set_font(void*, long, long);
};

typedef char pnl_msg_message_panel_size_check[
    (sizeof(TMessagePanel) == 0x380) ? 1 : -1];

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

#endif
