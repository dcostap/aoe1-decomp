// VA: 004AA730 TRIBE_Screen_Sed::set_paint_object_mode | scr_sed.cpp:1541-1560

class RGE_Static_Object {
public:
    char gap_00[4];
    unsigned char type;
    char gap_05[0x16C - 0x05];
    unsigned char some_flag;
};

class TPanel {
public:
    char gap_00[0xF4];
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x478 - 0xF4];
};

class TScreenPanel : public TEasy_Panel {
public:
};

class RGE_Base_Game {
public:
    char gap_00[0x1B8];
    int sub_game_mode;
    char gap_1BC[0x3FC - 0x1BC];
    short master_obj_id;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    char gap_478[0x4B8 - 0x478];
    short player_num;
    char gap_4BA[0x928 - 0x4BA];
    void* world;

    void set_paint_object_mode(void);
};

void TRIBE_Screen_Sed::set_paint_object_mode(void) {
    TRIBE_Screen_Sed* self = this;
    int enabled = 0;
    RGE_Base_Game* game = rge_base_game;
    if (game->master_obj_id != -1) {
        short pn = self->player_num;
        void** pp = *(void***)((char*)self->world + 0x40);
        void* ep = pp[pn];
        RGE_Static_Object** objs = *(RGE_Static_Object***)((char*)ep + 0x24);
        RGE_Static_Object* object = objs[game->master_obj_id];
        if (object != 0 && object->type == 0x50 && object->some_flag != 0) {
            enabled = 1;
        }
    }
    if (enabled) {
        (*(void(__stdcall**)(int, int))(*(int*)game + 0x10))(0x15, 0);
    } else {
        (*(void(__stdcall**)(int, int))(*(int*)game + 0x10))(8, game->sub_game_mode);
    }
}
