#ifndef ACT_LIST_SHARED_CONTEXT
class RGE_Action;
class RGE_Action_Node;
class RGE_Action_List {
public:
    char gap_0[8];
    RGE_Action_Node* list;
    RGE_Action* get_action();
};
#endif

RGE_Action* RGE_Action_List::get_action() {
    if (this->list) return this->list->action;
    return 0;
}
