// VA: 00471EC0 TButtonPanel constructor
// PDB source: Pnl_btn.cpp
// The wrapper supplies the reviewed class layout and normal C++ construction.

#include <string.h>

#ifndef PNL_BTN_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};
#endif /* PNL_BTN_SHARED_CONTEXT */

class TDrawArea;
class PanelNode;
class TDigital;
class TShape;

// Minimal TPanel layout (0xF4 bytes)
#ifndef PNL_BTN_SHARED_CONTEXT
class TPanel {
public:
    void* vtable;                       // +0x00
    TPanel* previousPanelValue;         // +0x04
    TPanel* previousModalPanelValue;    // +0x08
    long pnl_x;                         // +0x0C
    long pnl_y;                         // +0x10
    long pnl_wid;                       // +0x14
    long pnl_hgt;                       // +0x18
    char* panelNameValue;               // +0x1C
    TDrawArea* render_area;             // +0x20
    tagRECT clip_rect;                  // +0x24 (16 bytes)
    int position_mode;                  // +0x34
    int need_redraw;                    // +0x38
    TPanel* curr_child;                 // +0x3C
    TPanel* parent_panel;               // +0x40
    TPanel* left_panel;                 // +0x44
    TPanel* top_panel;                  // +0x48
    TPanel* right_panel;                // +0x4C
    TPanel* bottom_panel;               // +0x50
    PanelNode* node;                    // +0x54
    PanelNode* first_child_node;        // +0x58
    PanelNode* last_child_node;         // +0x5C
    TPanel* tab_prev_panel;             // +0x60
    TPanel* tab_next_panel;             // +0x64
    int mouse_captured;                 // +0x68
    int active;                         // +0x6C
    int visible;                        // +0x70
    int tab_stop;                       // +0x74
    int have_focus;                     // +0x78
    int overlapping_children;           // +0x7C
    int handle_mouse_input;             // +0x80
    int just_drawn;                     // +0x84
    void* clip_rgn;                     // +0x88
    tagRECT render_rect;                // +0x8C (16 bytes)
    long left_border;                   // +0x9C
    long top_border;                    // +0xA0
    long right_border;                  // +0xA4
    long bottom_border;                 // +0xA8
    long min_wid;                       // +0xAC
    long max_wid;                       // +0xB0
    long min_hgt;                       // +0xB4
    long max_hgt;                       // +0xB8
    long mouse_hold_interval;           // +0xBC
    long mouse_move_tolerance;          // +0xC0
    long mouse_down_x;                  // +0xC4
    long mouse_down_y;                  // +0xC8
    int mouse_down_ctrl;                // +0xCC
    int mouse_down_shift;               // +0xD0
    unsigned long mouse_down_time;      // +0xD4
    int error_code;                     // +0xD8
    int z_order;                        // +0xDC
    int display_changed_count;          // +0xE0
    long help_string_id;                // +0xE4
    long help_page_id;                  // +0xE8
    unsigned char mouse_action;         // +0xEC
    unsigned char mouse_down_button;    // +0xED
    unsigned char panel_type;           // +0xEE
    unsigned char color;                // +0xEF
    unsigned char fill_in_background;   // +0xF0
    unsigned char clip_to_parent;       // +0xF1
    unsigned char draw_rect2_flag;      // +0xF2
    unsigned char need_restore;         // +0xF3
    TPanel(); // constructor at 004648B0, defined elsewhere
};
#endif /* PNL_BTN_SHARED_CONTEXT */

// TButtonPanel extends TPanel, 0x2B8 bytes total
#ifndef PNL_BTN_SHARED_CONTEXT
class __declspec(novtable) TButtonPanel : public TPanel {
public:
    long id[9];                         // +0xF4 (36 bytes)
    long id2[9];                        // +0x118 (36 bytes)
    int buttonTypeValue;                // +0x13C
    int drawTypeValue;                  // +0x140
    int notifyTypeValue;                // +0x144
    TDigital* sound;                    // +0x148
    TShape* pic[9];                     // +0x14C (36 bytes)
    short pic_index[9];                 // +0x170 (18 bytes)
    unsigned char _pad_0[2];            // +0x182 (gap)
    int auto_pic_pos;                   // +0x184
    long pic_x;                         // +0x188
    long pic_y;                         // +0x18C
    int all_hot;                        // +0x190
    int draw_reverse;                   // +0x194
    char* text1[9];                     // +0x198 (36 bytes)
    char* text2[9];                     // +0x1BC (36 bytes)
    long text_x;                        // +0x1E0
    long text_y;                        // +0x1E4
    void* font;                         // +0x1E8
    long font_wid;                      // +0x1EC
    long font_hgt;                      // +0x1F0
    short num_states;                   // +0x1F4
    short cur_state;                    // +0x1F6
    int is_down;                        // +0x1F8
    TButtonPanel** radio_buttons;       // +0x1FC
    short num_radio_buttons;            // +0x200
    unsigned char _pad_1[2];            // +0x202 (gap)
    unsigned long button_down_time;     // +0x204
    unsigned long text_color1[9];       // +0x208 (36 bytes)
    unsigned long text_color2[9];       // +0x22C (36 bytes)
    unsigned long highlight_text_color1[9]; // +0x250 (36 bytes)
    unsigned long highlight_text_color2[9]; // +0x274 (36 bytes)
    long hotkey;                        // +0x298
    int hotkey_shift;                   // +0x29C
    int bevel_type;                     // +0x2A0
    unsigned char bevel_color1;         // +0x2A4
    unsigned char bevel_color2;         // +0x2A5
    unsigned char bevel_color3;         // +0x2A6
    unsigned char bevel_color4;         // +0x2A7
    unsigned char bevel_color5;         // +0x2A8
    unsigned char bevel_color6;         // +0x2A9
    unsigned char _pad_2[2];            // +0x2AA (gap)
    long key_down;                      // +0x2AC
    int disabled;                       // +0x2B0
    int sound_number;                   // +0x2B4

    TButtonPanel();
};
#endif /* PNL_BTN_SHARED_CONTEXT */

TButtonPanel::TButtonPanel()
{
    // Scalar field initializations (body, not initializer list)
    // VC5 batches by value: first non-zero, then zeros

    buttonTypeValue = Normal;
    drawTypeValue = DrawClear;
    notifyTypeValue = NotifyAction;

    sound = 0;

    auto_pic_pos = 1;
    pic_x = 0;
    pic_y = 0;
    all_hot = 1;
    draw_reverse = 0;

    text_x = -1;
    text_y = -1;
    font = 0;
    font_wid = 0;
    font_hgt = 0;

    num_states = 1;
    cur_state = 0;
    is_down = 0;
    radio_buttons = 0;
    num_radio_buttons = 0;
    button_down_time = 0;

    hotkey = 0;
    hotkey_shift = 0;
    bevel_type = 1;
    bevel_color1 = 0;
    bevel_color2 = 0;
    bevel_color3 = 0;
    bevel_color4 = 0;
    bevel_color5 = 0;
    bevel_color6 = 0;
    key_down = 0;
    disabled = 0;
    sound_number = -1;

    // The compiler emits the derived vptr as part of normal construction.
    ((TPanel*)this)->panel_type = 3;

    // Array initialization loop (9 iterations)
    for (int i = 0; i < 9; i++) {
        id[i] = 0;
        id2[i] = 0;
        pic[i] = 0;
        pic_index[i] = -1;
        text1[i] = 0;
        text2[i] = 0;
        text_color1[i] = 0xFFFFFF;
        text_color2[i] = 0;
        highlight_text_color1[i] = 0xFFFF;
        highlight_text_color2[i] = 0;
    }
}
