class TDropDownButtonPanel {
public:
    void parent_destroy();
    void destroy();
};

void TDropDownButtonPanel::destroy() {
    this->parent_destroy();
}
