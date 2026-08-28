class TRIBE_Panel_Button {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Panel_Button::destroy() {
    this->parent_destroy();
}
