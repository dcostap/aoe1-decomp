// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode (107 B)
// PDB: scr_sed.cpp lines 1541-1560
// Attempt: explicit this-as-local for register coloring

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
