class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x204];
    int field_208;
    int get_background2();
};

int TEasy_Panel::get_background2() { return this->field_208; }
