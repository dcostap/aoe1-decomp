extern const char * __stdcall nameTypeFunc_ED00(unsigned char typeId);

class AIPlayPhaseTrigger {
public:
    unsigned char typeField;
    const char *nameType();
};

const char *AIPlayPhaseTrigger::nameType() {
    return nameTypeFunc_ED00(this->typeField);
}
