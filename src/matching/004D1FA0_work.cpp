// VA: 004D1FA0 TRIBE_Action_Repair::work

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float world_x;
    float world_y;
    float world_z;
};

class TRIBE_Action_Repair {
public:
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void set_target(RGE_Static_Object* target);
    virtual void vf22();
    virtual void set_state(int state);

    char gap_04[8];
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target;
    char gap_14[0x0C];
    float x;
    float y;
    float z;

    void meet_target();
    int work(RGE_Static_Object* target, float x, float y, float z);
};

int TRIBE_Action_Repair::work(RGE_Static_Object* target, float param_2, float param_3, float z) {
    if (target != 0) {
        if (target == this->target) {
            unsigned char state = this->state;
            if (state == 4 || state == 6) {
                return 1;
            }
        }
        this->set_target(target);
        this->x = target->world_x;
        this->y = target->world_y;
        this->z = target->world_z;
        this->meet_target();
        this->set_state(4);
        return 1;
    }
    this->x = param_2;
    this->y = param_3;
    this->z = z;
    this->set_target(0);
    this->set_state(11);
    return 1;
}
