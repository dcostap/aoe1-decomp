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
// - Walkthrough18400 replaced the absolute rge_base_game macro with the reviewed
//   shared extern and explicit TRIBE_Game use. VC5 emitted identical code.
// - A focused exact-donor search for the remaining 15-instruction constant-store
//   block found no matching source example. Do not repeat blind store permutations.
// - Original PDB locals contain only `this`, `b`, `mapType`, `gameType`, and
//   `mapSize`; no local result or settings alias is present. A full local donor
//   search still found no source for the 15-instruction schedule.
// - Chained and comma-grouped stores, a narrow early-store scope, and a linked
//   early 30/10 expression all emitted the same 30-byte mismatch. They were
//   discarded. Keep direct assignments and the clean source order below.
// - Revisit probes: restoring natural 10/20/30/100 assignment order produced
//   313 bytes and 122 strict diff bytes; a scoped `const twenty` was unchanged.
//   Restore the pinned source after both probes.
// Final validation: 309 rebuilt bytes, 30 strict diff bytes, 27-byte edit diff;
// exact calls, size, frame, CFG, and verified setup behavior remain intact.

#include "../../include/rge_base_game_global.h"

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

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x234];
    AIModule* playerAI;
};

class TRIBE_Player : public RGE_Player {
public:
    void setupSumerian(int* b, int mapType, int gameType, int mapSize);
};

void TRIBE_Player::setupSumerian(int* b, int mapType, int gameType, int mapSize) {
    this->playerAI->logCommonHistory("Setting up as Sumerians.");

    if (((TRIBE_Game*)rge_base_game)->deathMatch() == 1) {
        if (mapType == 0 || mapType == 1) {
            b[0x46] = 100;
        } else if (mapType == 2 || mapType == 6) {
            b[0x20] = 0x3C;
            b[0x46] = 0x28;
        } else if (mapType == 5 || mapType == 8) {
            b[0x20] = 0x50;
            b[0x46] = 0x14;
        } else {
            b[0x20] = 100;
        }
    } else if (rge_base_game->difficulty() < 1) {
        b[0x26] = 100;
    } else {
        b[0x10] = 0x1E;
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[4] = 0x14;
        b[0x11] = 0x14;
        b[0x39] = 100;
        b[0x3A] = 100;

        if (mapType == 0 || mapType == 1) {
            b[0x5E] = 200;
            b[0x5F] = 200;
        } else if (mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5) {
            b[0x5E] = 100;
            b[0x5F] = 100;
        }
    }
}
