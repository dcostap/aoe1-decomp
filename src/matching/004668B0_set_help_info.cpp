#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:
    char gap_0[0xE4];
    int field_E4;
    int field_E8;
    void set_help_info(int a, int b);
};

#endif
void TPanel::set_help_info(long a, long b) {
    this->field_E4 = a;
    this->field_E8 = b;
}
