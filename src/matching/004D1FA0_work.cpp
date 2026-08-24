// VA: 004D1FA0 TRIBE_Action_Repair::work

#ifndef TACT_REP_CONTEXT_H
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
    virtual void set_target_obj(RGE_Static_Object* target);
    virtual void vf22();
    virtual void set_state(unsigned char state);

    char gap_04[8];
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    char gap_14[0x0C];
    float target_x;
    float target_y;
    float target_z;

    void meet_target();
    int work(RGE_Static_Object* target, float x, float y, float z);
};
#endif

int TRIBE_Action_Repair::work(RGE_Static_Object* target, float param_2, float param_3, float z) {
    if (target != 0) {
        if (target == this->target_obj) {
            unsigned char state = this->state;
            if (state == 4 || state == 6) {
                return 1;
            }
        }
        this->set_target_obj(target);
        this->target_x = target->world_x;
        this->target_y = target->world_y;
        this->target_z = target->world_z;
        this->meet_target();
        this->set_state(4);
        return 1;
    }
    this->target_x = param_2;
    this->target_y = param_3;
    this->target_z = z;
    this->set_target_obj(0);
    this->set_state(11);
    return 1;
}
