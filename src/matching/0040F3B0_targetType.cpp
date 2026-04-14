class AIPlay {
public:
    char gap_0[0x44];
    unsigned char arr_[5];
    unsigned char targetType(int index);
};

unsigned char AIPlay::targetType(int index) {
    if (index < 0 || index >= 5) return 0;
    return this->arr_[index];
}
