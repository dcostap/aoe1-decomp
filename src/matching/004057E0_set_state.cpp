#ifndef ACT_MOVE_CANONICAL_TU
class RGE_Static_Object;

class RGE_Action_Object {
public:
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
    virtual void vf38(unsigned long value);
    char gap_04[0x4];
    RGE_Action_Object* inner;
    char gap_0C[0xC];
    unsigned long value;
};

class RGE_Action_Move_To {
public:
    void* vtable_ptr;
    short action_type;
    char gap_06[0x2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[0x3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    void* task;
    void* sub_actions;
    RGE_Action_Object* sprite;
    unsigned char subActionValue;
    char gap_3D[0x3];
    float range;

    void set_state(unsigned char param_1);
};
#endif

void RGE_Action_Move_To::set_state(unsigned char param_1)
{
    this->state = param_1;

    switch (param_1) {
    case 4:
        this->obj->vf38((unsigned long)this->sprite);
        return;
    case 1:
    case 13:
    case 14:
        if (this->subActionValue == 0) {
#ifdef ACT_MOVE_CANONICAL_TU
            this->obj->vf38((unsigned long)this->obj->master_obj->name);
#else
            this->obj->vf38(this->obj->inner->value);
#endif
        }
        return;
    default:
        return;
    }
}
