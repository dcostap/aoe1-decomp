// 0040F3D0 AIPlay::isTargetType
// BINARY NOTE: targetTypeValue begins at AIPlay offset +0x44.

#ifndef AIPBOOK_CANONICAL_TU
class AIPlay {
public:
    unsigned char _pad[0x44];
    unsigned char targetTypeValue[5];
    int isTargetType(unsigned char type) const;
};
#endif

int AIPlay::isTargetType(unsigned char type) const {
    for (int i = 0; i < 5; i++) {
        if (this->targetTypeValue[i] == type)
            return 1;
    }
    return 0;
}
