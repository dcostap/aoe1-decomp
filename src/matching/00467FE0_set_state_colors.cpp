#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_0[0x338];
    int field_338;
    int field_33C;
    void set_state_colors(int a, int b);
};
#endif

void TEasy_Panel::set_state_colors(int a, int b) {
    this->field_338 = a;
    this->field_33C = b;
}
