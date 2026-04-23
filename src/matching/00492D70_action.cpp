class TDrawArea;
class TShape;
class PanelNode;
class RGE_Color_Table;
class TPanel;
class TScrollTextPanel;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual void vf00(void);

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
    unsigned char _pad_0[0x2];
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
    unsigned char _pad_1[0x2];
    int enable_ime;
    unsigned char help_mode;
    unsigned char _pad_2[0x3];
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    virtual ~TEasy_Panel();
    virtual long setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, unsigned char param_7);
    virtual long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

class TScreenPanel : public TEasy_Panel {
};

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    TScrollTextPanel* text_panel;
    int text_set;
    int picture_set;
    unsigned long last_picture_time;
    unsigned long last_pause_time;
    int mode;
    char color_table[0x400];
    char color[4];
    void* back_pics[7];
    int first_draw;
    int text_done;

    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

long TRIBE_Credits_Screen::action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4) {
    long lVar1;

    if (((param_1 != (TPanel*)0x0) && ((TScrollTextPanel*)param_1 == this->text_panel)) && (param_2 == 1)) {
        this->text_done = 1;
        return 1;
    }
    lVar1 = this->TEasy_Panel::action(param_1, param_2, param_3, param_4);
    return lVar1;
}
