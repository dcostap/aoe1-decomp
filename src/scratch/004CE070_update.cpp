// VA 004CE070 TRIBE_Action_Convert::update
// tact_cnv.cpp:311-522
// Attempt log:
// 1: Natural first pass from packet asm/decompiler, with local class/vtable surfaces for observed offsets.
// 2: Fixed RGE_Player layout to expose world at +0x3c, player_id at +0x4a, elapsed at +0x84, conversion_kind at +0x105.
// 3: Fixed RGE_World fields to map +0x38/+0x3c/+0x40 map coordinates and +0x3c player/world object chain used by object lookup.
// 4: Fixed object sprite id at +0x04, type at +0x08, player at +0x0c, angle at +0x26, conversion_time at +0x30, status at +0x48.
// 5: Fixed player relation prototype from short to int so VC5 emits original movsx word [target_player+4a] before call instead of mov ax/push eax.
// 6: Matched broad top call surface: target_id and target2_id object lookups, set_target_obj(0), vf58(0), set_state(3/1), object_command(0x22,0), sprite calls.
// 7: Matched broad state switch semantics including nested get_action_value switches for states 4 and 11, convert gate in state 6, conversion timer/random/chance path in state 7, and state 13 sprite/return 3.
// 8: Tried keeping a saved target_obj local/volatile local to increase register pressure and recover original push ebp; nonvolatile optimized away, volatile perturbed early load order and did not recover original prologue, rolled back.
// 9: Tried /GX and /Ob0: no change from default /O2. Tried /Od and /Oy- diagnostics: both much worse and first mismatch at offset 0; custom flags removed.
// 10: Current default build has exact size 906 but broad mismatch: 772 bytes / 85.2097% positional, 358 bytes / 39.5143% edit, first mismatch offset 2 because rebuilt saves EBX/ESI/EDI but original also saves EBP.
// 11: Remaining blocker is register-pressure/local-topology in large switch/FPU path; original carries target vptr in EBP in state 7 while current standalone C never allocates EBP under /Oy.
// GIVEUP: left in scratch; no accepted_drift because broad register/prologue and switch-layout drift remain.

typedef unsigned char uchar;

extern "C" int __cdecl debug_rand(char* file, int line);

struct RGE_Base_Game_004CE070 {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void send_chat(int msg, int p1, int p2, int zero1, int zero2);
};
extern RGE_Base_Game_004CE070* rge_base_game;

struct RGE_World_004CE070;

struct RGE_Player_004CE070 {
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18();
    virtual int relation(int player_id);
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74();
    virtual void sound(int id, float vol, int zero);
    virtual void vf7C();
    virtual void object_command(int id, int zero);
    char gap_04[0x38];
    RGE_World_004CE070* world;
    char gap_40[0x0A];
    short player_id;
    char gap_4C[0x38];
    float elapsed;
    char gap_88[0x7D];
    uchar conversion_kind;
};

struct RGE_World_004CE070 {
    char gap_00[0x38];
    int map_x;
    int map_y;
    int map_z;
    RGE_Player_004CE070* player;
    void* object(int id);
};

struct TRIBE_Type_004CE070 { char gap[0x14]; short id; char gap_16[0xCE]; float conversion_factor; };

struct RGE_Action_Object_004CE070 {
    virtual void vf00();
    int sprite_id;
    TRIBE_Type_004CE070* type;
    RGE_Player_004CE070* player;
    char gap_10[0x16];
    short angle;
    char gap_28[0x08];
    float conversion_time;
    char gap_34[0x14];
    uchar action_status;
    char gap_49[0xBB];
    uchar conversion_kind;
    virtual void vf04(); virtual void vf08(); virtual uchar get_action_value();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40();
    virtual void set_player(RGE_Player_004CE070* player);
    virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void vf54();
    virtual void vf58(); virtual void vf5C(); virtual void vf60(); virtual void vf64();
    virtual void vf68(); virtual void vf6C(); virtual void vf70(); virtual void vf74();
    virtual void vf78(); virtual void vf7C(); virtual void object_command(int id, int zero);
    virtual void vf84(); virtual void vf88(); virtual void vf8C(); virtual void vf90();
    virtual void notify(int id, int x, int y, int z, int zero);
    virtual void vf98(); virtual void vf9C(); virtual void vfA0(); virtual void vfA4();
    virtual void vfA8(); virtual void vfAC(); virtual void vfB0(); virtual void vfB4();
    virtual void vfB8(); virtual void vfBC(); virtual void vfC0(); virtual void vfC4();
    virtual void vfC8(); virtual void vfCC(); virtual void vfD0(); virtual void vfD4();
    virtual void vfD8(); virtual void vfDC(); virtual void vfE0(); virtual void vfE4();
    virtual void vfE8(); virtual void vfEC();
    virtual uchar convert(RGE_Action_Object_004CE070* target, int zero1, int zero2);
    virtual void vfF4(); virtual void vfF8(); virtual void vfFC(); virtual void vf100();
    virtual void vf104(); virtual void vf108(); virtual void vf10C(); virtual void vf110();
    virtual void vf114(); virtual void vf118(); virtual void vf11C(); virtual void vf120();
    virtual void vf124(); virtual void vf128(); virtual void vf12C(); virtual void vf130();
    virtual void vf134(); virtual void vf138(); virtual void vf13C(); virtual void vf140();
    virtual void vf144();
    virtual void sprite(int a, int b, int c, int d, int e, int f);
};

