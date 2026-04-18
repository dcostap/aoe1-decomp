class PaddingActionStateHost {
public:
    void set_state(unsigned char v);
    char gap_00[0x0C];
    unsigned char field_0C;
    char gap_0D[0x1F];
    float field_2C;
};

void PaddingActionStateHost::set_state(unsigned char v) {
    this->field_0C = v;
    if (v == 10) {
        this->field_2C = 3.0f;
    }
}
