#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x444];
    int field_448;
    int get_button_pics();
};
#endif

int TEasy_Panel::get_button_pics() { return this->field_448; }
