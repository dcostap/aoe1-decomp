#ifndef PNL_DROP_CONTEXT
class TTextPanel {
public:
    void set_text_color(unsigned long fg, unsigned long bg);
};

class TDropDownPanel {
public:
    char gap_00[0xF4];
    TTextPanel* val_panel;

    void set_val_text_color(unsigned long fg, unsigned long bg);
};
#endif

void TDropDownPanel::set_val_text_color(unsigned long fg, unsigned long bg) {
    if (this->val_panel != 0) {
        this->val_panel->set_text_color(fg, bg);
    }
}
