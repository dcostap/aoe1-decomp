class TRIBE_Action_Trade {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Trade::destroy() {
    this->parent_destroy();
}
