#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhase {
public:
    char data[0x8C];
};

class AIPlay {
public:
    char gap_00[0x90];
    AIPlayPhase phases[10];

    AIPlayPhase* phase(int index);
};
#endif

AIPlayPhase* AIPlay::phase(int index) {
    if (index >= 0 && index < 10)
        return this->phases + index;
    return 0;
}
