#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x1FC];
    int field_200;
    int get_info_id();
};
#endif

int TEasy_Panel::get_info_id() { return this->field_200; }
