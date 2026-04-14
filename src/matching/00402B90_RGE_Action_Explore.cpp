// STATUS: matched
// FLAGS: config\flags\00402B90_RGE_Action_Explore.rsp
// NOTE: Exact match verified; left in scratch per task request.

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Explore : public RGE_Action {
};

extern "C" void probe(RGE_Action_Explore* p);
#pragma alloc_text(".xtra", probe)
extern "C" void probe(RGE_Action_Explore* p) {
    p->RGE_Action_Explore::~RGE_Action_Explore();
}
