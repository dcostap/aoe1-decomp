#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void redraw(int mode);
    virtual void child_set_focus(int focus);

    char gap_04[0x38];
    TPanel* curr_child;
    char gap_40[0x38];
    int have_focus;

    virtual void set_focus(int focus);
};

#endif
void TPanel::set_focus(int focus) {
    if (focus != have_focus) {
        have_focus = focus;
        set_redraw(TPanel::RedrawNormal);
        if (curr_child != 0) {
            curr_child->set_focus(have_focus);
        }
    }
}
