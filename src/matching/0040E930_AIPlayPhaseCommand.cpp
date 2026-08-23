#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseCommand {
public:
    unsigned char field_0;
    unsigned char field_1;
    int field_4;
    int field_8;
    int field_C;
    AIPlayPhaseCommand();
};
#endif

AIPlayPhaseCommand::AIPlayPhaseCommand() {
    this->field_0 = 0;
    this->field_1 = 0;
    this->field_4 = 0;
    this->field_8 = 0;
    this->field_C = 0;
}
