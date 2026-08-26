#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x44C];
    int field_450;
    long get_shadow_amount();
};
#endif

long TEasy_Panel::get_shadow_amount() { return this->field_450; }
