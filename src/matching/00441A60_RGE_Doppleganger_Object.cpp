class RGE_Doppleganger_Object {
public:
    void parent_destroy();
    void destroy();
};

void RGE_Doppleganger_Object::destroy() {
    this->parent_destroy();
}
