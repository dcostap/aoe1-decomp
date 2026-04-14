// STATUS: matched
// FLAGS: config\flags\00404A00_RGE_Action_Make.rsp
// NOTE: Exact match verified; left in scratch per task request.

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Make : public RGE_Action {
};

extern "C" void probe(RGE_Action_Make* p);
#pragma alloc_text(".xtra", probe)
extern "C" void probe(RGE_Action_Make* p) {
    p->RGE_Action_Make::~RGE_Action_Make();
}
