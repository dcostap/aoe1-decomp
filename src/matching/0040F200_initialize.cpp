// AIPlayPhase::initialize
// Loops: zero 5 bytes at offsets +1, +11, +21, +31, +41 (stride 0x10)
// Then zero 3 bytes at offsets +50, +64, +78 (stride 0x14)
// No params, no return, __thiscall

struct AIPlayPhase {
    char data[0x100]; // placeholder
};

void __fastcall initialize(AIPlayPhase* self, int) {
    int i;
    char* p;

    p = ((char*)self) + 1;
    for (i = 0; i < 5; i++) {
        *p = 0;
        p += 0x10;
    }

    p = ((char*)self) + 0x50;
    for (i = 0; i < 3; i++) {
        *p = 0;
        p += 0x14;
    }
}
