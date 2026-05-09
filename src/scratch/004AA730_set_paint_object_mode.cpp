// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode()
// PDB source: scr_sed.cpp lines 1541-1560
// Default flags
//
// BLOCKER: behavior and field offsets are understood, but VC5 stays in the
// opposite this/global register basin. Original begins `mov edx,ecx; push esi;
// mov ecx,[rge_base_game]`, preserving `this` in EDX and game in ECX through the
// master-object checks. Natural source (macro or extern global, with/without
// self locals) loads game into EDX first and keeps `this` in ECX, cascading the
// pointer chain through EDI/ECX instead of EDX/EDI. Tail variants also either
// hoist the vtable load before `test esi,esi` or use the wrong register for the
// disabled branch call shape.
//
// Attempt log:
// 1. Original scratch with macro global: behavior right, but game loaded first into EDX; no initial `mov edx,ecx`.
// 2. extern `rge_base_game` plus explicit self local: same game-in-EDX/this-in-ECX basin.
// 3. volatile self local forced a stack spill and worse prologue.
// 4. branch-local vs preloaded vtable tail: preloaded tail gives smallest edit diff, branch-local closer to original test placement but larger edit diff.
// 5. variant_lab over macro/extern globals, no/local/ref self, this/self/split access, branch/preloaded vtable tails, and vc5-small flags: no exact. Only four asm families; all first mismatch at offset 1 due to missing `mov edx,ecx`.

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

class RGE_Base_Game {
public:
    void* vtable;
    char pad_04[0x1B4];
    int sub_game_mode;
    char pad_1BC[0x240];
    short master_obj_id;
};

class TRIBE_Screen_Sed {
public:
    char pad_00[0x4B8];
    short player_num;
    char pad_4BA[0x46E];
    void* world;

    void set_paint_object_mode();
};

class RGE_Master_Static_Object {
public:
    void* vtable;
    unsigned char type;
    char pad_05[0x167];
    unsigned char some_flag;
};

void TRIBE_Screen_Sed::set_paint_object_mode() {
    RGE_Base_Game* game = rge_base_game;
    int enabled = 0;
    int mo_id = game->master_obj_id;
    if (mo_id != -1) {
        short pn = this->player_num;
        void* pp = *(void**)((char*)this->world + 0x40);
        void* ep = *(void**)((int*)pp + pn);
        RGE_Master_Static_Object** masterObjs = *(RGE_Master_Static_Object***)((int*)ep + 9);
        RGE_Master_Static_Object* obj = masterObjs[mo_id];
        if (obj != 0 && obj->type == 0x50 && obj->some_flag != 0) {
            enabled = 1;
        }
    }
    int* vt = (int*)game->vtable;
    if (enabled) {
        ((void(__stdcall*)(int, int))vt[4])(0x15, 0);
    } else {
        ((void(__stdcall*)(int, int))vt[4])(8, game->sub_game_mode);
    }
}
