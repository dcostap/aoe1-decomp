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
// A shared-cluster TRIBE_Game surface (difficulty plus nonconst deathMatch) and
// distinct constant expressions for the three proven 20 stores were tested;
// both emitted the same 285-byte VC5 basin. Keep the ordinary literal source.
// The final declaration surface also uses the proven RGE_Base_Game base shared
// by the difficulty-using siblings; Shang's emitted bytes remain unchanged.
// v11 (sa-a2591ccc-r1): dossier/donor/ABI review confirmed two direct calls,
// b/mapType/gameType/mapSize stack ABI, playerAI +0x238, and no unknown layout
// fact.  Reordering the repeated-value groups worsened the same 285-byte basin.
// v12-v15: 24 group-order variants, register-qualified repeated constants,
// VC5-small flag sweep, and 24 permutations of the four 10-valued stores found
// no EDX/ECX split; all viable variants stayed 285 bytes.
// v16-v17: chained/comma assignment shapes and likely stdio/string/stdlib/
// windows header contexts also left the direct-store basin unchanged (the mixed
// expression shape was less plausible and only shifted the mismatch).
// Final session probe renamed parameters to their original PDB symbols without
// changing bytes.  The unresolved gap remains the non-deathmatch constant
// register coloring/7-byte size delta; retain this clean typed reconstruction.
// - TU-group closeout: the common civilization-table and TRIBE_Game declaration
//   context remains canonical; a fresh baseline emitted the same 285-byte basin.
//   The EDX/ECX split and seven-byte size gap have no new source-backed lead.
// v18 (sa-23c06259-r1): grouped/chained the repeated non-deathmatch stores to
// mirror the PDB store bands. VC5 emitted the identical 285-byte result
// (123 strict-diff bytes; first mismatch +0x97), so the clean literals remain.
// v19 (sa-40f54d55-r1): fresh baseline and five natural probes preserved the
// same 285-byte basin: a late mapType copy, reviewed base-game global typing,
// non-polymorphic TRIBE_Game, explicit deathmatch returns, and fully chained
// repeated stores. Retain this typed direct-store source; the only gap remains
// the original EDX/ECX constant coloring and immediate-store encoding.
// v20 (sa-63b9d937-r1): refreshed the dossier and searched exact local donors
// for the +0x97 store block. No same-TU donor gives this EDX/ECX pattern.
// The typed direct-store source remains the cleanest supported reconstruction.
// ACCEPTED DRIFT: The non-deathmatch hunk keeps the same table-store order but
// colors constants through ECX instead of EDX and moves the private mapType
// load and TEST after unconditional MOV stores. MOV preserves the oracle's
// flags until its branch. Both builds write each value to the same slot in the
// same order. Both calls, all branches, returns, and fault behavior match.

typedef unsigned char uchar;

// Main-agent audit confirmed the shared canonical game/player/AI ownership;
// direct civilization table stores remain authoritative.
#include "../../include/tplayer_context.h"

#if 0
class AIModule {
public:
    void logCommonHistory(char* fmt, ...);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    uchar deathMatch();
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char pad_04[0x234];
    AIModule* playerAI;  // +0x238
};

class TRIBE_Player : public RGE_Player {
public:
    void setupShang(int* b, int mapType, int gameType, int mapSize);
};

#endif

void TRIBE_Player::setupShang(int* b, int mapType, int gameType, int mapSize)
{
    this->playerAI->logCommonHistory("Setting up as Shang.");

    if (rge_base_game->deathMatch() == 1) {
        // Deathmatch path
        if (mapType == 0 || mapType == 1) {
            b[0x45] = 100;
        } else if (mapType == 2 || mapType == 6) {
            b[0x1F] = 0x3C;
            b[0x45] = 0x28;
        } else if (mapType == 5 || mapType == 8) {
            b[0x1F] = 0x50;
            b[0x45] = 0x14;
        } else {
            b[0x1F] = 100;
        }
    } else {
        // Non-deathmatch path
        b[0] = 10;
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[6] = 50;
        b[7] = 50;
        b[0x38] = 50;

        b[11] = 30;
        b[0x14] = 30;
        b[1] = 0x14;
        b[0x10] = 0x14;
        b[0x13] = 0x14;
        b[0x36] = 100;
        b[0x37] = 100;

        if (mapType == 0 || mapType == 1) {
            b[0x5D] = 0xA0;
        } else if (mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5) {
            b[0x5D] = 0x50;
        }
    }
}
