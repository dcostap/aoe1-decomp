class RGE_Action {
public:
    virtual ~RGE_Action();
};

class __declspec(novtable) RGE_Action_Gather : public RGE_Action {
public:
    virtual ~RGE_Action_Gather();
};

RGE_Action_Gather::~RGE_Action_Gather() {
}
