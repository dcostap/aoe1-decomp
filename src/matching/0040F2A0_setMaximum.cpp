class AIPlayGroup {
public:
    char gap_0[0x6];
    unsigned char arr_[6];
    void setMaximum(int index, unsigned char val);
};

void AIPlayGroup::setMaximum(int index, unsigned char val) {
    if (index < 0 || index >= 6) return;
    this->arr_[index] = val;
}
