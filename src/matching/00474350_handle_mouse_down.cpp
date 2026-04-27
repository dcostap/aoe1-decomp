// Pnl_drop.cpp target: TDropDownPanel::handle_mouse_down
// natural dropdown mouse-down path; child hit-test is virtual slot 0xBC.
// first compile had derived fields/base this adjusted by +4 and wrong derived offset; model TPanel as a virtual class with size 0xF4.

class TPanel {
public:
    virtual void vf00();
    char gap_04[0x3C];
    TPanel* parent_panel;
    char gap_44[0x30];
    int have_focus;
    char gap_78[0x7C];

    void set_curr_child(TPanel* panel);
    long handle_mouse_down(unsigned char buttons, long x, long y, int param4, int param5);
};

class THitPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8();
    virtual long handle_mouse_down(long x, long y);
};

class TDropDownPanel : public TPanel {
public:
    THitPanel* val_panel;
    THitPanel* btn_panel;
    THitPanel* list_panel;
    THitPanel* scbar_panel;
    int mode;
    short val_num;

    virtual long handle_mouse_down(unsigned char buttons, long x, long y, int param4, int param5);
    void set_mode(int mode);
    void set_line(long line);
};

long TDropDownPanel::handle_mouse_down(unsigned char buttons, long x, long y, int param4, int param5) {
    if (this->have_focus && this->parent_panel) {
        this->parent_panel->set_curr_child(this);
    }

    if (this->mode == 2) {
        long list_hit = this->list_panel->handle_mouse_down(x, y);
        long scbar_hit;
        if (this->scbar_panel) {
            scbar_hit = this->scbar_panel->handle_mouse_down(x, y);
        } else {
            scbar_hit = 0;
        }
        if (!list_hit && !scbar_hit) {
            this->set_mode(1);
            this->set_line(this->val_num);
            return 1;
        }
    }

    return TPanel::handle_mouse_down(buttons, x, y, param4, param5);
}
