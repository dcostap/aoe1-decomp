#pragma once
#include "../types.h"
#include <windows.h>

class TDrawArea;
class TPanel;

enum PositionMode {
    PositionFixed = 0,
    PositionVariable = 1,
    PositionCentered = 2,
    PositionLeft = 3,
    PositionTop = 4,
    PositionRight = 5,
    PositionBottom = 6,
    PositionLeftTop = 7,
    PositionLeftBottom = 8,
    PositionRightTop = 9,
    PositionRightBottom = 10,
};

enum RedrawMode {
    RedrawNone = 0,
    RedrawNormal = 1,
    RedrawFull = 2,
};

struct PanelNode {
    TPanel *panel;
    PanelNode *prev_node;
    PanelNode *next_node;
};

class TPanel {
public:
    /* 0x0000 */ // vftable (implicit)
    /* 0x0004 */ TPanel *previousPanelValue;
    /* 0x0008 */ TPanel *previousModalPanelValue;
    /* 0x000C */ long pnl_x;
    /* 0x0010 */ long pnl_y;
    /* 0x0014 */ long pnl_wid;
    /* 0x0018 */ long pnl_hgt;
    /* 0x001C */ char *panelNameValue;
    /* 0x0020 */ TDrawArea *render_area;
    /* 0x0024 */ RECT clip_rect;
    /* 0x0034 */ PositionMode position_mode;
    /* 0x0038 */ RedrawMode need_redraw;
    /* 0x003C */ TPanel *curr_child;
    /* 0x0040 */ TPanel *parent_panel;
    /* 0x0044 */ TPanel *left_panel;
    /* 0x0048 */ TPanel *top_panel;
    /* 0x004C */ TPanel *right_panel;
    /* 0x0050 */ TPanel *bottom_panel;
    /* 0x0054 */ PanelNode *node;
    /* 0x0058 */ PanelNode *first_child_node;
    /* 0x005C */ PanelNode *last_child_node;
    /* 0x0060 */ TPanel *tab_prev_panel;
    /* 0x0064 */ TPanel *tab_next_panel;
    /* 0x0068 */ int mouse_captured;
    /* 0x006C */ int active;
    /* 0x0070 */ int visible;
    /* 0x0074 */ int tab_stop;
    /* 0x0078 */ int have_focus;
    /* 0x007C */ int overlapping_children;
    /* 0x0080 */ int handle_mouse_input;
    /* 0x0084 */ int just_drawn;
    /* 0x0088 */ void *clip_rgn;
    /* 0x008C */ RECT render_rect;
    /* 0x009C */ long left_border;
    /* 0x00A0 */ long top_border;
    /* 0x00A4 */ long right_border;
    /* 0x00A8 */ long bottom_border;
    /* 0x00AC */ long min_wid;
    /* 0x00B0 */ long max_wid;
    /* 0x00B4 */ long min_hgt;
    /* 0x00B8 */ long max_hgt;
    /* 0x00BC */ long mouse_hold_interval;
    /* 0x00C0 */ long mouse_move_tolerance;
    /* 0x00C4 */ long mouse_down_x;
    /* 0x00C8 */ long mouse_down_y;
    /* 0x00CC */ int mouse_down_ctrl;
    /* 0x00D0 */ int mouse_down_shift;
    /* 0x00D4 */ unsigned long mouse_down_time;
    /* 0x00D8 */ int error_code;
    /* 0x00DC */ int z_order;
    /* 0x00E0 */ int display_changed_count;
    /* 0x00E4 */ long help_string_id;
    /* 0x00E8 */ long help_page_id;
    /* 0x00EC */ unsigned char mouse_action;
    /* 0x00ED */ unsigned char mouse_down_button;
    /* 0x00EE */ unsigned char panel_type;
    /* 0x00EF */ unsigned char color;
    /* 0x00F0 */ unsigned char fill_in_background;
    /* 0x00F1 */ unsigned char clip_to_parent;
    /* 0x00F2 */ unsigned char draw_rect2_flag;
    /* 0x00F3 */ unsigned char need_restore;

    TPanel();
    virtual ~TPanel();

    virtual long setup(TDrawArea *render_area, TPanel *parent, long x, long y, long wid, long hgt, unsigned char color);
    virtual void set_rect(RECT rect);
    virtual void set_rect(long x, long y, long wid, long hgt);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    // ... more virtuals as needed
};

static_assert(sizeof(TPanel) == 244, "TPanel size mismatch");
