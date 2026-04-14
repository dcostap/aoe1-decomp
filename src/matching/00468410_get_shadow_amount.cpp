class TEasy_Panel {
public:
    virtual ~TEasy_Panel();
    char gap_0[0x44C];
    int field_450;
    int get_shadow_amount();
};

int TEasy_Panel::get_shadow_amount() { return this->field_450; }
