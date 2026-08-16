class RGE_Action {
public:
    virtual ~RGE_Action();
};

class __declspec(novtable) RGE_Action_Make : public RGE_Action {
public:
    virtual ~RGE_Action_Make();
};

RGE_Action_Make::~RGE_Action_Make() {
}
