#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x318];
    int field_31C;
    void set_use_bevels(int v);
};
#endif

void TEasy_Panel::set_use_bevels(int v) { this->field_31C = v; }
