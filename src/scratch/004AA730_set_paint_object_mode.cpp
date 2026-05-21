// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode (107 B)
// PDB: scr_sed.cpp lines 1541-1560
// Attempt log:
// try 1: inherited scratch baseline was exact size but broad 98.13% diff; call surface used a fake indirect slot and global reload.
// try 2: changed RGE_Base_Game to a real virtual surface; tail calls now match exactly and diff dropped to 11 bytes / 10.28%.
// try 3: direct indexed expression self->world->players[self->player_num] kept same remaining mismatch.
// try 4: int player-number local kept same remaining mismatch.
// try 5: explicit players local kept same remaining mismatch.
// try 6: volatile player_num forced source load order but destroyed register allocation; rolled back.
// try 7: volatile self forced stack home/prologue and worsened badly; rolled back.
// try 8: final remaining mismatch is localized to lookup-chain register/load order only: original loads player_num into EDI before world into EDX, rebuilt loads world into EDI then player_num into EDX.
// try 9: typed world->players as RGE_Player** instead of void**; no codegen change.
// try 10: collapsed lookup to one direct indexed expression; no codegen change.
// try 11: made player_num field volatile; no improvement for the lookup hunk and with some shapes perturbed the whole register allocation, rolled back.
// try 12: raw offset read *(short*)((char*)self+0x4B8) for player_num; optimizer still reordered world load before index load.
// try 13: explicit world local and reversed pointer addition *(pn + players); no improvement; explicit world local with volatile field worsened prologue/register allocation.
// try 14: short pn local and direct players[pn] access; same 11-byte localized lookup-order mismatch.
// try 15: raw char* pointer arithmetic for world/player lookup; optimizer still hoisted world load before player_num.
// try 16: volatile short pointer for player_num forced source read order but changed prologue/register allocation and worsened to 26 bytes; rolled back.
// try 17: register int pn with explicit world local; no change, still world in EDI before player_num in EDX.
// try 18: volatile world load after pn forced source order but destroyed prologue/register allocation; rolled back.
// try 19: raw intptr chain with separate pn/world/players/player/masters locals; optimizer kept same reordered lookup hunk.
// try 20: mutating self to world after pn; no change.
// try 21: one raw direct expression with pn first; no change.
// try 22: C++ reference to self->world after pn; no change.
// try 23: function-scope local declaration order pn/w/obj; no change.
// try 24: players and player locals after pn; no change.
// try 25: /O1 tested as a flag probe but object was too small/wrong family; /O2 without /Oy, /Ob1, /Gs, and /Gr all kept same 11-byte hunk.
// try 26: direct this expression without self alias; no change.
// try 27: using game->master_obj_id directly instead of mo_id local destroyed early register/branch shape; rolled back.
// try 28: bool enabled changed the whole prologue/result basin; rolled back.
// try 29: nested ifs with short pn local; no change in lookup hunk.
// try 30: comma pn/world assignment and split pointer arithmetic variants; no change.
// try 31: register pn plus raw +0x40 players load; no change, same 11-byte hunk.
// try 32: pointer-to-players, C++ reference world, raw all-char chain, precomputed slot, short-copy pn, declaration-split assignments, and reversed w/pn declarations; all kept same 11-byte hunk.
// try 33: const int pn kept same 11-byte hunk.
// try 34: unsigned short pn destroyed prologue/register allocation and worsened to broad mismatch; rolled back.
// GIVEUP: behavior/calls/size match, but not exact; not proposing accepted_drift because remaining drift is a localized address-generation/register-topology hunk in the object lookup (world pointer vs player index register/load order), not a tiny harmless encoding swap.

struct RGE_Base_Game {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void set_game_mode(int mode, int arg);
    char pad_04[0x1B4];
    int sub_game_mode;
    char pad_1BC[0x240];
    short master_obj_id;
};

struct RGE_Player;

struct RGE_Game_World {
    char pad_00[0x40];
    RGE_Player** players;
};

struct RGE_Player {
    char pad_00[0x24];
    void** master_objects;
};

struct TRIBE_Screen_Sed {
    char pad_000[0x4B8];
    short player_num;
    char pad_4BA[0x46E];
    RGE_Game_World* world;
    void set_paint_object_mode();
};

struct RGE_Master_Static_Object {
    void* vtable;
    unsigned char obj_type;
    char pad_05[0x167];
    unsigned char flag;
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)


void TRIBE_Screen_Sed::set_paint_object_mode() {
    TRIBE_Screen_Sed* self = this;
    RGE_Base_Game* game = rge_base_game;
    int mo_id = (int)(short)game->master_obj_id;
    int enabled = 0;

    if (mo_id != -1) {
        int pn = (int)self->player_num;
        RGE_Master_Static_Object* obj = (RGE_Master_Static_Object*)(*(pn + self->world->players))->master_objects[mo_id];

        if (obj != 0 && obj->obj_type == 0x50 && obj->flag != 0) {
            enabled = 1;
        }
    }

    if (enabled) {
        game->set_game_mode(0x15, 0);
    } else {
        game->set_game_mode(8, game->sub_game_mode);
    }
}
