struct Map_Stack {
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    void remove_stack_node(Map_Stack* node);
    Map_Stack* pop_stack(Map_Stack* head, long* x, long* y, float* cost);
};

Map_Stack* RGE_Random_Map_Module::pop_stack(Map_Stack* head, long* x, long* y, float* cost) {
    Map_Stack* node = head->next;
    if (node == 0) {
        return 0;
    }
    *x = node->x;
    *y = node->y;
    *cost = node->cost;
    this->remove_stack_node(node);
    return node;
}
