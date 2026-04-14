class TEditPanel {
public:
    char gap_0[0xFC];
    int field_FC;

    void target_method();
    int get_text();
};

int TEditPanel::get_text() {
    this->target_method();
    return this->field_FC;
}
