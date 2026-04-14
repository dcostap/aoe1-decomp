class TTextPanel {
public:
    virtual ~TTextPanel();
    char gap_0[0xF6];
    short field_FA;
    int numberDrawLines();
};

int TTextPanel::numberDrawLines() { return this->field_FA; }
