class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual ~RGE_Action_Attack();
};

RGE_Action_Attack::~RGE_Action_Attack() {
}
