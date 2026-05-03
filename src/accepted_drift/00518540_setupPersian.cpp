// VA: 00518540, TRIBE_Player::setupPersian, 296 bytes
// Source: tplayer.cpp lines 4345-4390
// ACCEPTED_DRIFT: VC5 register allocation and scheduling differences.
// All field values, control flow, and behavior identical.
//
// Key techniques:
// - if-else if chains for cmp/je dispatch (matching setupBabylonian pattern)
// - Direct field assignments via p[XX] = value
//
// Remaining drift (stable across 7 source variants):
// 1. Schedule: original loads `mov edx, 28h` first (for p[1],p[0xB],p[0x14]),
//    then `mov edx, 64h` later; rebuilt loads `mov edx, 64h` first and uses
//    ecx for 28h group
// 2. Type load: original loads type from [esp+8] BEFORE the 28h stores;
//    rebuilt loads type AFTER all stores (just before comparison)
// 3. 14h stores: original uses 6-byte `mov dword [eax+XX], 14h` (immediate);
//    rebuilt uses 2-3 byte `mov [eax+XX], ecx` (register indirect)
// 4. Cascade: all offsets shift by ~16 bytes due to size differences,
//    affecting jump target bytes and comparison operand bytes
//
// What matches (157 bytes at start):
// - Prologue (mov eax,[ecx+238h]; push string; push eax; call logCommonHistory)
// - rge_base_game load + deathMatch call (mov ecx,[62C574h]; add esp,8; call)
// - deathMatch comparison (cmp al,1; jne short → non-deathMatch path)
// - DeathMatch block: type comparisons for 0,1,2,5,6,8 with correct
//   field assignments (p[0x43]=100; p[0x1D]=0x3C/0x50/0x64; p[0x43]=0x28/0x14)
// - Non-deathMatch block: p[6]=10, p[9]=10, p[10]=10, p[0x11]=0x3C, p[0x12]=0x3C
// - All type comparisons in non-deathMatch block (0,1,2,5,6,8 → same branches)
// - p[0x5A]/p[0x5B] assignments for each branch
// - All ret 10h instructions match

#include <stddef.h>

typedef unsigned char uchar;

void logCommonHistory(void* ai, char* msg);

struct TRIBE_Game {
    uchar deathMatch();
};

extern TRIBE_Game* rge_base_game;

class TRIBE_Player {
public:
    char _pad_000[0x238];
    void* playerAI;    // +0x238

    void setupPersian(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player::setupPersian(int* p, int type, int unused1, int unused2)
{
    logCommonHistory(this->playerAI, "Setting up as Persians.");

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
            p[0x1D] = 0x64;
        }
    } else {
        p[6] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0x11] = 0x3C;
        p[0x12] = 0x3C;
        p[1] = 0x28;
        p[0xB] = 0x28;
        p[0x14] = 0x28;
        p[0] = 0x14;
        p[0x10] = 0x14;
        p[7] = 0x32;
        p[0x13] = 0x14;
        p[0x34] = 0x64;

        if (type == 0 || type == 1) {
            p[0x5A] = 0xC8;
            p[0x5B] = 0xC8;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x5A] = 0x64;
            p[0x5B] = 0x64;
        }
    }
}
