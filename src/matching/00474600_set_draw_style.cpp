#ifndef PNL_DROP_CONTEXT
class TTextPanel;

class TDropDownPanel {
public:
    virtual void dummy_vf();
    char gap_04[0xF0];
    TTextPanel* val_panel;  // 0xF4
    char gap_F8[0x0C];
    int mode;               // 0x104
    char gap_108[0x34];
    int draw_style;         // 0x13C

    void set_draw_style(int param_1);
    void set_mode(int mode);
};
#endif

void TDropDownPanel::set_draw_style(int param_1) {
    this->draw_style = param_1;
    if (this->val_panel) {
        int old_mode = this->mode;
        this->mode = 0;
        this->set_mode(old_mode);
    }
}
