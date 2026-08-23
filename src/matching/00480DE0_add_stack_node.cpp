#ifndef RMM_BASE_SHARED_CONTEXT
struct Map_Stack {
    int x;
    int y;
    int cost;
    int tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    void remove_stack_node(Map_Stack* node);
    void add_stack_node(Map_Stack* target, Map_Stack* node);
};
#endif

void RGE_Random_Map_Module::add_stack_node(Map_Stack* target, Map_Stack* node) {
    if ((node->next != 0) || (node->prev != 0)) {
        this->remove_stack_node(node);
    }
    Map_Stack* next = target->next;
    node->prev = target;
    node->next = next;
    if (target->next != 0) {
        target->next->prev = node;
    }
    target->next = node;
}
