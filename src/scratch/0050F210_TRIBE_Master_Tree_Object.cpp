class TRIBE_Master_Tree_Object {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Master_Tree_Object::destroy() {
    this->parent_destroy();
}
