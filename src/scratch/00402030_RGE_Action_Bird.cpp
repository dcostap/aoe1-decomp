class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Bird : public RGE_Action {
};

extern "C" void probe(RGE_Action_Bird* p);
#pragma alloc_text(".xtra", probe)
extern "C" void probe(RGE_Action_Bird* p) {
    p->RGE_Action_Bird::~RGE_Action_Bird();
}
