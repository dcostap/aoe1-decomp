class TEditPanel {
public:
    char gap_0[0xFC];
    int field_FC;

    void target_method();
    int get_input_buffer();
};

int TEditPanel::get_input_buffer() {
    this->target_method();
    return this->field_FC;
}
