// VA: 0052E220 TRIBE_World::data_load_players_type(short, short, FILE*)
// PDB source: tworld.cpp lines 187-197 (141 B, 44 asm)
// FLAGS: default
//
// Attempt log (2026-05-19):
// try 5: Now have movsx/dec/je! Load before [fs:0] scheduling + register assignment left.
// try 6: Cast to force ecx->eax register flow
// ACCEPTED_DRIFT 2026-05-19: approved localized behavior-equivalent EH/register scheduling drift.
// Rebuilt loads p2 before installing FS while original loads it immediately after; no throwing
// operation occurs between. Remaining differences are temp-register choices for compare/call
// setup and equivalent base/index register swap in the final store. Calls, predicates, EH
// cleanup, stack cleanup, allocation size, constructor call, and memory effects are identical.

struct FILE;

void* operator new(unsigned int size);

class RGE_Master_Player {
public:
    char gap_00[0x2C];
    RGE_Master_Player(FILE* f);
};

class TRIBE_Master_Player : public RGE_Master_Player {
public:
    TRIBE_Master_Player(FILE* f);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    void** players;
    short master_player_num;
    char gap_46[2];
    void** master_players;
    void data_load_players_type(short p1, short p2, FILE* f);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x124 - 0x4C];
    void data_load_players_type(short p1, short p2, FILE* f);
};

void TRIBE_World::data_load_players_type(short p1, short p2, FILE* f)
{
    if ((int)(short)p2 - 1 != 0) {
        RGE_Game_World::data_load_players_type(p1, p2, f);
        return;
    }

    this->master_players[p1] = new TRIBE_Master_Player(f);
}
