class TRIBE_Action_Hunt {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Hunt::destroy() {
    this->parent_destroy();
}
