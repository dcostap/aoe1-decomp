#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void set_focus_state(int focus);

    char gap_04[0x38];
    TPanel* curr_child;
    char gap_40[0x38];
    int have_focus;

    void set_curr_child(TPanel* child);
};

#endif
void TPanel::set_curr_child(TPanel* child) {
    TPanel* old_child;

    old_child = curr_child;
    if (child != old_child) {
        if (old_child != 0 && have_focus != 0) {
        old_child->set_focus(0);
        }
        curr_child = child;
        if (child != 0 && have_focus != 0) {
        child->set_focus(1);
        }
    }
}
