#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x200];
    int field_204;
    TShape* get_background();
};
#endif

TShape* TEasy_Panel::get_background() { return (TShape*)this->field_204; }
