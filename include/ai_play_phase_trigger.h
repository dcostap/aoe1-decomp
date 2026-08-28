#ifndef AOE1_AI_PLAY_PHASE_TRIGGER_H
#define AOE1_AI_PLAY_PHASE_TRIGGER_H

class AIPlayPhaseTrigger {
protected:
    unsigned char typeValue;  // +0x00
    int value1Value;          // +0x04
    int value2Value;          // +0x08
    unsigned char phaseValue; // +0x0C
    unsigned char nextPhaseValue; // +0x0D
    int randomnessValue;      // +0x10

public:
    AIPlayPhaseTrigger();
    AIPlayPhaseTrigger(unsigned char type, int value1, int value2,
                       unsigned char phase, unsigned char nextPhase,
                       int randomness);
    AIPlayPhaseTrigger(char* type, int value1, int value2,
                       unsigned char phase, unsigned char nextPhase,
                       int randomness);

    unsigned char type() const { return this->typeValue; }
    void setType(unsigned char value) { this->typeValue = value; }
    void setType(char* value) { this->typeValue = this->convertToIntType(value); }
    int value1() const { return this->value1Value; }
    void setValue1(int value) { this->value1Value = value; }
    int value2() const { return this->value2Value; }
    void setValue2(int value) { this->value2Value = value; }
    unsigned char phase() const { return this->phaseValue; }
    void setPhase(unsigned char value) { this->phaseValue = value; }
    unsigned char nextPhase() const { return this->nextPhaseValue; }
    void setNextPhase(unsigned char value) { this->nextPhaseValue = value; }
    int randomness() const { return this->randomnessValue; }
    void setRandomness(int value) { this->randomnessValue = value; }
    char* nameType() const;

protected:
    unsigned char convertToIntType(char* name) const;
    char* convertToNameType(unsigned char type) const;
};

typedef char ai_play_phase_trigger_size_check[
    (sizeof(AIPlayPhaseTrigger) == 0x14) ? 1 : -1];

#endif
