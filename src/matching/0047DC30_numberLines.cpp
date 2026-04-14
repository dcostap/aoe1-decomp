class TTextPanel {
public:
    virtual ~TTextPanel();
    char gap_0[0xF4];
    short field_F8;
    int numberLines();
};

int TTextPanel::numberLines() { return this->field_F8; }
