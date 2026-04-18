class T_Scenario {
public:
    void parent_destroy();
    void destroy();
};

void T_Scenario::destroy() {
    this->parent_destroy();
}
