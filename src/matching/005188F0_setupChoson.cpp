// 005188F0 TRIBE_Player::setupChoson (tplayer.cpp:4495-4540, 298B)
// Sets up Choson civilization parameters based on game mode and game type.
// FLAGS: /nologo /c /O2 /Oy

#include "../../include/tplayer_context.h"

#if 0
extern "C" void logCommonHistory(void* aimodule, char* msg);

struct TRIBE_Game {
    char _gap_00[4];
    unsigned char deathMatch();
};

extern "C" { extern TRIBE_Game* rge_base_game; }

struct TRIBE_Player3 {
    char _pad_00[0x238];
    void* playerAI;

    void setupChoson(int* p, int type, int unused1, int unused2);
};

#endif

void TRIBE_Player::setupChoson(int* p, int type, int unused1, int unused2) {
    logCommonHistory(playerAI, "Setting up as Choson.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x3E] = 100;
        } else if (type == 2 || type == 6) {
            p[0x18] = 0x3C;
            p[0x3E] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x18] = 0x50;
            p[0x3E] = 0x14;
        } else {
            p[0x18] = 100;
        }
    } else {
        p[1] = 10;
        p[0x10] = 10;
        p[3] = 10;
        p[7] = 0x1E;
        p[9] = 0x1E;
        p[10] = 0x1E;
        p[0] = 0x14;
        p[6] = 0x14;
        p[0xB] = 0x46;
        p[0x13] = 0x32;
        p[0x14] = 0x5A;
        p[0x2C] = 100;
        p[0x2D] = 100;

        if (type == 0 || type == 1) {
            p[0x4E] = 200;
            p[0x4F] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[0x4E] = 100;
            p[0x4F] = 100;
        }
    }
}
