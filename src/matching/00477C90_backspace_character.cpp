class TInputPanel {
public:
    virtual ~TInputPanel();
    char gap_04[0x1B0];
    short input_pos;

    int delete_character();
    int backspace_character();
};

int TInputPanel::backspace_character() {
    if (this->input_pos > 0) {
        this->input_pos = this->input_pos - 1;
        return delete_character();
    }
    return 0;
}
