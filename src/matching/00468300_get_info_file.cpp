#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0xF8];
    char field_FC[1];
    char* get_info_file();
};
#endif

char* TEasy_Panel::get_info_file() { return this->field_FC; }
