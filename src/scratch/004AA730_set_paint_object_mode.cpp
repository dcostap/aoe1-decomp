// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode()
// PDB: scr_sed.cpp lines 1541-1560 (107 bytes, 39 asm lines)
// Default flags. No inline asm/hacks.
//
// === ACCEPTED_DRIFT CANDIDATE ===
// Remaining diff: pure benign register allocation swap across all callee-saved
// registers and the this ECX register. Every operation, constant, offset,
// branch target, and indirect call is equivalent; only which register holds
// which pointer/value differs.
//
// Original register assignment:
//   ECX = rge_base_game (loaded once, stays for game->master_obj_id/vtable/1B8)
//   EDX = this (saved from ECX at entry, used for player_num/world pointer chain)
//   ESI = enabled flag (0/1)
//   EDI = player_num (temporary for [edx+edi*4])
//   EAX = master_obj_id, object pointer (ephemeral)
//
// Rebuilt (all variants converge to one of several basins):
//   EDX/ESI = rge_base_game (different families choose different registers)
//   ECX = this (kept instead of saved)
//   Rest: cascading differences from the swapped primary registers
//
// The source-level cause: VC5 makes a fixed register-allocation decision about
// which register to use for `rge_base_game` and `this`. Original chooses game=ECX
// and saves this=EDX; VC5 always keeps this=ECX and puts game elsewhere. No
// declaration order, local pattern, or flag combination overrides this.
//
// The pointer chain structure, condition check sequence, indirect vtable call
// targets, constants (0x15, 0x50, 0xFFFF, 8), branch polarities, and function
// size (107 bytes) are all identical.
//
// Attempt log (10+ focused variants):
// - `RGE_Base_Game* game = rge_base_game;` as first declaration: game in EDX, this in ECX
// - Macro-only rge_base_game (no local): same basin with increased register shuffling
// - `this->player_num` accessed before `game`: game in ESI, enabled in EDI  
// - Various declaration orders, local patterns, extern global: all produce swapped registers
// - Flags /Oa, /Og, /Ot, /Ox: no change
// - variant_lab could probe thousands but the register swap is structural — no source
//   axis is known to influence VC5's primary register choice
//
// Left in scratch: see notes above. Not suitable for exact match.

struct RGE_Base_Game {
    void* vtable;             // +0x00
    char pad_04[0x1B4];       // to +0x1B8
    int sub_game_mode;        // +0x1B8
    char pad_1BC[0x240];      // to +0x3FC
    short master_obj_id;      // +0x3FC
};

struct RGE_Game_World {
    char pad_00[0x40];
    void** players;
};

struct RGE_Player {
    char pad_00[0x24];
    void** master_objects;    // +0x24
};

struct TRIBE_Screen_Sed {
    char pad_000[0x4B8];
    short player_num;         // +0x4B8
    char pad_4BA[0x46E];      // to +0x928
    RGE_Game_World* world;    // +0x928

    void set_paint_object_mode();
};

struct RGE_Master_Static_Object {
    void* vtable;
    unsigned char obj_type;    // +4
    char pad_05[0x167];        // to +0x16C
    unsigned char flag;
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

void TRIBE_Screen_Sed::set_paint_object_mode() {
    RGE_Base_Game* game = rge_base_game;
    short mo_id = game->master_obj_id;
    int enabled = 0;

    if (mo_id != -1) {
        short pn = this->player_num;
        RGE_Player* pl = (RGE_Player*)this->world->players[pn];
        RGE_Master_Static_Object* obj = (RGE_Master_Static_Object*)pl->master_objects[mo_id];

        if (obj != 0 && obj->obj_type == 0x50 && obj->flag != 0) {
            enabled = 1;
        }
    }

    if (enabled) {
        (*(void(__stdcall*)(int,int))*((int**)game)[4])(0x15, 0);
    } else {
        (*(void(__stdcall*)(int,int))*((int**)game)[4])(8, game->sub_game_mode);
    }
}
