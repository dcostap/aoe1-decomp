#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x314];
    int field_318;
    void set_background_pos(int v);
};
#endif

void TEasy_Panel::set_background_pos(int v) { this->field_318 = v; }
