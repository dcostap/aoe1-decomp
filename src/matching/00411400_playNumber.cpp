// 00411400 AIPlayBook::playNumber (aipbook.cpp:1317-1325, 113B)
//
// Attempt log:
// - Initial scratch manually spelled the 2-byte unrolled string compare loop. Behavior was correct but VC5
//   allocated an 8-byte stack frame, spilled count/index, and used different registers; 97% positional diff.
// - SpruceGlow try 1 MATCH: use the natural `strcmp(this->plays[i].nameValue, name) == 0` in a simple for-loop.
//   VC5 recognizes/inlines strcmp into the exact 2-byte unrolled compare loop and keeps plays/count/index in
//   edx/eax/ebp with no stack frame.
// Result: MATCH locally with `python tools/check_function.py --va 00411400`.

extern "C" int __cdecl strcmp(const char*, const char*);

struct AIPlay {
    char nameValue[0x608];
};

class AIPlayBook {
public:
    void* vtable_ptr;
    int numberPlaysValue;
    char pad_08[0x44];
    AIPlay* plays;

    int playNumber(char* name);
};

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
