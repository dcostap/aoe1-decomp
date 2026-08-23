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
// - Rechecked the shared RGE_Base_Game inheritance for the proven difficulty
//   ABI; codegen stayed unchanged, so the remaining p-load/jge schedule is a
//   VC5 basin rather than a game-type declaration issue.
// - The direct outer else-if difficulty form used by exact setup donors also
//   emitted the same bytes; retain it as the cleaner period-plausible shape.
// - Current claim: focused difficulty/pointer labs (8 + 13 forms), an
//   early-return whole-outer alias, full tplayer class surface, and small flag
//   context all retained the 303-byte basin; volatile/wrapper forms were
//   larger and are not living-source candidates.
// - A 576-way permutation of the two independent normal-store groups changed
//   only later scheduling/edit distance; every variant retained the same
//   first mismatch at the missing pre-jge p load.  The natural observed store
//   order remains the clean source.
// - Labeled/goto guard forms likewise retained the 303-byte basin; the one
//   altered CFG was strictly worse.  The p-load-before-jge gap is therefore
//   still isolated to a stable VC5 structural/codegen basin after 9 new
//   hypothesis families; no plausible source lead remains in this claim.
// FLAGS: /nologo /c /O2 /Oy
// - TU-group closeout: the common civilization-table and TRIBE_Game declaration
//   context remains canonical; a fresh baseline emitted the same 303-byte basin.
//   The p-load-before-jge schedule remains the only source-shape blocker.
// - This claim tested a function-scope alias, a self-assignment, an early-return
//   outer form, a named difficulty value, and an array parameter. All retained
//   the same 303-byte basin; the array form also changed the decorated owner.
// - Reviewed RGE_Base_Game global typing and a long difficulty return changed no
//   bytes. Ambient declarations (512 variants) and standard-header context
//   (4096 variants) each formed one 303-byte group with the same first mismatch.
// - Revisit probes tested a pointer alias local to the non-deathmatch path, a
//   nested difficulty guard with explicit returns, a difficulty-result plus
//   pointer alias, a positive guard, and a separate low-path return. None
//   reproduced the original mov p before jge. A reference alias moved three
//   bytes but changed the natural block shape and is not retained.
// - Exact-finish revisit in the canonical tplayer context tested separate
//   declaration/assignment, mixed arm aliases, comma assignment, named
//   difficulty, receiver caching, register and const parameters, and a
//   negated threshold. All retained the 303-byte basin and the same first
//   mismatch at +A1. The registered wrapper build reproduced that basin.
// - Fresh grouped anchor checks kept 00513000, 00517B90, 00517E10, 005181C0,
//   005188F0, 00518DD0, 00518F00, 005192F0, and 00519320 exact. 005153D0
//   retained its prior accepted drift and call parity.

// Main-agent audit confirmed the shared canonical game/player/AI ownership;
// direct civilization table stores remain authoritative.
// ACCEPTED DRIFT: The only edit-distance hunk moves the private p-parameter
// load across the difficulty branch and reloads it in the high-difficulty
// arm. Both arms use p before any later call or store. CMP, MOV, and JGE cannot
// fault except for the same private stack read. Values, flags at each branch,
// field stores, all three calls, returns, and fault behavior match.
#include "../../include/tplayer_context.h"

#if 0
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
    void setupMinoan(int* p, int type, int unused1, int unused2);
};

#endif

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
    } else if (rge_base_game->difficulty() < 1) {
        p[0x25] = 100;
    } else {
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
