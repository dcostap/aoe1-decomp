#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x208];
    int field_20C;
    void* get_palette();
};
#endif

void* TEasy_Panel::get_palette() { return (void*)this->field_20C; }
