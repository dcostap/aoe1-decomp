struct AIPlayPhase {
    char data[0x100];
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
