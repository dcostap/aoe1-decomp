#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    unsigned char arr_[6];
    void setMinimum(int index, int val);
};
#endif

void AIPlayGroup::setMinimum(int index, int val) {
    if (index < 0 || index >= 6) return;
    this->arr_[index] = val;
}
