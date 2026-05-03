// VA: 00517E10, TRIBE_Player::setupBabylonian, 275 bytes
// Source: tplayer.cpp lines 4046-4084
// Attempt log:
// - v1: switch → jump table (modern compiler optimization)
// - v2: if-else chains → should match cmp/je pattern
// FLAGS: /nologo /c /O2 /Oy

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
