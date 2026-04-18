class RGE_Main_View {
public:
    void parent_destroy();
    void destroy();
};

void RGE_Main_View::destroy() {
    this->parent_destroy();
}
