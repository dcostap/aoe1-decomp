class TRIBE_Gaia {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Gaia::destroy() {
    this->parent_destroy();
}
