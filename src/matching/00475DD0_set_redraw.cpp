// 00475DD0 TEditPanel::set_redraw
// MATCH: 0.0000% diff, 2 relocations masked
// Fixed: removed explicit void* vtable_ptr from TPanel.
// Having both explicit vtable_ptr AND virtual functions creates
// a double-vtable shift (+4 on all derived field offsets).

#ifndef PNL_EDIT_TU_CONTEXT
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void* hwnd, const void* rect, int erase);
#else
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(HWND hwnd, const tagRECT* rect, int erase);
#endif

#ifndef PNL_EDIT_TU_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    void* render_area;
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

    virtual void set_redraw(int mode);
};

class TEditPanel : public TPanel {
public:
    void* edit_wnd;
    short fixed_len;
    char gap_00[0x2];
    char* text;
    int text_len;
    int hidden;

    virtual void set_redraw(int mode);
};
#endif

void TEditPanel::set_redraw(TPanel::RedrawMode mode) {
    TPanel::set_redraw(TPanel::RedrawNormal);
    if (this->active != 0) {
        if (mode != 0) {
            if (this->edit_wnd != 0) {
                if (this->hidden == 0) {
                    InvalidateRect(this->edit_wnd, 0, 1);
                }
            }
        }
    }
}
