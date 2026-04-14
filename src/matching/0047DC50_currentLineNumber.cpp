class TTextPanel {
public:
    virtual ~TTextPanel();
    char gap_0[0xFC];
    short field_100;
    int currentLineNumber();
};

int TTextPanel::currentLineNumber() { return this->field_100; }
