struct Map_Stack {
    int x;
    int y;
    int cost;
    int tot_cost;
    void* next;
    void* prev;
};

class RGE_Random_Map_Module {
public:
    void init_stack(Map_Stack* stack);
};

void RGE_Random_Map_Module::init_stack(Map_Stack* stack) {
    stack->x = -1;
    stack->y = -1;
    stack->next = 0;
    stack->prev = 0;
    stack->cost = 0;
    stack->tot_cost = 0;
}
