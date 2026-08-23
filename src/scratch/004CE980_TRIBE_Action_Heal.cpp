class TRIBE_Action_Heal {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Heal::destroy() {
    this->parent_destroy();
}
