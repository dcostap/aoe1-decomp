class TRIBE_Gaia {
public:
    void destroy(void);
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *TRIBE_Gaia::vector_deleting_destructor(unsigned int param_1) {
    this->destroy();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
