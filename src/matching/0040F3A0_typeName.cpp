#ifndef AIPBOOK_CANONICAL_TU
class AIPlay {
public:
    char gap_0[0x43];
    unsigned char typeValue;
    char *convertToNameType(unsigned char value) const;
    char *typeName() const;
};
#endif

char *AIPlay::typeName() const {
    return this->convertToNameType(this->typeValue);
}
