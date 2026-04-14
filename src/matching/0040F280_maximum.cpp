class AIPlayGroup {
public:
    char gap_0[0x6];
    unsigned char arr_[6];
    unsigned char maximum(int index);
};

unsigned char AIPlayGroup::maximum(int index) {
    if (index < 0 || index >= 6) return (unsigned char)-1;
    return this->arr_[index];
}
