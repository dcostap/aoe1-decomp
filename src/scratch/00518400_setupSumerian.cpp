// 00518400 TRIBE_Player::setupSumerian (tplayer.cpp:4292-4340, 309B)
// Sets up Sumerian civilization parameters based on game mode, difficulty, and game type.
//
// Left in scratch: 288/309 bytes match (93.2%), edit diff 12.6%.
// Remaining diff is VC5 scheduling quirks: (1) p reload (`mov eax,[esp+4]`)
// is after `jge` in rebuilt vs before `jge` in original, (2) edx=100 loaded
// too early (before 20-value stores instead of after), (3) ecx vs edx register
// choice for value 20, (4) type load delayed until after all stores. Deathmatch
// path (170 bytes) matches perfectly. All field offsets, store values, string
// refs, and control flow verified correct.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void logCommonHistory(void* aimodule, char* msg);

struct RGE_Base_Game {
    char _pad_00[4];
    int difficulty();
};

struct TRIBE_Game : RGE_Base_Game {
    unsigned char deathMatch();
};

extern "C" { extern TRIBE_Game* rge_base_game; }

struct TRIBE_Player5 {
    char _pad_00[0x238];
    void* playerAI;

    void setupSumerian(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player5::setupSumerian(int* p, int type, int unused1, int unused2) {
    logCommonHistory(playerAI, "Setting up as Sumerians.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x46] = 100;
        } else if (type == 2 || type == 6) {
            p[0x20] = 0x3C;
            p[0x46] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x20] = 0x50;
            p[0x46] = 0x14;
        } else {
            p[0x20] = 100;
        }
    } else {
        if (rge_base_game->difficulty() < 1) {
            p[0x26] = 100;
            return;
        }

        p[3] = 10;
        p[9] = 10;
        p[10] = 10;
        p[11] = 10;
        p[4] = 0x14;
        p[0x11] = 0x14;
        p[0x10] = 0x1E;
        p[0x39] = 100;
        p[0x3A] = 100;

        if (type == 0 || type == 1) {
            p[0x5E] = 200;
            p[0x5F] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x5E] = 100;
            p[0x5F] = 100;
        }
    }
}
