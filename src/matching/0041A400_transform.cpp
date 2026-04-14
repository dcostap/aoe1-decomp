class RGE_Animated_Object {
public:
    void target_func(int p0);
    void transform(int p);
};

void RGE_Animated_Object::transform(int p) { this->target_func(p); }
