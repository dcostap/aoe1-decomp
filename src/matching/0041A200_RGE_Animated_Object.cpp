class RGE_Animated_Object {
public:
    void parent_destroy();
    void destroy();
};

void RGE_Animated_Object::destroy() {
    this->parent_destroy();
}
