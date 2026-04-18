class TRIBE_Action_Artifact {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Action_Artifact::destroy() {
    this->parent_destroy();
}
