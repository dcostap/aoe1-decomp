// VA: 00517F30 TRIBE_Player::setupAssyrian | tplayer.cpp:4089-4142
// matches through deathmatch and early non-deathmatch branches; left scratch because configured packet expects one extra padding byte and remaining non-deathmatch constant-register scheduling differs (edx=0x28/0x64 timing).

struct AIModule {
    void __cdecl logCommonHistory(char* msg);
};
struct TRIBE_Game {
    unsigned char deathMatch();
    int difficulty();
};
extern TRIBE_Game* rge_base_game;

struct TRIBE_Player {
    char gap_00[0x238];
    AIModule* playerAI;
    void setupAssyrian(int* param_1, int param_2, int param_3, int param_4);
};

void TRIBE_Player::setupAssyrian(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Assyrians.");
    if (rge_base_game->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x3c] = 100;
            return;
        }
        if (param_2 == 2 || param_2 == 6) {
            param_1[0x16] = 60;
            param_1[0x3c] = 40;
            return;
        }
        if (param_2 == 5 || param_2 == 8) {
            param_1[0x16] = 80;
            param_1[0x3c] = 20;
            return;
        }
        param_1[0x16] = 100;
        return;
    }

    if (rge_base_game->difficulty() < 1) {
        param_1[0x22] = 100;
        return;
    }

    int* p = param_1;
    p[3] = 10;
    p[7] = 10;
    p[9] = 10;
    p[10] = 10;
    p[0x14] = 10;
    p[0x48] = 0x50;
    p[0x49] = 0x50;
    p[0x4a] = 0x50;
    int p2 = param_2;
    p[0x10] = 0x28;
    p[0xb] = 0x28;
    p[6] = 0x14;
    p[0x13] = 0x14;
    p[0x28] = 100;
    p[0x29] = 100;
    if (p2 == 0 || p2 == 1) {
        p[0x4b] = 100;
        p[0x4c] = 100;
    } else if (p2 == 2 || p2 == 6 || p2 == 8 || p2 == 5) {
        p[0x4b] = 50;
        p[0x4c] = 50;
    }
}
