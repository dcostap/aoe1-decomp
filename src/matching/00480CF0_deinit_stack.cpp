#ifndef RMM_BASE_SHARED_CONTEXT
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
    void deinit_stack(Map_Stack& stack);
};
#endif
void RGE_Random_Map_Module::deinit_stack(Map_Stack& stack) {
    if (stack.next) {
        stack.next->prev = 0;
        stack.next = 0;
    }
}
