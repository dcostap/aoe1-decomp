class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x440];
    int field_444;
    int get_popup_info_id();
};

int TEasy_Panel::get_popup_info_id() { return this->field_444; }
