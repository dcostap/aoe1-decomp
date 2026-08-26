#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char gap_0[0x328];
    int field_328;
    int field_32C;

    void get_text_colors(unsigned long& out1, unsigned long& out2);
};
#endif

void TEasy_Panel::get_text_colors(unsigned long& out1, unsigned long& out2) {
    out1 = this->field_328;
    out2 = this->field_32C;
}
