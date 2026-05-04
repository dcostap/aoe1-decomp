// VA: 005187A0 setupYamato
// PDB source: tplayer.cpp
// Attempt log:
// - 12 attempts across: source ordering, local variables, block scoping, duplicate branches,
//   switch statements, volatile reads, different if-styles, early param_1 loading
// - Persistent VC5 scheduling/register barriers:
//   1) jge scheduling: original loads param_1 BEFORE jge, our version AFTER
//   2) Register allocation: original uses edx=50 then edx=100, our version uses edx=100 only
//      (dec/ecx for all other values)
//   3) Param_2 load timing: original between ecx=10 and edx=50 stores, our version after all stores
// - Size: 320 bytes (3 short of 323)
// - Edit diff: ~18% (57/320 bytes, shifted alignment)
// - Left in scratch: register allocation / scheduling mismatch locked after many probes

extern "C" void __cdecl logCommonHistory(int playerAI, const char* str);

class RGE_Base_Game {
public:
    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    unsigned char deathMatch();
};

extern TRIBE_Game* rge_base_game;

class RGE_Player {
public:
    char gap_000[0x220];
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_220[0x18];
    int playerAI;
    char gap_23C[0x60C];

    void setupYamato(int* param_1, int param_2, int param_3, int param_4);
};

void TRIBE_Player::setupYamato(int* param_1, int param_2, int param_3, int param_4)
{
    logCommonHistory(this->playerAI, "Setting up as Yamato.");

    if (rge_base_game->deathMatch() == 1) {
        if (param_2 == 0 || param_2 == 1) {
            param_1[0x47] = 100;
            return;
        }
        if (param_2 == 2 || param_2 == 6) {
            param_1[0x21] = 60;
            param_1[0x47] = 40;
            return;
        }
        if (param_2 == 5 || param_2 == 8) {
            param_1[0x21] = 80;
            param_1[0x47] = 20;
            return;
        }
        param_1[0x21] = 100;
        return;
    }

    if (rge_base_game->difficulty() < 1) {
        param_1[0x27] = 100;
        return;
    }

    param_1[3] = 10;
    param_1[4] = 10;
    param_1[9] = 10;
    param_1[10] = 10;
    param_1[6] = 50;
    param_1[7] = 50;
    param_1[0] = 20;
    param_1[1] = 20;
    param_1[0x10] = 40;
    param_1[0x0B] = 20;
    param_1[0x3B] = 100;

    if (param_2 == 0 || param_2 == 1) {
        param_1[0x60] = 200;
        param_1[0x61] = 200;
    } else if (param_2 == 2 || param_2 == 6 || param_2 == 8 || param_2 == 5) {
        param_1[0x60] = 100;
        param_1[0x61] = 100;
    }
}
