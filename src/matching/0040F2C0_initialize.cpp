#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    unsigned char minValue[6];
    unsigned char maxValue[6];

protected:
    void initialize(void);
};
#endif

void AIPlayGroup::initialize(void) {
    for (int i = 0; i < 6; ++i) {
        this->minValue[i] = 0;
        this->maxValue[i] = 0xFE;
    }
}
