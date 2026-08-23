class TRIBE_Action_Convert {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Convert::destroy() {
    this->parent_destroy();
}
