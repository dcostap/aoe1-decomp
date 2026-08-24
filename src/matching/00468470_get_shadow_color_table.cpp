#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x448];
    int field_44C;
    int get_shadow_color_table();
};
#endif

int TEasy_Panel::get_shadow_color_table() { return this->field_44C; }
