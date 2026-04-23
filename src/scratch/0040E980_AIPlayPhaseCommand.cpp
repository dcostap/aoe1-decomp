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
    unsigned char type;
    int v2 = value2;
    int v3 = value3;

    this->groupValue = group;
    type = this->convertToIntType(text);
    this->typeValue = type;
    this->value2Value = v2;
    this->value1Value = value1;
    this->value3Value = v3;
}
