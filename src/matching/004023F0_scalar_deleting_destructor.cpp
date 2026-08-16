class RGE_Action_Enter {
public:
    virtual ~RGE_Action_Enter();
    void* scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void* param_1);

void* RGE_Action_Enter::scalar_deleting_destructor(unsigned int param_1) {
    this->RGE_Action_Enter::~RGE_Action_Enter();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
