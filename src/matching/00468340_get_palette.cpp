#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x208];
    int field_20C;
    int get_palette();
};
#endif

int TEasy_Panel::get_palette() { return this->field_20C; }
