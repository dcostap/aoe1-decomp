// STATUS: matched
// FLAGS: config\flags\00402F30_RGE_Action_Gather.rsp
// NOTE: Exact match verified; left in scratch per task request.

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Gather : public RGE_Action {
};

extern "C" void probe(RGE_Action_Gather* p);
#pragma alloc_text(".xtra", probe)
extern "C" void probe(RGE_Action_Gather* p) {
    p->RGE_Action_Gather::~RGE_Action_Gather();
}
