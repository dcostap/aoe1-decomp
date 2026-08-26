#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x448];
    int field_44C;
    RGE_Color_Table* get_shadow_color_table();
};
#endif

RGE_Color_Table* TEasy_Panel::get_shadow_color_table() { return (RGE_Color_Table*)this->field_44C; }
