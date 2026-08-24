#ifndef AOE1_TPNL_BTN_CONTEXT_H
#define AOE1_TPNL_BTN_CONTEXT_H

// Authentic source module: C:\\msdev\\work\\age1_x1\\tpnl_btn.cpp.
// The owner wrapper follows PDB source order.  The normal module uses the
// pinned VC5 flags, with /GX required by the constructor owner.

#include <windows.h>

class TDigital;
class TShape;
class TPanel;
class TButtonPanel;
class TRIBE_Panel_Button;
class TRIBE_Panel_Button_Outer;

class TDrawArea {
public:
    char gap_00[0x38];
    HDC DrawDc;

    unsigned char* Lock(const char*, int);
    void Unlock(const char*);
    void* GetDc(const char*);
    void ReleaseDc(const char*);
    void SetClipRect(long, long, long, long);
};

typedef char tpnl_btn_tdrawarea_size_check[
    (sizeof(TDrawArea) == 0x3C) ? 1 : -1];

class TShape {
public:
    char gap_00[4];
    virtual ~TShape();
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char,
                             unsigned char*);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(RECT);
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
    virtual void get_clip_rect(RECT*);
    virtual void set_clip_rect(RECT*);
    virtual int is_inside(long, long);

    TPanel* previous_panel;          // +0x04
    TPanel* previous_modal_panel;    // +0x08
    long pnl_x;                      // +0x0C
    long pnl_y;                      // +0x10
    union {
        long pnl_wid;                // +0x14
        long pnl_cx;
    };
    union {
        long pnl_hgt;                // +0x18
        long pnl_cy;
    };
    char* panel_name;                // +0x1C
    TDrawArea* render_area;          // +0x20
    RECT clip_rect;                  // +0x24
    int position_mode;               // +0x34
    int need_redraw;                 // +0x38
    TPanel* curr_child;              // +0x3C
    union {
        TPanel* parent_panel;         // +0x40
        TRIBE_Panel_Button_Outer* panel_40;
    };
    TPanel* left_panel;              // +0x44
    TPanel* top_panel;               // +0x48
    TPanel* right_panel;             // +0x4C
    TPanel* bottom_panel;            // +0x50
    void* node;                      // +0x54
    void* first_child_node;          // +0x58
    void* last_child_node;           // +0x5C
    TPanel* tab_prev_panel;          // +0x60
    TPanel* tab_next_panel;           // +0x64
    int mouse_captured;              // +0x68
    union {
        int active;                  // +0x6C
        int field_6C;
    };
    union {
        int visible;                 // +0x70
        int field_70;
    };
    int tab_stop;                    // +0x74
    int have_focus;                 // +0x78
    int overlapping_children;        // +0x7C
    int handle_mouse_input;          // +0x80
    int just_drawn;                  // +0x84
    void* clip_rgn;                  // +0x88
    RECT render_rect;                // +0x8C
    long left_border;                // +0x9C
    long top_border;                 // +0xA0
    long right_border;               // +0xA4
    long bottom_border;              // +0xA8
    long min_wid;                    // +0xAC
    long max_wid;                    // +0xB0
    long min_hgt;                    // +0xB4
    long max_hgt;                    // +0xB8
    long mouse_hold_interval;        // +0xBC
    long mouse_move_tolerance;       // +0xC0
    long mouse_down_x;               // +0xC4
    long mouse_down_y;               // +0xC8
    int mouse_down_ctrl;             // +0xCC
    int mouse_down_shift;            // +0xD0
    unsigned long mouse_down_time;   // +0xD4
    int error_code;                  // +0xD8
    int z_order;                     // +0xDC
    int display_changed_count;       // +0xE0
    long help_string_id;             // +0xE4
    long help_page_id;               // +0xE8
    unsigned char mouse_action;      // +0xEC
    unsigned char mouse_down_button; // +0xED
    unsigned char panel_type;        // +0xEE
    unsigned char color;             // +0xEF
    unsigned char fill_in_background;// +0xF0
    unsigned char clip_to_parent;    // +0xF1
    unsigned char draw_rect2_flag;   // +0xF2
    unsigned char need_restore;      // +0xF3
};

