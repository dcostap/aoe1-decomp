class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x20C];
    char field_210[1];
    char* get_cursor();
};

char* TEasy_Panel::get_cursor() { return this->field_210; }
