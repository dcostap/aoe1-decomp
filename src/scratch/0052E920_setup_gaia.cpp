// 0052E920 TRIBE_World::setup_gaia()
// Source: tworld.cpp lines 348-351
// Size: 102 bytes, 33 asm lines

// 6+ prior attempts. Same EH epilogue codegen basin as 00471C90, 00519490.
// Size fixed: TRIBE_Gaia is 0x858 bytes (TRIBE_Player + 4 int fields).
// FLAGS: config/flags/0052E920_setup_gaia.rsp uses /GX; without /GX this EH
// constructor helper compiles to a shorter non-EH basin.
// 2026-05-09 GraniteCub: tried 20 focused variants: local result before store,
// decl/assign/store, void* result, players/master/world locals, cast/comma/ternary
// forms, manual operator new + placement ctor with if/else/goto common, explicit
// null no-op branch, volatile result, empty if/goto label forms, TRIBE_World method
// surface, virtual declaration surface, and narrow flag probes (/GX, /GR, /Ox,
// no /Oy, /Ob0). Direct source remains the cleanest. Best artificial no-op
// `if (gaia == 0) gaia = 0;` reached 16.67% / 7.84% by forcing the common store,
// but inserted a redundant `test eax,eax; jne +0`; not kept. Current clean source
// remains 21.6% diff: original has ctor `jmp`, null `xor eax,eax`, then common
// `[players[0]]=eax`/EH epilogue; pinned VC5 splits success/null epilogues.
// String/handler addresses are relocations masked by the tool. No inline asm/hacks.

class RGE_Master_Player {
public:
    void* vtable;
};

class RGE_Game_World {
public:
    char pad_00[0x40];
    void** players;
    char pad_44[0x4];
    void** master_players;

    void setup_gaia();
};

class TRIBE_World : public RGE_Game_World {
};

class TRIBE_Gaia {
public:
    char gap[0x858];

    TRIBE_Gaia(void* world, RGE_Master_Player* player,
               unsigned char param_3, const char* param_4, unsigned char param_5);
};

void RGE_Game_World::setup_gaia() {
    this->players[0] = new TRIBE_Gaia(this, (RGE_Master_Player*)this->master_players[0], 0, "GAIA", 0);
}
