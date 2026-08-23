// attempt 1: direct natural shape from the asm
// expected pattern: check target_obj, run inRange, branch to vcall 0x5c, otherwise test obj->vfFC against 0.0

#ifndef ACT_MOVE_CANONICAL_TU
class RGE_Static_Object {
public:
    virtual float vf00();
    virtual float vf04();
    virtual float vf08();
    virtual float vf0C();
    virtual float vf10();
    virtual float vf14();
    virtual float vf18();
    virtual float vf1C();
    virtual float vf20();
    virtual float vf24();
    virtual float vf28();
    virtual float vf2C();
    virtual float vf30();
    virtual float vf34();
    virtual float vf38();
    virtual float vf3C();
    virtual float vf40();
    virtual float vf44();
    virtual float vf48();
    virtual float vf4C();
    virtual float vf50();
    virtual float vf54();
    virtual float vf58();
    virtual void vf5C(unsigned char param_1);
    virtual float vf60();
    virtual float vf64();
    virtual float vf68();
    virtual float vf6C();
    virtual float vf70();
    virtual float vf74();
    virtual float vf78();
    virtual float vf7C();
    virtual float vf80();
    virtual float vf84();
    virtual float vf88();
    virtual float vf8C();
    virtual float vf90();
    virtual float vf94();
    virtual float vf98();
    virtual float vf9C();
    virtual float vfA0();
    virtual float vfA4();
    virtual float vfA8();
    virtual float vfAC();
    virtual float vfB0();
    virtual float vfB4();
    virtual float vfB8();
    virtual float vfBC();
    virtual float vfC0();
    virtual float vfC4();
    virtual float vfC8();
    virtual float vfCC();
    virtual float vfD0();
    virtual float vfD4();
    virtual float vfD8();
    virtual float vfDC();
    virtual float vfE0();
    virtual float vfE4();
    virtual float vfE8();
    virtual float vfEC();
    virtual float vfF0();
    virtual float vfF4();
    virtual float vfF8();
    virtual float vfFC();

    int inRange(RGE_Static_Object* param_1, float param_2);
};

class RGE_Action {
public:
    short action_type;
    unsigned char _pad_0[0x2];
    RGE_Static_Object* obj;       // +0x8
    unsigned char state;
    unsigned char _pad_1[0x3];
    RGE_Static_Object* target_obj; // +0x10
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    void* sprite;
    unsigned char subActionValue;
    unsigned char _pad_end[0x3];

    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C(unsigned char param_1);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    float range; // +0x40

    void first_in_stack(unsigned char param_1);
};
#endif

void RGE_Action_Move_To::first_in_stack(unsigned char param_1) {
    if (this->target_obj != 0) {
        if (this->obj->inRange(this->target_obj, this->range) != 0) {
#ifdef ACT_MOVE_CANONICAL_TU
            this->set_state(1);
#else
            this->vf5C(1);
#endif
            return;
        }
    }

    if (
#ifdef ACT_MOVE_CANONICAL_TU
        this->obj->maximumSpeed() == 0.0
#else
        this->obj->vfFC() == 0.0
#endif
    ) {
#ifdef ACT_MOVE_CANONICAL_TU
        this->set_state(0x0D);
#else
        this->vf5C(0x0D);
#endif
        return;
    }

#ifdef ACT_MOVE_CANONICAL_TU
    this->set_state(3);
#else
    this->vf5C(3);
#endif
}
