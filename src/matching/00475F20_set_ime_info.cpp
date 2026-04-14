class TEditPanel {
public:
    char gap_0[0x164];
    int field_164;
    int field_168;
    void set_ime_info(int a, int b);
};

void TEditPanel::set_ime_info(int a, int b) {
    this->field_164 = a;
    this->field_168 = b;
}
