// VA: 00517E10, TRIBE_Player::setupBabylonian, 275 bytes
// Source: tplayer.cpp lines 4046-4084
// BINARY NOTE: The PDB line band owns TRIBE_Player::setupBabylonian and the
// exact body boundary is 00517E10-00517F23.  The function is __thiscall and
// returns with the four dword stack arguments removed.
// BINARY NOTE: The first call reads playerAI at +0x238 and calls
// logCommonHistory.  The second call is rge_base_game->deathMatch().  The
// death-match result is tested before any civilization-table write.
// BINARY NOTE: p is an int table.  The observed dword stores, constants,
// source order, branch order, and early-return fault order are intentional.
// Attempt log:
// - v1: switch → jump table (modern compiler optimization)
// - v2: if-else chains → should match cmp/je pattern
// Exact-finish: The unchanged natural source rebuilt with Result: MATCH and
// 0.0000% strict positional difference on 2026-08-23.  No source or flag
// delta was needed in this claim, so there was no independent exact change to
// revert.  The fresh check proved the owner symbol, boundary, ordered calls,
// dword stores, and return paths.  Nine tplayer anchors were rebuilt fresh:
// 00517B90, 00517E10, 005181C0, 005188F0, 00518B50, 00518DD0, 00518F00,
// 005192F0, and 00519320; each returned MATCH with 0.0000% difference.
// FLAGS: /nologo /c /O2 /Oy

#include "../../include/tplayer_context.h"

#if 0
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

    void setupBabylonian(int* p, int type, int unused1, int unused2);
};

#endif

void TRIBE_Player::setupBabylonian(int* p, int type, int unused1, int unused2)
{
    logCommonHistory(this->playerAI, "Setting up as Babylonians.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[61] = 100;
        } else if (type == 2 || type == 6) {
            p[23] = 60;
            p[61] = 40;
        } else if (type == 5 || type == 8) {
            p[23] = 80;
            p[61] = 20;
        } else {
            p[23] = 100;
        }
    } else {
        p[1] = 10;
        p[6] = 10;
        p[9] = 10;
        p[11] = 10;
        p[0] = 20;
        p[19] = 40;
        p[20] = 40;
        p[16] = 30;
        p[42] = 100;
        p[43] = 100;
        p[3] = 20;
        p[10] = 20;

        if (type == 0 || type == 1)
            p[77] = 60;
        else if (type == 2 || type == 6 || type == 8 || type == 5)
            p[77] = 30;
    }
}