typedef char tpnl_btn_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TButtonPanel : public TPanel {
public:
    long id[9];                      // +0xF4
    long id2[9];                     // +0x118
    int buttonTypeValue;             // +0x13C
    int drawTypeValue;               // +0x140
    int notifyTypeValue;             // +0x144
    TDigital* sound;                  // +0x148
    TShape* pic[9];                  // +0x14C
    short pic_index[9];              // +0x170
    unsigned char gap_182[2];        // +0x182
    int auto_pic_pos;                // +0x184
    long pic_x;                      // +0x188
    long pic_y;                      // +0x18C
    int all_hot;                     // +0x190
    int draw_reverse;                // +0x194
    char* text1[9];                  // +0x198
    char* text2[9];                  // +0x1BC
    long text_x;                     // +0x1E0
    long text_y;                     // +0x1E4
    void* font;                      // +0x1E8
    long font_wid;                   // +0x1EC
    long font_hgt;                   // +0x1F0
    short num_states;                // +0x1F4
    short cur_state;                 // +0x1F6
    int is_down;                     // +0x1F8
    TButtonPanel** radio_buttons;    // +0x1FC
    short num_radio_buttons;         // +0x200
    unsigned char gap_202[2];        // +0x202
    unsigned long button_down_time; // +0x204
    unsigned long text_color1[9];    // +0x208
    unsigned long text_color2[9];    // +0x22C
    unsigned long highlight_text_color1[9]; // +0x250
    unsigned long highlight_text_color2[9]; // +0x274
    long hotkey;                     // +0x298
    int hotkey_shift;                // +0x29C
    int bevel_type;                  // +0x2A0
    unsigned char bevel_color1;      // +0x2A4
    unsigned char bevel_color2;      // +0x2A5
    unsigned char bevel_color3;      // +0x2A6
    unsigned char bevel_color4;      // +0x2A7
    unsigned char bevel_color5;      // +0x2A8
    unsigned char bevel_color6;      // +0x2A9
    unsigned char gap_2AA[2];        // +0x2AA
    long key_down;                   // +0x2AC
    int disabled;                    // +0x2B0
    int sound_number;                // +0x2B4

    virtual ~TButtonPanel();
    TButtonPanel();
    virtual void vf28(int);
    virtual void vf2c();
    virtual void vf30();
    virtual void get_clip_rect(RECT*);
    virtual void set_clip_rect(RECT*);
    virtual void draw();

    long setup(TDrawArea*, TPanel*, long, long, long, long, int, TDigital*,
               int, long);
    void set_font(void*, long, long);
};

typedef char tpnl_btn_tbutton_size_check[
    (sizeof(TButtonPanel) == 0x2B8) ? 1 : -1];

class TRIBE_Panel_Button : public TButtonPanel {
public:
    int display_garrison;            // +0x2B8
    union {
        int garrsion_number;         // +0x2BC
        int field_2BC;
    };
    union {
        unsigned char tribe_button_type; // +0x2C0
        unsigned char state_2c0;
    };
    unsigned char gap_2C1[3];        // +0x2C1
    TShape* border_pic;              // +0x2C4
    unsigned char* color_table;      // +0x2C8
    int border_frame;                // +0x2CC
    char text_msg[0x100];            // +0x2D0
    int in_use;                      // +0x3D0

    TRIBE_Panel_Button(TDrawArea*, TPanel*, TDigital*, void*, long, long,
                       TShape*);
    virtual ~TRIBE_Panel_Button();
    virtual void draw();
    void set_text_msg(char*);
    virtual int is_inside(long, long);
    void set_display_garrison(int);
    void set_garrison_number(int);
    int get_garrison_number();
};

typedef char tpnl_btn_button_size_check[
    (sizeof(TRIBE_Panel_Button) == 0x3D4) ? 1 : -1];

class TRIBE_Panel_Button_Nested {
public:
    virtual int vf00(); virtual int vf01(); virtual int vf02();
    virtual int vf03(); virtual int vf04(); virtual int vf05();
    virtual int vf06(); virtual int vf07(); virtual int vf08();
    virtual int vf09(); virtual int vf0A(); virtual int vf0B();
    virtual int vf0C(); virtual int vf0D(); virtual int vf0E();
    virtual int vf0F(); virtual int vf10(); virtual int vf11();
    virtual int vf12(); virtual int vf13(); virtual int vf14();
    virtual int vf15(); virtual int vf16(); virtual int vf17();
    virtual int vf18(); virtual int vf19(); virtual int vf1A();
    virtual int vf1B(); virtual int vf1C(); virtual int vf1D();
    virtual int vf1E(); virtual int vf1F(); virtual int vf20();
    virtual int vf21(); virtual int vf22(); virtual int vf23();
    virtual int vf24(); virtual int vf25(); virtual int vf26();
    virtual int vf27(); virtual int vf28(); virtual int vf29();
    virtual int vf2A(); virtual int vf2B(); virtual int vf2C();
    virtual int vf2D(); virtual int vf2E();
    virtual int hit_test(long, long);
};

class TRIBE_Panel_Button_Outer {
public:
    char gap_00[0x4BC];
    TRIBE_Panel_Button_Nested* nested_4bc;
};

class RGE_Color_Table {
public:
    char gap_00[0x26];
    short id;
};

class RGE_Player {
public:
    char gap_00[0x108];
    RGE_Color_Table* color_table;
};

class RGE_Base_Game {
public:
    RGE_Player* get_player();
};

#include "rge_base_game_global.h"

extern int fog_next_shape;
extern "C" void __cdecl _ASMSet_Shadowing(int, int, int, int);
extern "C" void __cdecl _ASMSet_Color_Xform(int);

#endif
