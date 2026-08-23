#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseTrigger {
public:
    char typeValue;
    char *convertToNameType(unsigned char value) const;
    char *nameType() const;
};
#endif

char *AIPlayPhaseTrigger::nameType() const {
    return this->convertToNameType(this->typeValue);
}
