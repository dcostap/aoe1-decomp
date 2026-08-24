#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x204];
    int field_208;
    int get_background2();
};
#endif

int TEasy_Panel::get_background2() { return this->field_208; }
