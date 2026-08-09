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
// Shared-cluster ABI uses RGE_Base_Game inheritance for the proven difficulty
// method and the common AIModule/TRIBE_Game/TRIBE_Player surface. Map-type and
// reused-value locals, plus a positive difficulty guard, did not move codegen;
// retain the natural direct-store reconstruction.
// Final validation: 313 rebuilt bytes, 292 equal bytes, 122 strict diff bytes,
// and 35-byte edit diff; the four-byte excess is the p-load-before-jge basin.
// Direct outer else-if difficulty syntax (as in exact same-TU donors) also
// stayed identical; retain this simpler source shape.

// Main-agent audit confirmed the shared canonical game/player/AI ownership;
// direct civilization table stores remain authoritative.
class AIModule {
public:
    void logCommonHistory(char* message, ...);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    unsigned char deathMatch();
};

extern TRIBE_Game* rge_base_game;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x234];
    AIModule* playerAI;
};

class TRIBE_Player : public RGE_Player {
public:
    void setupSumerian(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player::setupSumerian(int* p, int type, int unused1, int unused2) {
    this->playerAI->logCommonHistory("Setting up as Sumerians.");

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
    } else if (rge_base_game->difficulty() < 1) {
        p[0x26] = 100;
    } else {
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
