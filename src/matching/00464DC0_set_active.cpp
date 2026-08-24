#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
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
        set_redraw(1);
            return;
        }
        release_mouse();
        if (parent_panel != 0) {
            parent_panel->set_redraw(1);
        }
    }
}
