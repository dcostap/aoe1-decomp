// Pnl_drop.cpp target: TDropDownPanel::handle_mouse_down
// natural dropdown mouse-down path; child hit-test is virtual slot 0xBC.
// first compile had derived fields/base this adjusted by +4 and wrong derived offset; model TPanel as a virtual class with size 0xF4.

#ifndef PNL_DROP_CONTEXT
class TPanel {
public:
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
#endif

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
