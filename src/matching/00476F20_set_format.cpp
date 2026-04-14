class TInputPanel {
public:
    virtual ~TInputPanel();
    char gap_0[0x198];
    int field_19C;
    void set_format(int v);
};

void TInputPanel::set_format(int v) { this->field_19C = v; }
