#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action_List {
public:
    char gap_0[8];
    int field_8;

    void remove_action();
    void delete_list();
};
#endif

void RGE_Action_List::delete_list() {
    while (this->list) {
        this->remove_action();
    }
}
