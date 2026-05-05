// 00411400 AIPlayBook::playNumber (aipbook.cpp:1317-1325, 113B)
// ~95% mismatch. 2-byte unrolled string compare loop with VC5-version
// register allocation differences:
//
// 1. STACK FRAME: Our VC5 allocates `sub esp, 8` for local variables
//    (i and count). The 1998 build keeps both in registers (ebp, eax),
//    eliminating the stack frame entirely. This shifts all [esp+...]
//    offsets by 8.
//
// 2. REGISTER ALLOCATION: Original uses edx for plays base, eax for
//    count, ebp for loop index, esi for name, edi for current play ptr.
//    Our VC5 uses ebx for plays, spills count to [esp+14h], keeps i
//    at [esp+10h]. Different register choices cascade through the
//    comparison loop.
//
// 3. DUPLICATE COUNT CHECK: Our VC5 emits two `jle` checks for count
//    (one before xor ebp, one after). Original has one.
//
// 4. COMPARISON LOOP: Both compilers generate the same 2-byte unrolled
//    string comparison structure. The comparison loop body is
//    structurally identical — the only differences are register names
//    and jump offsets.
//
// The comparison logic, AIPlay struct size (0x608), field offsets,
// and control flow are all verified correct.

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
    if (this->plays == 0) return -1;
    if (this->numberPlaysValue <= 0) return -1;

    for (int i = 0; i < this->numberPlaysValue; i++) {
        char* a = this->plays[i].nameValue;
        char* b = name;
        char ca;
        char cb;
        do {
            ca = *a;
            cb = *b;
            if (ca != cb) break;
            if (ca == 0) return i;
            a++; b++;
            ca = *a;
            cb = *b;
            if (ca != cb) break;
            if (ca == 0) return i;
            a++; b++;
        } while (true);
        if (ca == cb) return i;
    }
    return -1;
}
