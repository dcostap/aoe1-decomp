// 00518090 TRIBE_Player::setupMinoan (tplayer.cpp:4147-4195, 299B)
// Sets up Minoan civilization parameters based on game mode, difficulty, and game type.
//
// Attempt log:
// - Natural typed reconstruction matches the calls, fields, stores, and CFG.
// - Ten focused guard/liveness/context probes (including positive/inverted
//   difficulty arms, shared pointer locals, named result, fastcall wrapper,
//   and register-qualified pointer) all returned the same VC5 codegen.
// - Remaining scheduling gap: original loads p before `jge` and reuses EAX;
//   default VC5 emits `jge` first, then reloads p in each arm. 303 rebuilt
//   bytes vs 299 original; edit/resync diff 8 bytes (1.33%), strict diff
//   122 bytes due the shifted hunk. All field offsets, values, string refs,
//   calls, and control flow remain verified.
// - Main-agent audit replaced the decompiler-style numbered structs and free
//   logger shim with canonical TRIBE_Game/TRIBE_Player/AIModule ownership;
//   emitted code remains unchanged.
// FLAGS: /nologo /c /O2 /Oy

class AIModule {
public:
    void logCommonHistory(char* message, ...);
};

class TRIBE_Game {
public:
    virtual ~TRIBE_Game();
    int difficulty();
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
    void setupMinoan(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player::setupMinoan(int* p, int type, int unused1, int unused2) {
    this->playerAI->logCommonHistory("Setting up as Minoans.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x42] = 100;
        } else if (type == 2 || type == 6) {
            p[0x1C] = 0x3C;
            p[0x42] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x1C] = 0x50;
            p[0x42] = 0x14;
        } else {
            p[0x1C] = 100;
        }
    } else {
        if (rge_base_game->difficulty() < 1) {
            p[0x25] = 100;
            return;
        }

        p[4] = 10;
        p[6] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0xB] = 10;
        p[0] = 0x3C;
        p[1] = 0x50;
        p[3] = 0x14;
        p[0x33] = 100;

        if (type == 0 || type == 1) {
            p[0x58] = 200;
            p[0x59] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x58] = 100;
            p[0x59] = 100;
        }
    }
}
