#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseCommand {
public:
    char gap_0[1];
    unsigned char typeValue;

protected:
    char *convertToNameType(unsigned char value) const;

public:
    char *nameType() const;
};
#endif

char *AIPlayPhaseCommand::nameType() const {
    return this->convertToNameType(this->typeValue);
}
