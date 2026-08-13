// 004CDE10 TRIBE_Action_Convert::set_state
// Requested 004E2270 was absent from live status.
// Query fallback: 004CDE10 was the smallest unleased normal target with no
// current check (`--max-lifetime-probes 0`).
//
// Attempt log:
// - Replaced the prior raw vtable and cursor scaffold with typed action,
//   object, task, player, and static-object surfaces.
// - Natural reconstruction baseline: /GX, ordinary switch, and Move_To
//   constructors.  The original has EH registration around both allocations.
// - Baseline: 618 rebuilt bytes, 80.00% exact-block coverage; the remaining
//   structural gaps are the remapped dispatch table and case-6 sprite call.
// - Shared local sprite plus a common label duplicated the call and grew the
//   body to 622 bytes; restored the natural direct-call source.
// - Grouped and split no-op arms, and a zero-based dispatch expression, all
//   emitted the same 618-byte code; retained the period-plausible switch.
// - Restored the pinned clean source for closure; the remaining extra
//   virtual +0x38 call is the unresolved shared sprite-tail gap.

class RGE_Sprite;
class RGE_Sound;
class RGE_Task;
class RGE_Action;
class RGE_Action_List;
class RGE_Static_Object;
class RGE_Action_Object;

class RGE_Player {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90();
    virtual void notify(int, float, float, float, int);

    char gap_04[0x46];
    short command_flag;
};

class RGE_Static_Object {
public:
    virtual void vf00();

    int id;
    void* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float x;
    float y;
    float z;
};

class RGE_Master_Static_Object {
public:
    virtual void vf00();
    char gap_04[0x14];
    RGE_Sprite* sprite;
};

class RGE_Action_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual unsigned char update(); virtual void vf28();
    virtual void vf2C(); virtual void vf30(); virtual void vf34();
    virtual void new_sprite(RGE_Sprite*);
    virtual void vf3C(); virtual void vf40(); virtual void vf44(); virtual void vf48();
    virtual void vf4C(); virtual void vf50(); virtual void vf54(); virtual void vf58();
    virtual void vf5C(); virtual void vf60(); virtual void vf64(); virtual void vf68();
    virtual void vf6C(); virtual void vf70(); virtual void vf74(); virtual void vf78();
    virtual void vf7C(); virtual void vf80(); virtual void vf84(); virtual void vf88();
    virtual void vf8C(); virtual void vf90(); virtual void vf94(); virtual void vf98();
    virtual void vf9C(); virtual void vfA0(); virtual void vfA4(); virtual void vfA8();
    virtual void vfAC(); virtual void vfB0(); virtual void vfB4(); virtual void vfB8();
    virtual void vfBC(); virtual void vfC0(); virtual void vfC4(); virtual void vfC8();
    virtual void vfCC(); virtual void vfD0(); virtual void vfD4(); virtual void vfD8();
    virtual void vfDC(); virtual void vfE0(); virtual void vfE4(); virtual void vfE8();
    virtual void vfEC(); virtual void vfF0(); virtual void vfF4(); virtual void vfF8();
    virtual void vfFC(); virtual void vf100(); virtual void vf104(); virtual void vf108();
    virtual void vf10C(); virtual void vf110(); virtual void vf114(); virtual void vf118();
    virtual void vf11C(); virtual void vf120(); virtual void vf124(); virtual void vf128();
    virtual void vf12C(); virtual void vf130(); virtual void vf134(); virtual void vf138();
    virtual void vf13C(); virtual void vf140(); virtual void vf144();
    virtual void notify(int, int, int, int, int, int);

    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    char gap_14[0x24];
    float x;
    float y;
    float z;
};

class RGE_Action_List {
public:
    void delete_list();
    void add_action(RGE_Action*);
};

class RGE_Task {
public:
    char gap_00[0x20];
    float timer;
    char gap_24[0x10];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
    char gap_3C[8];
    RGE_Sound* work_sound;
};

class RGE_Sound {
public:
    void play(int);
};

class RGE_Action {
public:
    virtual void vf00();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual unsigned char vf38(RGE_Static_Object*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*, void*, void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C();
    virtual RGE_Static_Object* vf50();
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

class TRIBE_Action_Convert : public RGE_Action {
public:
    virtual void set_state(unsigned char);
    unsigned char was_same_owner;
    char gap_41[3];
    float requiredRange;
};

void TRIBE_Action_Convert::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25C, 0, 0);

    case 1:
    case 2:
    case 13:
    case 14:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    case 11: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_x,
            this->target_y,
            this->target_z,
            this->requiredRange,
            this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        this->target_x = this->target_obj->x;
        this->target_y = this->target_obj->y;
        this->target_z = this->target_obj->z;
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj,
            this->target_obj,
            this->requiredRange,
            this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0D);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 5:
        return;

    case 6:
        this->obj->new_sprite(this->task->move_sprite);
        return;

    case 7:
        this->obj->new_sprite(this->task->work_sprite);
        if (this->task->work_sound != 0)
            this->task->work_sound->play(1);
        if (this->target_obj != 0 && this->target_obj->owner->command_flag > 0) {
            this->target_obj->owner->notify(0x70, this->obj->x, this->obj->y, this->obj->z, 0);
        }
        this->timer = this->task->timer;
        return;

    case 8:
    case 9:
    case 10:
    case 12:
    default:
        return;
    }
}
