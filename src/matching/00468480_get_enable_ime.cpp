#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x454];
    int field_458;
    int get_enable_ime();
};
#endif

int TEasy_Panel::get_enable_ime() { return this->field_458; }
