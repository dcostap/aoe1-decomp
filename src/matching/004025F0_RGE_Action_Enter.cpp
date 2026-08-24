#ifndef ACT_ENTR_CONTEXT_H
class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Enter : public RGE_Action {
public:
    virtual ~RGE_Action_Enter();
};
#endif

RGE_Action_Enter::~RGE_Action_Enter() {
}
