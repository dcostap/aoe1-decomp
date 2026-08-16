class RGE_Active_Animated_Sprite {
public:
    virtual ~RGE_Active_Animated_Sprite();
    virtual void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

// The qualified call preserves the direct complete-destructor target.
void *RGE_Active_Animated_Sprite::vector_deleting_destructor(unsigned int param_1) {
    this->RGE_Active_Animated_Sprite::~RGE_Active_Animated_Sprite();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
