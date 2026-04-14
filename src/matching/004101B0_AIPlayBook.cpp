class AIPlayBook {
public:
    int vfptr;
    int field_4;
    char gap_8[0x44];
    int field_4C;
    AIPlayBook();
};

AIPlayBook::AIPlayBook() {
    this->field_4 = 0;
    this->field_4C = 0;
    this->vfptr = 0x56E970;
}
