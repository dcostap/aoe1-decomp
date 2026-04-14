class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x208];
    int field_20C;
    int get_palette();
};

int TEasy_Panel::get_palette() { return this->field_20C; }
