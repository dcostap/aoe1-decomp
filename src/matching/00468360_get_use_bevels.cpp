class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x318];
    int field_31C;
    int get_use_bevels();
};

int TEasy_Panel::get_use_bevels() { return this->field_31C; }
