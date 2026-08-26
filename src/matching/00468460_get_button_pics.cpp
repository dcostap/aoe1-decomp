#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x444];
    int field_448;
    TShape* get_button_pics();
};
#endif

TShape* TEasy_Panel::get_button_pics() { return (TShape*)this->field_448; }
