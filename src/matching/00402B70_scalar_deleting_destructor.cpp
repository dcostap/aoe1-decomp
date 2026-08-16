class RGE_Action_Explore {
public:
    ~RGE_Action_Explore();
    virtual void* scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void* param_1);

void* RGE_Action_Explore::scalar_deleting_destructor(unsigned int param_1) {
    RGE_Action_Explore* self;

    self = this;
    this->~RGE_Action_Explore();
    if ((param_1 & 1) != 0) {
        operator_delete(self);
    }
    return self;
}
