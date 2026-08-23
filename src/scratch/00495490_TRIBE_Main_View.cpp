class TRIBE_Main_View {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Main_View::destroy() {
    this->parent_destroy();
}
