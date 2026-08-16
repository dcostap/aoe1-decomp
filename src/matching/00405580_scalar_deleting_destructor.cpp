class RGE_Action_Move_To {
public:
    virtual ~RGE_Action_Move_To();
    virtual void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Action_Move_To::scalar_deleting_destructor(unsigned int param_1) {
    this->RGE_Action_Move_To::~RGE_Action_Move_To();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
