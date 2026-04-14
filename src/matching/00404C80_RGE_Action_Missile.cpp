// STATUS: matched
// FLAGS: config\flags\00404C80_RGE_Action_Missile.rsp
// NOTE: Exact match verified; left in scratch per task request.

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
