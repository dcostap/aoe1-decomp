class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x13C];
    int field_140;
    int drawType();
};

int TButtonPanel::drawType() { return this->field_140; }
