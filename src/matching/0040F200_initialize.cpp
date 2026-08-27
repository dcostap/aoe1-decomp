// 0040F200 AIPlayPhase::initialize

void AIPlayPhase::initialize() {
    int i;
    char* p;

    p = ((char*)this) + 1;
    for (i = 0; i < 5; i++) {
        *p = 0;
        p += 0x10;
    }

    p = ((char*)this) + 0x50;
    for (i = 0; i < 3; i++) {
        *p = 0;
        p += 0x14;
    }
}
