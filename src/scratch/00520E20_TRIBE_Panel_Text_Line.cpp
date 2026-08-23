class TRIBE_Panel_Text_Line {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Panel_Text_Line::destroy() {
    this->parent_destroy();
}
