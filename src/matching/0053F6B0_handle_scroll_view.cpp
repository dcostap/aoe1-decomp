#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class TDrawArea;
class TShape;
class PanelNode;
class RGE_Color_Table;
class TPanel;

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
    TDrawArea* render_area;
    tagRECT clip_rect;
    long position_mode;
    long need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
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

    virtual ~TPanel();
    virtual void setup(void*, TPanel*, long, long, long, long,
                       unsigned char);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*,
                                 TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int param_1);
};

class RGE_View : public TPanel {
public:
    char gap_0xF4[0x26C];

    int handle_scroll_view(long param_1, long param_2);
};

class RGE_Main_View : public RGE_View {
public:
    TPanel* map_view;
    unsigned long last_mouse_scroll_time;
    int mouse_scrolling;
    long mouse_last_x;
    long mouse_last_y;
    unsigned long last_key_scroll_time;
    int key_scrolling;
    void* save_player;

    int handle_scroll_view(long param_1, long param_2);
};
#endif

int RGE_Main_View::handle_scroll_view(long param_1, long param_2) {
    int result = this->RGE_View::handle_scroll_view(param_1, param_2);
    if (result != 0) {
        if (this->map_view != 0) {
            this->map_view->set_redraw(1);
        }
        return 1;
    }
    return 0;
}
