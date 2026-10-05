#ifndef AOE1_AI_PLAY_PHASE_COMMAND_H
#define AOE1_AI_PLAY_PHASE_COMMAND_H

class AIPlayPhaseCommand {
  public:
    enum {
        InvalidCommand = 0,
        MoveCommand = 1,
        AttackCommand = 2,
        AttackSavedTargetCommand = 3,
        RetreatCommand = 4,
        HealCommand = 5,
        ResetHitPointsCommand = 6,
        ResetAliveCountCommand = 7,
        WaitCommand = 8
    };

  protected:
    unsigned char groupValue; // +0x00
    unsigned char typeValue;  // +0x01
    int value1Value;          // +0x04
    int value2Value;          // +0x08
    int value3Value;          // +0x0C

  public:
    AIPlayPhaseCommand();
    AIPlayPhaseCommand(unsigned char g, unsigned char t, int v1, int v2, int v3);
    AIPlayPhaseCommand(unsigned char g, char* t, int v1, int v2, int v3);

    unsigned char group() const {
        return this->groupValue;
    }
    void setGroup(unsigned char value) {
        this->groupValue = value;
    }
    unsigned char type() const {
        return this->typeValue;
    }
    void setType(unsigned char value) {
        this->typeValue = value;
    }
    void setType(char* value) {
        this->typeValue = this->convertToIntType(value);
    }
    int value1() const {
        return this->value1Value;
    }
    void setValue1(int value) {
        this->value1Value = value;
    }
    int value2() const {
        return this->value2Value;
    }
    void setValue2(int value) {
        this->value2Value = value;
    }
    int value3() const {
        return this->value3Value;
    }
    void setValue3(int value) {
        this->value3Value = value;
    }
    char* nameType() const;

  protected:
    unsigned char convertToIntType(char* t) const;
    char* convertToNameType(unsigned char t) const;
};

typedef char ai_play_phase_command_size_check[(sizeof(AIPlayPhaseCommand) == 0x10) ? 1 : -1];

#endif
