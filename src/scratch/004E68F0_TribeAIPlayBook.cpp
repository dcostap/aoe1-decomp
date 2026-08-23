class TribeAIPlayBook {
public:
    void parent_destroy();
    void destroy();
};

void TribeAIPlayBook::destroy() {
    this->parent_destroy();
}
