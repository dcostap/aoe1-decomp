// 00402C00 RGE_Action_Explore::set_state
// Source: act_expl.cpp lines 73-133
//
// Attempt log:
// - Baseline: reconstructed the typed action/object ownership and switch from
//   act_expl.cpp; /GX is required by the original EH registration.
// - Layout probe: the moving master owns sprite at +0x18 and move_sprite at
//   +0xBC.  Correcting those proven offsets fixed both virtual argument loads.
// - Control-flow probes: VC5 kept the switch default at the final epilogue
//   when the new-sprite cases were written in the obvious order.  The PDB puts
//   the shared new-sprite statement at the later act_expl.cpp line 130, while
//   the original emits it directly after case 3's notify call.  A source-local
//   shared label reached by case 3 and cases 1/13/14 reproduces that natural
//   source ordering and the original fall-through block topology.
// - Exact: the bottom shared-label switch shape, corrected master offsets, and
//   typed constructor surface produce all 359 bytes exactly.
// Left in scratch until final validation/promotion: exact source audit.
// FLAGS: config\flags\00402C00_set_state.rsp (/nologo /c /O2 /GX)

class RGE_Sprite;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual void vf00(void);
    char gap_04[0x14];
    RGE_Sprite* sprite;
    char gap_1C[0xA0];
};

class RGE_Master_Moving_Object : public RGE_Master_Static_Object {
public:
    RGE_Sprite* move_sprite;
};

class RGE_Action_Object {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual unsigned char update(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void new_sprite(RGE_Sprite*);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void vfE8(void);
    virtual void vfEC(void);
    virtual void vfF0(void);
    virtual void vfF4(void);
    virtual void vfF8(void);
    virtual void vfFC(void);
    virtual void vf100(void);
    virtual void vf104(void);
    virtual void vf108(void);
    virtual void vf10C(void);
    virtual void vf110(void);
    virtual void vf114(void);
    virtual void vf118(void);
    virtual void vf11C(void);
    virtual void vf120(void);
    virtual void vf124(void);
    virtual void vf128(void);
    virtual void vf12C(void);
    virtual void vf130(void);
    virtual void vf134(void);
    virtual void vf138(void);
    virtual void vf13C(void);
    virtual void vf140(void);
    virtual void vf144(void);
    virtual void notify(int, int, int, int, int, int);

    int id;
    RGE_Master_Moving_Object* master_obj;
};

class RGE_Action;
class RGE_Action_List {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual unsigned char update(void);

    void delete_list(void);
    void add_action(RGE_Action*);
};

class RGE_Task {
public:
    char gap_00[0x24];
    float work_range;
    char gap_28[0x0C];
    RGE_Sprite* move_sprite;
};

class RGE_Action {
public:
    virtual void vf00(void);
    virtual int vf04(RGE_Action_Object*);
    virtual int vf08(int, RGE_Action_Object*);
    virtual RGE_Action_List* vf0C(RGE_Action_Object*);
    virtual void vf10(void);
    virtual void vf14(int);
    virtual short vf18(void);
    virtual void vf1C(unsigned char);
    virtual unsigned char vf20(void);
    virtual unsigned char vf24(void);
    virtual unsigned char vf28(void);
    virtual int vf2C(void);
    virtual int vf30(RGE_Static_Object*, float, float, float);
    virtual int vf34(RGE_Static_Object*, float, float, float);
    virtual unsigned char vf38(RGE_Static_Object*);
    virtual unsigned char vf3C(long, unsigned char);
    virtual void vf40(RGE_Master_Moving_Object*);
    virtual void vf44(RGE_Master_Moving_Object*, RGE_Task*, RGE_Task*);
    virtual void vf48(char*);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object*);
    virtual void set_target_obj2(RGE_Static_Object*);
    virtual void set_state(unsigned char);

    int gap_04;
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x13];
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[0x03];

    void setSubAction(unsigned char);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    RGE_Action_Move_To(RGE_Action_Object*, float, float, float, float, RGE_Sprite*);
    float range;
};

class RGE_Action_Explore : public RGE_Action {
public:
    void set_state(unsigned char);
};

void RGE_Action_Explore::set_state(unsigned char param_1)
{
    this->sub_actions->delete_list();
    this->state = param_1;

    switch (param_1) {
    case 3:
        this->obj->notify(this->obj->id, this->obj->id, 0x202, 0x25D, 0, 0);
        goto new_sprite;

    case 2:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        this->set_target_obj(0);
        this->set_target_obj2(0);
        this->target_x = -1.0f;
        this->target_y = -1.0f;
        this->target_z = -1.0f;
        return;

    case 11:
        break;

    case 1:
    case 13:
    case 14:
    new_sprite:
        this->obj->new_sprite(this->obj->master_obj->sprite);
        return;

    default:
        return;
    }

    RGE_Sprite* ms;
    if ((this->task != 0) && (this->task->move_sprite != 0))
        ms = this->task->move_sprite;
    else
        ms = this->obj->master_obj->move_sprite;

    {
        RGE_Action_Move_To* action = new RGE_Action_Move_To(
            this->obj, this->target_x, this->target_y, this->target_z, 0.0f, ms);

        if (action == 0) {
            ((RGE_Action*)this)->set_state(0x0D);
            return;
        }

        action->setSubAction(1);
        this->sub_actions->add_action(action);
    }
}
