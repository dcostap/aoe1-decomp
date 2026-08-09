// VA: 00518670, TRIBE_Player::setupShang, 292 bytes
// Source: tplayer.cpp lines 4395-4435
// FLAGS: default
//
// Attempt log:
// v1: Direct field assignments. 288/292 bytes (4 short). Deathmatch path matches
//     exactly. Non-deathmatch: VC5 uses ecx for ALL constant stores instead of
//     original's edx/ecx split. Original edx=0Ah/1Eh/64h, ecx=32h→param_2.
//     Our VC5 keeps everything in ecx, no register split.
// v2-v6: Various attempts to force register split: separate local variables,
//     volatile pointer, const blocks, char-pointer casts, int*__restrict.
//     None changed VC5's register allocation decision.
// v7: /O1 flag → 274 bytes (worse).
// v8-v10 (this session): typed TRIBE_Game/const deathMatch, canonical AIModule
//     varargs member logger, polymorphic player base, C++ global linkage, a
//     map_type copy/register qualifier, and chained adjacent stores. The ABI
//     fixes changed call symbol identity but no emitted bytes; source-shape
//     probes all remained at 285 rebuilt bytes and the same first mismatch.
// 
// Root cause: VC5 register allocator version difference. Original uses edx
// for cyclic constants (0Ah→1Eh→64h) and ecx for 32h→param_2. Our VC5
// version keeps all constants in ecx. Same pattern as setupPhoenician
// (005182E0). Both functions require the same two-register constant pattern
// that this VC5 version doesn't produce.
// 
// Current source is the clean typed reconstruction: the deathmatch path and
// non-deathmatch behavior/CFG/calls match, but only the non-deathmatch store
// register coloring and immediate-vs-register encoding remain different.

typedef unsigned char uchar;

class AIModule {
public:
    void logCommonHistory(char* fmt, ...);
};

struct TRIBE_Game {
    virtual ~TRIBE_Game();
    uchar deathMatch() const;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x234];
    AIModule* playerAI;  // +0x238
};

class TRIBE_Player : public RGE_Player {
public:
    void setupShang(int* param_1, int param_2, int param_3, int param_4);
};

extern TRIBE_Game* rge_base_game;  // 0x0062C574

void TRIBE_Player::setupShang(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Shang.");

    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x45] = 100;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x1F] = 0x3C;
            param_1[0x45] = 0x28;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x1F] = 0x50;
            param_1[0x45] = 0x14;
        } else {
            param_1[0x1F] = 100;
        }
    } else {
        // Non-deathmatch path
        param_1[0] = 10;
        param_1[3] = 10;
        param_1[9] = 10;
        param_1[10] = 10;
        param_1[6] = 50;
        param_1[7] = 50;
        param_1[0x38] = 50;

        param_1[11] = 30;
        param_1[0x14] = 30;
        param_1[1] = 0x14;
        param_1[0x10] = 0x14;
        param_1[0x13] = 0x14;
        param_1[0x36] = 100;
        param_1[0x37] = 100;

        if (param_2 == 0 || param_2 == 1) {
            param_1[0x5D] = 0xA0;
        } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
            param_1[0x5D] = 0x50;
        }
    }
}
