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
