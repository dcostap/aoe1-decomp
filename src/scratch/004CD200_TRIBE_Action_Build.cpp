class TRIBE_Action_Build {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Build::destroy() {
    this->parent_destroy();
}
