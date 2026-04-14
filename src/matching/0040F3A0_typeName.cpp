extern const char * __stdcall nameTypeFunc_F3A0(unsigned char typeId);

class AIPlayPhaseCommand {
public:
    char gap_0[0x43];
    unsigned char typeField;
    const char *typeName();
};

const char *AIPlayPhaseCommand::typeName() {
    return nameTypeFunc_F3A0(this->typeField);
}
