class AIPlay {
public:
    char gap_0[0x49];
    unsigned char arr_[5];
    unsigned char targetCharacteristic(int index);
};

unsigned char AIPlay::targetCharacteristic(int index) {
    if (index < 0 || index >= 5) return 0;
    return this->arr_[index];
}
