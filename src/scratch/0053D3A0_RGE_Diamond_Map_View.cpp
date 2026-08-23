class RGE_Diamond_Map_View {
public:
    void parent_destroy();
    void destroy();
};

void RGE_Diamond_Map_View::destroy() {
    this->parent_destroy();
}
