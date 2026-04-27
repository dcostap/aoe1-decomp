// VA: 00542480 | RGE_Game_World::setup_gaia() | World.cpp:1156-1159 | 104 bytes
//
// Attempt log:
// [1] Without /GX: no EH frame, only 64 bytes. Need /GX.
// [2] With /GX (per-function rsp): EH frame ok, but RGE_Player had size 0 (wrong sizeof).
// [3] Fixed sizeof(RGE_Player)=0x220. 21% diff. EH frame, alloc size, ctor args all correct.
//     Remaining: epilogue ordering (pop esi before vs after store); EH restore offset differs.
// [4] Explicit operator new + placement new (custom operator). No EH frame (64 bytes).
// [5] Explicit ctor call (RGE_Player::RGE_Player). No EH frame (64 bytes).
// [6] Split decl/assign. Same 21% diff as [3].
//
// Remaining gap is a cascading epilogue structure difference:
// - Original: `mov ecx,[esi+40h]; pop esi; mov [ecx],eax` (pop before store)
// - Rebuilt:  `mov ecx,[esi+40h]; mov [ecx],eax; ...; pop esi` (pop after store)
// This shifts EH restore offset ([esp+4] vs [esp+8]) and pushes fail path code past
// the 104-byte boundary, truncating it.
// /GX per-function rsp at config/flags/00542480_setup_gaia.rsp.

#include "../../include/game_types.h"

class RGE_Player {
public:
    char _gap_00[0x220];
    RGE_Player(RGE_Game_World* world, void* masterPlayerInfo, int isGaia,
               const char* name, int flag, int isActive);
};

class RGE_Game_World {
public:
    char _gap_00[0x40];
    void** players;               // +0x40
    char _gap_44[0x04];
    void** master_players;        // +0x48

    void setup_gaia();
};

void RGE_Game_World::setup_gaia() {
    RGE_Player* p = new RGE_Player(this, *master_players, 0, "GAIA", 0, 1);
    *players = p;
}
