class RGE_Active_Animated_Sprite {
public:
    void destroy(void);
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Active_Animated_Sprite::vector_deleting_destructor(unsigned int param_1) {
    this->destroy();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
