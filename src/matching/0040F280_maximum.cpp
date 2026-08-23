// maximum (0040F280, 25 bytes, aipbook.cpp)
// bounds-check array access, return 0xFF if out of range

#ifndef AIPBOOK_CANONICAL_TU
class AIPlayGroup {
public:
    char gap_0[0x6];
    unsigned char maxValue[6];
    unsigned char maximum(int index) const;
};
#endif

unsigned char AIPlayGroup::maximum(int index) const {
    if (index >= 0 && index < 6)
        return maxValue[index];
    return 0xFF;
}
