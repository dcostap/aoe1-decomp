class RGE_Action {
public:
    ~RGE_Action();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Action::vector_deleting_destructor(unsigned int param_1) {
    this->~RGE_Action();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
