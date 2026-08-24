#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x314];
    int field_318;
    int get_background_pos();
};
#endif

int TEasy_Panel::get_background_pos() { return this->field_318; }
