class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x1F2];
    short field_1F6;
    int get_state();
};

int TButtonPanel::get_state() { return this->field_1F6; }
