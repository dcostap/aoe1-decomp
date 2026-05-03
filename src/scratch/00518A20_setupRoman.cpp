// VA: 00518A20, TRIBE_Player::setupRoman, 303 bytes
// Source: tplayer.cpp lines 4545-4589
// FLAGS: default

#include <stddef.h>

typedef unsigned char uchar;

extern "C" void __cdecl logCommonHistory(void* target, const char* msg);
extern "C" uchar __fastcall deathMatch_fn(void* game);

class RGE_Player {
public:
    char pad_00[0x238];
    void* playerAI;  // +0x238
};

class TRIBE_Player : public RGE_Player {
public:
    void setupRoman(int* param_1, int param_2, int param_3, int param_4);
};

extern void* rge_base_game;  // 0x0062C574

void TRIBE_Player::setupRoman(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Roman.");

    if (deathMatch_fn(rge_base_game) == 1) {
        // Deathmatch path
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x7C] = 0x64;
        } else if (param_2 == 2 || param_2 == 6) {
            param_1[0x78] = 0x3C;
            param_1[0x7C] = 0x28;
        } else if (param_2 == 5 || param_2 == 8) {
            param_1[0x78] = 0x50;
            param_1[0x7C] = 0x14;
        } else {
            param_1[0x78] = 0x64;
        }
    } else {
        // Non-deathmatch path - common unconditional stores
        // Use the same register allocation as original:
        // ecx stores 0x0A for first batch, then reused for 0x14, then 0x50
        // edx stores 0x14 first, then 0x50, then 0x64/0x3C are immediates
        int v10 = 0x0A;
        param_1[0] = v10;
        param_1[6] = v10;
        param_1[9] = v10;
        param_1[10] = v10;
        param_1[0x13] = v10;
        param_1[0x14] = v10;

        int p2 = param_2;
        int v14 = 0x14;
        param_1[3] = v14;
        param_1[4] = v14;
        int v50 = 0x50;
        param_1[0x0B] = v50;
        param_1[0x72] = v50;
        param_1[0x70] = 0x64;
        param_1[0x71] = 0x3C;

        // param_2 conditional
        if (p2 == 0 || p2 == 1) {
            param_1[0x73] = 0xC8;
            param_1[0x74] = 0xC8;
        } else if (p2 == 2 || p2 == 6 || p2 == 8 || p2 == 5) {
            param_1[0x73] = 0x64;
            param_1[0x74] = 0x64;
        }
    }
}
