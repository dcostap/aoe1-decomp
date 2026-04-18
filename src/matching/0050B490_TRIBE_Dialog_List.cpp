class TRIBE_Dialog_List {
public:
    void parent_destroy();
    void destroy();
};

void TRIBE_Dialog_List::destroy() {
    this->parent_destroy();
}
