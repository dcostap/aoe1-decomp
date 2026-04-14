class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x314];
    int field_318;
    int get_background_pos();
};

int TEasy_Panel::get_background_pos() { return this->field_318; }
