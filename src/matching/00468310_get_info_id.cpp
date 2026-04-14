class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x1FC];
    int field_200;
    int get_info_id();
};

int TEasy_Panel::get_info_id() { return this->field_200; }
