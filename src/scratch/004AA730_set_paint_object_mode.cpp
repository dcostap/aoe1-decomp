// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode (107 B)
// PDB: scr_sed.cpp lines 1541-1560
// Original attempt: explicit this-as-local for register coloring.
// Top-20 scratch retry attempt log:
// try 1: baseline validation: exact size 107B but 98.13% positional diff; edit/resync shows same broad structure shifted.
// try 2: swapped self/game local declaration order; no codegen change.
// try 3: replaced indirect virtual call expression with helper mode_call(game,mode,arg); worsened tail call surface and reduced equal bytes, rolled back.
// try 4: /GX probe; no code/size change, removed flag.
// try 5: inspected original: it preserves incoming this in EDX before loading global rge_base_game into ECX; rebuilt loads global first and keeps this in ECX.
// try 6: confirmed object lookup chain is behaviorally same but register topology differs: original uses EDX for this/world/player/master list, rebuilt uses ECX/EDI.
// try 7: tail call surface differs equivalently: original loads vtable then calls [vtable+0x10], rebuilt loads [game+0x10] then calls [reg]; same virtual slot if stub layout is interpreted as vtable pointer vs direct slot but not byte-local.
// try 8: no-/GX retained as best; /Od not tried because original is optimized FPO/no frame and prior /Od probes in this queue were broad bad matches.
// try 9: accepted_drift review rejected: although high-level behavior is likely same, diff spans nearly whole tiny function and includes call-surface/register topology, not a localized harmless drift.
// try 10: final validation remains exact size 107B, broad mismatch. GIVEUP.

struct RGE_Base_Game {
    void* vtable;
    char pad_04[0x1B4];
    int sub_game_mode;
    char pad_1BC[0x240];
    short master_obj_id;
};

struct RGE_Game_World {
    char pad_00[0x40];
    void** players;
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
        short pn = self->player_num;
        RGE_Player* pl = (RGE_Player*)self->world->players[pn];
        RGE_Master_Static_Object* obj = (RGE_Master_Static_Object*)pl->master_objects[mo_id];

        if (obj != 0 && obj->obj_type == 0x50 && obj->flag != 0) {
            enabled = 1;
        }
    }

    game = rge_base_game;
    if (enabled) {
        (*(void(__stdcall*)(int,int))*((int**)game)[4])(0x15, 0);
    } else {
        (*(void(__stdcall*)(int,int))*((int**)game)[4])(8, game->sub_game_mode);
    }
}
