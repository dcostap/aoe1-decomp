// 00517B90 TRIBE_Player::setupEgyptian (tplayer.cpp:3943-3987, 318B)
// Sets up Egyptian civilization parameters based on game mode and game type.
// FLAGS: /nologo /c /O2 /Oy

#include "../../include/tplayer_context.h"

#if 0
extern "C" void logCommonHistory(void* aimodule, char* msg);

struct TRIBE_Game {
    char _gap_00[4];
    unsigned char deathMatch();
    int difficulty();
};

extern "C" { extern TRIBE_Game* rge_base_game; }

struct TRIBE_Player {
    char _pad_00[0x238];
    void* playerAI;

    void setupEgyptian(int* p, int type, int unused1, int unused2);
};

#endif

void TRIBE_Player::setupEgyptian(int* p, int type, int unused1, int unused2)
{
    logCommonHistory(playerAI, "Setting up as Egyptians.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x3F] = 100;
        } else if (type == 2 || type == 6) {
            p[0x19] = 0x3C;
            p[0x3F] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x19] = 0x50;
            p[0x3F] = 0x14;
        } else {
            p[0x19] = 100;
        }
    } else if (rge_base_game->difficulty() < 1) {
        p[0x23] = 100;
    } else {
        p[3] = 10;
        p[9] = 10;
        p[10] = 10;
        p[0x11] = 0x28;
        p[0x12] = 0x28;
        p[0x2E] = 100;
        p[0x13] = 0x32;
        p[0x14] = 0x32;
        p[0x2F] = 100;
        p[0x50] = 100;
        p[0x51] = 0x1E;
        p[0x52] = 0x14;

        if (type == 0 || type == 1) {
            p[0x53] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x53] = 100;
        }
    }
}
