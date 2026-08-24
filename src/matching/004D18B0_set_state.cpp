// VA: 004D18B0 TRIBE_Action_Repair::set_state
// FLAGS: config/flags/004D18B0_set_state.rsp (/nologo /c /O2 /Oy /GX)
// Attempt log:
// - Baseline natural /GX switch preserved the EH frame and broad action paths,
//   but used the wrong state-1 call and duplicated the notify site.
// - State 1 calls the inherited virtual set_target_obj(0) at vslot +54; states
//   1/2/3 then join the natural post-switch new_sprite tail.
// - The exact layout is RGE_Action_Move_To size 0x44, task sprites/sound at
//   +34/+38/+44, and action-object data sprite/range at +18/+114.
// - Exact: 713/713 bytes under the pinned VC5 /O2 /Oy /GX toolchain. No inline
//   asm or compiler-only source scaffolding.

#ifndef TACT_REP_CONTEXT_H
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Action_Object;
class RGE_Action_List;
class RGE_Task;
class RGE_Sound;

class RGE_Action_Object_Data {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite; // +18
    char gap_1C[0xF8];
    float work_range; // +114
};

class RGE_Static_Object_Data {
public:
    char gap_00[0x14];
    short object_type; // +14
};

class RGE_Task {
public:
    char gap_00[0x34];
    RGE_Sprite* move_sprite; // +34
    RGE_Sprite* work_sprite; // +38
    char gap_3C[8];
    RGE_Sound* work_sound; // +44
};

class RGE_Action_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34();
    virtual void new_sprite(RGE_Sprite*); // +0x38
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
    virtual void notify(int,int,int,int,int,int); // +0x148
    virtual void vf14C(); virtual void vf150();
    virtual void moveTo(float, float, float, float, int); // +0x154
    int id; // +4
    RGE_Action_Object_Data* object_data; // +8
    char gap_0C[0x2C];
    float world_x; // +38
    float world_y; // +3c
    float world_z; // +40
    char gap_44[0x144];
    unsigned char command_flag; // +188
};

class RGE_Action {
public:
    virtual void vf00();
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int,RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10();
    virtual void vf14(int);
    virtual short vf18();
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20();
    virtual unsigned char vf24();
    virtual unsigned char vf28();
    virtual int vf2C();
    virtual int vf30(RGE_Static_Object*,float,float,float);
    virtual int vf34(RGE_Static_Object*,float,float,float);
    virtual void new_sprite(RGE_Sprite*); // +0x38
    virtual unsigned char vf3C(long,unsigned char);
    virtual void vf40(void*);
    virtual void vf44(void*,void*,void*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C();
    virtual RGE_Static_Object* vf50();
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char); // +0x5c
    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;        // +08
    unsigned char state;           // +0c
    char gap_0D[3];
    RGE_Static_Object* target_obj;  // +10
    RGE_Static_Object* target_obj2; // +14
    int targetID;                  // +18
    int target2ID;                 // +1c
    float target_x;                // +20
    float target_y;                // +24
    float target_z;                // +28
    float timer;                   // +2c
    RGE_Task* task;                // +30
    RGE_Action_List* sub_actions;  // +34
    RGE_Sprite* sprite;            // +38
    unsigned char subActionValue;  // +3c
    char gap_3D[3];
    void setSubAction(unsigned char);
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34();
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
    virtual void vf13C(); virtual void vf140(); virtual void vf144(); virtual void vf148();
    virtual void vf14C(); virtual void vf150();
    virtual void moveTo(float,float,float,float,int); // +154
    char gap_04[4];
    RGE_Static_Object_Data* object_data; // +8
    char gap_0C[0x2C];
    float world_x; float world_y; float world_z;
    char gap_44[0x144];
    unsigned char command_flag;
};

class RGE_Action_List { public: void delete_list(); void add_action(RGE_Action*); };
class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    RGE_Action_Move_To(RGE_Action_Object*, RGE_Static_Object*, float, RGE_Sprite*);
    float range;
};
class RGE_Sound { public: void play(int); };

class TRIBE_Action_Repair : public RGE_Action {
public:
    virtual void set_state(unsigned char);
    unsigned char save_target_command_flag; // +40
};
#endif

void TRIBE_Action_Repair::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x26a, 0, 0);
        break;

    case 11: {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_x, this->target_y, this->target_z, 0.0f, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0d);
            return;
        }
        action->setSubAction(1);
        this->sub_actions->add_action(action);
        return;
    }

    case 4: {
        if (this->target_obj != 0) {
            this->target_x = this->target_obj->world_x;
            this->target_y = this->target_obj->world_y;
            this->target_z = this->target_obj->world_z;
        }
        RGE_Action_Move_To* action = new RGE_Action_Move_To(this->obj, this->target_obj, this->obj->object_data->work_range, this->task->move_sprite);
        if (action == 0) {
            this->set_state(0x0d);
            return;
        }
        this->sub_actions->add_action(action);
        action->setSubAction(1);
        return;
    }

    case 10: {
        this->obj->new_sprite(this->obj->object_data->sprite);
        this->timer = 1.0f;
        RGE_Static_Object* target = this->target_obj;
        if (target == 0) return;
        short id = target->object_data->object_type;
        if (id != 2 && id != 0x14 && id != 0x15 && id != 0x16) return;
        if (target->command_flag != this->save_target_command_flag) return;
        target->moveTo(this->obj->world_x, this->obj->world_y, this->obj->world_z, 0, 1);
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
        if (this->task->work_sound != 0) {
            this->task->work_sound->play(1);
            return;
        }
        return;

    case 1:
        this->set_target_obj(0);
        if (this->subActionValue == 0) {
            this->obj->notify(this->obj->id, this->obj->id, 0x1fa, 0x26a, 0, 0);
        }
        break;

    case 2:
        break;

    default:
        return;
    }

        this->obj->new_sprite(this->obj->object_data->sprite);
}
