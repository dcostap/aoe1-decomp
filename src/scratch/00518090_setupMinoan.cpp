// 00518090 TRIBE_Player::setupMinoan (tplayer.cpp:4147-4195, 299B)
// Sets up Minoan civilization parameters based on game mode, difficulty, and game type.
//
// Left in scratch: 293/299 bytes match (98.0%), edit diff 4.0%.
// Remaining diff is VC5 scheduling: `mov eax,[esp+4]` (load p) is after `jge`
// in rebuilt vs before `jge` in original. VC5 loads p once before the branch
// (shared between easy/normal paths) in original but duplicates the load in
// rebuilt (separate load for each path). All field offsets, store values,
// string refs, and control flow verified correct.
// FLAGS: /nologo /c /O2 /Oy

extern "C" void logCommonHistory(void* aimodule, char* msg);

struct RGE_Base_Game4 {
    char _gap_00[4];
    int difficulty();
    unsigned char deathMatch();
};

extern "C" { extern RGE_Base_Game4* rge_base_game; }

struct TRIBE_Player4 {
    char _pad_00[0x238];
    void* playerAI;

    void setupMinoan(int* p, int type, int unused1, int unused2);
};

void TRIBE_Player4::setupMinoan(int* p, int type, int unused1, int unused2) {
    logCommonHistory(playerAI, "Setting up as Minoans.");

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
    } else {
        if (rge_base_game->difficulty() < 1) {
            p[0x25] = 100;
            return;
        }

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
