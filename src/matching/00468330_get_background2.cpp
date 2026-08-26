#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x204];
    int field_208;
    TShape* get_background2();
};
#endif

TShape* TEasy_Panel::get_background2() { return (TShape*)this->field_208; }
