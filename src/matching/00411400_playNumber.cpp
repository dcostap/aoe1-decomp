// 00411400 AIPlayBook::playNumber (aipbook.cpp:1317-1325, 113B)
//
// Attempt log:
// - Initial scratch manually spelled the 2-byte unrolled string compare loop. Behavior was correct but VC5
//   allocated an 8-byte stack frame, spilled count/index, and used different registers; 97% positional diff.
// - SpruceGlow try 1 MATCH: use the natural `strcmp(this->plays[i].nameValue, name) == 0` in a simple for-loop.
//   VC5 recognizes/inlines strcmp into the exact 2-byte unrolled compare loop and keeps plays/count/index in
//   edx/eax/ebp with no stack frame.
// BINARY NOTE: AIPlayBook is polymorphic. Use the canonical declaration for its
// vptr and post-vptr fields at +04 (count) and +4C (plays).
// Result: MATCH locally with `python tools/check_function.py --va 00411400`.

#include "../../include/aipbook_context.h"

int AIPlayBook::playNumber(char* name) {
    if (this->plays == 0) {
        return -1;
    }

    int n = this->numberPlaysValue;
    for (int i = 0; i < n; i++) {
        if (strcmp(this->plays[i].nameValue, name) == 0) {
            return i;
        }
    }

    return -1;
}
