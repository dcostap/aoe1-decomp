// VA: 0052E220 TRIBE_World::data_load_players_type
// PDB source: tworld.cpp lines 187-197
// Attempt log:
// rewrite 2026-05-19: replaced empty stub with packet-observed EH constructor/load behavior.
// try 1: baseline empty stub built 16B; rewrote full behavior and added /GX flag.
// try 2: full behavior with short params, TRIBE_Master_Player new(0x2C), base fallback call, and players pointer at +0x48 gives exact size 141B but MISMATCH 29 bytes / 20.57%.
// try 3: changed p2 dispatch to int temp with predecrement; worsened parameter width/registers.
// try 4: added explicit players local; kept (needed pointer load at +0x48) but register choice remains ECX/EDX swapped vs original.
// try 5: tried int p2 signature; worsened compare width and branch offsets, rolled back.
// try 6: tried volatile short p2 local to delay compare; worsened stack traffic and layout, rolled back.
// GIVEUP: best remaining drift is compiler scheduling/register topology: rebuilt loads p2 before FS install and compares AX directly, while original installs FS then loads p2 into ECX, movsx EAX,CX, dec EAX. Tail store is behaviorally equivalent but ECX/EDX swapped (`mov ecx,[esi+48]` vs original `mov edx,[esi+48]`). Not accepted_drift due EH/prologue and register-topology differences.

struct FILE;

class TRIBE_Master_Player {
public:
    char gap[0x2C];
    TRIBE_Master_Player(FILE* f);
};

class RGE_Game_World {
public:
    char gap_00[0x48];
    void** players;
    void data_load_players_type(short p1, short p2, FILE* f);
};

class TRIBE_World : public RGE_Game_World {
public:
    void data_load_players_type(short p1, short p2, FILE* f);
};

void TRIBE_World::data_load_players_type(short p1, short p2, FILE* f)
{
    if ((int)p2 != 1) {
        RGE_Game_World::data_load_players_type(p1, p2, f);
        return;
    }

    TRIBE_Master_Player* player = new TRIBE_Master_Player(f);
    void** players = this->players;
    players[p1] = player;
}
