#ifndef AOE1_AI_PLAY_PHASE_COMMAND_H
#define AOE1_AI_PLAY_PHASE_COMMAND_H

class AIPlayPhaseCommand {
protected:
    unsigned char groupValue;  // +0x00
    unsigned char typeValue;   // +0x01
    int value1Value;           // +0x04
    int value2Value;           // +0x08
    int value3Value;           // +0x0C

public:
    AIPlayPhaseCommand();
    AIPlayPhaseCommand(unsigned char group, unsigned char type, int value1,
                       int value2, int value3);
    AIPlayPhaseCommand(unsigned char group, char* type, int value1,
                       int value2, int value3);

    unsigned char group() const { return this->groupValue; }
    void setGroup(unsigned char value) { this->groupValue = value; }
    unsigned char type() const { return this->typeValue; }
    void setType(unsigned char value) { this->typeValue = value; }
    void setType(char* value) { this->typeValue = this->convertToIntType(value); }
    int value1() const { return this->value1Value; }
    void setValue1(int value) { this->value1Value = value; }
    int value2() const { return this->value2Value; }
    void setValue2(int value) { this->value2Value = value; }
    int value3() const { return this->value3Value; }
    void setValue3(int value) { this->value3Value = value; }
    char* nameType() const;

protected:
    unsigned char convertToIntType(char* name) const;
    char* convertToNameType(unsigned char type) const;
};

typedef char ai_play_phase_command_size_check[
    (sizeof(AIPlayPhaseCommand) == 0x10) ? 1 : -1];

#endif
