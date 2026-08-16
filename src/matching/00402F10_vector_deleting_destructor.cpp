class RGE_Action_Gather {
public:
    ~RGE_Action_Gather();
    virtual void* vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void* param_1);

void* RGE_Action_Gather::vector_deleting_destructor(unsigned int param_1) {
    RGE_Action_Gather* self;

    self = this;
    this->~RGE_Action_Gather();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
