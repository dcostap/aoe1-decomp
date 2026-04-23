// tried the minimal direct-base-call wrapper and the child_set_focus vcall shape; build still hit the function-size ceiling
// tried shrinking the local class surface down to only the fields used by the asm; same 70-bytes-vs-64-bytes extraction error
// leaving in scratch because the blocker is now the build/extraction ceiling, not a behavior mismatch
class TPanel {
public:
    void set_focus(int focus);
    virtual void child_set_focus(int focus);
    char gap_00[0x38];
    TPanel* curr_child;
    char gap_40[0x38];
    int have_focus;
};

class TTextPanel : public TPanel {
public:
    void* list;
    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;
};

class TListPanel : public TTextPanel {
public:
    int auto_track;
    unsigned long mouse_scroll_last_time;
    unsigned long mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;

    void set_focus(int focus);
};

void TListPanel::set_focus(int focus) {
    TPanel::set_focus(focus);
    if ((this->curr_child != 0) && (this->cur_line > -1) && (this->cur_line < this->num_lines)) {
        this->curr_child->child_set_focus((int)this->cur_line);
    }
}
