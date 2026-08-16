class RGE_Action_List {
public:
    char gap_0[8];
    int field_8;

    void remove_action();
    void delete_list();
};

void RGE_Action_List::delete_list() {
    while (this->field_8) {
        this->remove_action();
    }
}
