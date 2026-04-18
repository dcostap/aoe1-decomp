class TRIBE_Action_Repair {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Repair::destroy() {
    this->parent_destroy();
}
