// 00518B50 TRIBE_Player::setupCarthaginian (tplayer.cpp:4594-4640, 307B)
// Sets up Carthaginian civilization parameters based on game mode and game type.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void logCommonHistory(void* aimodule, char* msg);

struct TRIBE_Game {
    char _gap_00[4];
    unsigned char deathMatch();
};

extern "C" { extern TRIBE_Game* rge_base_game; }

struct TRIBE_Player {
    char _pad_00[0x238];
    void* playerAI;

    void setupCarthaginian(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player::setupCarthaginian(int* p, int type, int unused1, int unused2) {
    logCommonHistory(playerAI, "Setting up as Carthaginian.");

    if (rge_base_game->deathMatch() == 1) {
        if (type == 0 || type == 1) {
            p[0x79] = 100;
        } else if (type == 2 || type == 6) {
            p[0x75] = 0x3C;
            p[0x79] = 0x28;
        } else if (type == 5 || type == 8) {
            p[0x75] = 0x50;
            p[0x79] = 0x14;
        } else {
            p[0x75] = 100;
        }
    } else {
        p[0] = 10;
        p[1] = 10;
        p[0x10] = 10;
        p[7] = 10;
        p[9] = 10;
        p[10] = 10;
        p[11] = 10;
        p[0x11] = 0x3C;
        p[0x12] = 0x3C;
        p[3] = 0x46;
        p[0x62] = 0x50;
        p[99] = 0x50;
        p[4] = 0x32;
        p[6] = 0x1E;

        if (type == 0 || type == 1) {
            p[100] = 200;
            p[101] = 200;
        } else if (type == 2 || type == 6 || type == 8 || type == 5) {
            p[100] = 100;
            p[101] = 100;
        }
    }
}
