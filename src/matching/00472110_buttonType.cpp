class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x138];
    int field_13C;
    int buttonType();
};

int TButtonPanel::buttonType() { return this->field_13C; }
