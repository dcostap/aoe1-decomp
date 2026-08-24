#ifndef AOE1_PNL_MSG_CONTEXT_H
#define AOE1_PNL_MSG_CONTEXT_H

// Recovered source context for C:\\msdev\\work\\age1_x1\\Pnl_msg.cpp.
// The owner files include this header before their local fallback declarations.
// The layout uses the executable's TPanel size (0xF4) and message-panel fields.

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
    TDrawSystem* DrawSystem;       // +0x00
    void* Wnd;                     // +0x04
    unsigned char* Bits;           // +0x08
    void* BitmapInfo;              // +0x0C
    void* Bitmap;                  // +0x10
    void* OldBitmap;               // +0x14
    long Width;                    // +0x18
    long Height;                   // +0x1C
    long Pitch;                    // +0x20
    long Orien;                    // +0x24
    tagRECT ClipRect;              // +0x28
    HDC DrawDc;                    // +0x38
    void* DrawSurface;             // +0x3C

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
    // The period panel surface has the RECT overload before the four-long
    // overload. The executable maps set_active to +0x14 and set_redraw to
    // +0x20 in the message-panel callers.
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

    TPanel* previous_panel;          // +0x04
    TPanel* previous_modal_panel;    // +0x08
    long pnl_x;                      // +0x0C
    long pnl_y;                      // +0x10
    long pnl_wid;                    // +0x14
    long pnl_hgt;                    // +0x18
    char* panel_name;                // +0x1C
    TDrawArea* render_area;          // +0x20
    tagRECT clip_rect;               // +0x24
    int position_mode;               // +0x34
    int need_redraw;                 // +0x38
    TPanel* curr_child;              // +0x3C
    TPanel* parent_panel;            // +0x40
    TPanel* left_panel;              // +0x44
    TPanel* top_panel;               // +0x48
    TPanel* right_panel;             // +0x4C
    TPanel* bottom_panel;            // +0x50
    void* node;                      // +0x54
    void* first_child_node;          // +0x58
    void* last_child_node;           // +0x5C
    TPanel* tab_prev_panel;           // +0x60
    TPanel* tab_next_panel;           // +0x64
    int mouse_captured;              // +0x68
    int active;                      // +0x6C
    int visible;                     // +0x70
    int tab_stop;                    // +0x74
    int have_focus;                  // +0x78
    int overlapping_children;         // +0x7C
    int handle_mouse_input;          // +0x80
    int just_drawn;                  // +0x84
    void* clip_rgn;                  // +0x88
    tagRECT render_rect;              // +0x8C
    long left_border;                // +0x9C
    long top_border;                 // +0xA0
    long right_border;                // +0xA4
    long bottom_border;              // +0xA8
    long min_wid;                    // +0xAC
    long max_wid;                    // +0xB0
    long min_hgt;                    // +0xB4
    long max_hgt;                    // +0xB8
    long mouse_hold_interval;         // +0xBC
    long mouse_move_tolerance;        // +0xC0
    long mouse_down_x;                // +0xC4
    long mouse_down_y;                // +0xC8
    int mouse_down_ctrl;              // +0xCC
    int mouse_down_shift;             // +0xD0
    unsigned long mouse_down_time;    // +0xD4
    int error_code;                   // +0xD8
    int z_order;                      // +0xDC
    int display_changed_count;        // +0xE0
    long help_string_id;              // +0xE4
    long help_page_id;                // +0xE8
    unsigned char mouse_action;       // +0xEC
    unsigned char mouse_down_button;  // +0xED
    unsigned char panel_type;         // +0xEE
    unsigned char color;              // +0xEF
    unsigned char fill_in_background; // +0xF0
    unsigned char clip_to_parent;     // +0xF1
    unsigned char draw_rect2_flag;    // +0xF2
    unsigned char need_restore;       // +0xF3

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

    MessageType message_type;        // +0xF4
    char text[0x200];                // +0xF8
    int showing_message;             // +0x2F8
    int start_time;                  // +0x2FC
    int show_message_interval;       // +0x300
    void* font;                      // +0x304
    long font_wid;                   // +0x308
    long font_hgt;                   // +0x30C
    unsigned char font_color;        // +0x310
    unsigned char back_color;        // +0x311
    unsigned char gap_312[2];        // +0x312
    int index_color;                 // +0x314
    unsigned long font_color1;       // +0x318
    unsigned long font_color2;       // +0x31C
    JustType horz_just;              // +0x320
    JustType vert_just;              // +0x324
    int word_wrap;                   // +0x328
    void* image_clip_region;         // +0x32C
    TDrawArea* ImageBuffer;          // +0x330
    tagRECT ImageRect;               // +0x334
    tagRECT UsedImageRect;           // +0x344
    tagRECT UsedScreenRect;          // +0x354
    int LastIBWidth;                 // +0x364
    int LastIBHeight;                // +0x368
    int ImageTextActive;             // +0x36C
    TShape* Icon1;                   // +0x370
    TShape* Icon2;                   // +0x374
    int IconFrame1;                  // +0x378
    int IconFrame2;                  // +0x37C

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
    int render_to_image_buffer();
    void set_font(void*, long, long);
};

typedef char pnl_msg_message_panel_size_check[
    (sizeof(TMessagePanel) == 0x380) ? 1 : -1];

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

#endif
