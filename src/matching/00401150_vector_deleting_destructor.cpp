class RGE_Action_Attack {
public:
    virtual ~RGE_Action_Attack();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Action_Attack::vector_deleting_destructor(unsigned int param_1) {
    this->RGE_Action_Attack::~RGE_Action_Attack();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
