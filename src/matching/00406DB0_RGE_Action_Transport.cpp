// STATUS: matched
// FLAGS: config\flags\00406DB0_RGE_Action_Transport.rsp
// NOTE: Exact match verified; left in scratch per task request.

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
