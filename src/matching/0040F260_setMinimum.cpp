#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    unsigned char arr_[6];
    void setMinimum(int index, unsigned char val);
};
#endif

void AIPlayGroup::setMinimum(int index, unsigned char val) {
    if (index < 0 || index >= 6) return;
    this->arr_[index] = val;
}
