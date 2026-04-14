class TText {
public:
    char gap_0[0xC];
    int field_C;
    int field_10;
    void moveToFirstWord();
};

void TText::moveToFirstWord() {
    this->field_C = 0;
    this->field_10 = 0;
}
