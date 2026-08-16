class RGE_Action {
public:
    virtual ~RGE_Action();
};

class __declspec(novtable) RGE_Action_Transport : public RGE_Action {
public:
    virtual ~RGE_Action_Transport();
};

RGE_Action_Transport::~RGE_Action_Transport() {
}
