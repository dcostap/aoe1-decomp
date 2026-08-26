#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_0[0x330];
    int field_330;
    int field_334;

    void get_focus_colors(unsigned long& out1, unsigned long& out2);
};
#endif

void TEasy_Panel::get_focus_colors(unsigned long& out1, unsigned long& out2) {
    out1 = this->field_330;
    out2 = this->field_334;
}
