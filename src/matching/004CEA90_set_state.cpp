// 004CEA90 TRIBE_Action_Heal::set_state
// Source: tact_hea.cpp lines 98-169
// Size: 566 bytes, EH-framed
//
// Attempt log:
// Previous worker left only an experiment note after a noncanonical constructor
// definition.  The clean reconstruction below restores the period source shape:
// typed action/task ownership, source-order switch cases, and declaration-only
// Move_To constructors so VC5 emits operator new plus the existing ctor calls.
//
// Probe 1 (baseline): natural typed switch and declaration-only Move_To
// constructors; exact 566/566-byte match under the pinned VC5 toolchain.
// FLAGS: /nologo /c /O2 /Oy /GX

class RGE_Sprite;
class RGE_Static_Object;
class RGE_Action;
class RGE_Action_List;
class RGE_Action_Object;
class RGE_Master_Action_Object;
class RGE_Task;
class RGE_Sound;

class RGE_Master_Action_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
};

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual unsigned char update();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void new_sprite(RGE_Sprite*);
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual void vf130();
    virtual void vf134();
    virtual void vf138();
    virtual void vf13C();
    virtual void vf140();
    virtual void vf144();
    virtual void notify(int, int, int, int, int, int);

    int id;
    RGE_Master_Action_Object* master_obj;
};

class RGE_Action_List {
public:
    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    RGE_Sprite* work_sprite2;
    RGE_Sprite* carry_sprite;
    RGE_Sound* work_sound;
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object*);
    virtual int setup(int, RGE_Action_Object*);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object*);
    virtual void rehook();
    virtual void save(int);
    virtual short type();
    virtual void first_in_stack(unsigned char);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object*, float, float, float);
    virtual int work(RGE_Static_Object*, float, float, float);
    virtual unsigned char attack_response(RGE_Static_Object*);
    virtual unsigned char relation_response(long, unsigned char);
    virtual void copy_obj(void*);
    virtual void copy_obj_sprites(void*, RGE_Task*, RGE_Task*);
    virtual void get_state_name(char*);
    virtual RGE_Static_Object* get_target_obj();
    virtual RGE_Static_Object* get_target_obj2();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];

    void setSubAction(unsigned char);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    float range;
};

class TRIBE_Action_Heal : public RGE_Action {
public:
    virtual void set_state(unsigned char);
};

void TRIBE_Action_Heal::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25B, 0, 0);
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 11: {
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            0.0f,
            this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        move_to->setSubAction(1);
        this->sub_actions->add_action(move_to);
        return;
    }

    case 4: {
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        RGE_Action_Move_To* move_to = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            0.4f,
            this->task->move_sprite);
        if (move_to == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(move_to);
        move_to->setSubAction(1);
        return;
    }

    case 6:
        this->target_x = this->target_obj->world_x;
        this->target_y = this->target_obj->world_y;
        this->target_z = this->target_obj->world_z;
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0)
            this->task->work_sound->play(1);
        return;

    default:
        return;
    }
}
