#ifndef ACT_BIRD_CONTEXT_H
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
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual float teleport(float param_1, float param_2, float param_3);

    char gap_04[0x34];
    float world_x;
    float world_y;
};

class RGE_Action {
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
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void set_state(unsigned char param_1);

    unsigned short action_type;
    char gap_06[0x02];
    RGE_Action_Object* obj;
};

class RGE_Action_Bird : public RGE_Action {
public:
    virtual void first_in_stack(unsigned char param_1);
};
#endif

void RGE_Action_Bird::first_in_stack(unsigned char param_1) {
    if (param_1) {
        RGE_Action_Object* obj;

        obj = this->obj;
        obj->teleport(obj->world_x, obj->world_y, 6.0f);
        this->set_state(3);
        return;
    }

    this->set_state(3);
}
