class RGE_Action_Object;

class RGE_Action {
public:
    virtual void vf00(void);
    RGE_Action(int param_1, RGE_Action_Object* param_2, int param_3);

    unsigned short action_type;
};

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(int param_1, RGE_Action_Object* param_2);
};

RGE_Action_Explore::RGE_Action_Explore(int param_1, RGE_Action_Object* param_2)
    : RGE_Action(param_1, param_2, 1) {
    this->action_type = 4;
}
