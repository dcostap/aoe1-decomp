// 00518540 TRIBE_Player::setupPersian (tplayer.cpp:4345-4390, 296B)
// Sets up Persian civilization parameters based on game mode and game type.
//
// Left in scratch: VC5 register scheduling in non-deathmatch path.
// Deathmatch path (157 bytes) matches perfectly. Non-deathmatch diff:
// - edx=0x28 (orig) vs edx=0x64 (rebuilt): VC5 pre-loads 100 for later use
// - Store reordering: 0x28/0x14 stores via ecx/edx register allocation differs
// - param2 load timing: interleaved vs after all stores
// All field offsets, store values, and control flow verified correct.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void logCommonHistory(void* aimodule, char* msg);

struct TRIBE_Game {
    char _gap_00[4];
    unsigned char deathMatch();
};

extern "C" { extern TRIBE_Game* rge_base_game; }

struct TRIBE_Player {
    char _pad_00[0x238];
    void* playerAI;

    void setupPersian(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player::setupPersian(int* p, int type, int unused1, int unused2) {
    logCommonHistory(playerAI, "Setting up as Persians.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x43] = 100;
        } else if (type == 2 || type == 6) {
            p[0x1D] = 0x3C;
            p[0x43] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x1D] = 0x50;
            p[0x43] = 0x14;
        } else {
            p[0x1D] = 100;
        }
    } else {
        p[6] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0x11] = 0x3C;
        p[0x12] = 0x3C;

        int t = type;
        p[1] = 0x28;
        p[0xB] = 0x28;
        p[0x14] = 0x28;
        p[0] = 0x14;
        p[0x10] = 0x14;
        p[7] = 0x32;
        p[0x13] = 0x14;
        p[0x34] = 100;

        if (t == 0 || t == 1) {
            p[0x5A] = 200;
            p[0x5B] = 200;
        } else if (t == 2 || t == 6 || t == 8 || t == 5) {
            p[0x5A] = 100;
            p[0x5B] = 100;
        }
    }
}
