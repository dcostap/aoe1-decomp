#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x200];
    int field_204;
    int get_background();
};
#endif

int TEasy_Panel::get_background() { return this->field_204; }
