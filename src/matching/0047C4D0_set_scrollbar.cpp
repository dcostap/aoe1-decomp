#ifndef PNL_TXT_TU_CONTEXT
struct PanelNode;
struct TDrawArea;
struct HRGN__;
typedef HRGN__* HRGN;
struct tagRECT;

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
    char clip_rect[0x10];
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
    HRGN clip_rgn;
    char render_rect[0x10];
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
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long param_1, long param_2, long param_3, long param_4);
    int width();
};

class TScrollBarPanel : public TPanel {
public:
    char _pad_scrollbar[0xD0];
};

class TTextPanel : public TPanel {
public:
    char* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
    void* font;
    long font_wid;
    long font_hgt;
    long vert_align;
    long horz_align;
    int word_wrap;
    long text_style;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long highlightTextColor1;
    unsigned long highlightTextColor2;
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    short fixed_len;
    char _pad0[0x2];
    long text_wid;
    long text_hgt;
    void* back_pic;
    short back_pic_wid;
    short back_pic_hgt;
    int fill_back;
    unsigned char back_color;
    char _pad1[0x3];
    int outline;
    unsigned char outline_color;
    char _pad2[0x3];
    int sorted;
    long second_column_pos;
    long full_width;
    long scbar_width;

    void set_scrollbar(TScrollBarPanel* panel, int auto_scbar_value);
};
#endif

void TTextPanel::set_scrollbar(TScrollBarPanel* panel, int auto_scbar_value) {
    this->scbar_panel = panel;
    this->auto_scbar = auto_scbar_value;
    if (panel != 0) {
        this->scbar_width = panel->width();
        this->set_rect(this->pnl_x, this->pnl_y, this->pnl_wid, this->pnl_hgt);
    }
}
