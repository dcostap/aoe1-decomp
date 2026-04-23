class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    char gap_02[2];
    int value1Value;
    int value2Value;
    int value3Value;

    unsigned char convertToIntType(char* text);
    AIPlayPhaseCommand(unsigned char group, char* text, int value1, int value2, int value3);
};

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char group, char* text, int value1, int value2, int value3) {
    this->groupValue = group;
    this->typeValue = this->convertToIntType(text);
    this->value1Value = value1;
    this->value2Value = value2;
    this->value3Value = value3;
}
