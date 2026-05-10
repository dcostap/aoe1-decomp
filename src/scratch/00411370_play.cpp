// VA: 00411370 AIPlayBook::play (131 bytes)
//
// Attempt log:
// - Baseline natural `strcmp(this->plays[i].nameValue, name)` compiles to an inlined strcmp but uses a stack frame,
//   duplicates the string-compare body for later iterations, and broadly drifts from original.
// - SpruceGlow tried 23 variants: manual inline strcmp loop, strcmp pointer iteration, for/while/do/goto loop forms,
//   saved-base locals, decompiler-style locals, parameter reloads, n/i declaration order, volatile n, manual return
//   offset arithmetic, and minimal manual compare loops. No exact. Best edit diff seen was the simple `for`/`while`
//   family (edit diff 9) but it still shifts because VC5 adds an extra top loop guard and duplicates the compare body.
// - Original appears to need the no-frame inlined strcmp family with saved plays in a stack slot and one shared compare
//   loop over each play name. Current source kept as simplest behavior-correct baseline.
// Left in scratch: behavior is clear, but source shape/register scheduling for the shared inlined strcmp loop remains unresolved.
// Not an accepted_drift suggestion: broad control-flow/code-layout drift and duplicated compare body.

#include <string.h>

struct AIPlay {
    char nameValue[0x608];
};

class AIPlayBook {
public:
    void* vtable_ptr;
    int numberPlaysValue;
    char pad_08[0x44];
    AIPlay* plays;

    AIPlay* play(char* name);
};

AIPlay* AIPlayBook::play(char* name) {
    int i;
    int r;
    int n;

    if (this->plays == 0) return 0;
    n = this->numberPlaysValue;
    if (n <= 0) return 0;

    i = 0;
    do {
        r = strcmp(this->plays[i].nameValue, name);
        if (r == 0) return &this->plays[i];
        i++;
    } while (i < n);

    return 0;
}
