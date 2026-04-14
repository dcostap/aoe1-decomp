class TEditPanel {
public:
    char gap_0[0xFC];
    int field_FC;

    void target_method();
    int currentLine();
};

int TEditPanel::currentLine() {
    this->target_method();
    return this->field_FC;
}
