class AIPlayGroup {
public:
    unsigned char arr_[6];
    void setMinimum(int index, unsigned char val);
};

void AIPlayGroup::setMinimum(int index, unsigned char val) {
    if (index < 0 || index >= 6) return;
    this->arr_[index] = val;
}
