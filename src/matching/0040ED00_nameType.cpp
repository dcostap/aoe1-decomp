class AIPlayPhaseTrigger {
public:
    char typeValue;
    char *convertToNameType(unsigned char value) const;
    char *nameType() const;
};

char *AIPlayPhaseTrigger::nameType() const {
    return this->convertToNameType(this->typeValue);
}
