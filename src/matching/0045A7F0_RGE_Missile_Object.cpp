class RGE_Missile_Object {
public:
    void parent_destroy();
    void destroy();
};

void RGE_Missile_Object::destroy() {
    this->parent_destroy();
}
