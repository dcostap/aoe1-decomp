// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode()
// PDB source: scr_sed.cpp lines 1541-1560
// Default flags
//
// attempt log:
// Multiple attempts, all 79-80/107 matching.
// Root cause: original saves this→edx, loads game→ecx first thing.
// My VC5 loads game first and loses this→ecx, cascading reg alloc through 6
// pointer dereferences. Needs full TU context (scr_sed.cpp) to match.
//
// Also: call [reg+0x10h] (indirect through memory) vs mov reg,[reg+0x10h]; call reg
// (through register). Minor instruction encoding difference.
//
// Fields: player_num @+0x4B8 (short), world @+0x928, game @0x62C574 (global),
// game->sub_game_mode @+0x1B8, game->master_obj_id @+0x3FC (short).
// World->players @+0x40, player->master_objects @+0x24.
// Object type @+4 (byte), flag @+0x16C (byte).

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
