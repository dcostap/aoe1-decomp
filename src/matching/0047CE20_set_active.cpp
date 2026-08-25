// tried the naive local layout first; mismatch was the member offsets for auto_scbar/scbar_panel/scbar_active
// second pass will force the TPanel base to 0xF4 bytes so the derived offsets land on 0x130/0x134/0x16C
#ifndef PNL_TXT_TU_CONTEXT
class TPanel {
public:
    char gap_00[0x6C];
    int field_6C;
    char gap_70[0x84];

    void set_active(int active);
};
#endif

#ifndef PNL_TXT_TU_CONTEXT
class TScrollBarPanel {
public:
    virtual ~TScrollBarPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(struct tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int active);
};

class TTextPanel : public TPanel {
public:
    char gap_00[0x3C];
    TScrollBarPanel* scbar_panel;
    int auto_scbar;
    char gap_138[0x34];
    int scbar_active;

    void set_active(int active);
};
#endif

void TTextPanel::set_active(int active) {
    TPanel::set_active(active);
    if (this->auto_scbar != 0 && this->scbar_panel != 0) {
        if (this->field_6C != 0) {
            this->scbar_panel->set_active(this->scbar_active);
        }
        else {
            this->scbar_panel->set_active(0);
        }
    }
}
