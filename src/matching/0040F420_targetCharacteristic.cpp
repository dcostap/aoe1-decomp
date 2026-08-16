// targetCharacteristic (0040F420, 25 bytes, aipbook.cpp)
// bounds-check array access, return 0 if out of range
class AIPlay {
public:
    unsigned char _pad[0x49];
    unsigned char targetCharacteristicValue[5]; // +0x49
    unsigned char targetCharacteristic(int index) const;
};

unsigned char AIPlay::targetCharacteristic(int index) const {
    if (index >= 0 && index < 5)
        return targetCharacteristicValue[index];
    return 0;
}
