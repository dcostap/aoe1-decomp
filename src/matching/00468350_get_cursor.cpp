#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x20C];
    char field_210[1];
    char* get_cursor();
};
#endif

char* TEasy_Panel::get_cursor() { return this->field_210; }
