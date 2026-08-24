#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action_Node;

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node *list;

    unsigned char have_action(void);
};
#endif

unsigned char RGE_Action_List::have_action(void) {
    if (this->list) {
        return 1;
    }
    return 0;
}