class TRIBE_Action_Convert_004CE070 {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50();
    virtual void set_target_obj(RGE_Action_Object_004CE070* obj);
    virtual void vf58(int a);
    virtual void set_state(int state);

    short action_type;
    char gap_06[2];
    RGE_Action_Object_004CE070* obj;
    uchar state;
    char gap_0D[3];
    RGE_Action_Object_004CE070* target_obj;
    RGE_Action_Object_004CE070* target_obj2;
    int target_id;
    int target2_id;
    float target_x;
    float timer;
    void* task;
    void* sub_actions;
    char gap_38[8];
    uchar was_same_owner;
    char gap_41[3];
    float required_range;

    uchar update();
};

uchar TRIBE_Action_Convert_004CE070::update()
{
    if (this->target_id != -1) {
        if (this->obj->player->world->object(this->target_id) == 0) {
            this->set_target_obj(0);
            this->set_state(3);
            return 0;
        }
    }

    if (this->target2_id != -1) {
        if (this->obj->player->world->object(this->target2_id) == 0) {
            this->vf58(0);
        }
    }

    if (this->target_obj != 0) {
        if (this->target_obj->action_status != 2) {
            this->set_target_obj(0);
            this->set_state(3);
            return 0;
        }
        if (this->obj->player->relation(this->target_obj->player->player_id) == 1) {
            if (this->state == 7 || this->state == 6 || this->state == 4) {
                this->obj->object_command(0x22, 0);
            }
            this->set_state(1);
            this->obj->sprite(this->obj->sprite_id, this->obj->sprite_id, 0x1fb, 0x25c, 0, 0);
            return 4;
        }
    }

    switch (this->state) {
    case 1:
        return 1;

    case 4:
        switch (((RGE_Action_Object_004CE070*)this->sub_actions)->get_action_value()) {
        case 1:
        case 2:
            this->set_state(6);
            return 0;
        case 3:
            this->set_state(13);
            return 0;
        case 4:
        case 5:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        }
        break;

    case 6:
        if (this->target_obj == 0) {
            this->set_state(3);
            return 0;
        }
        if (this->obj->convert(this->target_obj, 0, 0)) {
            this->set_state(7);
            return 0;
        }
        break;

    case 7: {
        RGE_Action_Object_004CE070* target = this->target_obj;
        if (target == 0) {
            this->set_state(3);
            return 0;
        }
        target->sprite(this->obj->sprite_id, target->sprite_id, 500, this->obj->sprite_id, target->sprite_id, (int)target->angle);
        this->timer = this->timer - this->obj->player->world->player->elapsed;
        if (this->timer <= 0.0f) {
            if (this->target_obj != 0 && this->target_obj->player->player_id > 0) {
                this->target_obj->notify(0x70, this->obj->player->world->map_x, this->obj->player->world->map_y, this->obj->player->world->map_z, 0);
            }
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\tact_cnv.cpp", 0x1d7);
            float chance = (float)r * 0.00003051851f;
            RGE_Player_004CE070* tplayer = this->target_obj->player;
            if (tplayer->conversion_kind == 0x10) {
                chance = chance * 4.0f;
            } else {
                short type = this->target_obj->type->id;
                if (type == 0x15 || type == 2 || type == 0x14 || type == 0x16 || type == 0x12) {
                    chance = chance + chance;
                } else if (type == 0x23 || type == 0x17) {
                    chance = chance * 8.0f;
                }
            }
            if (chance <= ((RGE_Action_Object_004CE070*)this->task)->conversion_time * this->obj->type->conversion_factor) {
                rge_base_game->send_chat(0x7b, this->target_obj->player->player_id, this->obj->player->player_id, 0, 0);
                this->target_obj->set_player(this->obj->player);
                this->obj->player->sound(0x29, 1.0f, 0);
                this->obj->object_command(0x22, 0);
                this->set_state(3);
            }
            this->set_state(4);
            return 0;
        }
        break;
    }

    case 11:
        switch (((RGE_Action_Object_004CE070*)this->sub_actions)->get_action_value()) {
        case 1:
        case 2:
        case 5:
            this->set_state(3);
            return 0;
        case 3:
            this->set_state(13);
            return 0;
        case 4:
            this->set_target_obj(0);
            this->set_state(11);
            return 0;
        }
        break;

    case 13:
        this->obj->sprite(this->obj->sprite_id, this->obj->sprite_id, 0x1f9, 0x25c, 0, 0);
        this->set_state(2);
        return 3;
    }

    return 0;
}
