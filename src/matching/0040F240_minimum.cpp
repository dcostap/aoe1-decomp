#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    unsigned char arr_[6];
    unsigned char minimum(int index);
};
#endif

unsigned char AIPlayGroup::minimum(int index) {
    if (index < 0 || index >= 6) return 0;
    return this->arr_[index];
}
