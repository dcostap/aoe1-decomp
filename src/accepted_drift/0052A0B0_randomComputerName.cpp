// 0052A0B0 TRIBE_Game::randomComputerName
// Source: tribegam.cpp lines 5397-5431, size 187 bytes
// Attempt log:
// first: wrong stack alloc (16 instead of 12), wrong struct offset (0xBF8 vs 0x1198)
// second: &param1 trick backfires — forces param1 on stack, ruins register alloc
// third: clean locals, 16 diff bytes — all esi/edi register swap (91.4% match)
// fourth: minimal locs/goto — not better
// Parked: pure VC5 register allocation drift (esi=param1↔edi=param1; edi=limit↔esi=limit)
//         16 diff bytes (8.6%), same size (187), 3 relocations masked
//         counter at [esp+20h] matches, computerNameUsed offset 1198h matches
//         All code structure, loop bounds, stack cleanup byte-identical except register names

extern "C" int atoi(const char*);
extern "C" int debug_rand(const char* file, int line);

// VirtualHelper for calling through vtable+0x20 (slot 8)
struct TRIBE_Game_V20 {
    virtual void _d0();  virtual void _d1();  virtual void _d2();  virtual void _d3();
    virtual void _d4();  virtual void _d5();  virtual void _d6();  virtual void _d7();
    virtual void getTribeName(int idx, char* buf, int size);  // +0x20
};

// TRIBE_Game with computerNameUsed array at +0x1198
#ifndef TRIBEGAM_TU_CONTEXT
struct TRIBE_Game {
    virtual void _d0();  virtual void _d1();  virtual void _d2();  virtual void _d3();
    virtual void _d4();  virtual void _d5();  virtual void _d6();  virtual void _d7();
    virtual void _d8();  virtual void _d9();  virtual void _d10(); virtual void _d11();
    virtual void _d12(); virtual void _d13(); virtual void _d14(); virtual void _d15();
    virtual void _d16(); virtual void _d17(); virtual void _d18(); virtual void _d19();
    virtual void _d20(); virtual void _d21(); virtual void _d22(); virtual void _d23();
    virtual void _d24(); virtual void _d25(); virtual void _d26(); virtual void _d27();
    virtual void _d28(); virtual void _d29(); virtual void _d30(); virtual void _d31();
    virtual void _d32(); virtual void _d33(); virtual void _d34(); virtual void _d35();
    virtual void _d36(); virtual void _d37(); virtual void _d38(); virtual void _d39();
    virtual void _d40(); virtual void _d41(); virtual void _d42(); virtual void _d43();
    virtual void _d44();
    virtual TRIBE_Game* createGameWorld(); // +0xB4

    char gap_04[8];
    void* prog_info;
    char gap_10[0x3E4];
    void* world;
    char gap_3F8[0xDA0];
    unsigned char computerNameUsed[8][10];  // +0x1198

    int randomComputerName(int param1);
};
#endif

static char debugFilename[] = "C:\\msdev\\work\\age1_x1\\tribegam.cpp";

int TRIBE_Game::randomComputerName(int param1) {
    char s[12];
    int max;
    int slot;
    int i;
    int tries;

    ((TRIBE_Game_V20*)this)->getTribeName((param1 + 0x1B7) * 10, s, 10);
    max = atoi(s);

    tries = 0;

    do {
        int r = debug_rand(debugFilename, 0x1521);
        slot = r % max;
        if (slot > max - 1) slot = max - 1;
        if (this->computerNameUsed[param1][slot] == 0) break;
        tries++;
    } while (tries < 20);

    if (this->computerNameUsed[param1][slot] == 1) {
        for (i = 0; i < 10; i++) {
            if (this->computerNameUsed[param1][i] == 0) {
                slot = i;
                break;
            }
        }
    }

    this->computerNameUsed[param1][slot] = 1;
    return slot + param1 * 10 - 9;
}
