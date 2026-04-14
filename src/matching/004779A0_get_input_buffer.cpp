class TInputPanel {
public:
    virtual ~TInputPanel();
    char gap_0[0x19C];
    int field_1A0;
    int get_input_buffer();
};

int TInputPanel::get_input_buffer() { return this->field_1A0; }
