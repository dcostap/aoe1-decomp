// VA: 004D1BB0 TRIBE_Action_Repair::update
// Attempt log:
// try 1: natural reconstruction from asm/PDB line map and sibling tact_rep surfaces; compiled after modeling game/world/static-object offsets.
// try 2: fixed obj->game/world path (+0x0c game, +0x3c world) and target object_data at +0x0c; first validation improved from ~84.7% to ~71.7% diff.
// try 3: changed object_delta from free/cdecl-ish helper to member call on RGE_Action_Object; removed extra stack cleanup and improved edit diff (~55.4%).
// try 4: preserved redundant target null-test with local outer check and member inner access; improved edit diff to ~34.4%, but prologue still saves ECX instead of EBX and broad switch/layout remains off.
// GIVEUP: behavior/call map is only approximate. Remaining mismatch is not localized: switch case mapping/order, exact state/subaction enum source shape, command/send surface, repair_work block liveness (EBX), and several helper declarations need deeper donor-source reconstruction. No inline asm used.

class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Task;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Static_Object_List;
class RGE_Game;

class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class RGE_Master_Static_Object_List { public: int vf00(); virtual void vf04(); virtual void vf08(); virtual unsigned char get_value(); };
class RGE_Player { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual int can_build(short); char gap[0x64]; float speed; };
class RGE_Game {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual int can_build(short);
    char gap_04[4];
    RGE_Player* player;       // +8
    char gap_0C[0x30];
    RGE_Game_World* world;    // +3c
    char gap_40[0x0a];
    short player_id;          // +4a
    char gap_4C[0x38];
    float speed;              // +84
};
class RGE_CommandManager { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void send(int,int,int,int,int); };
extern RGE_CommandManager* command_manager;

class RGE_Action_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual int repair_work(float);
    char gap_04[4];
    void* object_data; // +8
    RGE_Game* game;    // +c
    char gap_10[0x28];
    float x; float y; float z;
    char gap_44[4];
    unsigned char master_type;
    char gap_49[0x13f];
    unsigned char command_flag;
    virtual unsigned char find_path(RGE_Static_Object*, int, int);
    virtual void vf190(); virtual void vf194(); virtual void vf198(); virtual void vf19C();
    virtual void vf1A0(); virtual void vf1A4(); virtual void vf1A8(); virtual void vf1AC();
    virtual void vf1B0(); virtual void vf1B4(); virtual void vf1B8(); virtual void vf1BC();
    virtual void vf1C0(); virtual void vf1C4(); virtual void vf1C8(); virtual void vf1CC();
    virtual void vf1D0(); virtual void vf1D4(); virtual void vf1D8(); virtual void vf1DC();
    virtual void vf1E0(); virtual void vf1E4(); virtual void vf1E8(); virtual void vf1EC();
    virtual unsigned char vf1F0(RGE_Static_Object*, int, int);
    float object_delta(RGE_Static_Object*);
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual unsigned char get_master_value();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual unsigned char repair_work(float);
    int id;
    char gap_08[4];
    void* object_data;
    char gap_10[0x28];
    float x; float y; float z;
    char gap_44[4];
    unsigned char master_type;
};

class RGE_Action_List { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual unsigned char get_value(); };

class TRIBE_Action_Repair {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50();
    virtual void set_target(RGE_Static_Object*); // +54
    virtual void reset_target(int);              // +58
    virtual void set_state(int);                 // +5c

    short action_type; char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state; char gap_0D[3];
    RGE_Static_Object* target;
    RGE_Static_Object* target2;
    int targetID;
    int target2ID;
    float target_x, target_y, target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    void* sprite;
    unsigned char subActionValue; char gap_3D[3];
    unsigned char save_target_command_flag;

    unsigned char update();
};

extern float repair_epsilon;
extern float f_575270;
extern float f_575278;
extern float g_float_86BC08;


unsigned char TRIBE_Action_Repair::update()
{
    RGE_Static_Object* check_target;
    if (this->targetID != -1) {
        if (this->obj->game->world->object(this->targetID) == 0) {
            goto invalid_target;
        }
    }
    if (this->target2ID != -1) {
        if (this->obj->game->world->object(this->target2ID) == 0) {
            this->reset_target(0);
        }
    }
    check_target = this->target;
    if (check_target != 0) {
        if (check_target->master_type != 2) {
            goto invalid_target;
        }
        if (this->target != 0) {
            short build_id = *(short*)((char*)this->target->object_data + 0x4a);
            if (!this->obj->game->can_build(build_id)) {
                goto invalid_target;
            }
        }
    }

    switch (this->state) {
    case 10:
        switch (this->sub_actions->get_value()) {
        case 1:
            this->set_target(0);
            this->set_state(11);
            return 0;
        case 2:
            this->set_state(1);
            return 0;
        case 3:
            goto invalid_target;
        case 4: {
            float d = this->obj->object_delta(this->target) - repair_epsilon;
            g_float_86BC08 = d;
            if (d < 0.0) this->set_state(6); else this->set_state(10);
            return 0;
        }
        case 5:
            if (this->target == 0) { this->set_state(1); return 0; }
            if (this->obj->vf1F0(this->target,0,0)) { this->set_state(7); return 0; }
            break;
        }
        break;

    case 11:
        this->set_state(1);
        return 0;

    case 12:
        switch (this->sub_actions->get_value()) {
        case 1: this->set_target(0); this->set_state(1); return 0;
        case 2: this->set_state(1); return 0;
        case 3: goto invalid_target;
        }
        break;

    case 4: {
        float d = this->obj->object_delta(this->target) - repair_epsilon;
        g_float_86BC08 = d;
        if (d < 0.0) this->set_state(6); else this->set_state(10);
        return 0;
    }

    case 6:
        if (this->target == 0) { this->set_state(1); return 0; }
        if (this->obj->vf1F0(this->target,0,0)) { this->set_state(7); return 0; }
        break;

    case 7:
        if (this->target == 0) { this->set_state(1); return 0; }
        if (this->target->x != this->target_x || this->target_y != this->target->y) {
            float d = this->obj->object_delta(this->target) - repair_epsilon;
            g_float_86BC08 = d;
            if (!(d < 0.0)) { this->set_state(3); return 0; }
            this->target_x = this->target->x;
            this->target_y = this->target->y;
            this->target_z = this->target->z;
            return 0;
        }
        if (this->target->repair_work(this->task ? *(float*)((char*)this->task+0x1c) * this->obj->game->speed * this->obj->game->player->speed : 0.0f) == 1) {
            this->set_state(1); return 0;
        }
        if (this->target->repair_work(0.0f) == 2) {
            this->obj->game->player->vf00();
            this->target->vf00();
            command_manager->send(0x6b, this->obj->game->player_id, this->target->id, 0, 0);
            this->set_state(2); return 0;
        }
        break;

    case 8:
        if (this->target == 0) break;
        this->timer -= this->obj->game->speed;
        if (!(this->timer < 0.0f)) break;
        {
            float d = this->obj->object_delta(this->target) - repair_epsilon;
            g_float_86BC08 = d;
            if (d < 0.0) { this->set_state(6); return 0; }
            this->timer = 1.0f;
            return 0;
        }

    case 1:
        return 1;

    case 9:
        this->obj->game->player->vf00();
        this->set_state(2);
        return 3;
    }
    return 0;

invalid_target:
    this->set_target(0);
    this->set_state(1);
    return 0;
}
