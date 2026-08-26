#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_02[2];
    int value1Value;
    int value2Value;
    int value3Value;

protected:
    unsigned char convertToIntType(char* text) const;

public:
    AIPlayPhaseCommand(unsigned char group, char* text, int value1, int value2, int value3);
};
#endif

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char group, char* text, int value1, int value2, int value3) {
    this->groupValue = group;
    this->typeValue = this->convertToIntType(text);
    this->value1Value = value1;
    this->value2Value = value2;
    this->value3Value = value3;
}
