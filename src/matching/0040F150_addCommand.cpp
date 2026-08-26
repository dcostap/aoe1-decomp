#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseCommand {
public:
    unsigned char groupValue;
    unsigned char typeValue;
    unsigned char _pad_0[2];
    int value1Value;
    int value2Value;
    int value3Value;
};

class AIPlayPhase {
public:
    AIPlayPhaseCommand commands[5];
    int addCommand(AIPlayPhaseCommand& command);
};
#endif

int AIPlayPhase::addCommand(AIPlayPhaseCommand& command) {
    int i = 0;
    unsigned char* p = &this->commands[0].typeValue;
    while (i < 5) {
        if (*p == 0) {
            AIPlayPhaseCommand* dest = &this->commands[i];
            dest->groupValue = command.groupValue;
            dest->typeValue = command.typeValue;
            dest->value1Value = command.value1Value;
            dest->value2Value = command.value2Value;
            dest->value3Value = command.value3Value;
            return 1;
        }
        i++;
        p += 0x10;
    }
    return 0;
}
