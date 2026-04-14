extern const char * __stdcall nameTypeFunc_E9C0(unsigned char typeId);

class AIPlayPhaseAction {
public:
    char gap_0[1];
    unsigned char typeField;
    const char *nameType();
};

const char *AIPlayPhaseAction::nameType() {
    return nameTypeFunc_E9C0(this->typeField);
}
