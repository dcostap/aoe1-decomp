#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseTrigger {
public:
    char typeValue;

protected:
    char *convertToNameType(unsigned char value) const;

public:
    char *nameType() const;
};
#endif

char *AIPlayPhaseTrigger::nameType() const {
    return this->convertToNameType(this->typeValue);
}
