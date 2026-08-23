#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    char data[12];
};

class AIPlay {
public:
    char gap_0[0x53];
    AIPlayGroup groups[5];
    AIPlayGroup *group(int index);
};
#endif

AIPlayGroup *AIPlay::group(int index) {
    if (index < 0 || index >= 5) return 0;
    return &this->groups[index];
}
