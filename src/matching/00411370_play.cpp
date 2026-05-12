// VA: 00411370 AIPlayBook::play — EXACT MATCH
// Source: aipbook.cpp lines 1304-1312
// FLAGS: /nologo /c /O2 /Oy
//
// Key matching insight: VC5's for-loop condition generates the upper-bound guard
// internally. An explicit `if (numberPlaysValue <= 0) return 0;` before the for-loop
// creates a *redundant* duplicate guard (test/jle) before the loop body. Removing the
// explicit check lets VC5 generate exactly one guard, matching the original binary.

#include <string.h>

struct AIPlay {
    char nameValue[0x608];
};

class AIPlayBook {
public:
    void* vtable;               // +0x00
    int numberPlaysValue;       // +0x04
    char pad_08[0x4C - 0x08];
    AIPlay* plays;              // +0x4C

    AIPlay* play(char* name);
};

AIPlay* AIPlayBook::play(char* name) {
    if (this->plays == 0) return 0;
    for (int i = 0; i < this->numberPlaysValue; i++) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return &this->plays[i];
        }
    }
    return 0;
}
