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
// - Rebuilt with the shared AIModule/RGE_Base_Game/TRIBE_Game/TRIBE_Player
//   surface, and tested a reused 50->100 value plus an early map_type local;
//   both stayed in the same 320-byte basin. Keep the direct stores.
// - Direct outer else-if difficulty syntax, matching exact setup donors, also
//   stayed identical; retain the simpler period-plausible branch shape.
// - This session exhausted 10 meaningful hypotheses: positive difficulty guard
//   worsened layout (+1 byte); scoped/function/branch-local pointer aliases,
//   named difficulty, register pointer, and explicit low return were duplicate
//   320-byte codegen; duplicated common stores grew to 405 bytes; the original
//   tplayer.cpp-style player_difficulty helper emitted an extra direct call.
// - Restored the audited clean source. Best current evidence remains 320/323
//   bytes, first mismatch 0051884A: VC5 keeps the param_1 load after jge and
//   colors 100/50 plus the map_type reload differently from the oracle.

// Main-agent audit confirmed the shared canonical game/player/AI ownership;
// direct civilization table stores remain authoritative.
class AIModule {
public:
    void logCommonHistory(char* message, ...);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    int difficulty();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    virtual ~TRIBE_Game();
    unsigned char deathMatch();
};

extern TRIBE_Game* rge_base_game;

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x234];
    AIModule* playerAI;
};

class TRIBE_Player : public RGE_Player {
public:
    void setupYamato(int* param_1, int param_2, int param_3, int param_4);
};

void TRIBE_Player::setupYamato(int* param_1, int param_2, int param_3, int param_4)
{
    this->playerAI->logCommonHistory("Setting up as Yamato.");

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
    } else if (rge_base_game->difficulty() < 1) {
        param_1[0x27] = 100;
    } else {
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
}
