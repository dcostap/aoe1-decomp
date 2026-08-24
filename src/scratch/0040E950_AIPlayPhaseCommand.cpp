// 0040E950 AIPlayPhaseCommand(unsigned char, unsigned char, int, int, int)

AIPlayPhaseCommand::AIPlayPhaseCommand(unsigned char group,
                                       unsigned char type,
                                       int value1,
                                       int value2,
                                       int value3) {
    this->groupValue = group;
    this->typeValue = type;
    this->value1Value = value1;
    this->value2Value = value2;
    this->value3Value = value3;
}
