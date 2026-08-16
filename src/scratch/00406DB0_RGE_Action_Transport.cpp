class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Transport : public RGE_Action {
};

extern "C" void probe(RGE_Action_Transport* p);
#pragma alloc_text(".xtra", probe)
extern "C" void probe(RGE_Action_Transport* p) {
    p->RGE_Action_Transport::~RGE_Action_Transport();
}
