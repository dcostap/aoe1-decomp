class RGE_Action_Object;

class RGE_Action {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);

    char gap_04[0x3C];
};

class RGE_Action_Attack : public RGE_Action {
public:
    char gap_40[0x1C];
    RGE_Action_Attack(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_Bird : public RGE_Action {
public:
    RGE_Action_Bird(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_Gather : public RGE_Action {
public:
    char gap_40[0x04];
    RGE_Action_Gather(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_Missile : public RGE_Action {
public:
    char gap_40[0x14];
    RGE_Action_Missile(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_Move_To : public RGE_Action {
public:
    char gap_40[0x04];
    RGE_Action_Move_To(int param_1, RGE_Action_Object* param_2);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);

    RGE_Action_Object* obj;
};

RGE_Action* RGE_Action_List::create_action(int param_1, short param_2) {
    switch (param_2) {
    case 9:
        return new RGE_Action_Attack(param_1, this->obj);
    case 10:
        return new RGE_Action_Bird(param_1, this->obj);
    case 4:
        return new RGE_Action_Explore(param_1, this->obj);
    case 5:
        return new RGE_Action_Gather(param_1, this->obj);
    case 8:
        return new RGE_Action_Missile(param_1, this->obj);
    case 1:
        return new RGE_Action_Move_To(param_1, this->obj);
    case 0x15:
        return new RGE_Action_Make(param_1, this->obj);
    default:
        return 0;
    }
}
