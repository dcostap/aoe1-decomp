#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_0[0x338];
    int field_338;
    int field_33C;

    void get_state_colors(unsigned long& out1, unsigned long& out2);
};
#endif

void TEasy_Panel::get_state_colors(unsigned long& out1, unsigned long& out2) {
    out1 = this->field_338;
    out2 = this->field_33C;
}
