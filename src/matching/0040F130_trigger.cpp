#ifndef AIPBOOK_CANONICAL_TU
class AIPlayPhaseTrigger {
public:
    int field_00[5];
};

class AIPlayPhase {
public:
    char gap_00[0x50];
    AIPlayPhaseTrigger triggers[3];

    AIPlayPhaseTrigger* trigger(int index);
};
#endif

AIPlayPhaseTrigger* AIPlayPhase::trigger(int index) {
    if ((index >= 0) && (index < 3)) {
        return &this->triggers[index];
    }
    return 0;
}
