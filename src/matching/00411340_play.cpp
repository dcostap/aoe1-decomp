// VA: 00411340
// PDB owner: public: class AIPlay *__thiscall AIPlayBook::play(int)
// Body boundary: 00411340-00411366; the next PDB function starts at 00411370.
// BINARY NOTE: the three guards preserve the shipped null, negative-index, and
// upper-bound fault order before the returned AIPlay address is formed.

#ifndef AIPBOOK_CANONICAL_TU
struct AIPlay {
    char data[0x608];
};

class AIPlayBook {
public:
    int vfptr;
    int numberPlaysValue;
    char gap_08[0x44];
    AIPlay* plays;

    AIPlay* play(int index);
};
#endif

AIPlay* AIPlayBook::play(int index) {
    if (this->plays != 0 && index >= 0 && index < this->numberPlaysValue)
        return this->plays + index;
    return 0;
}
