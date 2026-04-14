class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x138];
    int field_13C;
    void setButtonType(int v);
};

void TButtonPanel::setButtonType(int v) { this->field_13C = v; }
