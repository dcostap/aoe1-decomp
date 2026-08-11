// 00518400 TRIBE_Player::setupSumerian (tplayer.cpp:4292-4340, 309B)
// Sets up Sumerian civilization parameters based on game mode, difficulty, and game type.
//
// Best current reconstruction: 279/309 positional bytes match (90.3%),
// exact-size build, 27-byte edit diff, and 95.15% resync similarity.
// Deathmatch path (170 bytes), difficulty gate, all calls, fields, values,
// string refs, and control flow are verified. Remaining 30-byte drift begins
// at the non-deathmatch constant group: VC5 loads 100 into EDX where the
// original loads 20, then schedules the type/20/30/100 stores differently.
// FLAGS: /nologo /c /O2 /Oy
// Shared-cluster ABI uses RGE_Base_Game inheritance for the proven difficulty
// method and the common AIModule/TRIBE_Game/TRIBE_Player surface.
// Attempt log:
// - natural direct-store source: 313 bytes, 122 strict diff bytes; p reload
//   followed the jge and 100 was live too early.
// - settings pointer, map-type/result locals, independent constant locals,
//   donor-style guard forms, and broad group reorder probes were unchanged or
//   structurally worse.
// - moving the ordinary p[0x10] = 30 assignment before the ten-valued group
//   recovered the original p reload/jge schedule and exact 309-byte size;
//   retain this readable source-order hypothesis as the best reconstruction.
// - a focused 144-case store-order lab found no exact bytes; delaying the two
//   common 100 stores worsened the build to 321 bytes and was rolled back.
// Final validation: 309 rebuilt bytes, 30 strict diff bytes, 27-byte edit diff.

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
        p[0x10] = 0x1E;
        p[3] = 10;
        p[9] = 10;
        p[10] = 10;
        p[11] = 10;
        p[4] = 0x14;
        p[0x11] = 0x14;
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
