class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x33C];
    char field_340[1];
    char* get_popup_info_file();
};

char* TEasy_Panel::get_popup_info_file() { return this->field_340; }
