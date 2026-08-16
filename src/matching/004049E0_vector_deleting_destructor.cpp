class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Make : public RGE_Action {
public:
    virtual ~RGE_Action_Make();
    virtual void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Action_Make::vector_deleting_destructor(unsigned int param_1) {
    RGE_Action_Make *self;

    self = this;
    this->RGE_Action_Make::~RGE_Action_Make();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
