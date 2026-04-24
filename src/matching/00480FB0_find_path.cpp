// tried a one-function wrapper first; it compiled to a recursive basin because I defined the internal overload too
// switching to the outer wrapper only: local Map_Stack, init_stack, inner find_path overload call, deinit_stack
class Map_Stack {
public:
    long x;
    long y;
    float cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    void init_stack(Map_Stack* path_stack);
    void deinit_stack(Map_Stack* path_stack);
    unsigned char find_path(Map_Stack* path_stack, long param_1, long param_2, long* param_3, long* param_4, float* param_5);

    unsigned char find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5);
};

unsigned char RGE_Random_Map_Module::find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5) {
    Map_Stack path_stack;
    unsigned char result;

    this->init_stack(&path_stack);
    result = this->find_path(&path_stack, param_1, param_2, param_3, param_4, param_5);
    this->deinit_stack(&path_stack);
    return result;
}
