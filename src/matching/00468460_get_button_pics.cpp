class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x444];
    int field_448;
    int get_button_pics();
};

int TEasy_Panel::get_button_pics() { return this->field_448; }
