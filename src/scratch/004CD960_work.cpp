// VA: 004CD960 TRIBE_Action_Build::work
// left in scratch: behavior/core matched, but remaining 9-byte drift is load/register order.
// Original owner check loads actor into EDX first, then target owner into ECX; VC5 uses ECX first.
// Fallback coordinate stores also reload stack params in a different order despite source z,x,y and int punning.

class RGE_Static_Object;

class TRIBE_Action_Build {
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
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void set_target(RGE_Static_Object* target);
    virtual void vf58();
    virtual void set_action_type(int type);

    void* vptr2;                    // 0x04
    RGE_Static_Object* actor;       // 0x08
    unsigned char action;           // 0x0c
    char gap_0d[3];
    RGE_Static_Object* target;      // 0x10
    char gap_14[0x0c];
    float x;                        // 0x20
    float y;                        // 0x24
    float z;                        // 0x28

    int work(RGE_Static_Object* target, float param_2, float param_3, float param_4);
};

struct OwnerInfo {
    char gap_00[0x4a];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x0c];
    OwnerInfo* owner;
};

int TRIBE_Action_Build::work(RGE_Static_Object* target, float param_2, float param_3, float param_4) {
    if (target != 0 && target->owner->id == this->actor->owner->id) {
        if (target == this->target) {
            unsigned char action = this->action;
            if (action == 4 || action == 6) {
                return 1;
            }
        }
        this->set_target(target);
        this->set_action_type(4);
        return 1;
    }

    int iz = *(int*)&param_4;
    int ix = *(int*)&param_2;
    int iy = *(int*)&param_3;
    *(int*)&this->z = iz;
    *(int*)&this->x = ix;
    *(int*)&this->y = iy;
    this->set_target(0);
    this->set_action_type(11);
    return 1;
}
