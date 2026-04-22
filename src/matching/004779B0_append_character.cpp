class TInputPanel {
public:
    virtual ~TInputPanel();
    char gap_04[0x1A8];
    short input_len;
    char gap_1AE[0x06];
    short input_pos;

    int insert_character(long value);
    int append_character(long value);
};

int TInputPanel::append_character(long value) {
    this->input_pos = this->input_len;
    return insert_character(value);
}
