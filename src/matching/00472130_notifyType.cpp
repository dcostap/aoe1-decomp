class TButtonPanel {
public:
    virtual ~TButtonPanel();
    char gap_0[0x140];
    int field_144;
    int notifyType();
};

int TButtonPanel::notifyType() { return this->field_144; }
