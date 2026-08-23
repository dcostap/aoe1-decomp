#ifndef RMM_BASE_SHARED_CONTEXT
struct Map_Stack {
    char gap_00[0x10];
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    unsigned char check_stack(Map_Stack* stack);
};
#endif

unsigned char RGE_Random_Map_Module::check_stack(Map_Stack* stack) {
    if (stack->next == 0 && stack->prev == 0) {
        return 0;
    }
    return 1;
}
