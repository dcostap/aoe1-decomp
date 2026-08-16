class AIPlayPhaseCommand {
public:
    char gap_0[1];
    unsigned char typeValue;
    char *convertToNameType(unsigned char value) const;
    char *nameType() const;
};

char *AIPlayPhaseCommand::nameType() const {
    return this->convertToNameType(this->typeValue);
}
