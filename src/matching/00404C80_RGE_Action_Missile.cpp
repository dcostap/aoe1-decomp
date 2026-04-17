class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Missile : public RGE_Action {
};

extern "C" void probe(RGE_Action_Missile* p);
#pragma alloc_text(".xtra", probe)
extern "C" void probe(RGE_Action_Missile* p) {
    p->RGE_Action_Missile::~RGE_Action_Missile();
}
