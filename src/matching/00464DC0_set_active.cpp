#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void redraw(int mode);

    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0x28];
    int active;

    void release_mouse(void);
    virtual void set_active(int active);
};

#endif
void TPanel::set_active(int is_active) {
    if (active != is_active) {
        active = is_active;
        if (is_active != 0) {
        set_redraw(TPanel::RedrawNormal);
            return;
        }
        release_mouse();
        if (parent_panel != 0) {
            parent_panel->set_redraw(TPanel::RedrawNormal);
        }
    }
}
