#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    char gap_0[0x6];
    unsigned char maximumValues[6];
    void setMaximum(int index, unsigned char val);
};
#endif

void AIPlayGroup::setMaximum(int index, unsigned char val) {
    if (index < 0 || index >= 6) return;
    this->maximumValues[index] = val;
}
