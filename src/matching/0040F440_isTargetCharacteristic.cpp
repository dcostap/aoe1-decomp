// 0040F440 AIPlay::isTargetCharacteristic
// BINARY NOTE: targetCharacteristicValue begins at AIPlay offset +0x49.

#ifndef AIPBOOK_CANONICAL_TU
class AIPlay {
public:
    unsigned char _pad[0x49];
    unsigned char targetCharacteristicValue[5];
    int isTargetCharacteristic(unsigned char characteristic) const;
};
#endif

int AIPlay::isTargetCharacteristic(unsigned char characteristic) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetCharacteristicValue[i] == characteristic)
            return 1;
    }
    return 0;
}
