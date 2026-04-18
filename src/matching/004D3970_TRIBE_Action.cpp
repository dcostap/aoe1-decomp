class TRIBE_Action {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action::destroy() {
    this->parent_destroy();
}
