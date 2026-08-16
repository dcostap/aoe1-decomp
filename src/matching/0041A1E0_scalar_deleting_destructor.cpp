class RGE_Animated_Object {
public:
    ~RGE_Animated_Object();
    void *scalar_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Animated_Object::scalar_deleting_destructor(unsigned int param_1) {
    this->~RGE_Animated_Object();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
