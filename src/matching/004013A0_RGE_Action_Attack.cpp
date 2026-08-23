#ifndef ACT_ATAK_CONTEXT_H
class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Attack : public RGE_Action {
public:
    virtual ~RGE_Action_Attack();
};
#endif

RGE_Action_Attack::~RGE_Action_Attack() {
}
